/* 
 *  UNIVERSIDAD TÉCNICA DEL NORTE 
 *  NOMBRE :Alexander Yaguachi
 *  SISTEMAS MICROPROCESADOS 
 *  
 */
 String placa;
 String pl;
 void setup() {
  Serial.begin(9600);
  Serial.println("Validar Placas");
  Serial.println("Ingrese su placa");
  delay(100);
}
void loop() {
  if (Serial.available() > 0)
  {
    placa = Serial.readString();
    placa.toUpperCase(); //Permite que todo este en mayuscula.
    Serial.println(placa);
    Serial.println("Ingrese la Placa "); 
   provincias();
  }
}
void provincias(){
   if (placa.length() == 8) {
      pl = placa.substring(placa.indexOf("-") + 1, placa.length());
      if (pl.length() == 4) {
        if (placa.substring(3, 4) == "-") {
          if (placa.substring(0, 1) != "0" && placa.substring(0, 1) != "1" && placa.substring(0, 1) != "2" && placa.substring(0, 1) != "3" && placa.substring(0, 1) != "4" && placa.substring(0, 1) != "5" && placa.substring(0, 1) != "6" && placa.substring(0, 1) != "7" && placa.substring(0, 1) != "8" && placa.substring(0, 1) != "9") {
            if (placa.substring(1, 2) != "0" && placa.substring(1, 2) != "1" && placa.substring(1, 2) != "2" && placa.substring(1, 2) != "3" && placa.substring(1, 2) != "4" && placa.substring(1, 2) != "5" && placa.substring(1, 2) != "6" && placa.substring(1, 2) != "7" && placa.substring(1, 2) != "8" && placa.substring(1, 2) != "9") {
              if (placa.substring(2, 3) != "0" && placa.substring(2, 3) != "1" && placa.substring(2, 3) != "2" && placa.substring(2, 3) != "3" && placa.substring(2, 3) != "4" && placa.substring(2, 3) != "5" && placa.substring(2, 3) != "6" && placa.substring(2, 3) != "7" && placa.substring(2, 3) != "8" && placa.substring(2, 3) != "9") {
                
                
                if (placa.substring(0, 1) == "A")
                  Serial.println("Placa VALIDA");
                  Serial.println("Azuay");
                if (placa.substring(0, 1) == "B")
                Serial.println("Placa VALIDA");
                  Serial.println("Bolivar");
                if (placa.substring(0, 1) == "C")
                Serial.println("Placa VALIDA");
                  Serial.println("Carchi");
                if (placa.substring(0, 1) == "X")
                Serial.println("Placa VALIDA");
                  Serial.println("Cotopaxi");
                if (placa.substring(0, 1) == "H")
                Serial.println("Placa VALIDA");
                  Serial.println("Chimborazo");
                if (placa.substring(0, 1) == "O")
                Serial.println("Placa VALIDA");
                  Serial.println("El Oro");
                if (placa.substring(0, 1) == "E")
                Serial.println("Placa VALIDA");
                  Serial.println("Esmeraldas");
                if (placa.substring(0, 1) == "W")              
                  Serial.println("Placa VALIDA");
                  Serial.println("Galapagos");
                if (placa.substring(0, 1) == "G")
                Serial.println("Placa VALIDA");
                  Serial.println("Guayaquil");
                if (placa.substring(0, 1) == "I")
                Serial.println("Placa VALIDA");
                  Serial.println("Imbabura");
                if (placa.substring(0, 1) == "L")
                Serial.println("Placa VALIDA");
                  Serial.println("Loja");
                if (placa.substring(0, 1) == "R")
                Serial.println("Placa VALIDA");
                  Serial.println("Los Rios");
                if (placa.substring(0, 1) == "M")
                Serial.println("Placa VALIDA");
                  Serial.println("Manabi");
                if (placa.substring(0, 1) == "V")
                Serial.println("Placa VALIDA");
                  Serial.println("Morona Santiago");
                if (placa.substring(0, 1) == "N")
                Serial.println("Placa VALIDA");
                  Serial.println("Napo");
                if (placa.substring(0, 1) == "S")
                  Serial.println("Pastaza");
                if (placa.substring(0, 1) == "P")
                Serial.println("Placa VALIDA");
                  Serial.println("Pichincha");
                if (placa.substring(0, 1) == "Q")
                Serial.println("Placa VALIDA");
                  Serial.println("Orellana");
                if (placa.substring(0, 1) == "K")
                Serial.println("Placa VALIDA");
                  Serial.println("Sucumbios");
                if (placa.substring(0, 1) == "T")
                Serial.println("Placa VALIDA");
                  Serial.println("Tungurahua");
                if (placa.substring(0, 1) == "Z")
                Serial.println("Placa VALIDA");
                  Serial.println("Zamora Chinchipe");
                if (placa.substring(0, 1) == "Y")
                Serial.println("Placa VALIDA");
                  Serial.println("Santa Elena");
                if (placa.substring(0, 1) == "J")
                Serial.println("Placa VALIDA");
                  Serial.println("Santo Domingo de los Tsachilas");
              }
              
            }
            
          }
          
        }
       
      }
      
    }
}
