/////////////////////////////////////////////////////////////////////////////////
//                          Page gestion arrosage intégré
/////////////////////////////////////////////////////////////////////////////////


void P7_b0PopCallback(void *ptr)
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

void P7_b1PopCallback(void *ptr)
{
  page3.show();
  num_page = 3;
  P3_t4.setText(buffer_hour);
  P3_t6.setText(buffer_minute);
  dtostrf(conshorsgel, 5, 1, buffer);
  P3_t2.setText(buffer);
}

void P7_b2PopCallback(void *ptr)
{
  page8.show();
  num_page = 8;
  P8_n4.setValue(t_z1);
  P8_n5.setValue(t_z2);
  P8_n6.setValue(t_z3);
  P8_n7.setValue(t_z4);
  P8_n8.setValue(t_z5);
  P8_n9.setValue(t_z6);

  if (deb_1 >= 0){
    dtostrf(deb_1, 2, 0, buffer);
    P8_t7.setText(buffer);
  }
  else {
    strcpy(buffer, "OFF");
    P8_t7.setText(buffer);
  }

  if (deb_2 >= 0){
    dtostrf(deb_2, 2, 0, buffer);
    P8_t8.setText(buffer);
  }
  else {
    strcpy(buffer, "OFF");
    P8_t8.setText(buffer);
  }
  if (deb_3 >= 0){
    dtostrf(deb_3, 2, 0, buffer);
    P8_t9.setText(buffer);
  }
  else {
    strcpy(buffer, "OFF");
    P8_t9.setText(buffer);
  }
  if (deb_4 >= 0){
    dtostrf(deb_4, 2, 0, buffer);
    P8_t10.setText(buffer);
  }
  else {
    strcpy(buffer, "OFF");
    P8_t10.setText(buffer);
  }
}

void P7_b3PopCallback(void *ptr)
{
  on_lu = !on_lu;
  if (on_lu == 1){
    strcpy(buffer, "ON");
  }
  else {strcpy(buffer, "OFF");
  }
  EEPROM.writeBit(addr_on_day, point_on_lu, on_lu);
  P7_b3.setText(buffer);
}

void P7_b4PopCallback(void *ptr)
{
  on_ma = !on_ma;
  if (on_ma == 1){
    strcpy(buffer, "ON");
  }
  else {strcpy(buffer, "OFF");
  }
  EEPROM.writeBit(addr_on_day, point_on_ma, on_ma);
  P7_b4.setText(buffer);
}

void P7_b5PopCallback(void *ptr)
{
  on_me = !on_me;
  if (on_me == 1){
    strcpy(buffer, "ON");
  }
  else {strcpy(buffer, "OFF");
  }
  EEPROM.writeBit(addr_on_day, point_on_me, on_me);
  P7_b5.setText(buffer);
}

void P7_b6PopCallback(void *ptr)
{
  on_je = !on_je;
  if (on_je == 1){
    strcpy(buffer, "ON");
  }
  else {strcpy(buffer, "OFF");
  }
  EEPROM.writeBit(addr_on_day, point_on_je, on_je);
  P7_b6.setText(buffer);
}

void P7_b7PopCallback(void *ptr)
{
  on_ve = !on_ve;
  if (on_ve == 1){
    strcpy(buffer, "ON");
  }
  else {strcpy(buffer, "OFF");
  }
  EEPROM.writeBit(addr_on_day, point_on_ve, on_ve);
  P7_b7.setText(buffer);
}

void P7_b8PopCallback(void *ptr)
{
  on_sa = !on_sa;
  if (on_sa == 1){
    strcpy(buffer, "ON");
  }
  else {strcpy(buffer, "OFF");
  }
  EEPROM.writeBit(addr_on_day, point_on_sa, on_sa);
  P7_b8.setText(buffer);
}

void P7_b9PopCallback(void *ptr)
{
  on_di = !on_di;
  if (on_di == 1){
    strcpy(buffer, "ON");
  }
  else {strcpy(buffer, "OFF");
  }
  EEPROM.writeBit(addr_on_day, point_on_di, on_di);
  P7_b9.setText(buffer);
}

