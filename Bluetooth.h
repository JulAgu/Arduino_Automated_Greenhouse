class Bluetooth{

  public:

    void EnviaV (float t, float h, float l, float nA){
        Serial.print(t);
        Serial.print(" C");
        Serial.print("|");
        Serial.print(h);
        Serial.print(" %");
        Serial.print("|");
        Serial.print(l);
        Serial.print(" lx");
        Serial.print("|");
        if(nA == 0){
          Serial.print("LLENAR");
          Serial.print("|");
        }
        else{
          Serial.print(nA);
          Serial.print(" L");
          Serial.print("|");
        }
        return;
    }
    

    void Ordenes (){
        int valor = Serial.read();

        if (valor == 'V'){
          digitalWrite(9,HIGH);
          delay (2000);
          digitalWrite(9,LOW);
          delay (1000);
          digitalWrite(9,HIGH);
          delay (500);
          digitalWrite(9, LOW);
          valor = "";  
        }
        
        if (valor == 'L'){
          digitalWrite(8,HIGH);
          delay (2000);
          digitalWrite(8,LOW);
          delay (1000);
          digitalWrite(8,HIGH);
          delay (500);
          digitalWrite(8, LOW);
          valor = "";  
        }

        if (valor == 'B'){
          digitalWrite(10,HIGH);
          delay (3000);
          digitalWrite(10,LOW);
          delay (1000);
          digitalWrite(10,HIGH);
          delay (500);
          digitalWrite(10, LOW);
          valor = "";  
        }
    }  
};
