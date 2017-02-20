/////////////////////////////////////////////////////////////////////////////////
//                          Page étalonnage pH
/////////////////////////////////////////////////////////////////////////////////
void P6_b0PopCallback(void *ptr) // Bouton calibration acide
{
    val_acide = analogRead(pin_ph);
    P6_t4.setText("Calibration Acide Ok");
    dbSerialPrint("valeur acide:");
    dbSerialPrintln(val_acide);
}

void P6_b1PopCallback(void *ptr) // Bouton calibration acide base
{
    val_base = analogRead(pin_ph);
    P6_t4.setText("Calibration Base Ok ");
    dbSerialPrint("valeur base:");
    dbSerialPrintln(val_base);
}

void P6_b2PopCallback(void *ptr) // Bouton Fin etalonnage
{
    a_ph = (etalon_ph_base - etalon_ph_acide) / (val_base - val_acide);
    P6_t4.setText("Calibration terminee");
    dbSerialPrint("valeur a:");
    dbSerialPrintln(a_ph);
    b_ph = (etalon_ph_base - (a_ph * val_base));
    dbSerialPrint("valeur b:");
    dbSerialPrintln(b_ph);
    EEPROM.writeFloat(addr_a_ph, a_ph);
    EEPROM.writeFloat(addr_b_ph, b_ph);
}


void P6_b3PopCallback(void *ptr) // Bouton Home (appel page 0)
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

/////////////////////////////////////////////////////////////////////////////////
//                          Fonctions Diverses
/////////////////////////////////////////////////////////////////////////////////
void P6Display()
{
    P6_n0.setValue(analogRead(pin_ph));
}


