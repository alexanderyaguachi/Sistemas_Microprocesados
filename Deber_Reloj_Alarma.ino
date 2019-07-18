#include <MsTimer2.h>
#include <EEPROM.h>
#include <LiquidCrystal.h>

const int rs = 12, en = 10, d4 = 9, d5 = 8, d6 = 7, d7 = 6; // pines lcd16x2
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int horas=0;    //variable hotas
int minutos=0;  //varaible minutos
int segundos=0; // variable segundos
int tam;
int i;
int j;
int k;
int s,m,h;
String valor;
void setup() {
  
    Serial.begin(9600); //inicia comunicaion serial
    lcd.begin(16,2);    //iniciar lcd
    attachInterrupt(0,detener,FALLING);
    MsTimer2::set(1000, reloj);//tiempo
    MsTimer2::start();
    i=EEPROM.read(1);
    j=EEPROM.read(2);
    k=EEPROM.read(3);
  lcd.setCursor(0,0);
  lcd.print("Reloj");
   Serial.print("Alarma:");
   Serial.print(EEPROM.read(1));
   Serial.print(":");
   Serial.print(EEPROM.read(2));
   Serial.print(":");
   Serial.print(EEPROM.read(3));

   Serial.println(" ");
   Serial.println("Ingrese  Alarma");
   Serial.println("17:00:00");
}
void loop() {
  // put your main code here, to run repeatedly:
     if(Serial.available()>0){
  valor=Serial.readString();
  tam=valor.length();
  if(tam==8){
    h=valor.substring(0,2).toInt();
    m=valor.substring(3,5).toInt();
    s=valor.substring(6,8).toInt();
    

    if((h<=24 and h>=0)and(m<=60 and m>=0)and(s<=60 and h>=0)){

      Serial.println("alarma almacenada");
   Serial.println(" ");
   Serial.print(h);
   Serial.print(":");
   Serial.print(m);
   Serial.print(":");
   Serial.print(s);
       EEPROM.write(1,h);
       EEPROM.write(2,m);
       EEPROM.write(3,s);
      }
         else{
  Serial.println("Ingrese Alarma");
  Serial.println("17:00:00");
              }
    }
  }
}
      
void graficar(){
   lcd.setCursor(7,0);
   lcd.print("Reloj");
   lcd.clear();
   lcd.setCursor(5,0);
   lcd.print("Reloj");
   lcd.setCursor(0,1);
   lcd.print("Hora: ");
    lcd.setCursor(6,1); //posiscion donde se imprime
   lcd.print(horas);    //Imprimer la hora
   lcd.setCursor(8,1);  //posiscion donde se imprime
   lcd.print(": ");
   lcd.setCursor(9,2);  //posiscion donde se imprime
   lcd.print(minutos);  //Imprimer los minutos
   lcd.setCursor(11,2);
   lcd.print(": ");     //posiscion donde se imprime
   lcd.setCursor(12,2); //posiscion donde se imprime
   lcd.print(segundos); //Imprimer los segundos
    
    if((h==horas)and(m==minutos)and(s==segundos)){
    Serial.println("Alarma");
     }    
}
void reloj(){
  
  segundos++;
  if(segundos>=60){
    segundos=0;
    minutos++;
    }
  if(minutos>=60){
    minutos=0;
    horas++;
    }
  if(horas>=24){
    horas=0;
     }
 graficar(); 
 }
void detener(){
  Serial.println("Alarma Apagada");
  h=0;
  m=0;
  s=0;
}
