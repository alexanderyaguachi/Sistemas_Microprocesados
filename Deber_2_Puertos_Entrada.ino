//UNIVERSIDAD TECNICA DEL NORTE 
//DEBER
//Nombre :Alexander Yaguachi

/*
 *  Realice un programa que mediante dos pulsadores 
    (operando 1 y operando 2) sumen su valor de veces (hasta 25 cada uno)que
    han sido presionados. Dicho valor se mostrará en displas multiplexados 
    al presionar un tercer pulsador.
 */
int op1=5;      //variable para antirrebote
int op2=6;      //variable para antirrebote
int op3=7;      //variable para antirrebote

int A=11,B=10,C=9,D=8; // salida de display

int dec=13;           // activacion display decenas
int uni=12;           // activacion display unidades

int contuni=0;
int contdec=0;
int contdisplay=0;

int decenas=0;        //guarda un valor de decenas
int unidades=0;       //guarda un valor de unidades 


void setup() {

  // put your setup code here, to run once:
  Serial.begin(9600);// Inicializar la comunicacion Serial.
  pinMode(op1,INPUT);
  pinMode(op2,INPUT);
  pinMode(op3,INPUT);
  pinMode(decenas,OUTPUT);
  pinMode(unidades,OUTPUT);
  pinMode(A,OUTPUT);        //Pines de salida digitales del display
  pinMode(B,OUTPUT);        //Pines de salida digitales del display
  pinMode(C,OUTPUT);        //Pines de salida digitales del display
  pinMode(D,OUTPUT);        //Pines de salida digitales del display
}

void loop() {
  // put your main code here, to run repeatedly:
    if(digitalRead(op1)==HIGH){ 
      //Variable antirrebote que cambia cuando se presiona el pulsador
    if (contuni<25){    // limite del conteo
      contuni++;
    }else{
      contuni=0;
    }
    decenas=contuni/10;
    unidades=contuni-decenas*10;
    digitalWrite(dec,HIGH);     //pin en alto de decenas
    digitalWrite(uni,LOW);      //pin en bajo de unidades
    contador(decenas);
    delay(100);
    digitalWrite(dec,LOW);      //pin en bajo de decenas
    digitalWrite(uni,HIGH);     //pin en alto de unidades
    contador(unidades);
    delay(100);
   }
   if(digitalRead(op2)==HIGH){ 
    if (contdec<25){
      contdec++;
    }else{
      contdec=0;
    }
    decenas=contdec/10;
    unidades=contdec-decenas*10;
    digitalWrite(dec,HIGH);       //pin en alto de decenas
    digitalWrite(uni,LOW);        //pin en bajo de unidades
    contador(decenas);
    delay(100);
    digitalWrite(dec,LOW);        //pin en najo de decenas
    digitalWrite(uni,HIGH);       //pin en alto de unidades
    contador(unidades);
    delay(100);
   }
    if(digitalRead(op3)==HIGH){ 

    contdisplay=op1+op2;
    
    }
    decenas=contdisplay/10;
    unidades=contdisplay-decenas*10;
    digitalWrite(dec,HIGH);   //pin en alto de decenas
    digitalWrite(uni,LOW);    //pin en bajo de unidades
    contador(decenas);
    delay(100);
    digitalWrite(dec,LOW);     //pin en bajo de decenas
    digitalWrite(uni,HIGH);    //pin en alto de unidades
    contador(unidades);
    delay(100);
   }
//Declaramos los estados loginos para el control del decodificador
// y enviamos los datos a los displa de unidades y decenas  
void contador (int dato){
  switch(dato){
    case 0:
      digitalWrite(A,LOW);
      digitalWrite(B,LOW);
      digitalWrite(C,LOW);
      digitalWrite(D,LOW);
    break;

    case 1:
      digitalWrite(A,HIGH);
      digitalWrite(B,LOW);
      digitalWrite(C,LOW);
      digitalWrite(D,LOW);
    break;

    case 2:
      digitalWrite(A,LOW);
      digitalWrite(B,HIGH);
      digitalWrite(C,LOW);
      digitalWrite(D,LOW);
    break;

    case 3:
      digitalWrite(A,HIGH);
      digitalWrite(B,HIGH);
      digitalWrite(C,LOW);
      digitalWrite(D,LOW);
    break;
    
    case 4:
      digitalWrite(A,LOW);
      digitalWrite(B,LOW);
      digitalWrite(C,HIGH);
      digitalWrite(D,LOW);
    break;

    case 5:
      digitalWrite(A,HIGH);
      digitalWrite(B,LOW);
      digitalWrite(C,HIGH);
      digitalWrite(D,LOW);
    break;

    case 6:
      digitalWrite(A,LOW);
      digitalWrite(B,HIGH);
      digitalWrite(C,HIGH);
      digitalWrite(D,LOW);
    break;

    case 7:
      digitalWrite(A,HIGH);
      digitalWrite(B,HIGH);
      digitalWrite(C,HIGH);
      digitalWrite(D,LOW);
    break;
    
    case 8:
      digitalWrite(A,LOW);
      digitalWrite(B,LOW);
      digitalWrite(C,LOW);
      digitalWrite(D,HIGH);
    break;

    case 9:
      digitalWrite(A,HIGH);
      digitalWrite(B,LOW);
      digitalWrite(C,LOW);
      digitalWrite(D,HIGH);
    break;
  }
}
