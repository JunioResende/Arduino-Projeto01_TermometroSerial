#include <Arduino.h>

#include <DHT.h> //inclui a lib DHT

#define PINDHT 8 // define o pino utilizado no arduino

#define MODELODHT DHT11 // define o modelo do DHT utilizado no projeto

DHT dht(PINDHT, MODELODHT);

void setup()
{
  Serial.begin(9600);

  dht.begin(); // inicializacao do sensor

  Serial.println("Efetuando a leitura no sensor");
}

void loop()
{
  int delayMeasurement = 2000;
  delay(delayMeasurement); // tempo entre as medidas

  float moisture = dht.readHumidity(); // leitura da umidade %

  float temperature = dht.readTemperature(); // leitura da temperatura °C

  if (isnan(moisture) || isnan(temperature))
  {
    Serial.println("Falha na leitura do sensor DHT!!!");
  }
  else
  {
    Serial.print("Umidade: ");
    Serial.print(moisture);
    Serial.print("%");

    Serial.print("  |  ");

    Serial.print("Temperatura: ");
    Serial.print(temperature);
    Serial.println("°C");
  }
}