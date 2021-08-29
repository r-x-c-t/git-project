
#include <LedControl.h>
#include <LiquidCrystal_I2C.h>
#define DIN 8
#define CS 7
#define CLK 6
#define Red 3
#define Green 5
#define Blue 9
#define time_delay 2000
#define Height 8
#define Width 8
LiquidCrystal_I2C lcd(0x27,16,2);
LedControl LC=LedControl(DIN,CLK,CS,1);
byte R[8][8]={
  {0,0,0,1,1,1,1,1},
  {0,0,1,0,0,0,0,1},
  {0,0,1,0,0,0,0,1},
  {0,0,0,1,0,0,0,1},
  {0,0,0,0,1,1,1,1},
  {0,0,0,0,1,0,0,1},
  {0,0,0,1,0,0,0,1},
  {0,0,1,0,0,0,0,1}
};
byte G[8][8]={
  {0,0,1,1,1,1,0,0},
  {0,0,1,0,0,1,1,0},
  {0,0,0,0,0,0,1,1},
  {0,0,0,0,0,0,0,1},
  {0,0,1,1,0,0,0,1},
  {0,0,1,0,0,0,1,1},
  {0,0,1,0,0,1,1,0},
  {0,0,1,1,1,1,0,0}
};
byte B[8][8]={
  {0,0,1,1,1,1,0,0},
  {0,0,1,0,0,0,1,0},
  {0,0,1,0,0,0,1,0},
  {0,0,0,1,0,0,1,0},
  {0,0,0,1,1,1,1,0},
  {0,0,1,0,0,0,1,0},
  {0,0,1,0,0,0,1,0},
  {0,0,1,1,1,1,1,0}
};
void change_color(char c){
   Serial.println(c);
   if(c=='R'){
     analogWrite(Red,255);
     analogWrite(Green,0);
     analogWrite(Blue,0);
   }
   else if(c=='G'){
     analogWrite(Red,0);
     analogWrite(Green,255);
     analogWrite(Blue,0);
   }
   else if(c=='B'){
     analogWrite(Red,0);
     analogWrite(Green,0);
     analogWrite(Blue,255);
   }
}
void Update(byte array_[Height][Width],char a){
   change_color(a);
   for(int i=0;i<Height;i++){
      for(int j=0;j<Width;j++){
        LC.setLed(0,j,i,array_[i][j]);
        Serial.println("ok");
      }
    }
    
}
void set(){
  delay(time_delay);
  LC.clearDisplay(0);
  lcd.clear();
  analogWrite(Red,0);
  analogWrite(Green,0);
  analogWrite(Blue,0);
  delay(100);
}
void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("show color");
  lcd.clear();
  pinMode(Red,OUTPUT);
  pinMode(Green,OUTPUT);
  pinMode(Blue,OUTPUT);
  pinMode(DIN,OUTPUT);
  pinMode(CS,OUTPUT);
  pinMode(CLK,OUTPUT);
  LC.shutdown(0,false);
  LC.setIntensity(0,5);
  Serial.begin(9600);
}
 
void loop() {
  // put your main code here, to run repeatedly:
  Update(R,'R');
  lcd.print("this is Red");
  set();
  Update(G,'G');
  lcd.print("this is Green");
  set();
  Update(B,'B');
  lcd.print("this is Blue");
  set();
}
