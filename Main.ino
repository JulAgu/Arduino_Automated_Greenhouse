    #include "Bluetooth.h"
#include "SensorNivel.h"
#include <Wire.h>
#include <BH1750.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#include "Actuadores.h"



//Objetos a partir de clases que vienen desde las librerias, los objetos se declaran con los nombres de las clases, en minuscula.
DHT dht(2, DHT22);
BH1750 bh;
LiquidCrystal_I2C lcd(0x27,16,2);
Ventilador vent;
Bombillo bomb;
Bluetooth blue;
SensorNivel sensorN;

long tiempolectura = 0;
long tiempoI1 = 0;
long tiempoBombaIni = 0; 
int cuentapantalla = 0;
float t = 0;
float h = 0;
float lux = 0;
float nA = 0;
boolean BombE = false;

void BombaTempo (){
  if (millis()-tiempoBombaIni>7200000){
    digitalWrite(10,HIGH);
    tiempoBombaIni = millis();
    BombE = true;
    
  }
  else if (millis()-tiempoBombaIni>300000 && BombE){
    digitalWrite(10,LOW);
    BombE =false;
  }
}

void IMPlcd(String nombre, float valor, String unidad){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(nombre);
  lcd.setCursor(0,1);
  lcd.print(valor);
  lcd.print (" " + unidad);
  return;
}

void setup() {
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  digitalWrite(7,LOW);
  Serial.begin(9600);
  Wire.begin();
  dht.begin();
  bh.begin(BH1750::CONTINUOUS_HIGH_RES_MODE);
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {
  // La libreria lee la temperatura en grados Celsius, por defecto.
  if(millis()-tiempolectura>2000){
    t = dht.readTemperature();
    h = dht.readHumidity();
    lux = bh.readLightLevel();
    nA = sensorN.Leer();
    blue.EnviaV(t,h,lux,nA);
    tiempolectura = millis();    
  }
  blue.Ordenes();
  vent.SeEnciende(t,h);
  bomb.SeEnciende(lux,t);
  BombaTempo();
//  
  if(millis()-tiempoI1>3000){    
    if(cuentapantalla == 0){
      IMPlcd("Temperatura",t,"C");
      cuentapantalla++; 
    }
    else if(cuentapantalla == 1){
      IMPlcd("Humedad",h,"%");
      cuentapantalla++;
    }
    else{
      IMPlcd("Luminosidad",lux,"lx");
      cuentapantalla = 0;
    }
    tiempoI1 = millis();
  }   
}
