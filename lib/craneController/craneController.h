#ifndef CRANECONTROLLER_H
#define CRANECONTROLLER_H

struct CraneParams
{
    int X = 45;
    int Y = 90;
    int angle = 90;
};

void craneController(CraneParams *crane, int joy_X, int joy_Y, bool select);

#endif // CRANECONTROLLER_H