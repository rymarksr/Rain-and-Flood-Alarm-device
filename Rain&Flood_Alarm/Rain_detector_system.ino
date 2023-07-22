#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int Buzzer = 10;  // Buzzer in pin 10
int R = 7;    
int G = 6;    
int B = 5;     

// here i set up the tones, you can change them @ void loop.
int tones[] = {261, 277, 293, 311, 329, 349, 369, 392, 415, 440, 466, 493, 523 ,554};
//              1    2    3    4    5    6    7    8    9    10   11   12   13   14
// here you can change the tones by filling in a number between 1 and 14

void setup() {
    lcd.begin();
    lcd.backlight();
    Serial.begin(9600);
    pinMode (Buzzer, OUTPUT);
    pinMode (R, OUTPUT);
    pinMode (G, OUTPUT);
    pinMode (B, OUTPUT);
}

void loop() {

    
    int fldVal = analogRead(A1);
    int rainVal = analogRead(A0);
    
    if (fldVal > 300)
    {
    lcd.clear();
    digitalWrite(R, HIGH);
    digitalWrite(G, LOW);
    digitalWrite(B, LOW);
    digitalWrite(Buzzer, HIGH);
    tone(Buzzer, tones[13]);
    lcd.setCursor(0,0);
    lcd.print("WARNING!");
    lcd.setCursor(3,3);
    lcd.print("FLOOD (O_O)");
    delay(200);
    
    digitalWrite(R, LOW);
    digitalWrite(G, LOW);
    digitalWrite(B, LOW);
    digitalWrite(Buzzer, LOW);
    noTone(Buzzer);
    lcd.setCursor(0,0);
    lcd.print("WARNING!");
    lcd.setCursor(3,3);
    lcd.print("FLOOD (O_O)");
    delay(200);
    
    digitalWrite(R, HIGH);
    digitalWrite(G, LOW);
    digitalWrite(B, LOW);
    digitalWrite(Buzzer, HIGH);
    tone(Buzzer, tones[13]);
    lcd.setCursor(0,0);
    lcd.print("WARNING!");
    lcd.setCursor(3,3);
    lcd.print("FLOOD (O_O)");
    delay(200);
    
    digitalWrite(R, LOW);
    digitalWrite(G, LOW);
    digitalWrite(B, LOW);
    digitalWrite(Buzzer, LOW);
    noTone(Buzzer);
    lcd.setCursor(0,0);
    lcd.print("WARNING!");
    lcd.setCursor(3,3);
    lcd.print("FLOOD (O_O)");
    delay(200);
    }
    else if (rainVal < 900)
    {
    lcd.clear();
    digitalWrite(R, LOW);
    digitalWrite(G, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(Buzzer, HIGH);
    tone(Buzzer, tones[10]);
    lcd.setCursor(0,0);
    lcd.print("WARNING!");
    lcd.setCursor(3,3);
    lcd.print("RAINING >_<");
    delay(200);
    
    digitalWrite(R, LOW);
    digitalWrite(G, LOW);
    digitalWrite(B, LOW);
    digitalWrite(Buzzer, HIGH);
    digitalWrite(Buzzer, LOW);
    noTone(Buzzer);
    lcd.setCursor(0,0);
    lcd.print("WARNING!");
    lcd.setCursor(3,3);
    lcd.print("RAINING >_<");
    delay(200);
    
    digitalWrite(R, LOW);
    digitalWrite(G, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(Buzzer, HIGH);
    digitalWrite(Buzzer, HIGH);
    tone(Buzzer, tones[3]);
    lcd.setCursor(0,0);
    lcd.print("WARNING!");
    lcd.setCursor(3,3);
    lcd.print("RAINING >_<");
    delay(200);
    
    digitalWrite(R, LOW);
    digitalWrite(G, LOW);
    digitalWrite(B, LOW);
    digitalWrite(Buzzer, HIGH);
    digitalWrite(Buzzer, LOW);
    noTone(Buzzer);
    lcd.setCursor(0,0);
    lcd.print("WARNING!");
    lcd.setCursor(3,3);
    lcd.print("RAINING >_<");
    delay(200);
 
    } 
    
    else
    {
    lcd.clear();
    digitalWrite(R, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(Buzzer, LOW);
    lcd.setCursor(5,0);
    lcd.print("SUNNY");
    lcd.setCursor(4,3);
    lcd.print("DAY (^_^)");
    delay(1000);
    }
}
