/////////////////////////////////////////////////////////////////////////////////
//                          Page Réglage Doseur Ph
/////////////////////////////////////////////////////////////////////////////////
void P12_b0PopCallback(void *ptr) // Bouton retour page pompe doseuse Ph
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

void P12_b1PopCallback(void *ptr) // RAZ Compteur
{

  qte_hbdo_ph = 0;

}

void P12_b2PopCallback(void *ptr) // Init OFA
{

  SecuOfaPh =0;
  TpsSecuOfaPh = ConsTpsSecuOfaPh;

}

void P12_b3PopCallback(void *ptr) // Réglage débit pompe +
{
  debit_pompe_ph += 0.1;
  dtostrf(debit_pompe_ph, 5, 1, buffer);
  P12_t2.setText(buffer);
  EEPROM.writeDouble(addr_debit_pompe_ph, debit_pompe_ph);
}

void P12_b4PopCallback(void *ptr) // Réglage débit pompe -
{
  debit_pompe_ph -= 0.1;
  dtostrf(debit_pompe_ph, 5, 1, buffer);
  P12_t2.setText(buffer);
  EEPROM.writeDouble(addr_debit_pompe_ph, debit_pompe_ph);
}

