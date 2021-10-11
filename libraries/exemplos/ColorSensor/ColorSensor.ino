/****************************************************************
 
Testa as habilidades de detecção de cor e luz ambiente do
APDS-9960. Configura APDS-9960 em I2C e consulta o sensor para
luz ambiente e níveis de cor, que são exibidos sobre o
console serial. 

****************************************************************/

#include <Wire.h>
#include <APDS9960.h>

// Global Variables
APDS9960 apds = APDS9960();
uint16_t ambient_light = 0;
uint16_t red_light = 0;
uint16_t green_light = 0;
uint16_t blue_light = 0;

void setup() {
  
  // Initialize Serial port
  Serial.begin(9600);
  Serial.println();
  Serial.println(F("--------------------------------"));
  Serial.println(F("APDS-9960 - Sensor de cor"));
  Serial.println(F("--------------------------------"));
  
  // Initialize APDS-9960 (configure I2C and initial values)
  if ( apds.init() ) {
    Serial.println(F("Inicialização do APDS-9960 concluída "));
  } else {
    Serial.println(F("Algo deu errado durante a inicialização do APDS-9960! "));
  }
  
  // Start running the APDS-9960 light sensor (no interrupts)
  if ( apds.enableLightSensor(false) ) {
    Serial.println(F("O sensor de luz está funcionando "));
  } else {
    Serial.println(F("Algo deu errado durante a inicialização do sensor de luz!"));
  }
  
  // Wait for initialization and calibration to finish
  delay(500);
}

void loop() {
  
  // Read the light levels (ambient, red, green, blue)
  if (  !apds.readAmbientLight(ambient_light) ||
        !apds.readRedLight(red_light) ||
        !apds.readGreenLight(green_light) ||
        !apds.readBlueLight(blue_light) ) {
    Serial.println("Erro ao ler valores de luz ");
  } else {
    Serial.print("Ambiente: ");
    Serial.print(ambient_light);
    Serial.print(" Vermelho: ");
    Serial.print(red_light);
    Serial.print(" Verde: ");
    Serial.print(green_light);
    Serial.print(" Azul: ");
    Serial.println(blue_light);
  }
  
  // Wait 1 second before next reading
  delay(1000);
}
