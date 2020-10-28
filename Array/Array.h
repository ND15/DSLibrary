#ifndef ARRAY_H
#define ARRAY_H


class Array
{
    public:
        Array();
        Array(int sz);
        ~Array();

        //functions
        void Display();
        void Insert(int index,int x);
        void Append( int x);
        int Delete(int index);
        int LinearSearch(int key);
        int BinarySearh(int key);
        int Get(int index);
        void Set(int index, int x);
        int Max();
        int Min();
        int Sum();
        float Avg();
        void Reverse();
        void Reverse2();
        void InsertSort(int x);
        int isSorted();
        void Rearrange();
        Array* Merge(Array arr2);
        Array* Union(Array arr2);
        Array* Diff(Array arr2);
        Array* Inter(Array arr2);

    private:
        int *A;
        int size;
        int length;
        void swap(int *x, int *y);
};

#endif // ARRAY_H
