#include "cgeopolygon.h"

CGeoPolygon::CGeoPolygon()
{

}
CGeoPolygon::~CGeoPolygon()
{

}
void CGeoPolygon::Draw()
{

}
void CGeoPolygon::addNew(pair<double, double> pr)
{
    this->cordnates.push_back((pr));
}
