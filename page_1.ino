/////////////////////////////////////////////////////////////////////////////////
//                          Page principale réglages
/////////////////////////////////////////////////////////////////////////////////

void P1_b0PopCallback(void *ptr) // Touche "-"
{
    SetPhRedoxUp = 0;
    setPhRedox();
}

void P1_b1PopCallback(void *ptr) // Touche "+"
{
    SetPhRedoxUp = 1;
    setPhRedox();
}

void P1_b2PopCallback(void *ptr) // Touche "--"
{
    SetPhRedoxUp = 2;
    setPhRedox();
}

void P1_b3PopCallback(void *ptr) // Touche "++"
{
    SetPhRedoxUp = 3;
    setPhRedox();
}

void P1_b4PopCallback(void *ptr) // Bouton Home (appel page 0)
{
    page0.show();
    P0_t2.setText(buffer_hour);
    P0_t4.setText(buffer_minute);
    P0_t8.setText(buffer_day);
    P0_t9.setText(buffer_week);
    P0_t10.setText(buffer_month);
    P0_t12.setText(buffer_year);
    num_page = 0;
}

void P1_b5PopCallback(void *ptr) // réglage jour
{
    settime_type = 3;
}

void P1_b6PopCallback(void *ptr) // réglage mois
{
    settime_type = 2;
}

void P1_b8PopCallback(void *ptr) // réglage année
{
    settime_type = 1;   
}

void P1_b9PopCallback(void *ptr) // Bouton UP
{
    settime_up = 1;
    setTime();
}

void P1_b10PopCallback(void *ptr) // Bouton Down
{
    settime_up = 0;
    setTime();
}

void P1_b11PopCallback(void *ptr) // réglage heures
{
    settime_type = 4;
}

void P1_b12PopCallback(void *ptr) // réglage minutes
{
    settime_type = 5;
}

void P1_b13PopCallback(void *ptr) // réglage jour de la semaine
{
    settime_type = 6;

}

void P1_b14PopCallback(void *ptr) // Bouton validation
{
    rtc.set(0, number_settime_minute, number_settime_hour, 
            number_settime_week, number_settime_day, 
            number_settime_month, number_settime_year);
}

void P1_b15PopCallback(void *ptr) // Bouton appel page calibration pH
{
    page6.show();
    num_page = 6;
    P6_t4.setText("attente calibration Acide");
    dtostrf (etalon_ph_acide, 3, 1, buffer);
    P6_t6.setText(buffer);
    dtostrf (etalon_ph_base, 3, 1, buffer);
    P6_t7.setText(buffer);

}

void P1_n0PopCallback(void *ptr) // etalonage Ph
{
    SetPhRedoxType = 1;
}

void P1_n1PopCallback(void *ptr) // seuil redox
{
    SetPhRedoxType = 2;
}

void P1_n4PopCallback(void *ptr) // etalonage Redox
{
    SetPhRedoxType = 3;
}

void P1_n5PopCallback(void *ptr) // delta seuil redox
{
    SetPhRedoxType = 4;
}

void P1_t8PopCallback(void *ptr) // solution etalon acide
{
    SetPhRedoxType = 5;
}

void P1_t11PopCallback(void *ptr) // solution etalon base
{
    SetPhRedoxType = 6;
}

void P1_t13PopCallback(void *ptr) // Seuil Ph
{
    SetPhRedoxType = 7;
}


