/* Adrian Wojciechowski
 * 
 * Resistance meter
 * Based on the idea of voltage divider
 * Resistors connected in series between 5V and GND
 * Between resistors is connected a wire to A1 pin
 * 
 * lcd 16x2 on AVT 1615
 */

#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7); //(Rs, E, D4, D5, D6, D7)
  
int analogPin= 1;      //Chosen analog pin
int r = 0;             //To save result from digitalRead(A0)
int Uwe = 5;           //5V for Arduino
float Uwy = 0;         //Needs to be calculated. Analog pin goes between both resistors
float R1 = 1000;       //Known resistor
float R2 = 0;          //Resistor to calculate
float temp = 0;        //temp variable used in calculations

void setup() {
  lcd.begin(16,2);  //Initialize screen size;
  lcd.print("Adrian");
  lcd.setCursor(0,1);
  lcd.print("Wojciechowski");
  delay(500);
}

void loop() {
  r = analogRead(analogPin);
  if(r) 
  {
    temp = r * Uwe;
    Uwy = (temp)/1024.0;
    //Uwy = Uwe * R1/(R2+R1)
    //Uwy/Uwe = R1/(R2+R1)
    //R2+R1=R1*(Uwe/Uwy)
    //R2/R1+1=Uwe/Uwy
    temp = (Uwe/Uwy) -1;       //R2/R1 = Uwe/Uwy - 1
    R2 = R1 * temp;            //R2 = (Uwe/Uwy - 1) * R1
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Uwy: ");
    lcd.print(Uwy);
    lcd.setCursor(0,1);
    lcd.print("R2: ");
    lcd.print(R2);
    delay(1000);
  }
}
