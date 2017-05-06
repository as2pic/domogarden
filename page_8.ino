/////////////////////////////////////////////////////////////////////////////////
//                          Page Réglage Arrosage
/////////////////////////////////////////////////////////////////////////////////
void P8_b0PopCallback(void *ptr) // Bouton retour
{
    page7.show();
    num_page = 7;
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

void P8_b1PopCallback(void *ptr) // Touche "+"
{
    SetArrosageUp = 1;
    SetArrosage();
}

void P8_b2PopCallback(void *ptr) // Touche "++"
{
    SetArrosageUp = 3;
    SetArrosage();
}


void P8_b3PopCallback(void *ptr) // Touche "-"
{
    SetArrosageUp = 0;
    SetArrosage();
}

void P8_b4PopCallback(void *ptr) // Touche "--"
{
    SetArrosageUp = 2;
    SetArrosage();
}

void P8_t7PopCallback(void *ptr) // 
{
    SetArrosageType = 1;
}

void P8_t8PopCallback(void *ptr) // 
{
    SetArrosageType = 2;
}

void P8_t9PopCallback(void *ptr) // 
{
    SetArrosageType = 3;
}

void P8_t10PopCallback(void *ptr) // 
{
    SetArrosageType = 4;
}

void P8_n4PopCallback(void *ptr) // Réglage Durée Zone 1
{
    SetArrosageType = 5;
}

void P8_n5PopCallback(void *ptr) // Réglage Durée Zone 2
{
    SetArrosageType = 6;
}

void P8_n6PopCallback(void *ptr) // Réglage Durée Zone 3
{
    SetArrosageType = 7;
}

void P8_n7PopCallback(void *ptr) // Réglage Durée Zone 4
{
    SetArrosageType = 8;
}


/////////////////////////////////////////////////////////////////////////////////
//                          Fonctions Diverses
/////////////////////////////////////////////////////////////////////////////////
// ------------------------------------------------------------------------------------------
// ------------------------ Set config Arrosage -------------------------------
// ------------------------------------------------------------------------------------------
void SetArrosage(void)
{

        switch (SetArrosageType)
    {
          case 1: // Départ 1
            if (SetArrosageUp == 0)
            {
              deb_1 -= 1;
            }
            if (SetArrosageUp == 1)
            {
              deb_1 += 1;
            }
            if (SetArrosageUp == 2)
            {
              deb_1 -= 10;
            }
            if (SetArrosageUp == 3)
            {
              deb_1 += 10;
            }
            if (deb_1>23){
              deb_1=23;
            }
            if (deb_1<-1){
              deb_1=-1;
            }
            EEPROM.writeDouble(addr_deb_1, deb_1);
            if (deb_1 >= 0){
              dtostrf(deb_1, 2, 0, buffer);
              P8_t7.setText(buffer);
            }
            else {
              strcpy(buffer, "OFF");
              P8_t7.setText(buffer);
            }
          break;
          
          case 2: // Départ 2
            if (SetArrosageUp == 0)
            {
              deb_2 -= 1;
            }
            if (SetArrosageUp == 1)
            {
              deb_2 += 1;
            }
            if (SetArrosageUp == 2)
            {
              deb_2 -= 10;
            }
            if (SetArrosageUp == 3)
            {
              deb_2 += 10;
            }
            if (deb_2>23){
              deb_2=23;
            }
            if (deb_2<-1){
              deb_2=-1;
            }
            EEPROM.writeDouble(addr_deb_2, deb_2);
            if (deb_2 >= 0){
              dtostrf(deb_2, 2, 0, buffer);
              P8_t8.setText(buffer);
            }
            else {
              strcpy(buffer, "OFF");
              P8_t8.setText(buffer);
            }
          
          break;
          
          case 3: // Départ 3
            if (SetArrosageUp == 0)
            {
              deb_3 -= 1;
            }
            if (SetArrosageUp == 1)
            {
              deb_3 += 1;
            }
            if (SetArrosageUp == 2)
            {
              deb_3 -= 10;
            }
            if (SetArrosageUp == 3)
            {
              deb_3 += 10;
            }
            if (deb_3>23){
              deb_3=23;
            }
            if (deb_3<-1){
              deb_3=-1;
            }
            EEPROM.writeDouble(addr_deb_3, deb_3);
            if (deb_3 >= 0){
              dtostrf(deb_3, 2, 0, buffer);
              P8_t9.setText(buffer);
            }
            else {
              strcpy(buffer, "OFF");
              P8_t9.setText(buffer);
            }
            
          break;
          
          case 4: // Départ 4
            if (SetArrosageUp == 0)
            {
              deb_4 -= 1;
            }
            if (SetArrosageUp == 1)
            {
              deb_4 += 1;
            }
            if (SetArrosageUp == 2)
            {
              deb_4 -= 10;
            }
            if (SetArrosageUp == 3)
            {
              deb_4 += 10;
            }
            if (deb_4>23){
              deb_4=23;
            }
            if (deb_4<-1){
              deb_4=-1;
            }
            EEPROM.writeDouble(addr_deb_4, deb_4);
            if (deb_4 >= 0){
              dtostrf(deb_4, 2, 0, buffer);
              P8_t10.setText(buffer);
            }
            else {
              strcpy(buffer, "OFF");
              P8_t10.setText(buffer);
            }
          break;
          
          case 5: // Réglage Durée Zone 1
            if (SetArrosageUp == 0)
            {
              t_z1 -= 1;
            }
            if (SetArrosageUp == 1)
            {
              t_z1 += 1;
            }
            if (SetArrosageUp == 2)
            {
              t_z1 -= 10;
            }
            if (SetArrosageUp == 3)
            {
              t_z1 += 10;
            }
            if (t_z1 > 254){
              t_z1 = 254;
            }
            if (t_z1 < 0){
              t_z1 = 0;
            }
            EEPROM.writeDouble(addr_t_z1, t_z1);
            P8_n4.setValue(t_z1);
          break;

          case 6: // Réglage Durée Zone 2
            if (SetArrosageUp == 0)
            {
              t_z2 -= 1;
            }
            if (SetArrosageUp == 1)
            {
              t_z2 += 1;
            }
            if (SetArrosageUp == 2)
            {
              t_z2 -= 10;
            }
            if (SetArrosageUp == 3)
            {
              t_z2 += 10;
            }
            if (t_z2 > 254){
              t_z2 = 254;
            }
            if (t_z2 < 0){
              t_z2 = 0;
            }
            EEPROM.writeDouble(addr_t_z2, t_z2);
            P8_n5.setValue(t_z2);
          break;

          case 7: // Réglage Durée Zone 3
            if (SetArrosageUp == 0)
            {
              t_z3 -= 1;
            }
            if (SetArrosageUp == 1)
            {
              t_z3 += 1;
            }
            if (SetArrosageUp == 2)
            {
              t_z3 -= 10;
            }
            if (SetArrosageUp == 3)
            {
              t_z3 += 10;
            }
            if (t_z3 > 254){
              t_z3 = 254;
            }
            if (t_z3 < 0){
              t_z3 = 0;
            }
            EEPROM.writeDouble(addr_t_z3, t_z3);
            P8_n6.setValue(t_z3);
          break;

          case 8: // Réglage Durée Zone 4
            if (SetArrosageUp == 0)
            {
              t_z4 -= 1;
            }
            if (SetArrosageUp == 1)
            {
              t_z4 += 1;
            }
            if (SetArrosageUp == 2)
            {
              t_z4 -= 10;
            }
            if (SetArrosageUp == 3)
            {
              t_z4 += 10;
            }
            if (t_z4 > 254){
              t_z4 = 254;
            }
            if (t_z4 < 0){
              t_z4 = 0;
            }
            EEPROM.writeDouble(addr_t_z4, t_z4);
            P8_n7.setValue(t_z4);
          break;

    }
  
}

