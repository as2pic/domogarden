//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                              Pompes
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void pompes()
{

  if (rtc.hour() >= depart_filtration && rtc.hour() < (depart_filtration + duree_filtration)){
      digitalWrite(relais_filtration, LOW);
      filtrationON = 1;
  }
  else {
      digitalWrite(relais_filtration, HIGH);
      filtrationON = 0;
  }
  
  if (rtc.hour() >= depart_robot && rtc.hour() < (depart_robot + duree_robot)){
      digitalWrite(relais_robot, LOW);
      robotON = 1;
      
  }
  else {
      digitalWrite(relais_robot, HIGH);
      robotON = 0;
  }

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                            Hors Gel
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void horsgel()
{
    switch (chk)
    {
      case DHTLIB_OK: 
           if (temp <= (conshorsgel - 0.1)){  
              digitalWrite(relais_filtration, LOW); // si température basse, on démarre la pompe
              horsgelON = 1;
           }
           else if (temp >= (conshorsgel + 0.1)){
              digitalWrite(relais_filtration, HIGH); // si température haute, on arrete la pompe
              horsgelON = 0;
           }
           break;
      case DHTLIB_ERROR_CHECKSUM: 
           dbSerialPrintln(F("Erreur DHT regul Checksum,\t"));
          break;
      case DHTLIB_ERROR_TIMEOUT: 
           dbSerialPrintln(F("Erreur DHT regul Time out,\t"));
           digitalWrite(relais_filtration, LOW); // si défaut capteur, on démarre la pompe
           horsgelON = 1;
          break;
      default: 
           dbSerialPrintln(F("Erreur DHT regul Unknown error,\t"));
          break;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                           Arrosage
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void decompte_arrosage_auto()
{

          // Décompte temps zone 1
        if ((start_z1 == 1) && (val_z1 == 1)){
          t_z1 -= 1;
        }


        // Décompte temps zone 2
        if ((start_z2 == 1) && (val_z2 == 1)){
          t_z2 -= 1;
        }

        // Décompte temps zone 3
        if ((start_z3 == 1) && (val_z3 == 1)){
          t_z3 -= 1;
        }

        // Décompte temps zone 4
        if ((start_z4 == 1) && (val_z4 == 1)){
          t_z4 -= 1;
        }


}

void arrosage(){
    // Déclenchement zone 2 (si t_z1 = 0 ou zone 1 pas activée)
    if ((start_z1 == 1) && ((t_z1 == 0) || (val_z1 == 0))){
          start_z1 = 0;
          delay (2000);
          start_z2 = 1;
    }

    // Déclenchement zone 3 (si t_z2 = 0 ou zone 2 pas activée)
    if ((start_z2 == 1) && ((t_z2 == 0) || (val_z2 == 0))){
          start_z2 = 0;
          delay (2000);
          start_z3 = 1;
    }

    // Déclenchement zone 4 (si t_z3 = 0 ou zone 3 pas activée)
    if ((start_z3 == 1) && ((t_z3 == 0) || (val_z3 == 0))){
          start_z3 = 0;
          delay (2000);
          start_z4 = 1;
     }

    // Stop zone 4
    if ((start_z4 == 1) && ((t_z4 == 0) || (val_z4 == 0))){
          start_z4 = 0;
          t_z1 = EEPROM.readDouble(addr_t_z1);
          t_z2 = EEPROM.readDouble(addr_t_z2);
          t_z3 = EEPROM.readDouble(addr_t_z3);
          t_z4 = EEPROM.readDouble(addr_t_z4);
    }
    
    // Commutation du relais Z1
    if (((start_z1 == 1) && (start_z2 == 0) && (start_z3 == 0) && (start_z4 == 0)) || ((val_z1 == 2) && (val_z2 != 2) && (val_z3 != 2) && (val_z4 != 2))){
      if (mem_etat_R1 ==0){
        delay (2000);
        digitalWrite(relais_z1, LOW);
        mem_etat_R1 = 1;
        sendCommand("t14_p7.bco=2016");
        sendCommand("ref t14_p7");
      }
    }
    if ((val_z1 != 2) && (start_z1 == 0)){
      digitalWrite(relais_z1, HIGH);
      mem_etat_R1 = 0;
      sendCommand("t14_p7.bco=65535");
      sendCommand("ref t14_p7");
    }

    // Commutation du relais Z2
    if (((start_z1 == 0) && (start_z2 == 1) && (start_z3 == 0) && (start_z4 == 0)) || ((val_z1 != 2) && (val_z2 == 2) && (val_z3 != 2) && (val_z4 != 2))){
      if (mem_etat_R2 ==0){
        delay (2000);
        digitalWrite(relais_z2, LOW);
        mem_etat_R2 = 1;
        sendCommand("t15_p7.bco=2016");
        sendCommand("ref t15_p7");
      }
    }
    if ((val_z2 != 2) && (start_z2 == 0)){
      digitalWrite(relais_z2, HIGH);
      mem_etat_R2 = 0;
      sendCommand("t15_p7.bco=65535");
      sendCommand("ref t15_p7");
    }

    // Commutation du relais Z3
    if (((start_z1 == 0) && (start_z2 == 0) && (start_z3 == 1) && (start_z4 == 0)) || ((val_z1 != 2) && (val_z2 != 2) && (val_z3 == 2) && (val_z4 != 2))){
      if (mem_etat_R3 ==0){
        delay (2000);
        digitalWrite(relais_z3, LOW);
        mem_etat_R3 = 1;
        sendCommand("t16_p7.bco=2016");
        sendCommand("ref t16_p7");
      }
    }
    if ((val_z3 != 2) && (start_z3 == 0)){
      digitalWrite(relais_z3, HIGH);
      mem_etat_R3 = 0;
      sendCommand("t16_p7.bco=65535");
      sendCommand("ref t16_p7");
    }

    // Commutation du relais Z4
    if (((start_z1 == 0) && (start_z2 == 0) && (start_z3 == 0) && (start_z4 == 1)) || ((val_z1 != 2) && (val_z2 != 2) && (val_z3 != 2) && (val_z4 == 2))){
      if (mem_etat_R4 ==0){
        delay (2000);
        digitalWrite(relais_z4, LOW);
        mem_etat_R4 = 1;
        sendCommand("t17_p7.bco=2016");
        sendCommand("ref t17_p7");
      }
    }
    if ((val_z4 != 2) && (start_z4 == 0)){
      digitalWrite(relais_z4, HIGH);
      mem_etat_R4 = 0;
      sendCommand("t17_p7.bco=65535");
      sendCommand("ref t17_p7");
    }
  
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                  Mesure température systeme (Via le RTC DS3232)
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void temp_sytem(){
    union int16_byte {
       int i;
       byte b[2];
    } rtcTemp;

    Wire.beginTransmission(DS3231_RTC_ADDR);
    Wire.write(DS3231_TEMP_MSB);
    Wire.endTransmission();
    Wire.requestFrom(DS3231_RTC_ADDR, 2);
    rtcTemp.b[1] = Wire.read(); 
    rtcTemp.b[0] = Wire.read();
    long tempC100 = (rtcTemp.i >> 6) * 25;    //degrees celsius times 100
    val_temp_system = tempC100 / 100;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                Ecriture SDcard
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SDCard(){

    //Ouverture du fichier
    fichierSD = SD.open("log.txt", FILE_WRITE);
    if(fichierSD) {
      dbSerialPrintln(F("Ecriture Data"));
      fichierSD.print(rtc.hour());
      fichierSD.print(":");
      fichierSD.print(rtc.minute()/10);
      fichierSD.println(rtc.minute()%10);
      fichierSD.print("Ph:");
      fichierSD.println(ph_value_float);
      fichierSD.print("Redox:");
      fichierSD.println(redox_value_float);
      fichierSD.println("   ");
      fichierSD.close();
    }  
    
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                Injection chlore
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void injection_chlore(){
    ///////////////////// Injection, consigne 740 /////////////////
    // si 670 =< redox <740 (20% injection) Ton=120 Toff=480
    if ((filtrationON == 1) && (redox_value_float >= (seuil_redox - 70)) && (redox_value_float < seuil_redox) && (StartInjection == 0)){      
        Ton = 120;
        Toff = 480;
        StartInjection = 1;
        CycleChlore = 20;
    }
    // si 600 =< redox <670 (50% injection )Ton=300 Toff=300
    if ((filtrationON == 1) && (redox_value_float >= (seuil_redox - 140)) && (redox_value_float < (seuil_redox - 70)) && (StartInjection == 0)){
        Ton = 300;
        Toff = 300;
        StartInjection = 1;
        CycleChlore = 50;
    }
    // si 530 =< redox <600 (75% injection) Ton=450 Toff=150
    if ((filtrationON == 1) && (redox_value_float >= (seuil_redox - 210)) && (redox_value_float < (seuil_redox - 140)) && (StartInjection == 0)){
        Ton = 450;
        Toff = 150;
        StartInjection = 1;
        CycleChlore = 75;
    }
    // si redox <530 (100% injection) Ton=600 Toff=1 
    if ((filtrationON == 1) && (redox_value_float < (seuil_redox - 210)) && (StartInjection == 0)){
        Ton = 600;
        Toff = 1;
        StartInjection = 1;
        CycleChlore = 100;
    }
    // si redox > seuil, on stop l'injection 
    if ((redox_value_float >= seuil_redox) && (StartInjection == 0)){
        injection_chloreON = 0;
        CycleChlore = 0;
    }

    // Décompte temps injection
    if (StartInjection == 1){
      if (Ton > 0){
        Ton -= 1;
        injection_chloreON = 1;
      }
      if (Ton == 0){
        Toff -= 1;
        injection_chloreON = 0;
      }
      if (Toff <= 0){
        StartInjection = 0;
        injection_chloreON = 0;
      }
    }
    
    if ((val_bouton_chlore == 0) || (SecuOfaChlore == 1) || (filtrationON == 0)){  // Bouton chlore sur OFF ou sécu OFA ou pompe arrêtée, stop injection et init variables
        Ton = 0;
        Toff = 0;
        StartInjection = 0;
        injection_chloreON = 0;
        CycleChlore = 0;
    }
    
    // Pilotage Relais Pompe Injection chlore
    if ((((injection_chloreON == 1)&& (SecuOfaChlore == 0)) || (val_bouton_chlore == 2))&& (filtrationON == 1)){
        digitalWrite(relais_chlore, LOW);
        qte_hbdo = qte_hbdo + (debit_pompe_chlore / 3600);
    }
    else {
        digitalWrite(relais_chlore, HIGH);
    }

    //    Activation sortie buzzer
    if (SecuOfaChlore == 1){
      digitalWrite(Buzzer, LOW);
    }
    else {
      digitalWrite(Buzzer, HIGH);
    }

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                Injection Ph
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void injection_ph(){
    ///////////////////// Injection, consigne 7.4 /////////////////
    // si 7.4 < ph =<7.55 (20% injection) Ton=120 Toff=480
    if ((filtrationON == 1) && (ph_value_float <= (seuil_ph + 0.15)) && (ph_value_float > seuil_ph) && (StartInjectionPh == 0)){      
        TonPh = 120;
        ToffPh = 480;
        StartInjectionPh = 1;
        CyclePh = 20;
    }
    // si 7.55 < ph =<7.70 (50% injection )Ton=300 Toff=300
    if ((filtrationON == 1) && (ph_value_float <= (seuil_ph + 0.30)) && (ph_value_float > (seuil_ph + 0.15)) && (StartInjectionPh == 0)){
        TonPh = 300;
        ToffPh = 300;
        StartInjectionPh = 1;
        CyclePh = 50;
    }
    // si 7.70 < ph =<7.85 (75% injection) Ton=450 Toff=150
    if ((filtrationON == 1) && (ph_value_float <= (seuil_ph + 0.45)) && (ph_value_float > (seuil_ph + 0.30)) && (StartInjectionPh == 0)){
        TonPh = 450;
        ToffPh = 150;
        StartInjectionPh = 1;
        CyclePh = 75;
    }
    // si ph > 7.85  (100% injection) Ton=600 Toff=1 
    if ((filtrationON == 1) && (ph_value_float > (seuil_ph + 0.45)) && (StartInjectionPh == 0)){
        TonPh = 600;
        ToffPh = 1;
        StartInjectionPh = 1;
        CyclePh = 100;
    }
    // si ph < seuil ph  -> pas d'injection 
    if ((ph_value_float <= seuil_ph) && (StartInjectionPh == 0)){
        injection_phON = 0;
        CyclePh = 0;
    }

    // Décompte temps injection
    if (StartInjectionPh == 1){
      if (TonPh > 0){
        TonPh -= 1;
        injection_phON = 1;
      }
      if (TonPh == 0){
        ToffPh -= 1;
        injection_phON = 0;
      }
      if (ToffPh <= 0){
        StartInjectionPh = 0;
        injection_phON = 0;
      }
    }
    
    if ((val_bouton_ph == 0) || (SecuOfaPh == 1) || (filtrationON == 0)){  // Bouton Ph sur OFF ou sécu OFA ou pompe arrêtée, stop injection et init variables
        TonPh = 0;
        ToffPh = 0;
        StartInjectionPh = 0;
        injection_phON = 0;
        CyclePh = 0;
    }
    
    // Pilotage Relais Pompe Injection Ph
    if ((((injection_phON == 1)&& (SecuOfaPh == 0)) || (val_bouton_ph == 2))&& (filtrationON == 1)){
        digitalWrite(relais_ph, LOW);
        qte_hbdo_ph = qte_hbdo_ph + (debit_pompe_ph / 3600);
    }
    else {
        digitalWrite(relais_ph, HIGH);
    }

    //    Activation sortie buzzer
    if (SecuOfaPh == 1){
      digitalWrite(Buzzer, LOW);
    }
    else {
      digitalWrite(Buzzer, HIGH);
    }
  
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
