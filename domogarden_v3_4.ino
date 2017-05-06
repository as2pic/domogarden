 ///////////////////////////////////////////////////////////////////////////////
//                            INCLUDE                                    
///////////////////////////////////////////////////////////////////////////////
#include <SPI.h>
#include <SD.h>
#include "Nextion.h"
#include "RTCLib.h"
#include <Ethernet.h>
#include <EEPROMex.h>
#include <dht.h>
#include <OneWire.h> 
#include <DallasTemperature.h>

///////////////////////////////////////////////////////////////////////////////
//                            NEXTION Component                                   
///////////////////////////////////////////////////////////////////////////////

// Déclaration des objets Nextion: [page id:x,component id:x, component name: "x0"]

// page 0
NexPage page0 = NexPage(0, 0, "page0");
NexButton P0_b0 = NexButton(0, 21, "b0");
NexButton P0_b1 = NexButton(0, 22, "b1");
NexButton P0_b2 = NexButton(0, 2, "b2");
NexText P0_t0 = NexText(0, 1, "t0");
NexText P0_t1 = NexText(0, 5, "t1");
NexText P0_t2 = NexText(0, 4, "t2");
NexText P0_t4 = NexText(0, 6, "t4");
NexText P0_t7 = NexText(0, 9, "t7");
NexText P0_t8 = NexText(0, 10, "t8");
NexText P0_t9 = NexText(0, 11, "t9");
NexText P0_t10 = NexText(0, 12, "t10");
NexText P0_t12 = NexText(0, 14, "t12");
NexText P0_t14 = NexText(0, 23, "t14");
NexText P0_t17 = NexText(0, 18, "t17");
NexText P0_t22 = NexText(0, 30, "t22");
NexNumber P0_n0 = NexNumber(0, 15, "n0");
NexNumber P0_n1 = NexNumber(0, 19, "n1");
NexNumber P0_n2 = NexNumber(0, 20, "n2");
NexNumber P0_n3 = NexNumber(0, 26, "n3");
NexNumber P0_n4 = NexNumber(0, 32, "n4");

// page 1
NexPage page1 = NexPage(1, 0, "page1");
NexButton P1_b0 = NexButton(1, 1, "b0_p1");
NexButton P1_b1 = NexButton(1, 2, "b1_p1");
NexButton P1_b2 = NexButton(1, 3, "b2_p1");
NexButton P1_b3 = NexButton(1, 4, "b3_p1");
NexButton P1_b4 = NexButton(1, 5, "b4_p1");
NexButton P1_b5 = NexButton(1, 6, "b5_p1");
NexButton P1_b6 = NexButton(1, 8, "b6_p1");
NexButton P1_b7 = NexButton(1, 10, "b7_p1");
NexButton P1_b8 = NexButton(1, 11, "b8_p1");
NexButton P1_b9 = NexButton(1, 12, "b9_p1");
NexButton P1_b10 = NexButton(1, 13, "b10_p1");
NexButton P1_b11 = NexButton(1, 14, "b11_p1");
NexButton P1_b12 = NexButton(1, 16, "b12_p1");
NexButton P1_b13 = NexButton(1, 17, "b13_p1");
NexButton P1_b14 = NexButton(1, 18, "b14_p1");
NexButton P1_b15 = NexButton(1, 26, "b15_p1");
NexNumber P1_n1 = NexNumber(1, 20, "n1_p1");
NexNumber P1_n3 = NexNumber(1, 22, "n3_p1");
NexNumber P1_n4 = NexNumber(1, 23, "n4_p1");
NexNumber P1_n5 = NexNumber(1, 25, "n5_p1");
NexText P1_t8 = NexText(1, 29, "t8_p1");
NexText P1_t11 = NexText(1, 30, "t11_p1");
NexText P1_t13 = NexText(1, 34, "t13_p1");

// page 2
NexPage page2 = NexPage(2, 0, "page2");
NexButton P2_b0 = NexButton(2, 6, "b0_p2");
NexButton P2_b1 = NexButton(2, 7, "b1_p2");
NexButton P2_b2 = NexButton(2, 8, "b2_p2");
NexNumber P2_n0 = NexNumber(2, 14, "n0_p2");
NexNumber P2_n1 = NexNumber(2, 15, "n1_p2");
NexNumber P2_n2 = NexNumber(2, 18, "n2_p2");
NexNumber P2_n3 = NexNumber(2, 19, "n3_p2");
NexText P2_t4 = NexText(2, 9, "t4_p2");
NexText P2_t6 = NexText(2, 11, "t6_p2");
NexText P2_t8 = NexText(2, 13, "t8_p2");

// page 3
NexPage page3 = NexPage(3, 0, "page3");
NexButton P3_b0 = NexButton(3, 1, "b0_p3");
NexButton P3_b1 = NexButton(3, 2, "b1_p3");
NexButton P3_b2 = NexButton(3, 3, "b2_p3");
NexText P3_t2 = NexText(3, 12, "t2_p3");
NexText P3_t4 = NexText(3, 4, "t4_p3");
NexText P3_t6 = NexText(3, 6, "t6_p3");
NexText P3_t8 = NexText(3, 8, "t8_p3");
NexText P3_t9 = NexText(3, 14, "t9_p3");

