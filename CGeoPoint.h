#pragma once
#include "CGeoObject.h"

class CGeoPoint :public CGeoObject
{
public:
    CGeoPoint(void);
    ~CGeoPoint(void);
    bool draw(CDC* pDC);
    POINT m_Point;
};