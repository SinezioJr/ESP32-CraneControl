#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

#define TFT_DC 2
#define TFT_CS 15
#define crane_color tft.color565(0, 255, 0)

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

void initDisplay()
{
    // Inicialização do display
    tft.begin();
    tft.setRotation(3); // Rotaciona o display para o modo paisagem
}

void drawVerticalVission()
{

    // Desenho do quadrado
    int squareX = tft.width() - 54 - 15 - 15; // Posição x do quadrado
    int squareY = tft.height() / 4 - 25 - 10; // Posição y do quadrado

    tft.fillRect(squareX, squareY, 30, tft.height() - 50, crane_color); // Base of crane

    squareX = tft.width() - 4 - 19 - 15;   // Posição x do quadrado
    squareY = tft.height() - 16 - 38 - 10; // Posição y do quadrado

    tft.fillRect(squareX, squareY, 38, 38, crane_color); // Balance of crane

    squareX = tft.width() - 42 - 150 - 15; // Posição x do quadrado
    squareY = tft.height() - 35 - 10 - 10; // Posição y do quadrado

    tft.fillRect(squareX, squareY, 170, 20, crane_color); // arm of crane
}

void drawCrane(int x, int y)
{
    // 0 > X >  89
    // 0 > Y > 128
    int squareX = tft.width() - 54 - 135 - 15;  // Posição x do quadrado
    int squareY = tft.height() - 35 - 170 - 10; // Posição y do quadrado

    tft.fillRect(squareX, squareY, 120, 160, tft.color565(0, 0, 0)); // arm of crane

    squareX = tft.width() - 54 - 135 - 15 + x;  // Posição x do quadrado
    squareY = tft.height() - 35 - 170 - 10 + y; // Posição y do quadrado

    tft.fillRect(squareX, squareY, 30, 30, tft.color565(255, 0, 0)); // arm of crane
}

void drawSuperiorVision(int angle)
{  
    int x_angle_circle = tft.width() - 50;  // Posição x do círculo
    int y_angle_circle = (tft.height())/2;  // Posição y do círculo
    int circle_radius = 30;                 // Raio do círculo

    int x1 = x_angle_circle + circle_radius*cos((270+angle)*PI/180);
    int y1 = y_angle_circle + circle_radius*sin((270+angle)*PI/180);

    tft.drawLine(x_angle_circle, y_angle_circle, x1, y1, ILI9341_WHITE);     // Desenho da linha do raio do círculo
    tft.drawCircle(x_angle_circle, y_angle_circle, circle_radius, ILI9341_WHITE);    // Desenho do círculo
}