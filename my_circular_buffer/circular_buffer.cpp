#include "circular_buffer.h"
#include "QDebug"


template<class Type>
circular_buffer<Type>::circular_buffer() //bufferı initilaze etmek için
{

  buff=new Type[max_size];
  rear=-1;
  front=0;
  numberofcaount=0;
}

template<class Type>
void circular_buffer<Type>::setMaximumSize(int a){ //  max size ayarlamak için
  max_size=a;
}

template<class Type>
int circular_buffer<Type>::currunt_count(){ //bufferda kaç eleman olduğunu konrol etmek için
    return numberofcaount;
}

template<class Type>
bool circular_buffer<Type>::isempty(){ //boşmu diye kontrol etmek için
    return (currunt_count()==0);
}

template<class Type>
bool circular_buffer<Type>::isfull(){  //dolumu diye kontrol etmek için
    return (currunt_count()==max_size);
}

template<class Type>
void circular_buffer<Type>::set_data(Type item){  // bufera eleman eklemek için

    rear++;
    rear=rear%max_size;
    buff[rear]=item;

    if(isfull()==1){               // eğer buffer doluysa ve yeni eleman eklendiyse
        front=(front+1)%max_size;  //okunma adresini bufferdaki en eski elemanın adresine çekitm
    }
    else {
       numberofcaount++;
    }
}
template<class Type>
Type circular_buffer<Type>::getdata(){  //buferdan verileri okumak için
    if(isempty()==1){
        qDebug()<<"buffer boş";
    }
    Type returned_value;
    returned_value=buff[front];
    front++;
    front=front%max_size;
    numberofcaount--;
    return returned_value;
}
