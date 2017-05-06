/////////////////////////////////////////////////////////////////////////////////
//                          Page réglage pompes
/////////////////////////////////////////////////////////////////////////////////

void P4_b8PopCallback(void *ptr)
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

void P4_b0PopCallback(void *ptr)
{
    depart_filtration -= 1;
    if (depart_filtration > 24){
      depart_filtration = 0;
    }
    P4_n0.setValue(depart_filtration);
    EEPROM.writeDouble(addr_depart_filtration, depart_filtration);
}

void P4_b1PopCallback(void *ptr)
{
    depart_filtration += 1;
    if (depart_filtration > 24){
      depart_filtration = 24;
    }
    P4_n0.setValue(depart_filtration);
    EEPROM.writeDouble(addr_depart_filtration, depart_filtration);
}

void P4_b2PopCallback(void *ptr)
{
    if (ModeFiltration == 0){
      duree_filtration -= 1;
      if (duree_filtration > 24){
        duree_filtration = 0;
      }
      P4_n1.setValue(duree_filtration); 
      EEPROM.writeDouble(addr_duree_filtration, duree_filtration); 
    }
}

void P4_b3PopCallback(void *ptr)
{
    if (ModeFiltration == 0){
      duree_filtration += 1;
      if (duree_filtration > 24){
        duree_filtration = 24;
      }
      P4_n1.setValue(duree_filtration);
      EEPROM.writeDouble(addr_duree_filtration, duree_filtration);   
    }  
}

void P4_b4PopCallback(void *ptr)
{
    depart_robot -= 1;
    if (depart_robot > 24){
      depart_robot = 0;
    }
    P4_n2.setValue(depart_robot);
    EEPROM.writeDouble(addr_depart_robot, depart_robot); 
}

void P4_b5PopCallback(void *ptr)
{
    depart_robot += 1;
    if (depart_robot > 24){
      depart_robot = 24;
    }
    P4_n2.setValue(depart_robot);
    EEPROM.writeDouble(addr_depart_robot, depart_robot);
}

void P4_b6PopCallback(void *ptr)
{
    duree_robot -= 1;
    if (duree_robot > 24){
      duree_robot = 0;
    }
    P4_n3.setValue(duree_robot);
    EEPROM.writeDouble(addr_duree_robot, duree_robot);  
}

void P4_b7PopCallback(void *ptr)
{
    duree_robot += 1;
    if (duree_robot > 24){
      duree_robot = 24;
    }
    P4_n3.setValue(duree_robot); 
    EEPROM.writeDouble(addr_duree_robot, duree_robot); 
}

void P4_b9PopCallback(void *ptr)
{
  ModeFiltration = !ModeFiltration;
  if (ModeFiltration == 0){
    strcpy(buffer, "MANU");
    duree_filtration = EEPROM.readDouble(addr_duree_filtration);
  }
  else {
    strcpy(buffer, "AUTO");
    duree_filtration = TEau / 2;
  }
  P4_b9.setText(buffer);
  P4_n1.setValue(duree_filtration);
  EEPROM.write(addr_ModeFiltration, ModeFiltration);
}

