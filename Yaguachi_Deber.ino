/*
 * Yaguachi Alexander
 Realizar un programa de seguridad domótica que permita encender las luces de un
 domicilio de 5 habitaciones de forma aleatoria solo en horario nocturno. 
 El sistema se activa al ingresar una contraseña por comunicación serial.
						 
 * 
 */
#include <TimerOne.h>
#include <LiquidCrystal.h>
#include <EEPROM.h>
#include <MsTimer2.h>
const int rs = 12, en = 10, d4 = 9, d5 = 8, d6 = 7, d7 = 6;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int horas=0;    //variable hotas
int minutos=0;  //varaible minutos
int segundos=0; // variable segundos
int funcion=0;
int led1=22;
int led2=23;
int led3=24;
int led4=25;
int led5=26;
String clave;
int i;
boolean validar;
void setup() {
  // put your setup code here, to run once:
    
    Serial.begin(9600);
     lcd.begin(16,2);
     attachInterrupt(0,sistema,FALLING);
     MsTimer2::set(1000, reloj);
     MsTimer2::start();
     pinMode(led1,OUTPUT);
     pinMode(led2,OUTPUT);
     pinMode(led3,OUTPUT);
     pinMode(led4,OUTPUT);
     pinMode(led5,OUTPUT);
     
}

void loop() {

   if (funcion == 1) {
    if (Serial.available() > 0) {
      clave = Serial.readString();
      if (clave.length() != 4) {
        Serial.println(" ");
        Serial.println("Clave ");
        Serial.println(" ");
        lcd.setCursor(0, 1);
        lcd.print("Clave ");
        delay(1000);
        lcd.clear();
      }
      else {
        validar = clave.equals("M123");
        if (validar == true) {
          Serial.println(" ");
          Serial.println("Clave Correcta");
          Serial.println(" ");
          lcd.clear();
          lcd.setCursor(0, 1);
          lcd.print("Clave Correcta");
          delay(1000);
          lcd.clear();
        }
        else {
          Serial.println(" ");
          Serial.println("Clave Incorrect");
          Serial.println(" ");
          lcd.clear();
          lcd.setCursor(0, 1);
          lcd.print("Clave Incorrect");
          delay(1000);
          lcd.clear();
        }
      }
    }
  }
}

void sistema(){
  switch (funcion) {
    case 0:
      Serial.println("SISTEMAS ACTIVO");
      Serial.println("INGRESE clave");
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("SIS. PRENDIDO");
      lcd.setCursor(0, 1);
      lcd.print("INGRESE CLAVE");
      funcion++;
      break;
  }
}
void reloj(){
   if (segundos < 59) {
    segundos++;
    Serial.print(horas);
    Serial.print(':');
    Serial.print(minutos);
    Serial.print(':');
    Serial.print(segundos);
    Serial.println(" ");
  }
  else {
    segundos = 0;
    if (minutos < 59) {
      minutos++;
      Serial.print(horas);
      Serial.print(':');
      Serial.print(minutos);
      Serial.print(':');
      Serial.print(segundos);
      Serial.println(" ");
    }
    else {
      minutos = 0;
      if (horas < 23) {
        horas++;
        Serial.print(horas);
        Serial.print(':');
        Serial.print(minutos);
        Serial.print(':');
        Serial.print(segundos);
        Serial.println(" ");
      }
      else {
        minutos = 0;
        Serial.print(horas);
        Serial.print(':');
        Serial.print(minutos);
        Serial.print(':');
        Serial.print(segundos);
        Serial.println(" ");
      }
    }
  }
  if (((horas >= 19 && horas <= 23) || (horas >= 0 && horas <= 5))
      && (minutos >= 0 && minutos <= 59)  && (segundos >= 0 && segundos <= 59)) {
    i = random(led1, led5);//se asigna i  un numero aleatorio
    digitalWrite (i, HIGH);
    delay (10000);
  } if (((horas >= 19 && horas <= 23) || (horas >= 0 && horas <= 5)) 
    && (minutos >= 0 && minutos <= 59)  && (segundos >= 0 && segundos <= 59)) {
    i = random(led1, led5);//se asigna i un numero aleatorio
    digitalWrite (i, LOW);
    delay (1000);
  } else {
    digitalWrite (led1, LOW);
    digitalWrite (led2, LOW);
    digitalWrite (led3, LOW);
    digitalWrite (led4, LOW);
    digitalWrite (led5, LOW);
  }
}