// page 4
NexPage page4 = NexPage(4, 0, "page4");
NexButton P4_b0 = NexButton(4, 11, "b0_p4");
NexButton P4_b1 = NexButton(4, 12, "b1_p4");
NexButton P4_b2 = NexButton(4, 13, "b2_p4");
NexButton P4_b3 = NexButton(4, 14, "b3_p4");
NexButton P4_b4 = NexButton(4, 15, "b4_p4");
NexButton P4_b5 = NexButton(4, 16, "b5_p4");
NexButton P4_b6 = NexButton(4, 17, "b6_p4");
NexButton P4_b7 = NexButton(4, 18, "b7_p4");
NexButton P4_b8 = NexButton(4, 19, "b8_p4");
NexButton P4_b9 = NexButton(4, 20, "b9_p4");
NexNumber P4_n0 = NexNumber(4, 7, "n0_p4");
NexNumber P4_n1 = NexNumber(4, 8, "n1_p4");
NexNumber P4_n2 = NexNumber(4, 9, "n2_p4");
NexNumber P4_n3 = NexNumber(4, 10, "n3_p4");

// page 5
NexPage page5 = NexPage(5, 0, "page5");
NexButton P5_b0 = NexButton(5, 3, "b0_p5");
NexButton P5_b1 = NexButton(5, 4, "b1_p5");
NexButton P5_b2 = NexButton(5, 5, "b2_p5");
NexText P5_t1 = NexText(5, 2, "t1_p5");

// page 6
NexPage page6 = NexPage(6, 0, "page6");
NexButton P6_b0 = NexButton(6, 1, "b0_p6");
NexButton P6_b1 = NexButton(6, 4, "b1_p6");
NexButton P6_b2 = NexButton(6, 6, "b2_p6");
NexButton P6_b3 = NexButton(6, 10, "b3_p6");
NexText P6_t4 = NexText(6, 9, "t4_p6");
NexText P6_t6 = NexText(6, 11, "t6_p6");
NexText P6_t7 = NexText(6, 13, "t7_p6");
NexNumber P6_n0 = NexNumber(6, 7, "n0_p6");

// page 7
NexPage page7 = NexPage(7, 0, "page7");
NexButton P7_b0 = NexButton(7, 1, "b0_p7");
NexButton P7_b1 = NexButton(7, 2, "b1_p7");
NexButton P7_b2 = NexButton(7, 3, "b2_p7");
NexButton P7_b3 = NexButton(7, 21, "b3_p7");
NexButton P7_b4 = NexButton(7, 22, "b4_p7");
NexButton P7_b5 = NexButton(7, 23, "b5_p7");
NexButton P7_b6 = NexButton(7, 24, "b6_p7");
NexButton P7_b7 = NexButton(7, 25, "b7_p7");
NexButton P7_b8 = NexButton(7, 26, "b8_p7");
NexButton P7_b9 = NexButton(7, 27, "b9_p7");
NexButton P7_b10 = NexButton(7, 12, "b10_p7");
NexButton P7_b11 = NexButton(7, 32, "b11_p7");
NexButton P7_b12 = NexButton(7, 33, "b12_p7");
NexButton P7_b13 = NexButton(7, 34, "b13_p7");
NexButton P7_b16 = NexButton(7, 38, "b16_p7");
NexText P7_t0 = NexText(7, 4, "t0_p7");
NexText P7_t2 = NexText(7, 6, "t2_p7");
NexText P7_t10 = NexText(7, 28, "t10_p7");
NexText P7_t11 = NexText(7, 29, "t11_p7");
NexText P7_t12 = NexText(7, 30, "t12_p7");
NexText P7_t13 = NexText(7, 31, "t13_p7");
NexText P7_t14 = NexText(7, 13, "t14_p7");
NexText P7_t15 = NexText(7, 35, "t15_p7");
NexText P7_t16 = NexText(7, 36, "t16_p7");
NexText P7_t17 = NexText(7, 37, "t17_p7");

// page 8
NexPage page8 = NexPage(8, 0, "page8");
NexButton P8_b0 = NexButton(8, 1, "b0_p8");
NexButton P8_b1 = NexButton(8, 2, "b1_p8");
NexButton P8_b2 = NexButton(8, 3, "b2_p8");
NexButton P8_b3 = NexButton(8, 4, "b3_p8");
NexButton P8_b4 = NexButton(8, 5, "b4_p8");
NexNumber P8_n4 = NexNumber(8, 11, "n4_p8");
NexNumber P8_n5 = NexNumber(8, 12, "n5_p8");
NexNumber P8_n6 = NexNumber(8, 13, "n6_p8");
NexNumber P8_n7 = NexNumber(8, 14, "n7_p8");
NexText P8_t7 = NexText(8, 15, "t7_p8");
NexText P8_t8 = NexText(8, 16, "t8_p8");
NexText P8_t9 = NexText(8, 17, "t9_p8");
NexText P8_t10 = NexText(8, 18, "t10_p8");