// Bouton Zone 1
void P7_b10PopCallback(void *ptr)
{
  val_z1++;
  if (val_z1 > 2){
    val_z1 = 0;
  }
  dbSerialPrintln(val_z1);
  
  switch (val_z1)
  {
    case 0:
    strcpy(buffer, "OFF");
//    digitalWrite(relais_z1, HIGH);
    break;
    case 1:
    strcpy(buffer, "ON");
//    digitalWrite(relais_z1, HIGH);
    break;
    case 2:
    strcpy(buffer, "FOR.");
    break;
    }
  EEPROM.write(addr_val_z1, val_z1);
  P7_b10.setText(buffer);

}

// Bouton Zone 2
void P7_b11PopCallback(void *ptr)
{
  val_z2++;
  if (val_z2 > 2){
    val_z2 = 0;
  }
  dbSerialPrintln(val_z2);
  
  switch (val_z2)
  {
    case 0:
    strcpy(buffer, "OFF");
    digitalWrite(relais_z2, HIGH);
    break;
    case 1:
    strcpy(buffer, "ON");
    digitalWrite(relais_z2, HIGH);
    break;
    case 2:
    strcpy(buffer, "FOR.");
    break;
    }
  EEPROM.write(addr_val_z2, val_z2);
  P7_b11.setText(buffer);

}

void P7_b12PopCallback(void *ptr)
{
  val_z3++;
  if (val_z3 > 2){
    val_z3 = 0;
  }
  dbSerialPrintln(val_z3);
  
  switch (val_z3)
  {
    case 0:
    strcpy(buffer, "OFF");
    digitalWrite(relais_z3, HIGH);
    break;
    case 1:
    strcpy(buffer, "ON");
    digitalWrite(relais_z3, HIGH);
    break;
    case 2:
    strcpy(buffer, "FOR.");
    break;
    }
  EEPROM.write(addr_val_z3, val_z3);
  P7_b12.setText(buffer);

}

void P7_b13PopCallback(void *ptr)
{
  val_z4++;
  if (val_z4 > 2){
    val_z4 = 0;
  }
  dbSerialPrintln(val_z4);
  
  switch (val_z4)
  {
    case 0:
    strcpy(buffer, "OFF");
    digitalWrite(relais_z4, HIGH);
    break;
    case 1:
    strcpy(buffer, "ON");
    digitalWrite(relais_z4, HIGH);
    break;
    case 2:
    strcpy(buffer, "FOR.");
    break;
    }
  EEPROM.write(addr_val_z4, val_z4);
  P7_b13.setText(buffer);

}

void P7_b16PopCallback(void *ptr)
{
  start_z1 = 0;
  start_z2 = 0;
  start_z3 = 0;
  start_z4 = 0;
  t_z1 = EEPROM.readDouble(addr_t_z1);
  t_z2 = EEPROM.readDouble(addr_t_z2);
  t_z3 = EEPROM.readDouble(addr_t_z3);
  t_z4 = EEPROM.readDouble(addr_t_z4);
  dbSerialPrintln("Cycle arrete");
    
}

/////////////////////////////////////////////////////////////////////////////////
//                          Fonctions Diverses
/////////////////////////////////////////////////////////////////////////////////

void timeDisplay_p7()
{
  
    memset(buffer, 0, sizeof(buffer)); 
    number = rtc.hour();
    itoa(number, buffer, 10);
    if (strcmp(buffer_hour, buffer))
    {
        P7_t0.setText(buffer);
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
        P7_t2.setText(buffer);
        strcpy(buffer_minute, buffer); 
    }
    
}

void P7Display()
{
  dtostrf(t_z1, 3, 0, buffer);
  P7_t14.setText(buffer);
  dtostrf(t_z2, 3, 0, buffer);
  P7_t15.setText(buffer);
  dtostrf(t_z3, 3, 0, buffer);
  P7_t16.setText(buffer);
  dtostrf(t_z4, 3, 0, buffer);
  P7_t17.setText(buffer);
    
}


