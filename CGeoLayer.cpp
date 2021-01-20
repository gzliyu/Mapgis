#include "pch.h"
#include "CGeoLayer.h"
#include "clipper.hpp"
using namespace ClipperLib;
CGeoLayer::CGeoLayer(void)
{
	m_ObjectNum = 0;
}

CGeoLayer::CGeoLayer(CGeoMap* ptMap)
{
	m_ptMap = ptMap;
	m_ObjectNum = 0;
}

CGeoLayer::~CGeoLayer(void)
{
}

void CGeoLayer::SetLayerName(std::string strLayerName)
{
	m_strLayerName = strLayerName;
}

void CGeoLayer::AddPoly(int nArc, INTARRAY& numArray, POINTARRAY& ptArray)
{
	CGeoPoly* pPoly = new CGeoPoly;

	pPoly->SetData(ptArray.size() - 1, numArray, ptArray);
	//pPoly->setLayer(this);
	pPoly->height = height;
	pPoly->width = width;
	pPoly->max_x = &max_x;
	pPoly->max_y = &max_y;
	pPoly->min_x = &min_x;
	pPoly->min_y = &min_y;
	pPoly->m_nKey = m_ObjectNum++;

	m_nPolyArray.push_back(pPoly);
}

void CGeoLayer::AddPoly(CGeoPoly* ptPoly)
{
	m_nPolyArray.push_back(ptPoly);
}

bool CGeoLayer::setColor(int red, int green, int blue)
{
	for (std::vector<CGeoPoint*>::const_iterator iter = m_nPointArray.begin(); iter != m_nPointArray.end(); iter++) {
		(*iter)->color[0] = red;
		(*iter)->color[1] = green;
		(*iter)->color[2] = blue;

	}
	for (std::vector<CGeoLine*>::const_iterator iter = m_nLineArray.begin(); iter != m_nLineArray.end(); iter++) {
		(*iter)->color[0] = red;
		(*iter)->color[1] = green;
		(*iter)->color[2] = blue;
	}
	for (std::vector<CGeoPoly*>::const_iterator iter = m_nPolyArray.begin(); iter != m_nPolyArray.end(); iter++) {
		(*iter)->color[0] = red;
		(*iter)->color[1] = green;
		(*iter)->color[2] = blue;
	}
	return true;
}

bool CGeoLayer::drawLayer(CDC* pDC)
{
	for (std::vector<CGeoPoint*>::const_iterator iter = m_nPointArray.begin(); iter != m_nPointArray.end(); iter++) {
		(*iter)->draw(pDC);
	}
	for (std::vector<CGeoLine*>::const_iterator iter = m_nLineArray.begin(); iter != m_nLineArray.end(); iter++) {
		(*iter)->draw(pDC);
	}
	for (std::vector<CGeoPoly*>::const_iterator iter = m_nPolyArray.begin(); iter != m_nPolyArray.end(); iter++) {
		(*iter)->draw(pDC);
	}
	return true;
}
void addpaths(INTARRAY arr, Paths& ps)
{
	Path p;
	for (int i = 0; i < arr.size(); i++)
	{
		IntPoint ip;
		ip.X = arr[i].x;
		ip.Y = arr[i].y;
		p.push_back(ip);
	}
	ps.push_back(p);

}
CGeoLayer* CGeoLayer::overlay(long SubKey, long ClipKey, int option)
{
	CGeoPoly* ptrsub = m_nPolyArray[SubKey];
	CGeoPoly* ptrClip = m_nPolyArray[ClipKey];




	INTARRAY numArr;
	POINTARRAY pArr;
	int nArc;

	Paths subj;
	ptrsub->GetData(nArc, numArr, pArr);
	addpaths(numArr, subj);

	Paths clip;
	ptrClip->GetData(nArc, numArr, pArr);
	addpaths(numArr, clip);

	Clipper c;
	c.AddPaths(subj, ptSubject, true);
	c.AddPaths(clip, ptClip, true);
	Paths solution;
	switch (option)
	{
	case 3:
		c.Execute(ctIntersection, solution, pftNonZero, pftNonZero);
	case 1:
		c.Execute(ctDifference, solution, pftNonZero, pftNonZero);
	case 2:
		c.Execute(ctUnion, solution, pftNonZero, pftNonZero);
	case 4:
		c.Execute(ctXor, solution, pftNonZero, pftNonZero);
	}




	CGeoLayer* pLayer = new CGeoLayer;
	pLayer->SetLayerName("Overlay Result");


	pLayer->min_x = *ptrsub->min_x;
	pLayer->min_y = *ptrsub->min_y;
	pLayer->max_x = *ptrsub->max_x;
	pLayer->max_y = *ptrsub->max_y;

	pLayer->height = ptrsub->height;
	pLayer->width = ptrsub->width;


	double cx, cy, x1, y1, x2, y2;
	cx = (pLayer->min_x + pLayer->max_x) / 2;
	cy = (pLayer->min_y + pLayer->max_y) / 2;
	int scale = 1000;
	x1 = scale * (pLayer->min_x - cx);
	y1 = scale * (pLayer->min_y - cy);
	x2 = scale * (pLayer->max_x - cx);
	y2 = scale * (pLayer->max_y - cy);


	
	for (unsigned i = 0; i < solution.size(); i++)
	{
		INTARRAY numArr;
		POINTARRAY pArr;
		int nArc;
		Path p3 = solution.at(i);

		for (unsigned j = 0; j < p3.size(); j++)
		{
			IntPoint ip = p3.at(j);
			printf("%d = %lld, %lld\n", j, ip.X, ip.Y);

			POINT p;
			p.x = ip.X;
			p.y = ip.Y;
			numArr.push_back(p);

			double x, y;
			x = cx + (double(x2 - x1) / double(scale)) * double(double(ip.X) / double(*pLayer->width));
			y = cy + (double(y2 - y1) / double(scale)) * double(double(ip.Y) / double(*pLayer->height));

			DPOINT dp;
			dp.x = x;
			dp.y = y;
			pArr.push_back(dp);
		}

		CGeoPoly* ptPoly = new CGeoPoly;
		ptPoly->color[0] = 255;
		ptPoly->color[1] = 255;
		ptPoly->color[2] = 0;

		pLayer->AddPoly(p3.size() - 1, numArr, pArr);

	}


	return pLayer;
}
