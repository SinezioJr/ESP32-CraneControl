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
        return analogRead(_pinX);
    }

    // Leitura do valor do eixo Y
    int readY()
    {
        return analogRead(_pinY);
    }

private:
    int _pinX; // Porta do eixo X
    int _pinY; // Porta do eixo Y
};
