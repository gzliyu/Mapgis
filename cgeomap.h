#pragma once
#include<vector>

#include"CGeoLayer.h"
#include<fstream>
#include"CDlgOverlay.h"
class CGeoMap
{
//private:
//    /* data */
public:
    CGeoMap(void);
    ~CGeoMap();
    std::vector<CGeoLayer*> m_LayerArray;
    int* nWidth, * nHeight;
    long m_nNum;
    long m_nLayerNum;
    long m_nObjectNum;
    bool m_bSelected;
    bool ReadData(const char* filename);
    void Draw(CDC* pDC);
    long NewKey();
    DPOINT m_ptCenter;
    double m_dScale;
    double read_double(std::ifstream* ifptr);
    int read_int(std::ifstream* ifptr);
    bool overlay(long SubKey, long ClipKey, int option);
    bool overlay(CDlgOverlay* ptdlg);
    CGeoLayer* AddLayer();
    void AddLayer(CGeoLayer* pLayer);

};

