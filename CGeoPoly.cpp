#include "pch.h"
#include "CGeoPoly.h"

CGeoPoly::CGeoPoly(void)
{
    m_nType = 2;
    m_nKey = -1;
    m_nPoint = new POINT;
    m_bSelected = false;
    //m_ptGeoLayer = nullptr;
}


CGeoPoly::~CGeoPoly(void)
{
}

void CGeoPoly::SetData(int nArc, INTARRAY& numArray, POINTARRAY& ptArray)
{
    m_nArc = nArc;
    m_numArray.assign(numArray.begin(), numArray.end());
    m_ptArray.assign(ptArray.begin(), ptArray.end());
    m_nKey = 0;
    //m_numArray.Copy(numArray);
    //m_ptArray.Copy(ptArray);
}


void CGeoPoly::GetData(int& nArc, INTARRAY& numArray, POINTARRAY& ptArray)
{
    nArc = m_nArc;


    m_numArray.clear();
    for (POINTARRAY::const_iterator iter = m_ptArray.begin(); iter != m_ptArray.end(); iter++) {
        double x, y, cx, cy;
        x = (*iter).x;
        y = (*iter).y;
        cx = (*min_x + *max_x) / 2;
        cy = (*min_y + *max_y) / 2;

        int scale = 1000;


        double x1 = scale * (*min_x - cx);
        double y1 = scale * (*min_y - cy);
        double x2 = scale * (*max_x - cx);
        double y2 = scale * (*max_y - cy);



        int sx = *width * (scale * (x - cx)) / (x2 - x1);
        int sy = *height * (scale * (y - cy)) / (y2 - y1);
        POINT p;
        p.x = sx;
        p.y = sy;
        m_numArray.push_back(p);
    }


    numArray.assign(m_numArray.begin(), m_numArray.end());
    ptArray.assign(m_ptArray.begin(), m_ptArray.end());

}

ScreenXY CGeoPoly::transformxy()
{
    CPoint* sxy = new CPoint[m_nArc];
    return sxy;
}

bool CGeoPoly::draw(CDC* pDC)
{

    //ScreenXY sxy = transformxy();


    POINT* sxy = new POINT[m_nArc];
    int cnt = 0;
    for (POINTARRAY::const_iterator iter = m_ptArray.begin(); iter != m_ptArray.end(); iter++) {
        double x, y, cx, cy;
        x = (*iter).x;
        y = (*iter).y;
        cx = (*min_x + *max_x) / 2;
        cy = (*min_y + *max_y) / 2;

        int scale = 1000;


        double x1 = scale * (*min_x - cx);
        double y1 = scale * (*min_y - cy);
        double x2 = scale * (*max_x - cx);
        double y2 = scale * (*max_y - cy);



        int sx = *width * (scale * (x - cx)) / (x2 - x1);
        int sy = *height * (scale * (y - cy)) / (y2 - y1);
        sxy[cnt].x = sx;
        sxy[cnt].y = sy;
        cnt++;

    }

    CPen Pen;
    Pen.CreatePen(PS_SOLID, 5, RGB(color[0],color[1],color[2]));
    CBrush brushColor(RGB(color[0], color[1], color[2]));

    CPen* oldPen = pDC->SelectObject(&Pen);
    CBrush* poldBrush = pDC->SelectObject(&brushColor);
    


    pDC->PolyPolygon(sxy, &m_nArc, 1);

    pDC->SelectObject(&poldBrush);

    for (int i = 0; i < m_nArc; i++) {
        CString str;
        str.Format(_T("%d"), m_nKey);
        pDC->TextOut(sxy->x, sxy->y, str);
    }

    return true;
}
