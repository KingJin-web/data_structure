#ifndef CIRCLE_H //这个名字也可以自定义
#define CIRCLE_H
class Arrays
{
private:
    /* data */
public:
    Arrays(/* args */);
    ~Arrays();
    void toString(int arr[]);
};

Arrays::Arrays(/* args */)
{
}

Arrays::~Arrays()
{
}

Arrays::toString(int arr[]){
    int length = sizeof(arr) / sizeof(int);
    printf("[");
    for (int i = 0; i < length - 1; i++)
    {
        printf("%d,", arr[i]);
    }
    printf("%d]\n", arr[length - 1]);
}

#endif