// page 9
NexPage page9 = NexPage(9, 0, "page9");
NexButton P9_b0 = NexButton(9, 1, "b0_p9");
NexButton P9_b1 = NexButton(9, 2, "b1_p9");
NexButton P9_b2 = NexButton(9, 3, "b2_p9");
NexButton P9_b3 = NexButton(9, 20, "b3_p9");
NexNumber P9_n0 = NexNumber(9, 15, "n0_p9");
NexNumber P9_n1 = NexNumber(9, 16, "n1_p9");
NexNumber P9_n2 = NexNumber(9, 22, "n2_p9");
NexNumber P9_n3 = NexNumber(9, 23, "n3_p9");
NexText P9_t4 = NexText(9, 4, "t4_p9");
NexText P9_t6 = NexText(9, 6, "t6_p9");
NexText P9_t8 = NexText(9, 8, "t8_p9");
NexText P9_t9 = NexText(9, 14, "t9_p9");
NexText P9_t14 = NexText(9, 17, "t14_p9");
NexText P9_t18 = NexText(9, 25, "t18_p9");

// page 10
NexPage page10 = NexPage(10, 0, "page10");
NexButton P10_b0 = NexButton(10, 1, "b0_p10");
NexButton P10_b1 = NexButton(10, 2, "b1_p10");
NexButton P10_b2 = NexButton(10, 4, "b2_p10");
NexButton P10_b3 = NexButton(10, 6, "b3_p10");
NexButton P10_b4 = NexButton(10, 7, "b4_p10");
NexText P10_t2 = NexText(10, 8, "t2_p10");

// page 11
NexPage page11 = NexPage(11, 0, "page11");
NexButton P11_b0 = NexButton(11, 1, "b0_p11");
NexButton P11_b1 = NexButton(11, 2, "b1_p11");
NexButton P11_b2 = NexButton(11, 3, "b2_p11");
NexButton P11_b3 = NexButton(11, 20, "b3_p11");
NexNumber P11_n0 = NexNumber(11, 15, "n0_p11");
NexNumber P11_n1 = NexNumber(11, 16, "n1_p11");
NexNumber P11_n2 = NexNumber(11, 22, "n2_p11");
NexNumber P11_n3 = NexNumber(11, 23, "n3_p11");
NexText P11_t4 = NexText(11, 4, "t4_p11");
NexText P11_t6 = NexText(11, 6, "t6_p11");
NexText P11_t8 = NexText(11, 8, "t8_p11");
NexText P11_t9 = NexText(11, 14, "t9_p11");
NexText P11_t14 = NexText(11, 17, "t14_p11");
NexText P11_t18 = NexText(11, 25, "t18_p11");

// page 12
NexPage page12 = NexPage(12, 0, "page12");
NexButton P12_b0 = NexButton(12, 1, "b0_p12");
NexButton P12_b1 = NexButton(12, 2, "b1_p12");
NexButton P12_b2 = NexButton(12, 4, "b2_p12");
NexButton P12_b3 = NexButton(12, 6, "b3_p12");
NexButton P12_b4 = NexButton(12, 7, "b4_p12");
NexText P12_t2 = NexText(12, 8, "t2_p12");


///////////////////////////////////////////////////////////////////////////////
//                            Définition des variables                                    
///////////////////////////////////////////////////////////////////////////////
const int DS3231_RTC_ADDR = 0x68;
const int DS3231_TEMP_MSB = 0x11;
   

#define DHT22_PIN A10


// Attribution des sorties

#define DS18B20 24
#define Buzzer 26

// Bornier superieur
#define relais_z4 28
#define relais_z3 30
#define relais_z2 32
#define relais_z1 34

// Bornier inferieur
#define relais_ph 36
#define relais_filtration 38
#define relais_robot 40
#define relais_chlore 42

// *******************
//      Mesure PH
// *******************
uint8_t pin_ph = A8;                    // Pin Sonde pH 
float ph_sensor_value = 0.0;            // Valeur Ph lue en Volt (0 to 5)
float ph_value_float = 0.0;             // valeur pH entre 0.0 to 14.0 en float
char ph_value_char[5];                  // valeur pH entre from 0 to 14 en char
int val_acide;
int val_base;
float etalon_ph_acide = 4.0;
float etalon_ph_base = 6.9;
float a_ph;
float b_ph;
float seuil_ph = 7.4;

// *******************
//      Mesure redox
// *******************
uint8_t pin_redox = A9;                 // Pin Sonde Redox
float redox_sensor_value = 0.0;         // Valeur Redox lue en Volt (0 to 5)
float redox_value_float = 0.0;          // valeur redox entre -2000 to 2000 mV en float
char redox_value_char[5];               // Valeur redox entre -2000 to 2000 en char
int redox_max = 550;                    // Definition de la valeur maxi redox
int redox_min = 500;                    // Definition de la valeur mini redox
int delta_redox = 50;
int seuil_redox = 500;
uint16_t etalon_redox = 0;

// *******************
// Pompes
// *******************
uint8_t depart_filtration;
uint8_t duree_filtration; 
uint8_t depart_robot;
uint8_t duree_robot;
bool filtrationON = 0;
bool robotON = 0;
int ModeFiltration = 1;

// *******************
// Hors gel
// *******************
float conshorsgel = -2.5;
bool horsgelON = 0;

// *******************
//      Arrosage
// *******************
int val_z1 = 1; 			// 0->OFF 1->ON 2->FOR
int val_z2 = 1; 			// 0->OFF 1->ON 2->FOR
int val_z3 = 1; 			// 0->OFF 1->ON 2->FOR
int val_z4 = 1; 			// 0->OFF 1->ON 2->FOR

