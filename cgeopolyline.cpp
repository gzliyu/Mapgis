#include "cgeopolyline.h"
#include<vector>


using namespace std;
CGeoPolyLine::CGeoPolyLine()
{

}
CGeoPolyLine::~CGeoPolyLine()
{

}
void CGeoPolyLine::Draw()
{

    for(vector<pair<double,double>>::iterator it;it!=this->paths.begin();it++)
    {


    }

}

void CGeoPolyLine::addNew(pair<double,double> pr)
{
    this->paths.push_back((pr));
}