/////////////////////////////////////////////////////////////////////////////////
//                          Fonctions Diverses
/////////////////////////////////////////////////////////////////////////////////
// ------------------------------------------------------------------------------------------
// ------------------------ Set config et etalonnage PH/Redox -------------------------------
// ------------------------------------------------------------------------------------------
void setPhRedox(void)
{

    switch (SetPhRedoxType)
    {
/*        case 1: // Réglage etalonnage PH
            if (SetPhRedoxUp == 0)
            {
              etalon_ph -= 1;
            }
            if (SetPhRedoxUp == 1)
            {
              etalon_ph += 1;
            }
            if (SetPhRedoxUp == 2)
            {
              etalon_ph -= 10;
            }
            if (SetPhRedoxUp == 3)
            {
              etalon_ph += 10;
            }
            if (etalon_ph < 0){
              etalon_ph = 0;
            }
            if (etalon_ph > 1024){
              etalon_ph = 1024;
            }
            dtostrf(ph_value_float, 5, 2, buffer);
            P1_t1.setText(buffer);
            P1_n0.setValue(etalon_ph);
            EEPROM.writeDouble(addr_eeprom_ph, etalon_ph);
        break; */
        case 2: // Réglage seuil redox
            if (SetPhRedoxUp == 0)
            {
              seuil_redox -= 1;
            }
            if (SetPhRedoxUp == 1)
            {
              seuil_redox += 1;
            }
            if (SetPhRedoxUp == 2)
            {
              seuil_redox -= 10;
            }
            if (SetPhRedoxUp == 3)
            {
              seuil_redox += 10;
            }
            if (seuil_redox > 1000){
              seuil_redox = 1000;
            }
            if (seuil_redox<0){
              seuil_redox = 0;
            }
            P1_n1.setValue(seuil_redox);
            EEPROM.writeDouble(addr_seuil_redox, seuil_redox);
        
        break;
        case 3: // Réglage etalonnage redox
            if (SetPhRedoxUp == 0)
            {
              etalon_redox -= 1;
            }
            if (SetPhRedoxUp == 1)
            {
              etalon_redox += 1;
            }
            if (SetPhRedoxUp == 2)
            {
              etalon_redox -= 10;
            }
            if (SetPhRedoxUp == 3)
            {
              etalon_redox += 10;
            }
            if (etalon_redox > 1000){
              etalon_redox = 1000;
            }
            if (etalon_redox < 0){
              etalon_redox=0;
            }
            P1_n3.setValue(redox_value_float);
            P1_n4.setValue(etalon_redox);
            EEPROM.writeDouble(addr_eeprom_redox, etalon_redox);
        
        break;
        case 4: // Réglage delta redox
            if (SetPhRedoxUp == 0)
            {
              delta_redox -= 1;
            }
            if (SetPhRedoxUp == 1)
            {
              delta_redox += 1;
            }
            if (SetPhRedoxUp == 2)
            {
              delta_redox -= 10;
            }
            if (SetPhRedoxUp == 3)
            {
              delta_redox += 10;
            }
            if (delta_redox > 1000){
              delta_redox = 1000;
            }
            if (delta_redox < 0){
              delta_redox=0;
            }
            P1_n5.setValue(delta_redox);
            EEPROM.writeDouble(addr_delta_redox, delta_redox);
        
        break;
        case 5: // Réglage solution etalon acide
            if (SetPhRedoxUp == 0)
            {
              etalon_ph_acide -= 0.1;
            }
            if (SetPhRedoxUp == 1)
            {
              etalon_ph_acide += 0.1;
            }
            if (SetPhRedoxUp == 2)
            {
              etalon_ph_acide -= 1;
            }
            if (SetPhRedoxUp == 3)
            {
              etalon_ph_acide += 1;
            }
            if (etalon_ph_acide > 12){
              etalon_ph_acide = 12;
            }
            if (etalon_ph_acide < 0){
              etalon_ph_acide = 0;
            }
            dtostrf (etalon_ph_acide, 3, 1, buffer);
            P1_t8.setText(buffer);
            EEPROM.writeFloat(addr_etalon_ph_acide, etalon_ph_acide);
        
        break;
        case 6: // Réglage solution etalon base
            if (SetPhRedoxUp == 0)
            {
              etalon_ph_base -= 0.1;
            }
            if (SetPhRedoxUp == 1)
            {
              etalon_ph_base += 0.1;
            }
            if (SetPhRedoxUp == 2)
            {
              etalon_ph_base -= 1;
            }
            if (SetPhRedoxUp == 3)
            {
              etalon_ph_base += 1;
            }
            if (etalon_ph_base > 12){
              etalon_ph_base = 12;
            }
            if (etalon_ph_base < 0){
              etalon_ph_base = 0;
            }
            dtostrf (etalon_ph_base, 3, 1, buffer);
            P1_t11.setText(buffer);
            EEPROM.writeFloat(addr_etalon_ph_base, etalon_ph_base);
        
        break;
        case 7: // Réglage Seuil Ph
            if (SetPhRedoxUp == 0)
            {
              seuil_ph -= 0.1;
            }
            if (SetPhRedoxUp == 1)
            {
              seuil_ph += 0.1;
            }
            if (SetPhRedoxUp == 2)
            {
              seuil_ph -= 1;
            }
            if (SetPhRedoxUp == 3)
            {
              seuil_ph += 1;
            }
            if (etalon_ph_base > 9){
              seuil_ph = 9;
            }
            if (seuil_ph < 0){
              seuil_ph = 0;
            }
            dtostrf (seuil_ph, 3, 1, buffer);
            P1_t13.setText(buffer);
            EEPROM.writeFloat(addr_seuil_ph, seuil_ph);
        
        break;
    }


}