int t_z1 = 3; 				// durée z1
int t_z2 = 3; 				// durée z2
int t_z3 = 3; 				// durée z3
int t_z4 = 3; 				// durée z4

int8_t deb_1 = 8; 			// heure début horaire 1
int8_t deb_2 = 12; 			// heure début horaire 2
int8_t deb_3 = 16; 			// heure début horaire 2
int8_t deb_4 = 20; 			// heure début horaire 2


bool start_z1 = 0; 			// bit démarrage zone 1
bool start_z2 = 0; 			// bit démarrage zone 2
bool start_z3 = 0; 			// bit démarrage zone 3
bool start_z4 = 0; 			// bit démarrage zone 4

uint8_t point_on_lu = 0; 	// Numéro du bit dans le mot stocké à l'adresse addr_on_day en EEPROM
uint8_t point_on_ma = 1;
uint8_t point_on_me = 2;
uint8_t point_on_je = 3;
uint8_t point_on_ve = 4;
uint8_t point_on_sa = 5;
uint8_t point_on_di = 6;

bool on_lu = 1; 			// bit arrosage lundi ON/OFF
bool on_ma = 1; 			// bit arrosage mardi ON/OFF
bool on_me = 1; 			// bit arrosage mercredi ON/OFF
bool on_je = 1; 			// bit arrosage jeudi ON/OFF
bool on_ve = 1; 			// bit arrosage vendredi ON/OFF
bool on_sa = 1; 			// bit arrosage samedi ON/OFF
bool on_di = 1; 			// bit arrosage dimanche ON/OFF

bool mem_etat_R1; 			// bit mémorisation état relais zone 1
bool mem_etat_R2; 			// bit mémorisation état relais zone 2
bool mem_etat_R3; 			// bit mémorisation état relais zone 3
bool mem_etat_R4; 			// bit mémorisation état relais zone 4

// *******************
// injection chlore 
// *******************
bool injection_chloreON = 0;
bool StartInjection = 0;
bool SecuOfaChlore = 0;
int Ton = 0;
int Toff = 0;
int val_bouton_chlore = 0;
int ConsTpsSecuOfaChlore = 240;                     // durée avant déclenchement sécurité OFA 240 minutes = 4 heures
int TpsSecuOfaChlore;
int CycleChlore;
float debit_pompe_chlore = 2.1;          // débit en l/h
float qte_hbdo = 0;

// *******************
// injection Ph
// *******************
bool injection_phON = 0;
bool StartInjectionPh = 0;
bool SecuOfaPh = 0;
int TonPh = 0;
int ToffPh = 0;
int val_bouton_ph = 0;
int ConsTpsSecuOfaPh = 240;                     // durée avant déclenchement sécurité OFA 240 minutes = 4 heures
int TpsSecuOfaPh;
int CyclePh;
float debit_pompe_ph = 2.1;          // débit en l/h
float qte_hbdo_ph = 0;

// *******************
// Mesure de temps
// *******************
char buffer_temp[10] = {0};
char buffer_year[10] = {0};
char buffer_month[10] = {0};
char buffer_day[10] = {0};
char buffer_hour[10] = {0};
char buffer_minute[10] = {0};
char buffer_second[10] = {0};
char buffer_week[10] = {0};

int8_t settime_type = -1;
int8_t settime_up = -1;
int8_t number_settime_year = 0;
int8_t number_settime_month = 0;
int8_t number_settime_day = 0;
int8_t number_settime_hour = 0;
int8_t number_settime_minute = 0;
int8_t number_settime_week = 0;

// *******************
// adresse de stockage données en eeprom 
// *******************
int addr_eeprom_redox = 10;
int addr_seuil_redox = 20;
int addr_delta_redox = 30;
int addr_depart_filtration = 40;
int addr_duree_filtration = 50;
int addr_depart_robot = 60;
int addr_duree_robot = 70;
int addr_conshorsgel = 80;
int addr_a_ph = 90;
int addr_b_ph = 100;
int addr_etalon_ph_acide = 110;
int addr_etalon_ph_base = 120;
int addr_t_z1 = 130;
int addr_t_z2 = 140;
int addr_t_z3 = 150;
int addr_t_z4 = 160;
int addr_seuil_ph = 170;
int addr_deb_1 = 190;
int addr_deb_2 = 200;
int addr_deb_3 = 210;
int addr_deb_4 = 220;
int addr_on_day = 230;
int addr_val_z1 = 231;
int addr_val_z2 = 232;
int addr_val_z3 = 233;
int addr_val_z4 = 234;
int addr_val_bouton_chlore = 237;
int addr_qte_hbdo = 238;
int addr_debit_pompe_chlore = 248;
int addr_val_bouton_ph = 258;
int addr_qte_hbdo_ph = 259;
int addr_debit_pompe_ph = 269;
int addr_ModeFiltration = 279;

