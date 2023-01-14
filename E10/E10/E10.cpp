#include<string.h>
#include <iostream>
using namespace std;
int re(int a[], int num,int size);
int n(char a[], char b[]);
void op(int *a, int size);
int nose(int a[], int size, int num);
int main()
{
    int a[] = { 1,2,3,4,5,6,7};
    int size = sizeof(a) / sizeof(a[0]);

  


    
}

void op(int *a,int size)
{
    if (size <=1)
    {
        return ;
    }
    else
    {
        int n=a[0];
        a[0] = a[size - 1];
        a[size - 1] = n;
        return op(a+1, size - 2);
    }
    


}
int n(char a[], char b[])
{
    if (a[0] == '\0' || b[0] == '\0')
    {
        return 0;
    }
    if (a[0] == b[0])
    {
        return 1 + n(a+1, b+1);
    }
    else
    {
        return n(a+1, b+1);
    }
    

    


}




int re(int a[], int num,int size)
{
    if (size < 0)
    {
        return 0;
    }
    if (a[size-1] == num)
    {
        return 1 + re(a, num, size - 1);
    }
    else
    {
        return re(a, num, size - 1);
    }
   

}