/////////////////////////////////////////////////////////////////////////////////
//                          Page principale
/////////////////////////////////////////////////////////////////////////////////
void P0_b0PopCallback(void *ptr) // Bouton page suivante (appel page 2)
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

void P0_b1PopCallback(void *ptr) // Bouton page précedente (appel page 11)
{
  page11.show();
  num_page = 11;
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
  P11_b3.setText(buffer);
  P11_t4.setText(buffer_hour);
  P11_t6.setText(buffer_minute);
}

void P0_b2PopCallback(void *ptr) // Bouton réglage (appel page 1)
{
    page1.show();
    num_page = 1;
    P1_n1.setValue(seuil_redox);
    P1_n3.setValue(redox_value_float);
    P1_n4.setValue(etalon_redox);
    P1_n5.setValue(delta_redox);
    P1_b8.setText(buffer_year);
    P1_b6.setText(buffer_month);
    P1_b5.setText(buffer_day);
    P1_b11.setText(buffer_hour);
    P1_b12.setText(buffer_minute);
    P1_b13.setText(buffer_week);
    dtostrf (etalon_ph_acide, 3, 1, buffer);
    P1_t8.setText(buffer);
    dtostrf (etalon_ph_base, 3, 1, buffer);
    P1_t11.setText(buffer);
    dtostrf (seuil_ph, 3, 1, buffer);
    P1_t13.setText(buffer);
    number_settime_year = atoi(buffer_year);
    number_settime_month = atoi(buffer_month);
    number_settime_day = atoi(buffer_day);
    number_settime_hour = atoi(buffer_hour);
    number_settime_minute = atoi(buffer_minute);
    if(strcmp(buffer_week, "Lundi") == 0)
    {
        number_settime_week = 1;
    }
    if(strcmp(buffer_week, "Mardi") == 0)
    {
        number_settime_week = 2;
    }
    if(strcmp(buffer_week, "Mercredi") == 0)
    {
        number_settime_week = 3;
    }
    if(strcmp(buffer_week, "Jeudi") == 0)
    {
        number_settime_week = 4;
    }
    if(strcmp(buffer_week, "Vendredi") == 0)
    {
        number_settime_week = 5;
    }
    if(strcmp(buffer_week, "Samedi") == 0)
    {
        number_settime_week = 6;
    }
    if(strcmp(buffer_week, "Dimanche") == 0)
    {
        number_settime_week = 7;
    }
    if(strcmp(buffer_week, "Fail") == 0)
    {
        number_settime_week = -1;
    }
    
}

/////////////////////////////////////////////////////////////////////////////////
//                          Fonctions Diverses
/////////////////////////////////////////////////////////////////////////////////
void P0Display() 
{
    memset(buffer, 0, sizeof(buffer));
    dtostrf(temp, 5, 1, buffer);
    P0_t14.setText(buffer);
    memset(buffer, 0, sizeof(buffer));
    dtostrf(ph_value_float, 5, 1, buffer);
    P0_t0.setText(buffer);
    P0_n0.setValue(redox_value_float);
    P0_n1.setValue(redox_min);
    P0_n2.setValue(redox_max);
    P0_n3.setValue(val_temp_system);
    if( redox_value_float < redox_min)
    {
        P0_t17.setText("Chlore trop bas");
    }
    else if( redox_value_float > redox_max)
    {
        P0_t17.setText("Chlore trop haut");
    }
    else 
    {
        P0_t17.setText("Chlore Ok :o)");
    }
    dtostrf (seuil_ph, 3, 1, buffer);
    P0_t22.setText(buffer);
}

void timeDisplay()
{
    memset(buffer, 0, sizeof(buffer)); 
    number = rtc.hour();
    itoa(number, buffer, 10);
    if (strcmp(buffer_hour, buffer))
    {
        P0_t2.setText(buffer);
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
        P0_t4.setText(buffer);
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
            P0_t7.setText(buffer);
            strcpy(buffer_second, buffer);
         }
    } 
    else
    {
        if (strcmp(buffer_temp, buffer_second))
        {
            P0_t7.setText(buffer_temp);
            strcpy(buffer_second, buffer_temp);
        }
    }
        
    
    switch (rtc.dayOfWeek())
    {
        case 1:
                strcpy(buffer, "Lundi");
                break;
        case 2: 
                strcpy(buffer, "Mardi");
                break;
        case 3:
                strcpy(buffer, "Mercredi");
                break;
        case 4:
                strcpy(buffer, "Jeudi");
                break;
        case 5:
                strcpy(buffer, "Vendredi");
                break;
        case 6:
                strcpy(buffer, "Samedi");
                break;
        case 7:
                strcpy(buffer, "Dimanche");
                break;
        default:
                strcpy(buffer, "fail");
                break;
    }

    if (strcmp(buffer_week, buffer))
    {
        P0_t9.setText(buffer);
        strcpy(buffer_week, buffer);
    }

    
    switch (rtc.month())
    {
        case 1:
                strcpy(buffer, "Jan.");
                break;
        case 2: 
                strcpy(buffer, "Feb.");
                break;
        case 3:
                strcpy(buffer, "Mar.");
                break;
        case 4:
                strcpy(buffer, "Apr.");
                break;
        case 5:
                strcpy(buffer, "May.");
                break;
        case 6:
                strcpy(buffer, "Jun.");
                break;
        case 7:
                strcpy(buffer, "Jul.");
                break;
        case 8: 
                strcpy(buffer, "Aug.");
                break;
        case 9:
                strcpy(buffer, "Sep.");
                break;
        case 10:
                strcpy(buffer, "Oct.");
                break;
        case 11:
                strcpy(buffer, "Nov.");
                break;
        case 12:
                strcpy(buffer, "Dec.");
                break;
        default:
                strcpy(buffer, "fail");
                break;
    }
    if (strcmp(buffer_month, buffer))
    {
        P0_t10.setText(buffer);
        strcpy(buffer_month, buffer);
    }
    

    
    memset(buffer, 0, sizeof(buffer));
    number = rtc.day();
    itoa(number, buffer, 10);
    if (strcmp(buffer_day, buffer))
    {
        P0_t8.setText(buffer);
        strcpy(buffer_day, buffer);
    }
    

    memset(buffer, 0, sizeof(buffer));
    memset(buffer_temp, 0, sizeof(buffer_temp));
    number = rtc.year();
    itoa(number, buffer, 10);
    if (strcmp(buffer_year, buffer))
    {
        P0_t12.setText(buffer);
        strcpy(buffer_year, buffer);
    }
    
}


