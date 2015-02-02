//
//  BinHeap.cpp
//

#include "BinHeap.h"
#include "Flags.h"

/* **************************************************************** */

#if CONSTRUCTOR || ALL
template <class T>
BinHeap<T>::BinHeap()
{
    maxSize = 1;
    heapArray = new T[2];
    heapArray[0] = -1;
    heapSize = 0;

}
#endif

/* **************************************************************** */

#if DESTRUCTOR || ALL
template <class T>
BinHeap<T>::~BinHeap()
{
    delete[] heapArray;
}
#endif

/* **************************************************************** */

#if ISEMPTY || ALL
template <class T>
bool BinHeap<T>::isEmpty(){
    if (heapSize ==  0)
    {
        return true;
    }

    return false;
}
#endif

/* **************************************************************** */

#if MAKEEMPTY || ALL
template <class T>
void BinHeap<T>::makeEmpty(){

    delete[] heapArray;

    maxSize = 1;
    heapArray = new T[2];
    heapArray[0] = -1;
    heapSize = 0;
}
#endif

/* **************************************************************** */

#if RESIZEARRAY || ALL
template <class T>
void BinHeap<T>::resizeArray(int newSize){
    T *temp = new T[newSize];
    for (int i = 0; i <= heapSize; ++i)
    {
        temp[i] = heapArray[i];
    }
    T *oldArray = heapArray;
    heapArray = temp;
    delete[] oldArray;

    maxSize = newSize;


}
#endif

/* **************************************************************** */

#if LEFTINDEX || ALL
template <class T>
int BinHeap<T>::leftIndex(int idx){
    return (2*idx);
}
#endif

/* **************************************************************** */

#if RIGHTINDEX || ALL
template <class T>
int BinHeap<T>::rightIndex(int idx){
    return ((2*idx)+1);
}
#endif

/* **************************************************************** */

#if PARENTINDEX || ALL
template <class T>
int BinHeap<T>::parentIndex(int idx){
    return idx/2;
}
#endif

/* **************************************************************** */

#if MINCHILD || ALL
template <class T>
int BinHeap<T>::minChild(int idx){
    int left = leftIndex(idx);
    int right = rightIndex(idx);

    T valRight = heapArray[right];
    T valLeft = heapArray[left];

    if (left > heapSize)
    {
        return -1;
    }

    if (right > heapSize)
    {
        return left;
    }

    if (valLeft > valRight)
    {
        return right;
    }

    return left;
}
#endif

/* **************************************************************** */

#if INSERT || ALL
template <class T>
void BinHeap<T>::insert(const T & x){
    heapSize++;
    if (heapSize > maxSize)
    {
        resizeArray(maxSize*2);
    }

    heapArray[heapSize] = x;

    percolateUp(heapSize);
}
#endif

/* **************************************************************** */

#if REMOVEMIN || ALL

template <class T>
T BinHeap<T>::removeMin(){
    if (heapSize <= 0)
    {
        return -1;
    }

    T temp = heapArray[1];
    heapArray[1] = heapArray[heapSize];

    heapSize--;

    if (heapSize < (maxSize/3))
    {
        resizeArray(maxSize/2);
    }

    percolateDown(1);
    

    return temp;
}

#endif

/* **************************************************************** */

#if PERCOLATEUP || ALL
template <class T>
void BinHeap<T>::percolateUp(int idx){
    int pdx = parentIndex(idx);
    while(heapArray[pdx] > heapArray[idx]){
        T temp = heapArray[pdx];
        heapArray[pdx] = heapArray[idx];
        heapArray[idx] = temp;

        idx = pdx;
        pdx = parentIndex(idx);
    }

}
#endif

/* **************************************************************** */

#if PERCOLATEDOWN || ALL
template <class T>
void BinHeap<T>::percolateDown(int idx){
    int cdx = minChild(idx);
    while(cdx!=-1 && heapArray[cdx] <= heapArray[idx]){
        T temp = heapArray[cdx];
        heapArray[cdx] = heapArray[idx];
        heapArray[idx] = temp;

        idx = cdx;
        cdx = minChild(idx);
        
    }

}
#endif

/* **************************************************************** */

#if BUILDHEAP || ALL
template <class T>
void BinHeap<T>::buildHeap(const T* arr, int size){
    resizeArray(size);
    heapSize = size;
    for (int i = 0; i < size; ++i)
    {
        heapArray[i+1] = arr[i];
    }
    
    for (int i = (heapSize/2); i > 0; --i)
    {
        percolateDown(i);
    }
}
#endif

/* **************************************************************** */



/* **************************************************************** */
/* Do NOT modify anything below this line                           */
/* **************************************************************** */

#ifndef BUILD_LIB
template <class T>
void BinHeap<T>::printHeap()
{
    std::cout << "Current array size: " << maxSize << std::endl;
    std::cout << "Current heap size: " << heapSize << std::endl;
    if (!isEmpty())
    {
        std::cout << "Heap Elements: ";
        // Print heap array
        for (int i = 1; i <= heapSize; i++) {
            std::cout << heapArray[i] << " ";
        }
    }
    else
    {
        std::cout << "Heap is empty";
    }
    std::cout << std::endl << std::endl;
}
#endif

template class BinHeap<int>;
