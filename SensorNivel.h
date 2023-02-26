class SensorNivel{

  public:

    float Leer(){
      digitalWrite(7,HIGH);
      delay(10);
      float voltaje = analogRead(A3);
      digitalWrite(7,LOW);
      float alturaSensor = (0.0187*voltaje)-8.6111; //altura en cm
      float altura = 8-3+alturaSensor;
      float litros = (altura*55.5*37)/1000;
      if (voltaje>=300){
        return litros;
      }
      else{
        return 0;
      }
       
    }
};
