#ifndef CGEOMETRY_H
#define CGEOMETRY_H
#include<vector>
#include<string>
using namespace std;

class CGeometry
{
public:
    CGeometry();
    virtual ~CGeometry(void);
    virtual void Draw(void);
    string name;
private:
    int dimension;
};

#endif // CGEOMETRY_H
