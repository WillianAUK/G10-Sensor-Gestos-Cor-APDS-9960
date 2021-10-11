/****************************************************************
Testa as habilidades de detecção de proximidade do APDS-9960.
Configura o APDS-9960 em I2C e pesquisa a distância para
o objeto mais próximo do sensor.

Conexões de hardware:

IMPORTANTE: O APDS-9960 só pode aceitar 3,3 V!
 
  Função da placa Esp8266 Pin APDS-9960 
 
 3.3V         VCC              Power
 GND          GND              Ground
 A4           SDA              I2C Data
 A5           SCL              I2C Clock


****************************************************************/

#include <Wire.h>
#include <APDS9960.h>

// Global Variables
APDS9960 apds = APDS9960();
uint8_t proximity_data = 0;

void setup() {
  
  // Initialize Serial port
  Serial.begin(9600);
  Serial.println();
  Serial.println(F("------------------------------------"));
  Serial.println(F("Proximidade - APDS-9960"));
  Serial.println(F("------------------------------------"));
  
  // Initialize APDS-9960 (configure I2C and initial values)
  if ( apds.init() ) {
    Serial.println(F("Inicialização completa"));
  } else {
    Serial.println(F("Algo deu errado durante a inicialização! "));
  }
  
  // Adjust the Proximity sensor gain
  if ( !apds.setProximityGain(PGAIN_2X) ) {
    Serial.println(F("Algo deu errado ao tentar definir PGAIN "));
  }
  
  // Start running the APDS-9960 proximity sensor (no interrupts)
  if ( apds.enableProximitySensor(false) ) {
    Serial.println(F("O sensor de proximidade está funcionando"));
  } else {
    Serial.println(F("Algo deu errado durante a inicialização do sensor! "));
  }
}

void loop() {
  
  // Read the proximity value
  if ( !apds.readProximity(proximity_data) ) {
    Serial.println("Erro ao ler o valor de proximidade ");
  } else {
    Serial.print("Proximidade: ");
    Serial.println(proximity_data);
  }
  
  // Wait 250 ms before next reading
  delay(250);
}
