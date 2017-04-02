/////////////////////////////////////////////////////////////////////////////////
//                          Page gestion Pompe doseuse
/////////////////////////////////////////////////////////////////////////////////

void P9_b0PopCallback(void *ptr) // Bouton page suivante (appel page 0)
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

void P9_b1PopCallback(void *ptr) // Bouton page précedente (appel page 7)
{
  page7.show();
  num_page = 7;
  P7_t0.setText(buffer_hour);
  P7_t2.setText(buffer_minute);
  switch (val_z1)
  {
    case 0:
    strcpy(buffer, "OFF");
    break;
    case 1:
    strcpy(buffer, "ON");
    break;
    case 2:
    strcpy(buffer, "FOR.");
    break;
  }
  P7_b10.setText(buffer);
  
  switch (val_z2)
  {
    case 0:
    strcpy(buffer, "OFF");
    break;
    case 1:
    strcpy(buffer, "ON");
    break;
    case 2:
    strcpy(buffer, "FOR.");
    
    break;
  }
  P7_b11.setText(buffer);
  
  switch (val_z3)
  {
    case 0:
    strcpy(buffer, "OFF");
    break;
    case 1:
    strcpy(buffer, "ON");
    break;
    case 2:
    strcpy(buffer, "FOR.");
    break;
  }
  P7_b12.setText(buffer);

  switch (val_z4)
  {
    case 0:
    strcpy(buffer, "OFF");
    break;
    case 1:
    strcpy(buffer, "ON");
    break;
    case 2:
    strcpy(buffer, "FOR.");
    break;
  }
  P7_b13.setText(buffer);

  switch (val_z5)
  {
    case 0:
    strcpy(buffer, "OFF");
    break;
    case 1:
    strcpy(buffer, "ON");
    break;
    case 2:
    strcpy(buffer, "FOR.");
    break;
  }
  P7_b14.setText(buffer);
  
  switch (val_z6)
  {
    case 0:
    strcpy(buffer, "OFF");
    break;
    case 1:
    strcpy(buffer, "ON");
    break;
    case 2:
    strcpy(buffer, "FOR.");
    break;
  }
  P7_b15.setText(buffer);

  if (deb_1 >= 0){
     dtostrf(deb_1, 2, 0, buffer);
     P7_t10.setText(buffer);
  }
  else {
     strcpy(buffer, "OFF");
     P7_t10.setText(buffer);
  }

  if (deb_2 >= 0){
     dtostrf(deb_2, 2, 0, buffer);
     P7_t11.setText(buffer);
  }
  else {
     strcpy(buffer, "OFF");
     P7_t11.setText(buffer);
  }

    if (deb_3 >= 0){
     dtostrf(deb_3, 2, 0, buffer);
     P7_t12.setText(buffer);
  }
  else {
     strcpy(buffer, "OFF");
     P7_t12.setText(buffer);
  }

    if (deb_4 >= 0){
     dtostrf(deb_4, 2, 0, buffer);
     P7_t13.setText(buffer);
  }
  else {
     strcpy(buffer, "OFF");
     P7_t13.setText(buffer);
  }

    if (on_lu == 1){
    strcpy(buffer, "ON");
  }
  else {strcpy(buffer, "OFF");
  }
  P7_b3.setText(buffer);
  
  if (on_ma == 1){
    strcpy(buffer, "ON");
  }
  else {strcpy(buffer, "OFF");
  }
  P7_b4.setText(buffer);
  
  if (on_me == 1){
    strcpy(buffer, "ON");
  }
  else {strcpy(buffer, "OFF");
  }
  P7_b5.setText(buffer);
  
  if (on_je == 1){
    strcpy(buffer, "ON");
  }
  else {strcpy(buffer, "OFF");
  }
  P7_b6.setText(buffer);
  
    if (on_ve == 1){
    strcpy(buffer, "ON");
  }
  else {strcpy(buffer, "OFF");
  }
  P7_b7.setText(buffer);
  
    if (on_sa == 1){
    strcpy(buffer, "ON");
  }
  else {strcpy(buffer, "OFF");
  }
  P7_b8.setText(buffer);
  
    if (on_di == 1){
    strcpy(buffer, "ON");
  }
  else {strcpy(buffer, "OFF");
  }
  P7_b9.setText(buffer);

}

// Bouton OFF/Auto/Forcé
void P9_b3PopCallback(void *ptr)
{
  val_bouton_chlore++;
  if (val_bouton_chlore > 2){
    val_bouton_chlore = 0;
  }
  dbSerialPrintln(val_bouton_chlore);
  
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
  EEPROM.write(addr_val_bouton_chlore, val_bouton_chlore);
  P9_b3.setText(buffer);

}

/////////////////////////////////////////////////////////////////////////////////
//                          Fonctions Diverses
/////////////////////////////////////////////////////////////////////////////////
void P9Display() 
{
    P9_n0.setValue(Ton);
    P9_n1.setValue(Toff);
    if (StartInjection == 1){
      P9_t9.setText("ON"); 
    }
    else{
      P9_t9.setText("OFF"); 
    }
    dtostrf (qte_hbdo, 3, 2, buffer);
    P9_t14.setText(buffer);
}

void timeDisplay_p9()
{
  
    memset(buffer, 0, sizeof(buffer)); 
    number = rtc.hour();
    itoa(number, buffer, 10);
    if (strcmp(buffer_hour, buffer))
    {
        P9_t4.setText(buffer);
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
        P9_t6.setText(buffer);
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
            P9_t8.setText(buffer);
            strcpy(buffer_second, buffer);
         }
    } 
    else
    {
        if (strcmp(buffer_temp, buffer_second))
        {
            P9_t8.setText(buffer_temp);
            strcpy(buffer_second, buffer_temp);
        }
    }
}

