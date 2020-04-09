#include <QCoreApplication>
#include "circular_buffer.h"
#include "QDebug"
#include "circular_buffer.cpp"//QT güncelledikden sonra .h eklememe rağmen.cpp eklemeyince hata vermekte o yüzden ekli

using namespace  std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug()<<"FırAtmaca";

    qDebug()<<"İnteger İmplementation";
    circular_buffer<int> *integerBuffer=new circular_buffer<int> (); //integer türünde  buffer oluşturdum
    integerBuffer->setMaximumSize(100);                              //max size 100e ayarladım
    for (int i=0;i<120;i++) {                                        //120 eleman ekledim
        integerBuffer->set_data(i);
    }
    for(int z=0;z<5;z++) {                                         //bufferdaki en eski 5 elemanı okudum
        int c;
         c=integerBuffer->getdata();
        qDebug()<<"int number:"<<c;
    }

    qDebug()<<"Float İmplementation";

   circular_buffer<float> *floatBuffer=new circular_buffer<float>();  // float türünde buffer oluşturdum
    floatBuffer->setMaximumSize(100);                                 //max size 100e ayarladım
     float f2=0.1f;
    for (int x=0;x<120;x++) {                                          //120 eleman ekledim
        floatBuffer->set_data(f2);
        f2+=0.1f;
    }
    for(int y=0;y<5;y++) {                                             //bufferdaki en eski 5 elemanı okudum
        float d;
         d=floatBuffer->getdata();
        qDebug()<<"float number:"<<d;
    }


    qDebug()<<"firat";
    return a.exec();
}
