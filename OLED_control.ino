#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

#define OLED_RESET     -1
#define SCREEN_ADDRESS 0x3C
#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

String inputString = "";  
char inChar;      
bool stringComplete = false;
int ancho = 0, alto = 0;
int sujeto = 1; // Control del sujeto de animación

static const unsigned char PROGMEM logo1[] = {
  0b00000000, 0b10000000,
  0b00000001, 0b10000000,
  0b00111001, 0b00110000,
  0b01111111, 0b11111000,
  0b11111111, 0b11111100,
  0b11111111, 0b11111100,
  0b11111111, 0b11111000,
  0b11111111, 0b11110000,
  0b11111111, 0b11110000,
  0b11111111, 0b11110000,
  0b11111111, 0b11111000,
  0b01111111, 0b11111100,
  0b01111111, 0b11111000,
  0b00111111, 0b11110000,
  0b00001111, 0b11100000,
  0b00000000, 0b00000000
};

static const unsigned char PROGMEM logo2[] = {
  0b00000001, 0b11000000,
  0b00000110, 0b10110000,
  0b00001000, 0b10001000,
  0b00010000, 0b10000100,
  0b00100000, 0b10000010,
  0b00100001, 0b11000010,
  0b01000001, 0b11000001,
  0b01000011, 0b11100001,
  0b01000111, 0b01110001,
  0b00101100, 0b00011010,
  0b00111000, 0b00001110,
  0b00010000, 0b00000100,
  0b00001000, 0b00001000,
  0b00000110, 0b00110000, 
  0b00000001, 0b11000000,
  0b00000000, 0b00000000
};

void setup() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.clearDisplay();
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    inChar = (char)Serial.read();
    inputString += inChar;
    if (inChar == '\n') {
      stringComplete = true;
    }
  }


  if (stringComplete) {
    stringComplete = false;

    if (inputString == "1\n") {
      sujeto = 1;
      mostrarSujeto(ancho, alto, sujeto);
    }
    if (inputString == "2\n") {
      sujeto = 2;
      mostrarSujeto(ancho, alto, sujeto);
    }
    if (inputString == "3\n") {
      sujeto = 3;
      mostrarSujeto(ancho, alto, sujeto);
    }
    if (inputString == "4\n") {
      sujeto = 4;
      mostrarSujeto(ancho, alto, sujeto);
    }
    if (inputString == "a\n") {
      ancho--;
      if (ancho < 0) ancho = 0;
      mostrarSujeto(ancho, alto, sujeto);
    }
    if (inputString == "d\n") {
      ancho++;
      if (ancho > 112) ancho = 111;
      mostrarSujeto(ancho, alto, sujeto);
    }
    if (inputString == "w\n") {
      alto--;
      if (alto < 0) alto = 0;
      mostrarSujeto(ancho, alto, sujeto);
    }
    if (inputString == "s\n") {
      alto++;
      if (alto > 16) alto = 15;
      mostrarSujeto(ancho, alto, sujeto);
    }
    inputString = "";
  }
}

void mostrarSujeto(int x, int y, int tipo) {
  display.clearDisplay();
  switch (tipo) {
    case 1:
      display.drawBitmap(x, y, logo1, LOGO_WIDTH, LOGO_HEIGHT, SSD1306_WHITE);
      break;
    case 2:
      display.drawBitmap(x, y, logo2, LOGO_WIDTH, LOGO_HEIGHT, SSD1306_WHITE);
      break;
    case 3:
      mostrarMensaje("THE FUTURE", x, y);
      break;
    case 4:
      mostrarMensaje("Mercedes AMG", x, y);
      break;
  }
  display.display();
}


void mostrarMensaje(String msg, int x, int y) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(x, y); 
  display.println(msg);
  display.display();
}
