#ifndef CGEOPOLYGON_H
#define CGEOPOLYGON_H
#include"cgeometry.h"
#include<vector>
using namespace std;
class CGeoPolygon : public CGeometry
{
public:
    CGeoPolygon();
    virtual ~CGeoPolygon() override;
    virtual void Draw() override;

    void addNew(pair<double,double>pr);
private:
    vector<pair<double,double>>cordnates;
    double area;
    double perimeter;

};

#endif // CGEOPOLYGON_H
