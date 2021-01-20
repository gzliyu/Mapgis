#pragma once

class CGeoObject
{
protected:
    long m_nKey;
    int m_nType;
public:
    CGeoObject(void);
    virtual ~CGeoObject(void);
    virtual bool draw(CDC* pDC);
    double *min_x, *min_y, *max_x, *max_y;
    int *width;
    int *height;
    int color[3] = { 255,0,0 };


};