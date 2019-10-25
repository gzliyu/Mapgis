#ifndef CGEOPOLYLINE_H
#define CGEOPOLYLINE_H
#include<cgeometry.h>
#include<vector>
using namespace std;
class CGeoPolyLine: public CGeometry
{
public:
    CGeoPolyLine();
    virtual ~CGeoPolyLine() override;
    virtual void Draw() override;
    int width;
    char from_name[40];
    char to_name[40];
    void addNew(pair<double,double> pr);
private:
    vector<pair<double,double>>paths;


};

#endif // CGEOPOLYLINE_H
