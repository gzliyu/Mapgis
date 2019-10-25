#include "cgeolayers.h"
#include<vector>
using namespace std;
CGeoLayers::CGeoLayers()
{

}
CGeoLayers::~CGeoLayers()
{

}
void CGeoLayers::show()
{

}
void CGeoLayers::addNew(CGeometry gmtry)
{
    this->geometry.push_back(gmtry);
}
