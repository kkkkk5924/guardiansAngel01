#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int lock = 13;
int buttonState = 0;
const int Rx = 7;
const int Tx = 6;
SoftwareSerial bluetooth(Tx,Rx);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(20, 4);
  lcd.print("HelloWorld");
  Serial.begin(9600);
  bluetooth.begin(9600);
  Serial.println("Start");
  pinMode(lock, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//  lcd.setCursor(0,0);
//  lcd.print("START");
  if (bluetooth.available() > 0) {
  //Serial.write(bluetooth.read());
  char num = char(bluetooth.read());
  if(num=='1'){
    digitalWrite(lock, 1);
  }
  else if(num=='0'){
    digitalWrite(lock, 0);
  }
    lcd.setCursor(0,1);
    lcd.print(num);

    
  
}
  
}
