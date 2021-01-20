#pragma once
#include "CGeoObject.h"
class CGeoPoly :public CGeoObject
{
private:
    int m_nArc = 0;

    int* m_pNum;
    POINT* m_nPoint;
    INTARRAY m_numArray;
    POINTARRAY m_ptArray;

public:
    CGeoPoly(void);
    
    ~CGeoPoly(void);
    long m_nKey = 0;
    bool m_bSelected;
    bool draw(CDC* pDC);
    ScreenXY transformxy();
    void SetData(int nArc, INTARRAY& numArray, POINTARRAY& ptArray);
    void GetData(int& nArc, INTARRAY& numArray, POINTARRAY& ptArray);


};
