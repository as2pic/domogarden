/////////////////////////////////////////////////////////////////////////////////
//                          Page Hors gel
/////////////////////////////////////////////////////////////////////////////////

void P3_b2PopCallback(void *ptr)
{
  page5.show();
  num_page = 5;
  dtostrf(conshorsgel, 5, 1, buffer);
  P5_t1.setText(buffer);
}

void P3_b0PopCallback(void *ptr)
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
  
void P3_b1PopCallback(void *ptr)
{
  page2.show();
  num_page = 2;
  P2_n0.setValue(depart_filtration);
  P2_n2.setValue(duree_filtration);
  P2_n1.setValue(depart_robot);
  P2_n3.setValue(duree_robot);
  P2_t4.setText(buffer_hour);
  P2_t6.setText(buffer_minute);
}

/////////////////////////////////////////////////////////////////////////////////
//                          Fonctions Diverses
/////////////////////////////////////////////////////////////////////////////////
void P3Display()
{

    switch (chk)
    {
      case DHTLIB_OK:  
            if (temp <= conshorsgel){
              P3_t9.setText("ON");
            }
            else {
              P3_t9.setText("OFF");
            }
           break;
      case DHTLIB_ERROR_CHECKSUM: 
          P3_t9.setText("Err.");     
          break;
      case DHTLIB_ERROR_TIMEOUT: 
          P3_t9.setText("Err.");       
          break;
      default: 
          P3_t9.setText("Err.");   
          break;
    }

}
void timeDisplay_p3()
{
  
    memset(buffer, 0, sizeof(buffer)); 
    number = rtc.hour();
    itoa(number, buffer, 10);
    if (strcmp(buffer_hour, buffer))
    {
        P3_t4.setText(buffer);
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
        P3_t6.setText(buffer);
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
            P3_t8.setText(buffer);
            strcpy(buffer_second, buffer);
         }
    } 
    else
    {
        if (strcmp(buffer_temp, buffer_second))
        {
            P3_t8.setText(buffer_temp);
            strcpy(buffer_second, buffer_temp);
        }
    }
}
