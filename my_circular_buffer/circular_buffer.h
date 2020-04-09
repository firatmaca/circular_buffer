#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H



template<class Type>
class circular_buffer
{
public:
    circular_buffer();
    Type getdata();
     void setMaximumSize(int);
    void set_data(Type);
    int front;
    int rear;
    int numberofcaount;
    bool isempty();
    bool isfull();
    int currunt_count();
private:
    Type *buff;
    int max_size;
};


#endif // CIRCULAR_BUFFER_H
