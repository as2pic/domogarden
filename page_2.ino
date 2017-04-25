/////////////////////////////////////////////////////////////////////////////////
//                          Page gestion pompes
/////////////////////////////////////////////////////////////////////////////////

void P2_b0PopCallback(void *ptr) // Bouton page suivante (appel page 3)
{
  page3.show();
  num_page = 3;
  P3_t4.setText(buffer_hour);
  P3_t6.setText(buffer_minute);
  dtostrf(conshorsgel, 5, 1, buffer);
  P3_t2.setText(buffer);
}

void P2_b1PopCallback(void *ptr) // Bouton page précedente (appel page 0)
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

void P2_b2PopCallback(void *ptr)
{
  page4.show();
  num_page = 4; 
  P4_n0.setValue(depart_filtration);
  P4_n1.setValue(duree_filtration); 
  P4_n2.setValue(depart_robot);
  P4_n3.setValue(duree_robot);
}

/////////////////////////////////////////////////////////////////////////////////
//                          Fonctions Diverses
/////////////////////////////////////////////////////////////////////////////////
void timeDisplay_p2()
{

    
    memset(buffer, 0, sizeof(buffer)); 
    number = rtc.hour();
    itoa(number, buffer, 10);
    if (strcmp(buffer_hour, buffer))
    {
        P2_t4.setText(buffer);
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
        P2_t6.setText(buffer);
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
            P2_t8.setText(buffer);
            strcpy(buffer_second, buffer);
         }
    } 
    else
    {
        if (strcmp(buffer_temp, buffer_second))
        {
            P2_t8.setText(buffer_temp);
            strcpy(buffer_second, buffer_temp);
        }
    }
}
