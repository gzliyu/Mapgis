#pragma once
#include "CGeoObject.h"
class CGeoLine :public CGeoObject
{
public:
    CGeoLine(void);
    ~CGeoLine(void);
    POINTARRAY m_line;
    bool draw(CDC* pDC);
};
