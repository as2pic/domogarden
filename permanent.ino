///////////////////////////////////////////////////////////
//            Pompes
///////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////
//            Hors Gel
///////////////////////////////////////////////////////////

void horsgel()
{
    switch (chk)
    {
      case DHTLIB_OK: 
           if (temp <= (conshorsgel - 0.1)){  
              digitalWrite(relais_horsgel, LOW); // si température basse, on démarre la pompe
              horsgelON = 1;
           }
           else if (temp >= (conshorsgel + 0.1)){
              digitalWrite(relais_horsgel, HIGH); // si température haute, on arrete la pompe
              horsgelON = 0;
           }
           break;
      case DHTLIB_ERROR_CHECKSUM: 
           dbSerialPrintln("Erreur DHT regul Checksum,\t");
          break;
      case DHTLIB_ERROR_TIMEOUT: 
           dbSerialPrintln("Erreur DHT regul Time out,\t");
           digitalWrite(relais_horsgel, LOW); // si défaut capteur, on démarre la pompe
           horsgelON = 1;
          break;
      default: 
           dbSerialPrintln("Erreur DHT regul Unknown error,\t");
          break;
    }
}

///////////////////////////////////////////////////////////
//            Arrosage
///////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////
//     Mesure température systeme (Via le RTC DS3232)
///////////////////////////////////////////////////////////
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
//    Serial.print("temp RTC= ");
//    Serial.print( tempC100 / 100 );
//    Serial.print( '.' );
//    Serial.println( abs(tempC100 % 100) );
    Serial.println( tempC100);
    Serial.println( val_temp_system);
}

///////////////////////////////////////////////////////////
//     Ecriture SDcard
///////////////////////////////////////////////////////////
void SDCard(){

    //Ouverture du fichier
    fichierSD = SD.open("log.txt", FILE_WRITE);
    if(fichierSD) {
      dbSerialPrintln("Ecriture Data");
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

///////////////////////////////////////////////////////////
//    Injection chlore
///////////////////////////////////////////////////////////
void injection_chlore(){
    ///////////////////// Injection, consigne 740 /////////////////
    // si 670 =< redox <740 (20% injection) Ton=120 Toff=480
    if ((filtrationON == 1) && (redox_value_float >= (seuil_redox - 70)) && (redox_value_float < seuil_redox) && (StartInjection == 0)){      
        Ton = 120;
        Toff = 480;
        StartInjection = 1;
    }
    // si 600 =< redox <670 (50% injection )Ton=300 Toff=300
    if ((filtrationON == 1) && (redox_value_float >= (seuil_redox - 140)) && (redox_value_float < (seuil_redox - 70)) && (StartInjection == 0)){
        Ton = 300;
        Toff = 300;
        StartInjection = 1;
    }
    // si 530 =< redox <600 (75% injection) Ton=450 Toff=150
    if ((filtrationON == 1) && (redox_value_float >= (seuil_redox - 210)) && (redox_value_float < (seuil_redox - 140)) && (StartInjection == 0)){
        Ton = 450;
        Toff = 150;
        StartInjection = 1;
    }
    // si redox <530 (100% injection) Ton=500 Toff=1 
    if ((filtrationON == 1) && (redox_value_float < (seuil_redox - 210)) && (StartInjection == 0)){
        Ton = 500;
        Toff = 1;
        StartInjection = 1;
    }
    if ((redox_value_float >= 740)&& (StartInjection == 0)){
        injection_chloreON = 0;
    }

    // Décompte temps injection
    if (StartInjection == 1){
      if (Ton > 0){
        Ton -= 1;
        qte_hbdo = qte_hbdo + debit_pompe_chlore;
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
    
    if (val_bouton_chlore == 0){  // Bouton chlore sur OFF, on coupe la pompe
        Ton = 0;
        Toff = 0;
        StartInjection = 0;
        injection_chloreON = 0;
    }
    
    // Pilotage Relais
    if ((injection_chloreON == 1) || (val_bouton_chlore == 2)){
        digitalWrite(relais_chlore, LOW);
    }
    else {
        digitalWrite(relais_chlore, HIGH);
    }
}
///////////////////////////////////////////////////////////          

