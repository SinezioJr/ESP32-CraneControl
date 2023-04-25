#include <Arduino.h>

class Joystick
{
public:
    // Construtor
    Joystick(int pinX, int pinY) : _pinX(pinX), _pinY(pinY) {}

    // Inicialização do joystick
    void begin()
    {
        pinMode(_pinX, INPUT);
        pinMode(_pinY, INPUT);
    }

    // Leitura do valor do eixo X
    int readX()
    {
        return round(map(analogRead(_pinX), 0, 4095, -100, 100));
    }

    // Leitura do valor do eixo Y
    int readY()
    {
        return round(map(analogRead(_pinY), 0, 4095, -100, 100));
    }

private:
    int _pinX; // Porta do eixo X
    int _pinY; // Porta do eixo Y
};
