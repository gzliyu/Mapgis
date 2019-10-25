#ifndef CGEOLAYERS_H
#define CGEOLAYERS_H
#include<cgeometry.h>
#include<vector>
using namespace std;
class CGeoLayers
{
public:
    CGeoLayers();
    vector<CGeometry>Geometry;
    virtual void show();
    virtual ~CGeoLayers();
    void addNew(CGeometry);
private:
    vector<CGeometry>geometry;


};

#endif // CGEOLAYERS_H
