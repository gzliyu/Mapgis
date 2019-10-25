#ifndef CGEOMAP_H
#define CGEOMAP_H
#include<cgeolayers.h>
#include<vector>
using namespace std;
class CGeoMap
{
public:
    CGeoMap();
    vector<CGeoLayers>Layers;
    virtual void show();
    virtual ~CGeoMap();
};

#endif // CGEOMAP_H
