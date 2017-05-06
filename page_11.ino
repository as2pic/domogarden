/////////////////////////////////////////////////////////////////////////////////
//                          Page gestion Pompe doseuse PH
/////////////////////////////////////////////////////////////////////////////////
void P11_b0PopCallback(void *ptr) // Bouton page suivante (appel page 0)
{
  page0.show();
  num_page = 0;
  P0_t2.setText(buffer_hour);
  P0_t4.setText(buffer_minute);
  P0_t8.setText(buffer_day);
  P0_t9.setText(buffer_week);
  P0_t10.setText(buffer_month);
  P0_t12.setText(buffer_year);
}

void P11_b1PopCallback(void *ptr) // Bouton page précedente (appel page 9)
{
  page9.show();
  num_page = 9;
  switch (val_bouton_chlore)
  {
    case 0:
    strcpy(buffer, "OFF");
    break;
    case 1:
    strcpy(buffer, "AUTO");
    break;
    case 2:
    strcpy(buffer, "FOR.");
    break;
    }
  P9_b3.setText(buffer);
  P9_t4.setText(buffer_hour);
  P9_t6.setText(buffer_minute);
}

void P11_b2PopCallback(void *ptr) // Bouton page Réglages (page 12)
{
  page12.show();
  num_page = 12;
  dtostrf(debit_pompe_ph, 5, 1, buffer);
  P12_t2.setText(buffer);
}


// Bouton OFF/Auto/Forcé
void P11_b3PopCallback(void *ptr)
{
  val_bouton_ph++;
  if (val_bouton_ph > 2){
    val_bouton_ph = 0;
  }
  
  switch (val_bouton_ph)
  {
    case 0:
    strcpy(buffer, "OFF");
    break;
    case 1:
    strcpy(buffer, "AUTO");
    break;
    case 2:
    strcpy(buffer, "FOR.");
    break;
    }
  EEPROM.write(addr_val_bouton_ph, val_bouton_ph);
  P11_b3.setText(buffer);

}

/////////////////////////////////////////////////////////////////////////////////
//                          Fonctions Diverses
/////////////////////////////////////////////////////////////////////////////////
void P11Display() 
{
    P11_n0.setValue(TonPh);
    P11_n1.setValue(ToffPh);
    P11_n2.setValue(TpsSecuOfaPh);
    P11_n3.setValue(CyclePh);
    if (StartInjectionPh == 1){
      P11_t9.setText("ON"); 
    }
    else{
      P11_t9.setText("OFF"); 
    }
    dtostrf (qte_hbdo_ph, 3, 2, buffer);
    P11_t14.setText(buffer);
    if (SecuOfaPh == 1){
      P11_t18.setText("ALARME OFA");
    }
    else {
      P11_t18.setText(" ");
    }
}

void timeDisplay_p11()
{
  
    memset(buffer, 0, sizeof(buffer)); 
    number = rtc.hour();
    itoa(number, buffer, 10);
    if (strcmp(buffer_hour, buffer))
    {
        P11_t4.setText(buffer);
        strcpy(buffer_hour, buffer); 
    }

    memset(buffer, 0, sizeof(buffer));
    memset(buffer_temp, 0, sizeof(buffer_temp));
    number = rtc.minute();
    itoa(number, buffer_temp, 10);
    if (rtc.minute() < 10)
    {
        strcat(buffer, "0");
    }
    strcat(buffer, buffer_temp);
    if (strcmp(buffer_minute, buffer))
    {
        P11_t6.setText(buffer);
        strcpy(buffer_minute, buffer); 
    }
    
    
    memset(buffer, 0, sizeof(buffer)); 
    memset(buffer_temp, 0, sizeof(buffer_temp)); 
    number = rtc.second();
    itoa(number, buffer_temp, 10);
    if (number < 10)
    {
        strcpy(buffer, "0");
        strcat(buffer, buffer_temp);
        if (strcmp(buffer, buffer_second))
        {
            P11_t8.setText(buffer);
            strcpy(buffer_second, buffer);
         }
    } 
    else
    {
        if (strcmp(buffer_temp, buffer_second))
        {
            P11_t8.setText(buffer_temp);
            strcpy(buffer_second, buffer_temp);
        }
    }
}