// ------------------------------------------------------------------------------------------
// ------------------------------------------------- Set time -------------------------------
// ------------------------------------------------------------------------------------------
void setTime(void)
{
    switch (settime_type)
    {
        case 1: 
            if (settime_up == 1)
            {
               number_settime_year++;
               if (number_settime_year > 99)
               {
                    number_settime_year = 10;
               }
               memset(buffer, 0, sizeof(buffer));  
               itoa(number_settime_year, buffer, 10);
               P1_b8.setText(buffer);
            }   
            else if (settime_up == 0)
            {
                number_settime_year--;
                if (number_settime_year < 10)
                {
                    number_settime_year = 99;
                }
                memset(buffer, 0, sizeof(buffer));  
                itoa(number_settime_year, buffer, 10);
                P1_b8.setText(buffer);
            }
            break;
        case 2:
            if (settime_up == 1)
            {
                number_settime_month++;
                if (number_settime_month > 12)
                {
                    number_settime_month = 1;
                }
                memset(buffer, 0, sizeof(buffer));  
                itoa(number_settime_month, buffer, 10);
                P1_b6.setText(buffer);
            }
            else if (settime_up == 0)
            {
                number_settime_month--;
                if (number_settime_month < 1)
                {
                    number_settime_month= 12;
                }
                memset(buffer, 0, sizeof(buffer));  
                itoa(number_settime_month, buffer, 10);
                P1_b6.setText(buffer);
            }
            break;
        case 3:
        {
            memset(buffer, 0, sizeof(buffer)); 
            P1_b6.getText(buffer,sizeof(buffer));
            uint8_t dayofmonth = atoi(buffer);
            if (settime_up == 1)
            {
                number_settime_day++;
                if (dayofmonth == 1 || dayofmonth == 3 || dayofmonth == 5 
                    || dayofmonth == 7 || dayofmonth == 8 || dayofmonth == 10
                    || dayofmonth == 12 )
                {
                    if (number_settime_day > 31)
                    {
                        number_settime_day = 1;
                    }
                }
                if (dayofmonth == 4 || dayofmonth == 6 || dayofmonth == 9 
                    || dayofmonth == 11)
                {
                    if (number_settime_day > 30)
                    {
                        number_settime_day = 1;
                    }
                }
                if (dayofmonth == 2)
                {
                    if(number_settime_day > 28)
                    {
                        number_settime_day = 1;
                    }
                }
                memset(buffer, 0, sizeof(buffer));  
                itoa(number_settime_day, buffer, 10);
                P1_b5.setText(buffer);
            }
            else if (settime_up == 0)
            {
                number_settime_day--;
                if (dayofmonth == 1 || dayofmonth == 3 || dayofmonth == 5 
                    || dayofmonth == 7 || dayofmonth == 8 || dayofmonth == 10
                    || dayofmonth == 12 )
                {
                    if (number_settime_day < 1)
                    {
                        number_settime_day = 31;
                    }
                }
                if (dayofmonth == 4 || dayofmonth == 6 || dayofmonth == 9 
                    || dayofmonth == 11)
                {
                    if (number_settime_day < 1)
                    {
                        number_settime_day = 30;
                    }
                }
                if (dayofmonth == 2)
                {
                    if(number_settime_day < 1)
                    {
                        number_settime_day = 28;
                    }
                }
                memset(buffer, 0, sizeof(buffer));  
                itoa(number_settime_day, buffer, 10);
                P1_b5.setText(buffer);
            }
            break;
        }
        case 4:
            if (settime_up == 1)
            {
                number_settime_hour++;
                if (number_settime_hour > 23)
                {
                    number_settime_hour = 0;
                }
                memset(buffer, 0, sizeof(buffer));  
                itoa(number_settime_hour, buffer, 10);
                P1_b11.setText(buffer);
            }
            else if (settime_up == 0)
            {
                number_settime_hour--;
                if (number_settime_hour < 0)
                {
                    number_settime_hour = 23;
                }
                memset(buffer, 0, sizeof(buffer));  
                itoa(number_settime_hour, buffer, 10);
                P1_b11.setText(buffer);
            }
            break;
        case 5:
            if (settime_up == 1)
            {
                number_settime_minute++;
                if (number_settime_minute > 59)
                {
                    number_settime_minute = 0;
                }
                memset(buffer, 0, sizeof(buffer));  
                itoa(number_settime_minute, buffer, 10);
                P1_b12.setText(buffer);
            }
            else if (settime_up == 0)
            {
                number_settime_minute--;
                if (number_settime_minute < 0)
                {
                    number_settime_minute = 59;
                }
                memset(buffer, 0, sizeof(buffer));  
                itoa(number_settime_minute, buffer, 10);
                P1_b12.setText(buffer);
            }
            break;                
        case 6:
            if (settime_up == 1)
            {
                number_settime_week++;
                if (number_settime_week > 7)
                {
                    number_settime_week = 1;
                }  
            }
            else if (settime_up == 0)
            {
                number_settime_week--;
                if (number_settime_week < 1)
                {
                    number_settime_week = 7;
                }
            }
            switch (number_settime_week)
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
            P1_b13.setText(buffer);
            break;
    }
}
