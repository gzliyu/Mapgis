#include "cfile.h"
#include <QDir>
#include <QCoreApplication>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonValue>
#include <QString>
#include <QDebug>
#include <QFile>
#include<cgeopolyline.h>
#include<cgeolayers.h>
#include<cgeopolygon.h>
using namespace std;
CFile::CFile()
{

}
bool CFile::LoadFile()
{
    QFile file(QDir::homePath() + "/testJson.json");
    if(!file.open(QIODevice::ReadWrite)) {
            qDebug() << "File open error";
        }
    QString val=file.readAll();
    file.close();
    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject d_object = d.object();
    QJsonValue fields = d_object.value(QString("features"));
    QJsonArray arr_fileds=fields.toArray();
    CGeoLayers *geolay = new CGeoLayers;
    for(QJsonArray::iterator it=arr_fileds.begin();it!=arr_fileds.end();it++)
    {
        CGeoPolygon *geoplygon = new CGeoPolygon;
        QJsonObject line=(*it).toObject();
        QJsonObject line_attribu=line.value(QString("attributes")).toObject();
        QJsonObject line_geometry=line.value(QString("geometry")).toObject();
        QJsonArray line_paths=line_geometry.value(QString("coordinates")).toArray();
        foreach (const QJsonValue& i, line_paths) {
            foreach(const QJsonValue& j,i.toArray()){
                pair<double,double>pr;
                pr.first=j.toArray().at(0).toDouble();
                pr.second=j.toArray().at(1).toDouble();
                geoplygon->addNew((pr));
            }
        }
        geolay->addNew(*geoplygon);
    }
    return true;
}
