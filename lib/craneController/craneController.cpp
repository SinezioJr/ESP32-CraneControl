
#include "craneController.h"

void craneController(CraneParams *crane, int joy_X, int joy_Y, bool select)
{
    if (select)
    {
        if (joy_X > 50)
        {
            crane->X += 5;
        }
        else if (joy_X < -50)
        {
            crane->X -= 5;
        }

        if (joy_Y > 50)
        {
            // crane->Y += 5;
            crane->Y = 90;
        }
        else if (joy_Y < -50)
        {
            crane->Y = 90;
        }

        if (crane->X < 0)
        {
            crane->X = 0;
        }
        else if (crane->X > 89)
        {
            crane->X = 89;
        }
        if (crane->Y < 30)
        {
            crane->Y = 30;
        }
        else if (crane->Y > 140)
        {
            crane->Y = 140;
        }
    }
    else
    {

        if (joy_X > 50)
        {
            crane->angle += 5;
        }
        else if (joy_X < -50)
        {
            crane->angle -= 5;
        }

        if (crane->angle < 0)
        {
            crane->angle = 0;
        }
        else if (crane->angle > 360)
        {
            crane->angle = 360;
        }
    }
}
