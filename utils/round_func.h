//
// Created by User on 26.03.2025.
//

#ifndef UNTITLED3_ROUND_FUNC_H
#define UNTITLED3_ROUND_FUNC_H

float round2D(float var)
{
    // 37.66666 * 100 =3766.66
    // 3766.66 + .5 =3767.16    for rounding off value
    // then type cast to int so value is 3767
    // then divided by 100 so the value converted into 37.67
    float value = (int)(var * 100 + .5);
    return (float)value / 100;
}

#endif //UNTITLED3_ROUND_FUNC_H
