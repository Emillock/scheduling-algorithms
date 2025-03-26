//
// Created by User on 26.03.2025.
//

#ifndef UNTITLED3_ROUND_FUNC_H
#define UNTITLED3_ROUND_FUNC_H

float round2D(float var)
{
    float value = (int)(var * 100 + .5);
    return (float)value / 100;
}

#endif //UNTITLED3_ROUND_FUNC_H
