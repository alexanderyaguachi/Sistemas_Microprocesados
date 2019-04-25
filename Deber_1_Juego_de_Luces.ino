//UNIVERSIDAD TECNICA DEL NORTE
//Alexander Yaguachi
//Deber 1 Juego de Luces


int t=200;                         //Declaramos el tiempo de prendido
int leds[8]={6,7,8,9,10,11,12,13};       //Declaramos un vector de 8 posiciones
int rdm;
int i=0;
int j=0;
void setup() {
      
     for(int i=0;i<8;i++){
        pinMode(leds[i],OUTPUT);
      }
}
void juego1(){
  
  for(int i=0;i<8;i=i+2){       //Indica la secuencia de pines en alto "1,3,5,7"
    digitalWrite(leds[i],HIGH);
    delay(t);                     //Reliza una pausa durante un tiempo
    digitalWrite(leds[i],LOW);
    delay(t);                     //Reliza una pausa durante un tiempo
    }
  }
void juego2(){
   for(int i=1;i<8;i=i+2){      //Indica la secuencia de pines en alto "2,4,6,8"
    digitalWrite(leds[i],HIGH);
    delay(t);                   //Reliza una pausa durante un tiempo
    digitalWrite(leds[i],LOW);
    delay(t);
    }
  }
void juego3(){
   rdm=random(8);              //Imprime un led aleatorio dentro del vector de 8 posiciones
    digitalWrite(leds[rdm],HIGH);
    delay(t);
    digitalWrite(leds[rdm],LOW);
    delay(t);
  }
void juego4(){
  for(i=0;i<8;i++){//los leds se encenderan de forma ascendente.
  digitalWrite(leds[i],HIGH);
  delay(t);  
  }
  for(i=8;i>=0;i--){//los leds de apagaran en forma descendente.
  digitalWrite(leds[i],LOW); 
  delay(t);  
  }
 }
  void juego5(){
   for(i=0,j=8;i<5;i++,j--){//Los leds se encenderan al mismo tiempo desde los extemos
  digitalWrite(leds[i],HIGH),digitalWrite(leds[j],HIGH);
  delay(t);}
  for(i=5,j=5;i>=0;i--,j++){//Se apagaran los leds al contrario del encendido.
  digitalWrite(leds[i],LOW),digitalWrite(leds[j],LOW);
  delay(t);}
  }
void loop() {
  juego1(); 
  delay(250); //Hace una pausa entre el juego 1 y 2
  juego2(); 
  delay(250); //Hace una pausa entre el juego 2 y 3
  juego3(); 
  delay(250); //Hace una pausa entre el juego 3 y 4
  juego4(); 
  delay(250); //Hace una pausa entre el juego 4 y 5
  juego5(); 
  delay(250); //Hace una pausa entre el juego 5 y 1
}
  
