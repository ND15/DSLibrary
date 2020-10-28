#include "Array.h"
#include <iostream>
using namespace std;

Array::Array()
{
    size = 10;
    length = 0;
    A = new int[size];
}

Array::Array(int sz)
{
    size = sz;
    length = 0;
    A = new int[size];
}

Array::~Array()
{
    delete []A;
}

void Array :: Display()
{
    int i;
    cout<<"Elements: "<<endl;
    for(i =0;i<length;i++)
    {
        cout<<A[i]<<endl;
    }
}

void Array::Insert(int index,int x)
{
    int i=0;
    if(index>=0 && index<=length)
    {
        for (i = length; i>index ; i--)
        {
            A[i] = A[i-1];
        }
        A[index] = x;
        length++;
    }
}
void Array ::Append(int x)
{
    if(length<size)
    {
        A[length++] = x;
    }
}

int Array::Delete(int index)
{
    int x,i=0;
    x = A[index];
    if(index>=0 && index<length)
    {
        for (i = 0; i <length-1; i++)
        {
            A[i] = A[i+1];
        }
        length--;
        return x;
    }
}

int Array::LinearSearch(int key)
{
    int i;
    for (i = 0; i < length; i++)
    {
        if (A[i]==key)
        {
            return i;
        }
        return -1;
    }
}

int Array::BinarySearh(int key)
{
    int l,h,mid;
    l=0;
    h=length-1;
    while (l<=h)
    {
        mid = (l+h)/2;
        if(key == A[mid])
        {
            return mid;
        }
        else if(key<A[mid])
        {
            h=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return -1;
}

int Array::Get(int index)
{
    if (index>=0 && index<length)
    {
        return A[index];
    }
    return -1;
}

void Array::Set(int index, int x)
{
    if(index>=0 && index<length)
    {
        A[index] = x;
    }
}

int Array::Max()
{
    int max;
    max=A[0];
    for (int i = 1; i < length; i++)
    {
        if(A[i]>max)
        {
            max = A[i];
        }
    }
    return max;
}

int Array::Min()
{
    int min;
    min=A[0];
    for (int i = 1; i < length; i++)
    {
        if(A[i]<min)
        {
            min = A[i];
        }
    }
    return min;
}

int Array::Sum()
{
    int s=0;
    for (int i = 0; i < length; i++)
    {
        s+=A[i];
    }
    return s;
}

float Array::Avg()
{
    return Sum()/length;
}

void Array::Reverse()
{
    int *B;
    B=new int[sizeof(int)];
    int i,j;

    for (i = length-1,j=0; i >=0; i--,j++)
    {
        B[j]=A[i];
    }
    for ( i = 0; i < length; i++)
    {
        A[i]=B[i];
    }
}

void Array::swap(int *x,int *y)
{
    int temp;
    temp = *x;
    *x=*y;
    *y=temp;
}

void Array::Reverse2()
{
    int i,j;
    for(i=0,j=length-1;i<j;i++,j--)
    {
        swap(&A[i],&A[j]);
    }
}

void Array::InsertSort(int x)
{
    int i = length-1;
    if(length==size)
    {
        return;
    }
    while (i>=0 && A[i]>x)
    {
        A[i+1]=A[i];
    }
    A[i+1]=x;
    length++;
}

int Array::isSorted()
{
    int i;
    for(i=0;i<length;i++)
    {
        if(A[i]>A[i+1])
            return 0;
    }
    return 1;
}

void Array::Rearrange()
{
    int i,j;
    i=0;
    j=length-1;


    while(i<j)
    {
        while (A[i]<0)
        {
            i++;
        }
        while (A[i]>=0)
        {
            j++;
        }
        if(i<j)
        {
            swap(&A[i],&A[j]);
        }
    }
}

Array* Array::Merge(Array arr2)
{
    int i,j,k;
    i=j=k=0;

    Array *arr3 = new Array(length+arr2.length);
    while(i<length && j<arr2.length)
    {
        if(A[i]<arr2.A[j])
        {
            arr3->A[k++]=A[i++];
        }
        else
        {
            arr3->A[k++]=arr2.A[j++];
        }
        for ( ; i < length; i++)
        {
            arr3->A[k++]=A[i];
        }
        for (; j < arr2.length; j++)
        {
            arr3->A[k++]=arr2.A[j];
        }
        arr3->length=length+arr2.length;

        return arr3;
    }
}

Array* Array::Union(Array arr2)
{
    int i,j,k;
    i=j=k=0;

    Array *arr3 = new Array(length+arr2.length);

    while (i<length && j<arr2.length)
    {
        if (A[i]<arr2.A[j])
        {
            arr3->A[k++]=A[i++];
        }
        else if(arr2.A[j]<A[i])
        {
            arr3->A[k++]=A[j++];
        }
        else
        {
            arr3->A[k++]=A[i++];
            j++;
        }
    }
    for (; i < length; i++)
    {
        arr3->A[k++]=A[i];
    }
    for (; j < arr2.length; j++)
    {
        arr3->A[k++]=arr2.A[i];
    }
    arr3->length =k;
    return arr3;
}

Array* Array::Inter(Array arr2)
{
    int i,j,k;
    i=j=k=0;

    Array *arr3 = new Array(length+arr2.length);

    while (i<length && j<arr2.length)
    {
        if (A[i]<arr2.A[j])
        {
            i++;
        }
        else if(arr2.A[j]<A[i])
        {
            j++;
        }
        else
        {
            arr3->A[k++]=A[i++];
            j++;
        }
    }
    arr3->length =k;
    return arr3;
}

Array* Array::Diff(Array arr2)
{
    int i,j,k;
    i=j=k=0;

    Array *arr3 = new Array(length+arr2.length);

    while (i<length && j<arr2.length)
    {
        if (A[i]<arr2.A[j])
        {
            arr3->A[k++]=A[i++];
        }
        else if(arr2.A[j]<A[i])
        {
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }
    for (; i < length; i++)
    {
        arr3->A[k++]=A[i];
    }
    arr3->length =k;
    return arr3;
}
