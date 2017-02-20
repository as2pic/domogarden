///////////////////////////////////////////////////////////
//            Pompes
///////////////////////////////////////////////////////////

void pompes()
{

  if (rtc.hour() >= depart_filtration && rtc.hour() < (depart_filtration + duree_filtration)){
      digitalWrite(relais_filtration, LOW);
  }
  else {
      digitalWrite(relais_filtration, HIGH);
  }
  
  if (rtc.hour() >= depart_robot && rtc.hour() < (depart_robot + duree_robot)){
      digitalWrite(relais_robot, LOW);
  }
  else {
      digitalWrite(relais_robot, HIGH);
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
           }
           else if (temp >= (conshorsgel + 0.1)){
              digitalWrite(relais_horsgel, HIGH); // si température haute, on arrete la pompe
           }
           break;
      case DHTLIB_ERROR_CHECKSUM: 
           dbSerialPrintln("Erreur DHT regul Checksum,\t");
          break;
      case DHTLIB_ERROR_TIMEOUT: 
           dbSerialPrintln("Erreur DHT regul Time out,\t");
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
          start_z2 = 1;
    }

    // Déclenchement zone 3 (si t_z2 = 0 ou zone 2 pas activée)
    if ((start_z2 == 1) && ((t_z2 == 0) || (val_z2 == 0))){
          start_z2 = 0;
          start_z3 = 1;
    }

    // Déclenchement zone 4 (si t_z3 = 0 ou zone 3 pas activée)
    if ((start_z3 == 1) && ((t_z3 == 0) || (val_z3 == 0))){
          start_z3 = 0;
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
    if ((start_z1 == 1) || (val_z1 == 2)){
      digitalWrite(relais_z1, LOW);
      sendCommand("t14_p7.bco=2016");
      sendCommand("ref t14_p7");
    }
    else if (val_z1 != 2){
      digitalWrite(relais_z1, HIGH);
      sendCommand("t14_p7.bco=65535");
      sendCommand("ref t14_p7");
    }

    // Commutation du relais Z2
    if ((start_z2 == 1) || (val_z2 == 2)){
      digitalWrite(relais_z2, LOW);
      sendCommand("t15_p7.bco=2016");
      sendCommand("ref t15_p7");
    }
    else if (val_z2 != 2){
      digitalWrite(relais_z2, HIGH);
      sendCommand("t15_p7.bco=65535");
      sendCommand("ref t15_p7");
    }

    // Commutation du relais Z3
    if ((start_z3 == 1)|| (val_z3 == 2)){
      digitalWrite(relais_z3, LOW);
      sendCommand("t16_p7.bco=2016");
      sendCommand("ref t16_p7");
    }
    else if (val_z3 != 2){
      digitalWrite(relais_z3, HIGH);
      sendCommand("t16_p7.bco=65535");
      sendCommand("ref t16_p7");
    }

    // Commutation du relais Z4
    if ((start_z4 == 1) || (val_z1 == 2)){
      digitalWrite(relais_z4, LOW);
      sendCommand("t17_p7.bco=2016");
      sendCommand("ref t17_p7");
    }
    else if (val_z4 != 2){
      digitalWrite(relais_z4, HIGH);
      sendCommand("t17_p7.bco=65535");
      sendCommand("ref t17_p7");
    }
  
}
///////////////////////////////////////////////////////////