// *******************
// Divers
// *******************
unsigned long lastReadingTime = 0;
unsigned long previousMillis = 0;
unsigned long previousMillis2 = 0;
int val_temp_system;
int num_page = 0;
int chk;
int ValTimer1 = 0;
int PresetTimer1 = 10;   // Valeur du Timer 1 en minutes (frequence ecriture carte Sd)
char buffer[10] = {0};
int8_t SetPhRedoxType = -1;
int8_t SetPhRedoxUp = -1;
int8_t SetArrosageType = -1;
int8_t SetArrosageUp = -1;
uint8_t number = 0;
float humd;
float temp;
int TEau = 0;

RTCLib rtc;


///////////////////////////////////////////////////////////////////////////////
//                            INIT                                    
///////////////////////////////////////////////////////////////////////////////
File fichierSD;

  
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
// Adresse IP et Port
// Piscine
 IPAddress ip(192, 168, 1, 178);
 EthernetServer server(2854);

// Banc de test
// IPAddress ip(192, 168, 1, 179);
// EthernetServer server(2855);


// Register object to the touch event list.  
NexTouch *nex_listen_list[] = 
{
  &page0,
  &P0_b0, &P0_b1, &P0_b2,
  &P0_t0, &P0_t1, &P0_t2, &P0_t4, &P0_t7, &P0_t8, &P0_t9, &P0_t10,
  &page1,
  &P1_b0, &P1_b1, &P1_b2, &P1_b3, &P1_b4, &P1_b5, &P1_b6, &P1_b7, 
  &P1_b8, &P1_b9, &P1_b10, &P1_b11, &P1_b12, &P1_b13, &P1_b14, &P1_b15,
  &P1_n1, &P1_n4, &P1_n5, &P1_t8, &P1_t11, &P1_t13,
  &page2,
  &P2_b0, &P2_b1, &P2_b2,
  &page3,
  &P3_b0, &P3_b1, &P3_b2,
  &page4,
  &P4_b8, &P4_b0, &P4_b1, &P4_b2, &P4_b3, &P4_b4, &P4_b5, &P4_b6, &P4_b7, &P4_b9,
  &page5,
  &P5_b2, &P5_b0, &P5_b1,
  &page6,
  &P6_b0, &P6_b1, &P6_b2, &P6_b3,
  &page7,
  &P7_b0, &P7_b1, &P7_b2, &P7_b3, &P7_b4, &P7_b5, &P7_b6, &P7_b7, &P7_b8, &P7_b9, &P7_b10, &P7_b11, &P7_b12, &P7_b13, &P7_b16,
  &page8,
  &P8_b0, &P8_b1, &P8_b2, &P8_b3, &P8_b4, &P8_t7, &P8_t8, &P8_t9, &P8_t10, &P8_n4, &P8_n5,
  &P8_n6, &P8_n7,
  &page9,
  &P9_b0, &P9_b1, &P9_b2, &P9_b3,
  &page10,
  &P10_b0, &P10_b1, &P10_b2, &P10_b3, &P10_b4,
  &page11,
  &P11_b0, &P11_b1, &P11_b2, &P11_b3,
  &page12,
  &P12_b0, &P12_b1, &P12_b2, &P12_b3, &P12_b4,
   NULL
};

  dht DHT;

  OneWire oneWire(DS18B20); //Bus One Wire sur la pin 24 de l'arduino
  DallasTemperature sensors(&oneWire); //Utilistion du bus Onewire pour les capteurs
  DeviceAddress sensorDeviceAddress; //Vérifie la compatibilité des capteurs avec la librairie
   
///////////////////////////////////////////////////////////////////////////////
//                            SETUP                                    
///////////////////////////////////////////////////////////////////////////////

