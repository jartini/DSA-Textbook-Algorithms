#include <iostream>

class Heap
{
   int* array;
   int count;
   bool Heap_Type;
    void swap(int* x, int* y)
    {

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
    int findIndex(int k){/*returns index if heap contains k, returns -1 if not */};
    bool contains(int k){/*searches the heap for a value returns bool t/f */}
};



int main(){
    return 0;
}