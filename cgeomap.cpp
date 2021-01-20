#include "pch.h"
#include "CGeoMap.h"
#include "CGeoLayer.h"

#include<iostream>
CGeoMap::CGeoMap(void)
{
    m_nObjectNum = 0;
    m_nLayerNum = 0;
    m_dScale = 1000;
}

CGeoMap::~CGeoMap()
{
}

double CGeoMap::read_double(std::ifstream* ifptr)
{
    std::string str;
    (*ifptr) >> str;
    return atof(str.c_str());
}

int CGeoMap::read_int(std::ifstream* ifptr)
{
    std::string str;
    (*ifptr) >> str;
    return atoi(str.c_str());
}

bool CGeoMap::overlay(long SubKey, long ClipKey, int option)
{
    int nLayerNum = m_LayerArray.size();
    if (!nLayerNum)
    {
        return false;
    }
    CGeoLayer* pLayer = m_LayerArray[0];
    CGeoLayer* presLayer = pLayer->overlay(SubKey, ClipKey, option);
    AddLayer(presLayer);
    pLayer->ifdraw = FALSE;
    return true;

}

bool CGeoMap::overlay(CDlgOverlay* ptdlg)
{
    overlay(ptdlg->m_SubKey, ptdlg->m_ClipKey, ptdlg->m_Select);
    m_LayerArray[1]->setColor(ptdlg->red, ptdlg->green, ptdlg->blue);
    return true;
}

bool CGeoMap::ReadData(const char* filename)
{
    CGeoLayer* pLayer = AddLayer();
    pLayer->SetLayerName("hhh");
    std::ifstream infile;
    infile.open(filename, std::ios::in);
    //double min_x, min_y, max_x, max_y;
    pLayer->min_x = read_double(&infile);
    pLayer->min_y = read_double(&infile);
    pLayer->max_x = read_double(&infile);
    pLayer->max_y = read_double(&infile);

    pLayer->height = nHeight;
    pLayer->width = nWidth;
    while (!infile.eof() && infile.good()) {
        int num = read_int(&infile);
        INTARRAY* numArray = new INTARRAY;
        POINTARRAY* ptArray = new POINTARRAY;
        for (int i = 0; i < num; i++) {
            DPOINT p;
            p.x = read_double(&infile);
            p.y = read_double(&infile);

            (*ptArray).push_back(p);
        }
        pLayer->AddPoly(num - 1, *numArray, *ptArray);
    }
    return true;
}
long CGeoMap::NewKey()
{
    return m_nObjectNum++;
}

CGeoLayer* CGeoMap::AddLayer()
{
    CGeoLayer* pLayer = new CGeoLayer;
    pLayer->m_nID = m_nLayerNum++;
    m_LayerArray.push_back(pLayer);
    m_nLayerNum = m_LayerArray.size();
    return pLayer;
}

void CGeoMap::AddLayer(CGeoLayer* pLayer)
{
    pLayer->m_nID = m_nLayerNum++;
    m_LayerArray.push_back(pLayer);
    m_nLayerNum = m_LayerArray.size();
}

void CGeoMap::Draw(CDC* pDC)
{
    if (!m_LayerArray.size()) {
        AfxMessageBox(_T("NO DATA!"));
        return;
    }
    if (m_LayerArray.size() == 2) {
        printf("yes!!!");
    }
    for (std::vector<CGeoLayer*>::const_iterator iter = m_LayerArray.begin(); iter != m_LayerArray.end(); iter++) {
        if ((*iter)->ifdraw) {
            (*iter)->drawLayer(pDC);
        } 
    }
}
