#include <QCoreApplication>
#include <iostream>
#include <QDebug>
#include <QtCore>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>

using namespace std;

int main()
{

    QHash<QString, int> defaultDictTests;
        defaultDictTests.insert(QString("ph"),         1);
        defaultDictTests.insert(QString("pCO2"),       2);
        defaultDictTests.insert(QString("PO2"),        3);
        defaultDictTests.insert(QString("ctHb"),       4);
        defaultDictTests.insert(QString("SO2"),        5);
        defaultDictTests.insert(QString("Na"),         6);
        defaultDictTests.insert(QString("K"),          7);
        defaultDictTests.insert(QString("Ca"),         8);
        defaultDictTests.insert(QString("Cl"),         9);
        defaultDictTests.insert(QString("Glu"),        10);
        defaultDictTests.insert(QString("BUN/Urea"),   11);
        defaultDictTests.insert(QString("Lac"),        12);
        defaultDictTests.insert(QString("Baro"),       13);
        defaultDictTests.insert(QString("HCO3"),       14);
        defaultDictTests.insert(QString("BE"),         15);
        defaultDictTests.insert(QString("BEecf"),      16);
        defaultDictTests.insert(QString("BEact"),      17);
        defaultDictTests.insert(QString("BB"),         18);
        defaultDictTests.insert(QString("tCO2"),       19);
        defaultDictTests.insert(QString("st. HCO3-"),  20);
        defaultDictTests.insert(QString("SO2(c)"),     21);
        defaultDictTests.insert(QString("AaDO2"),      22);
        defaultDictTests.insert(QString("P50"),        23);
        defaultDictTests.insert(QString("Hct(c)"),     24);
        defaultDictTests.insert(QString("AnGap"),      25);
        defaultDictTests.insert(QString("nCa++"),      26);

        QJsonArray jsonArr;

   foreach(int element, defaultDictTests)
                {
                    QJsonObject jsonObj;
                    jsonObj.insert("testName",defaultDictTests.key(element));
                    jsonObj.insert("number",element);
                    jsonArr.append(jsonObj);
                }

   QJsonDocument json_document(jsonArr);
   QString json_string = json_document.toJson();

   QFile fileTest("D:/fileTest.txt");
   if (!fileTest.open(QIODevice::WriteOnly | QIODevice::Text))
   {
       qDebug() << "Write error";
   }
   else
   {
       QTextStream writeStream(&fileTest);
       writeStream << json_string;
       fileTest.close();
       qDebug() << "Write completed";
   }

    return 0;
}
