/////////////////////////////////////////////////////////////////////////////////
//                          Page réglage Hors gel
/////////////////////////////////////////////////////////////////////////////////
void P5_b2PopCallback(void *ptr) // Bouton retour
{
    page3.show();
    num_page = 3;
    dtostrf(conshorsgel, 5, 1, buffer);
    P3_t2.setText(buffer);
}

void P5_b0PopCallback(void *ptr) // Bouton "-"
{
    conshorsgel -= 0.1;
    dtostrf(conshorsgel, 5, 1, buffer);
    P5_t1.setText(buffer);
    EEPROM.writeDouble(addr_conshorsgel, conshorsgel);
}

void P5_b1PopCallback(void *ptr) // Bouton "+"
{
    conshorsgel += 0.1;
    dtostrf(conshorsgel, 5, 1, buffer);
    P5_t1.setText(buffer);
    EEPROM.writeDouble(addr_conshorsgel, conshorsgel);
}



