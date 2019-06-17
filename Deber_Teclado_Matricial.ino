/*
 * UNIVERSIDAD TECNICA DEL NORTE
 * Alexander Yaguachi
 */

#include <Password.h> //Incluimos la libreria Password
#include <Keypad.h> //Incluimos la libreria Keypad
#include <LiquidCrystal.h>  //Incluimos la libreria LiquidCrystal
 
Password password = Password("1234");  //Definimos el Password

LiquidCrystal lcd(A0, A1, A2, A3, A4, A5); //Definimos los pines del LCD

const byte ROWS = 4; // Cuatro Filas
const byte COLS = 4; // Cuatro Columnas

// Definimos el Keymap
char keys[ROWS][COLS] = {
 
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
  
};

byte rowPins[ROWS] = { 9,8,7,6 };// Conectar los keypads fila1, fila2, fila3 y fila4 a esos Pines de Arduino.
byte colPins[COLS] = { 5,4,3,2 };// Conectar los keypads columna1, columna2, columna3 y columna4 a esos Pines de Arduino.
 
Keypad customkeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
 
void setup()
{
  customkeypad.addEventListener(keypadEvent);  

  lcd.begin(16, 2);
 
  lcd.setCursor(0,0);
  lcd.print("  *Bienvenido*");
  lcd.setCursor(0,1);
  lcd.print("INGRESE LA CLAVE");
}
 
void loop()
{
 char customkey=  customkeypad.getKey();  
}
void keypadEvent(KeypadEvent eKey)
{
  switch (customkeypad.getState())
  {
    case PRESSED:
Serial.print("Digite Contraseña: ");
Serial.println(eKey);
switch (eKey)
{
delay(250);
checkPassword();
   } 
  }
}
void checkPassword()
{
  if (password.evaluate())
  {  
    password.reset();       
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("  *Bienvenido*");
    lcd.setCursor(0,1);
    lcd.print("INGRESE LA CLAVE");  
    delay(2000); 
    Serial.println("Correcto");    
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("CLAVE CORRECTA");     
  }  
  else     // si es incorrecto
  { 
    password.reset();

     lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("INGRESE LA CLAVE"); 
    delay(2000);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("CLAVE INCORRECTA");
    lcd.setCursor(0,0);
    lcd.print("Intenta otra vez");
   
       
  }

 
}
