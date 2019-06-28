#include <iostream>

class Heap
{
   int* array;
   int count = 0;
   bool Heap_Type;  //true -> min; false->max
   void swap(int* x, int* y)
   {    //swaps values
        int* tmp = x;
        x = y;
        y = tmp;
    }

    public:
    //constructor
    Heap(int max, bool htype)
    {
        array = new int[max];
        Heap_Type = htype;
    }
    //public functions
    //tree indexing functions
    int getParentIndex(int i)    {return (i-1)/2;}
    int getLeftChildIndex(int i)    {return (2*i)+1;}
    int getRightChildIndex(int i)   {return (2*i)+2;}
    //edit functions
    void add(int k){}; //resolves heap type in implementation
    void MinHeapify(){/*resolves the heap to min root */};
    void MaxHeapify(){/*resolves the heap to max root */}
    bool remove(int k){}; //resolves heap type in implementation
    int findIndex(int k, int node = 0){/*returns index if heap contains k, returns -1 if not */};
    bool contains(int k){/*searches the heap for a value returns bool t/f */} //In DSA book, findIndex but with bools
};

void Heap::add(int k)
{
    array[count] = k;
    count += 1;
    if(Heap_Type){  //resolving the heap to the heap type
        MinHeapify();
    }else{
        MaxHeapify();
    }
}

void Heap::MinHeapify()
{
    int i = count - 1;
    while(i > 0 && array[i] < array[getParentIndex(i)] )
    {
        swap(&array[i], &array[getParentIndex(i)]);
        i = getParentIndex(i);
    }
}

void Heap::MaxHeapify()
{
    int i = count - 1;
    while(i > 0 && array[i] > array[getParentIndex(i)])
    {
        swap(&array[i], &array[getParentIndex(i)]);
        i = getParentIndex(i);
    }
}

int Heap::findIndex(int k, int node = 0)
{
    if(Heap_Type){
        //Min
        
    }else{
        //Max

    }
}


int main(){
    return 0;
}