void setup(){

//  Initialisation des variables EEPROM arduino vierge (a executer une seule fois):

//  debit_pompe_chlore = 2.1;
//  EEPROM.writeDouble(addr_debit_pompe_chlore, debit_pompe_chlore);
//  debit_pompe_ph = 2.1;
//  EEPROM.writeDouble(addr_debit_pompe_ph, debit_pompe_ph);
//  seuil_ph = 7.4;
//  EEPROM.writeDouble(addr_seuil_ph, seuil_ph);
//    conshorsgel = 18.0;
//    EEPROM.writeDouble(addr_conshorsgel, conshorsgel);
  
    // Démarre la connection ethernet et le serveur
    Ethernet.begin(mac, ip);
    server.begin();

    // Initialisation des variables stockées en eeprom
    etalon_redox = EEPROM.readDouble(addr_eeprom_redox);
    seuil_redox = EEPROM.readDouble(addr_seuil_redox);
    delta_redox = EEPROM.readDouble(addr_delta_redox);
    depart_filtration = EEPROM.readDouble(addr_depart_filtration);
    duree_filtration = EEPROM.readDouble(addr_duree_filtration);
    depart_robot = EEPROM.readDouble(addr_depart_robot);
    duree_robot = EEPROM.readDouble(addr_duree_robot);
    conshorsgel = EEPROM.readDouble(addr_conshorsgel);
    a_ph = EEPROM.readFloat(addr_a_ph);
    b_ph = EEPROM.readFloat(addr_b_ph);
    etalon_ph_acide = EEPROM.readFloat(addr_etalon_ph_acide);
    etalon_ph_base = EEPROM.readFloat(addr_etalon_ph_base);
    seuil_ph = EEPROM.readFloat(addr_seuil_ph);
    
    t_z1 = EEPROM.readDouble(addr_t_z1);
    t_z2 = EEPROM.readDouble(addr_t_z2);
    t_z3 = EEPROM.readDouble(addr_t_z3);
    t_z4 = EEPROM.readDouble(addr_t_z4);
    
    deb_1 = EEPROM.readDouble(addr_deb_1);
    deb_2 = EEPROM.readDouble(addr_deb_2);
    deb_3 = EEPROM.readDouble(addr_deb_3);
    deb_4 = EEPROM.readDouble(addr_deb_4);

    on_lu = EEPROM.readBit(addr_on_day, point_on_lu);
    on_ma = EEPROM.readBit(addr_on_day, point_on_ma);
    on_me = EEPROM.readBit(addr_on_day, point_on_me);
    on_je = EEPROM.readBit(addr_on_day, point_on_je);
    on_ve = EEPROM.readBit(addr_on_day, point_on_ve);
    on_sa = EEPROM.readBit(addr_on_day, point_on_sa);
    on_di = EEPROM.readBit(addr_on_day, point_on_di);

    val_z1 = EEPROM.read(addr_val_z1);
    val_z2 = EEPROM.read(addr_val_z2);
    val_z3 = EEPROM.read(addr_val_z3);
    val_z4 = EEPROM.read(addr_val_z4);

    val_bouton_chlore = EEPROM.read(addr_val_bouton_chlore);
    debit_pompe_chlore = EEPROM.readDouble(addr_debit_pompe_chlore);

    val_bouton_ph = EEPROM.read(addr_val_bouton_ph);
    debit_pompe_ph = EEPROM.readDouble(addr_debit_pompe_ph);
    
    ModeFiltration = EEPROM.read(addr_ModeFiltration);
    
    /* Set the baudrate which is for debug and communicate with Nextion screen. */
    nexInit();
    P0_b0.attachPop(P0_b0PopCallback);
    P0_b1.attachPop(P0_b1PopCallback);
    P0_b2.attachPop(P0_b2PopCallback);
    
    P1_b0.attachPop(P1_b0PopCallback);
    P1_b1.attachPop(P1_b1PopCallback);
    P1_b2.attachPop(P1_b2PopCallback);
    P1_b3.attachPop(P1_b3PopCallback);
    P1_b4.attachPop(P1_b4PopCallback);
    P1_b5.attachPop(P1_b5PopCallback);
    P1_b6.attachPop(P1_b6PopCallback);
    P1_b8.attachPop(P1_b8PopCallback);
    P1_b9.attachPop(P1_b9PopCallback);
    P1_b10.attachPop(P1_b10PopCallback);
    P1_b11.attachPop(P1_b11PopCallback);
    P1_b12.attachPop(P1_b12PopCallback);
    P1_b13.attachPop(P1_b13PopCallback);
    P1_b14.attachPop(P1_b14PopCallback);
    P1_b15.attachPop(P1_b15PopCallback);
    P1_n1.attachPop(P1_n1PopCallback);
    P1_n4.attachPop(P1_n4PopCallback);
    P1_n5.attachPop(P1_n5PopCallback);
    P1_t8.attachPop(P1_t8PopCallback);
    P1_t11.attachPop(P1_t11PopCallback);
    P1_t13.attachPop(P1_t13PopCallback);
    
    P2_b0.attachPop(P2_b0PopCallback);
    P2_b1.attachPop(P2_b1PopCallback);
    P2_b2.attachPop(P2_b2PopCallback);
    
    P3_b0.attachPop(P3_b0PopCallback);
    P3_b1.attachPop(P3_b1PopCallback);
    P3_b2.attachPop(P3_b2PopCallback);

    P4_b0.attachPop(P4_b0PopCallback);
    P4_b1.attachPop(P4_b1PopCallback);
    P4_b2.attachPop(P4_b2PopCallback);
    P4_b3.attachPop(P4_b3PopCallback);
    P4_b4.attachPop(P4_b4PopCallback);
    P4_b5.attachPop(P4_b5PopCallback);
    P4_b6.attachPop(P4_b6PopCallback);
    P4_b7.attachPop(P4_b7PopCallback);
    P4_b8.attachPop(P4_b8PopCallback);
    P4_b9.attachPop(P4_b9PopCallback);
    
    P5_b0.attachPop(P5_b0PopCallback);
    P5_b1.attachPop(P5_b1PopCallback);
    P5_b2.attachPop(P5_b2PopCallback);

    P6_b0.attachPop(P6_b0PopCallback);
    P6_b1.attachPop(P6_b1PopCallback);
    P6_b2.attachPop(P6_b2PopCallback);
    P6_b3.attachPop(P6_b3PopCallback);

    P7_b0.attachPop(P7_b0PopCallback);
    P7_b1.attachPop(P7_b1PopCallback);
    P7_b2.attachPop(P7_b2PopCallback);
    P7_b3.attachPop(P7_b3PopCallback);
    P7_b4.attachPop(P7_b4PopCallback);
    P7_b5.attachPop(P7_b5PopCallback);
    P7_b6.attachPop(P7_b6PopCallback);
    P7_b7.attachPop(P7_b7PopCallback);
    P7_b8.attachPop(P7_b8PopCallback);
    P7_b9.attachPop(P7_b9PopCallback);
    P7_b10.attachPop(P7_b10PopCallback);
    P7_b11.attachPop(P7_b11PopCallback);
    P7_b12.attachPop(P7_b12PopCallback);
    P7_b13.attachPop(P7_b13PopCallback);
    P7_b16.attachPop(P7_b16PopCallback);
    
    P8_b0.attachPop(P8_b0PopCallback);
    P8_b1.attachPop(P8_b1PopCallback);
    P8_b2.attachPop(P8_b2PopCallback);
    P8_b3.attachPop(P8_b3PopCallback);
    P8_b4.attachPop(P8_b4PopCallback);
    P8_n4.attachPop(P8_n4PopCallback);
    P8_n5.attachPop(P8_n5PopCallback);
    P8_n6.attachPop(P8_n6PopCallback);
    P8_n7.attachPop(P8_n7PopCallback);
    P8_t7.attachPop(P8_t7PopCallback);
    P8_t8.attachPop(P8_t8PopCallback);
    P8_t9.attachPop(P8_t9PopCallback);
    P8_t10.attachPop(P8_t10PopCallback);

    P9_b0.attachPop(P9_b0PopCallback);
    P9_b1.attachPop(P9_b1PopCallback);
    P9_b2.attachPop(P9_b2PopCallback);
    P9_b3.attachPop(P9_b3PopCallback);

    P10_b0.attachPop(P10_b0PopCallback);
    P10_b1.attachPop(P10_b1PopCallback);
    P10_b2.attachPop(P10_b2PopCallback);
    P10_b3.attachPop(P10_b3PopCallback);
    P10_b4.attachPop(P10_b4PopCallback);

    P11_b0.attachPop(P11_b0PopCallback);
    P11_b1.attachPop(P11_b1PopCallback);
    P11_b2.attachPop(P11_b2PopCallback);
    P11_b3.attachPop(P11_b3PopCallback);

    P12_b0.attachPop(P12_b0PopCallback);
    P12_b1.attachPop(P12_b1PopCallback);
    P12_b2.attachPop(P12_b2PopCallback);
    P12_b3.attachPop(P12_b3PopCallback);
    P12_b4.attachPop(P12_b4PopCallback);
    
    dbSerialPrint(F("server is at "));
    dbSerialPrintln(Ethernet.localIP());
    dbSerialPrintln(F("setup done"));


    
     /* RTCLib::set(byte second, byte minute, byte hour, 
     * byte dayOfWeek, byte dayOfMonth, byte month, byte year);
     */
//    rtc.set(0, 5, 16, 3, 15, 2, 16);

      pinMode(relais_filtration, OUTPUT);     //Configure la broche relais filtration en sortie
      pinMode(relais_robot, OUTPUT);          //Configure la broche relais robot en sortie
      pinMode(relais_ph, OUTPUT);        //Configure la broche relais horgel en sortie
      pinMode(relais_chlore, OUTPUT);        //Configure la broche relais chlore en sortie
      pinMode(relais_z1, OUTPUT);        //Configure la broche relais electrovanne z1 en sortie
      pinMode(relais_z2, OUTPUT);        //Configure la broche relais electrovanne z2 en sortie
      pinMode(relais_z3, OUTPUT);        //Configure la broche relais electrovanne z3 en sortie
      pinMode(relais_z4, OUTPUT);        //Configure la broche relais electrovanne z4 en sortie
      pinMode(Buzzer, OUTPUT);     //Configure la Buzzer en sortie
        
      digitalWrite(relais_filtration, HIGH);  // par défaut, la relais n'est pas collé
      digitalWrite(relais_robot, HIGH);       // par défaut, la relais n'est pas collé
      digitalWrite(relais_ph, HIGH);     // par défaut, la relais n'est pas collé
      digitalWrite(relais_chlore, HIGH);     // par défaut, la relais n'est pas collé
      digitalWrite(relais_z1, HIGH);     // par défaut, la relais n'est pas collé
      digitalWrite(relais_z2, HIGH);     // par défaut, la relais n'est pas collé
      digitalWrite(relais_z3, HIGH);     // par défaut, la relais n'est pas collé
      digitalWrite(relais_z4, HIGH);     // par défaut, la relais n'est pas collé

      TpsSecuOfaChlore = ConsTpsSecuOfaChlore; // initialisation temps OFA Chlore
      TpsSecuOfaPh = ConsTpsSecuOfaPh; // initialisation temps OFA Ph
      ValTimer1 = PresetTimer1;                         // initialisation du timer 1
      qte_hbdo = 0;
      
      // Init capteur OneWire
      sensors.getAddress(sensorDeviceAddress, 0); //Demande l'adresse du capteur à l'index 0 du bus
      sensors.setResolution(sensorDeviceAddress, 12); //Résolutions possibles: 9,10,11,12

      sensors.requestTemperatures(); //Demande la température aux capteurs
      TEau = (int) sensors.getTempCByIndex(0);
      
      // Initialisation de la carte SD
      if(!SD.begin(4)) {
      dbSerialPrintln(F("Init carte SD impossible !"));
      return;
      }
      dbSerialPrintln(F("Init carte SD OK"));
      
      //////////// ATTENTION: ne rien mettre aprés (return) si pas d'init carte SD //////////////
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//                            Programme principal                                    
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void loop() {

    unsigned long currentMillis = millis();
    unsigned long currentMillis2 = millis();


////////////////////////// Temporisation de 1 seconde /////////////////////////
    if (currentMillis - previousMillis >= 1000) {
        previousMillis = currentMillis;

		// pH
		ph_sensor_value = analogRead(pin_ph);
		ph_value_float = (a_ph * ph_sensor_value) + b_ph;     	// calcule du pH 

		if (ph_value_float < 0){								// On borne le Ph entre 0 et 14
			ph_value_float = 0;
		}
		if (ph_value_float > 14){
			ph_value_float = 14;
		}

    
		// Redox
		redox_sensor_value = analogRead(pin_redox) * 5000.0 / 1023.0 / 1000.0;   // Convertit 0.0 to 5.0 V
		redox_value_float = (((2.5 - redox_sensor_value) / 1.037) * 1000.0) + (etalon_redox - 250);     // calibration entre -2000 to 2000 mV

/*    	if (redox_value_float < 0){
			redox_value_float = 0;
		}
		if (redox_value_float > 2000){
			redox_value_float = 2000;
		}
*/    
		// calcul du min-max redox accepté
		redox_min = seuil_redox - delta_redox/2;
		redox_max = seuil_redox + delta_redox/2;
    
		rtc.refresh();
       
		if (num_page == 0) {    
			P0Display();
			timeDisplay();
		}

		if (num_page == 2) {    
			timeDisplay_p2();
		}

		if (num_page == 3) {
			P3Display();    
			timeDisplay_p3();
		}

		if (num_page == 6) {
			P6Display();
		}

		if (num_page == 7) {
			P7Display();
			timeDisplay_p7();
		}

		if (num_page == 9) {
			P9Display();
			timeDisplay_p9();
		}

    if (num_page == 11) {
      P11Display();
      timeDisplay_p11();
    }

		// lecture du DHT22 	
		chk = DHT.read22(DHT22_PIN);
		temp = (DHT.temperature);

		humd = (DHT.humidity);

		pompes();    // Appel routine gestion des pompes
		horsgel();   // Appel routine gestion du hors-gel

		// Lancement arrosage auto
		if ((((rtc.hour() == deb_1) || (rtc.hour() == deb_2) || (rtc.hour() == deb_3) || (rtc.hour() == deb_4)) && rtc.minute() == 0) && ((on_lu == 1 && rtc.dayOfWeek() == 1) || (on_ma == 1 && rtc.dayOfWeek() == 2) || (on_me == 1 && rtc.dayOfWeek() == 3) || (on_je == 1 && rtc.dayOfWeek() == 4) || (on_ve == 1 && rtc.dayOfWeek() == 5) || (on_sa == 1 && rtc.dayOfWeek() == 6) || (on_di == 1 && rtc.dayOfWeek() == 7))) {
			t_z1 = EEPROM.readDouble(addr_t_z1);
			t_z2 = EEPROM.readDouble(addr_t_z2);
			t_z3 = EEPROM.readDouble(addr_t_z3);
			t_z4 = EEPROM.readDouble(addr_t_z4);
			start_z1 = 1;
		}

		if ((rtc.hour() == 1) && (rtc.minute() == 0)){qte_hbdo = 0;} // à 1 heure du matin, on réinitialise la quantité de chlore hebdo injectée
     
		arrosage();
		injection_chlore();
    injection_ph();
		temp_sytem();
    
    // Sécurité OFA 
    if (TpsSecuOfaChlore == 0){SecuOfaChlore = 1;}
    if (redox_value_float >= seuil_redox){TpsSecuOfaChlore = ConsTpsSecuOfaChlore;}

    if (TpsSecuOfaPh == 0){SecuOfaPh = 1;}
    if (ph_value_float <= seuil_ph){TpsSecuOfaPh = ConsTpsSecuOfaPh;}

    // Démarage pompe filtration
    if ((filtrationON == 1) || (horsgelON == 1)){
      digitalWrite(relais_filtration, LOW);
    }
    else {
      digitalWrite(relais_filtration, HIGH);
    }


    }

////////////////////////// Fin Temporisation de 1 seconde/////////////////////////
    
////////////////////////// Temporisation de 1 minute /////////////////////////
    if (currentMillis2 - previousMillis2 >= 60000) {
        previousMillis2 = currentMillis2;

		decompte_arrosage_auto();

		// Décompte timer 1 et ecriture sur la carte SD
		ValTimer1 -= 1;
		if (ValTimer1 == 0){
			SDCard();
			ValTimer1 = PresetTimer1;
		}

		// Sécurité OFA 
		if (StartInjection == 1){TpsSecuOfaChlore -= 1;}
    if (TpsSecuOfaChlore <= 0){TpsSecuOfaChlore = 0;}

    if (StartInjectionPh == 1){TpsSecuOfaPh -= 1;}
    if (TpsSecuOfaPh <= 0){TpsSecuOfaPh = 0;}

    if (filtrationON == 1){
      sensors.requestTemperatures(); //Demande la température aux capteurs
      TEau = (int) sensors.getTempCByIndex(0);
    }

	}
////////////////////////// Fin Temporisation de 1 minute/////////////////////////

    ethernet();
    nexLoop(nex_listen_list);

}
