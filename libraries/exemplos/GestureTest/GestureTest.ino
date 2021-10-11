/****************************************************************

Testa as habilidades de detecção de gestos do APDS-9960. Configura
APDS-9960 sobre I2C e espera por eventos de gesto. Calcula o
direção do deslize (para cima, para baixo, para a esquerda, para a direita) e exibe-o
em um console serial.

Para realizar um gesto PRÓXIMO, segure sua mão
muito acima do sensor e mova-o para perto do sensor (dentro de 2
polegadas). Mantenha sua mão lá por pelo menos 1 segundo e mova-a
longe.

Para realizar um gesto distante, segure sua mão a 2 polegadas do
sensor por pelo menos 1 segundo e, em seguida, mova-o para cima (para fora do
faixa) do sensor. 

****************************************************************/

#include <Wire.h>
#include <APDS9960.h>

// Pins on wemos D1 mini
#define APDS9960_SDA    4  //GPIO4 (D2)
#define APDS9960_SCL    5  //GPIO5 (D1)
// Constants
const byte APDS9960_INT  = 12; //GPIO12 (D6)

// Global Variables
APDS9960 apds = APDS9960();
volatile bool isr_flag = 0;

//Interrupt callback function in IRAM
void ICACHE_RAM_ATTR interruptRoutine ();

void setup() {
   //Start I2C with pins defined above
  Wire.begin(APDS9960_SDA,APDS9960_SCL);

  // Set interrupt pin as input
  pinMode(digitalPinToInterrupt(APDS9960_INT), INPUT);

  // Initialize Serial port
  Serial.begin(115200);
  Serial.println();
  Serial.println(F("--------------------------------"));
  Serial.println(F("APDS-9960 - Testes de gestos"));
  Serial.println(F("--------------------------------"));
  
  // Initialize interrupt service routine
  attachInterrupt(digitalPinToInterrupt(APDS9960_INT), interruptRoutine, FALLING);

  // Initialize APDS-9960 (configure I2C and initial values)
  if ( apds.init() ) {
    Serial.println(F("Inicialização do APDS-9960 concluída "));
  } else {
    Serial.println(F("Algo deu errado durante o init APDS-9960! "));
  }
  
  // Start running the APDS-9960 gesture sensor engine
  if ( apds.enableGestureSensor(true) ) {
    Serial.println(F("O sensor de gestos está funcionando"));
  } else {
    Serial.println(F("Algo deu errado durante a inicialização do sensor de gestos!"));
  }
}

void loop() {
  if( isr_flag == 1 ) {
    detachInterrupt(digitalPinToInterrupt(APDS9960_INT));
    handleGesture();
    isr_flag = 0;
    attachInterrupt(digitalPinToInterrupt(APDS9960_INT), interruptRoutine, FALLING);
  }
}

void interruptRoutine() {
  isr_flag = 1;
}

void handleGesture() {
    if ( apds.isGestureAvailable() ) {
    switch ( apds.readGesture() ) {
      case DIR_UP:
        Serial.println("UP");
        break;
      case DIR_DOWN:
        Serial.println("DOWN");
        break;
      case DIR_LEFT:
        Serial.println("LEFT");
        break;
      case DIR_RIGHT:
        Serial.println("RIGHT");
        break;
      case DIR_NEAR:
        Serial.println("NEAR");
        break;
      case DIR_FAR:
        Serial.println("FAR");
        break;
      default:
        Serial.println("NONE");
    }
  }
}
