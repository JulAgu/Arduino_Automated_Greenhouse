class Actuadores{
  public:
    boolean E;
};

class Ventilador : public Actuadores{
  public:
  
    void SeEnciende(float temp, float hum){
      
      if(temp <= 20){
        digitalWrite(9,LOW);
        E = false;
      }
      if(temp > 20 || hum > 70){
        digitalWrite(9,HIGH);
        E = true;
      }
      return;
    }
};

class Bombillo : public Actuadores{
  public:
  
    void SeEnciende(float luz, float temp){
      
      if(luz <= 200){
        digitalWrite(8,HIGH);
        E = true;
      }
      if(luz > 200){
        digitalWrite(8,LOW);
        E = false;
      }
      return;
    }
};
