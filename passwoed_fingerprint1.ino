#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20, 16, 2);
#include <Keypad.h>
const int rnums = 4;
const int cnums = 4;
char keys[rnums][cnums] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};
byte rpins[rnums] = { 2, 3, 4, 5 };
byte cpins[cnums] = { 6, 7, 8, 9 };
Keypad keypad(makeKeymap(keys), rpins, cpins, rnums, cnums);
byte CorrectPass[6] = { '2', '3', '6', '4', '7', '8' };
byte InsertedPass[6] = {};
byte Counter = 0;
byte PassCounter = 0;
byte Colcounter = 0;
byte user1=10;
byte user2=11;
byte user3=12;
byte user4=13;
byte user5=14;
void homescreen() {
  lcd.clear();
  Counter = 0;
  PassCounter = 0;
  Colcounter = 0;
  lcd.setCursor(0, 0);
  lcd.print("Enter Password :");
}
void setup() {
  lcd.init();
  lcd.backlight();
  homescreen();
  pinMode(user1,INPUT);
  pinMode(user2,INPUT);
  pinMode(user3,INPUT);
  pinMode(user4,INPUT);
  pinMode(user5,INPUT);
  Serial.begin(9600);
}
void loop() {
  char key = keypad.getKey();
  if (key) {
    if (key != 'D') {
      InsertedPass[Counter] = key;
      lcd.setCursor(Colcounter, 1);
      lcd.print("*");
      Colcounter++;
      if (Colcounter == 6) { Colcounter = 0; }
      Counter++;
      Serial.println(PassCounter);
      if (key == 'A') {
        lcd.clear();
        lcd.print("Reseting System");
        delay(2000);
        homescreen();}
    } else {
      for (byte i = 0; i <= 5; i++)
        if (InsertedPass[i] == CorrectPass[i]) PassCounter++;
      if (PassCounter >= 6) {
        lcd.setCursor(0, 1);
        lcd.print("Correct Password");
        delay(2000);
        lcd.clear();
        lcd.print("Fingerprint Required!");      
    }  else {
        lcd.setCursor(0, 1);
        lcd.print("Wrong Password");
        delay(2000);
        lcd.clear();
		lcd.print("Fingerprint Required!");
      }}}if (digitalRead(user1)){
        lcd.clear();
        lcd.print("User ID : 1");
        delay(2000);
        homescreen();
        }
        if (digitalRead(user2)){
        lcd.clear();
        lcd.print("User ID : 2");
        delay(2000);
        homescreen();
        }if (digitalRead(user3)){
        lcd.clear();
        lcd.print("User ID : 3");
        delay(2000);
        homescreen();
        }if (digitalRead(user4)){
        lcd.clear();
        lcd.print("User ID : 4");
        delay(2000);
        homescreen();
        }if (digitalRead(user5)){
        lcd.clear();
        lcd.print("User ID : 5");
        delay(2000); }}