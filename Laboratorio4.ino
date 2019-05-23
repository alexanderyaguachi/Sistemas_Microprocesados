/*
 * UNIVERSIDAD TECNICA DEL NORTE
 * LABORATORIO
 * ALEJANDRO ORTEGA, EDISON PICUASI, ALEXANDER YAGUACHI 
 * 
 * 
 * 
 */
int pass[5]={1,2,3,4,6};
int i=0,j=0;
int ntam,estado,alarma;
int a1,a2,a3,a4,a5;
int s1=13,s2=12,s3=11,s4=10,s5=9;
String CX;
void setup() {
Serial.begin(9600);
pinMode(s1,INPUT);
pinMode(s2,INPUT);
pinMode(s3,INPUT);
pinMode(s4,INPUT);
pinMode(s5,INPUT);
attachInterrupt(0,menu,LOW);
attachInterrupt(1,seleccion,LOW);
}

void loop() {
/*=============CAMBIAR CONTRASENA=============*/
if(i==1){
    if(Serial.available()>0){
    CX=Serial.readString();
    ntam=CX.length();
    Serial.println(ntam);

    String n1=CX.substring(0,1);
    String n2=CX.substring(1,2);
    String n3=CX.substring(2,3);
    String n4=CX.substring(3,4);
    String n5=CX.substring(4,5);
    a1=n1.toInt();
    a2=n2.toInt();
    a3=n3.toInt();
    a4=n4.toInt();
    a5=n5.toInt();

    pass[0]=a1;
    pass[1]=a2;
    pass[2]=a3;
    pass[3]=a4;
    pass[4]=a5;
    }
  }
/*=============ACTIVAR ALARMA=============*/
if(i==3){  
  if(Serial.available()>0){
    CX=Serial.readString();
    ntam=CX.length();
    Serial.println(ntam);

    String n1=CX.substring(0,1);
    String n2=CX.substring(1,2);
    String n3=CX.substring(2,3);
    String n4=CX.substring(3,4);
    String n5=CX.substring(4,5);
    a1=n1.toInt();
    a2=n2.toInt();
    a3=n3.toInt();
    a4=n4.toInt();
    a5=n5.toInt();
    if(a1==pass[0]&&a2==pass[1]&&a3==pass[2]&&a4==pass[3]&&a5==pass[4]){
      Serial.println("CORRECTO");
      estado=1;
      }else{
        Serial.println("INCORRECTO");
        }
   }
  }

 if(estado==1){ 
  for(int k=0;k<=j;k++){
    
    switch(k){
    case 1:
    if(digitalRead(s1)==HIGH){
        alarma=1;
    Serial.println("S1");}
    break;
    case 2:
    if(digitalRead(s2)==HIGH){
      alarma=1;
    Serial.println("S2");}
    break;
    case 3:
    if(digitalRead(s3)==HIGH){
        alarma=1;
    Serial.println("S3");}
    break;
    case 4:
    if(digitalRead(s4)==HIGH){
        alarma=1;
    Serial.println("S4");}
    break;
    case 5:
    if(digitalRead(s5)==HIGH){
        alarma=1;
    Serial.println("S5");}
    break;
      
      }
    
    }
  
  }

  if(alarma==1){
    
    Serial.println("SONANDO");
    }
  
/*=============DESACTIVAR ALARMA=============*/
if(i==4){
   if(Serial.available()>0){
    CX=Serial.readString();
    ntam=CX.length();
    Serial.println(ntam);

    String n1=CX.substring(0,1);
    String n2=CX.substring(1,2);
    String n3=CX.substring(2,3);
    String n4=CX.substring(3,4);
    String n5=CX.substring(4,5);
    a1=n1.toInt();
    a2=n2.toInt();
    a3=n3.toInt();
    a4=n4.toInt();
    a5=n5.toInt();
    if(a1==pass[0]&&a2==pass[1]&&a3==pass[2]&&a4==pass[3]&&a5==pass[4]){
      Serial.println("CORRECTO");
      estado=0;
      alarma=0;
      }else{
        Serial.println("INCORRECTO");
        }
   }
  }

}

void menu(){
i++;
switch(i)  {
  
  case 1:
  Serial.println("Cambio de Contrasena");
  break;
  case 2:
  Serial.println("Seleccion de sensores");
  break;
  case 3:
  Serial.println("Activar Alarma");
  break;
  case 4:
  Serial.println("Parar Alarma");
  break;
  default:
  i=0;
  
  }
}

void seleccion(){

 if(i==2){
 j++;
  switch(j){
    case 1:
    Serial.println("Sensor 1: Activado");
    break;
    case 2:
    Serial.println("Sensor 2: Activado");
    break;
    case 3:
    Serial.println("Sensor 3: Activado");
    break;
    case 4:
    Serial.println("Sensor 4: Activado");
    break;
    case 5:
    Serial.println("Sensor 5: Activado");
    break;
    default: 
    j=0;
  }
}
}
