/////////////////////////////////////////////////////////////////////////////////
//                          Page Réglage Doseur Redox
/////////////////////////////////////////////////////////////////////////////////
void P10_b0PopCallback(void *ptr) // Bouton retour page pompe doseuse Redox
{

  page9.show();
  num_page = 9;
  switch (val_bouton_chlore)
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
  P9_b3.setText(buffer);
  P9_t4.setText(buffer_hour);
  P9_t6.setText(buffer_minute);
}

void P10_b1PopCallback(void *ptr) // RAZ Compteur
{

  qte_hbdo = 0;

}

void P10_b2PopCallback(void *ptr) // Init OFA
{

  SecuOfaChlore =0;
  TpsSecuOfaChlore = ConsTpsSecuOfaChlore;

}

void P10_b3PopCallback(void *ptr) // Réglage débit pompe +
{
  debit_pompe_chlore += 0.1;
  dtostrf(debit_pompe_chlore, 5, 1, buffer);
  P10_t2.setText(buffer);
  EEPROM.writeDouble(addr_debit_pompe_chlore, debit_pompe_chlore);
}

void P10_b4PopCallback(void *ptr) // Réglage débit pompe -
{
  debit_pompe_chlore -= 0.1;
  dtostrf(debit_pompe_chlore, 5, 1, buffer);
  P10_t2.setText(buffer);
  EEPROM.writeDouble(addr_debit_pompe_chlore, debit_pompe_chlore);
}

