#pragma once
#include<vector>
#include"CGeoPoint.h"
#include"CGeoLine.h"
#include"CGeoPoly.h"
#include<string>
#include "clipper.hpp"
//
class CGeoMap;

class CGeoLayer
{
//data
protected:
	std::string m_strLayerName;
	std::vector<CGeoPoint*>m_nPointArray;
	std::vector<CGeoPoly*>m_nPolyArray;
	std::vector<CGeoLine*>m_nLineArray;
	CGeoMap* m_ptMap;
public:
	CGeoLayer(void);
	CGeoLayer(CGeoMap* ptMap);	
	~CGeoLayer(void);
	long m_nID;
	long m_ObjectNum;
	double min_x, min_y, max_x, max_y;
	int *width, *height;
	bool ifdraw=TRUE;

	void SetLayerName(std::string strLayerName);
	void AddPoly(int nArc, INTARRAY& numArray, POINTARRAY& ptArray);
	void AddPoly(CGeoPoly* ptPoly);
	bool setColor(int red, int green, int blue);
	bool drawLayer(CDC* pDC);
	CGeoLayer* overlay(long SubKey, long ClipKey, int option);
};

