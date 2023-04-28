#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

MCUFRIEND_kbv tft;

void initDisplay()
{
    // Inicialização do display
    tft.reset();
    tft.begin(0x9341);
    tft.setRotation(3);
    tft.fillScreen(BLACK);
    tft.setTextSize(2);
    tft.setTextColor(WHITE);
}

void drawVerticalVision()
{    
    // Desenho do quadrado
    int squareX = tft.width() - 54 - 15 - 15; // Posição x do quadrado
    int squareY = tft.height() / 4; // Posição y do quadrado

    tft.fillRect(squareX, squareY, 30, tft.height() - 80, GREEN); // Base of crane

    squareX = tft.width() - 4 - 19 - 15;   // Posição x do quadrado
    squareY = tft.height() / 3 - 5; // Posição y do quadrado

    tft.fillRect(squareX, squareY, 38, 38, GREEN); // Balance of crane

    squareX = tft.width() - 42 - 150 - 15; // Posição x do quadrado
    squareY = tft.height() / 3 - 5; // Posição y do quadrado

    tft.fillRect(squareX, squareY, 170, 20, GREEN); // arm of crane
}

void drawCrane(int x, int y)
{
    int squareX = tft.width() - 54 - 135 - 15;  // Posição x do quadrado
    int squareY = tft.height() - 35 - 170 - 10; // Posição y do quadrado

    squareX = tft.width() - 54 - 135 - 15 + x;  // Posição x do quadrado
    squareY = tft.height() - 35 - 170 - 10 + y; // Posição y do quadrado

    tft.fillRect(squareX+15, tft.height()/3-5, 5, squareY-45, MAGENTA); // arm of crane

    tft.fillRect(squareX, squareY, 30, 30, MAGENTA); // crane
}

void drawSuperiorVision(int angle)
{
    int x_angle_circle = tft.width() - 250;  // Posição x do círculo
    int y_angle_circle = (tft.height()) / 2; // Posição y do círculo

    int circle_radius = 30;                  // Raio do círculo

    int x1 = x_angle_circle + circle_radius * cos((270 + angle) * PI / 180);
    int y1 = y_angle_circle + circle_radius * sin((270 + angle) * PI / 180);

    tft.drawLine(x_angle_circle, y_angle_circle, x1, y1, GREEN);          // Desenho da linha do raio do círculo
    tft.drawCircle(x_angle_circle, y_angle_circle, circle_radius, GREEN); // Desenho do círculo
}

void drawSuperiorCrane(int angle)
{
    int x_angle_circle = tft.width() - 250;  // Posição x do círculo
    int y_angle_circle = (tft.height()) / 2; // Posição y do círculo
    int circle_radius = 29;                  // Raio do círculo

    int x1 = x_angle_circle + circle_radius * cos((90 + angle) * PI / 180);
    int y1 = y_angle_circle + circle_radius * sin((90 + angle) * PI / 180);
    tft.fillCircle(x_angle_circle, y_angle_circle, circle_radius, BLACK); // Desenho do círculo

    tft.drawLine(x_angle_circle, y_angle_circle, x1, y1, WHITE); // Desenho da linha do raio do círculo
}

void showInfo(int x, int y, int angle, bool selectFlag)
{
    tft.setCursor(40, 40);
    tft.print("X: ");
    tft.print(x);
    tft.print(" Y: ");
    tft.print(y);
    tft.print(" A: ");
    tft.print(angle);
    if(selectFlag) tft.print(" S: C"); else tft.print(" S: R");
}
