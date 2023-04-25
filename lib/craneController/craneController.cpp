
#include "craneController.h"

void craneController(CraneParams *crane, int joy_X, int joy_Y, bool select)
{
    if (select)
    {
        if (joy_X > 50)
        {
            crane->X += 1;
        }
        else if (joy_X < -50)
        {
            crane->X -= 1;
        }

        if (joy_Y > 50)
        {
            crane->Y += 1;
        }
        else if (joy_Y < -50)
        {
            crane->Y -= 1;
        }

        if (crane->X < 0)
        {
            crane->X = 0;
        }
        else if (crane->X > 89)
        {
            crane->X = 89;
        }
        if (crane->Y < 0)
        {
            crane->Y = 0;
        }
        else if (crane->Y > 128)
        {
            crane->Y = 128;
        }
    }
    else
    {

        if (joy_X > 50)
        {
            crane->angle += 1;
        }
        else if (joy_X < -50)
        {
            crane->angle -= 1;
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
