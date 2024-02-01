//
// Created by Emely Pleitez on 10/21/22.
//

#ifndef CTP_250_LAB_6_QUEUEARRAY_H
#define CTP_250_LAB_6_QUEUEARRAY_H
#include <iostream>
#include <cassert>

#include "QueueInterface.h"

using namespace std;

const int MAX_QUEUE = 5;

template <typename T>
class QueueArray : public QueueInterface<T>{
public:
    bool isEmpty() ;

    bool isFull() ;

    void initialize() ;

    T peek() ;

    bool enqueue(const T& newElement) ;

    bool dequeue();

    int size() ;

    QueueArray();

    QueueArray(int);

    ~QueueArray();

    void displayQueue();

private:
    int maxQueueSize;
    int numElements ;
    int indexFront;
    int indexRear;

    T* list;  //pointer to the array that holds the queue elements
};




template <typename T>
QueueArray<T>::QueueArray(){
    maxQueueSize = MAX_QUEUE;
    list = new T [MAX_QUEUE];
    indexFront = 0;
    indexRear = maxQueueSize - 1;
    numElements = 0;
}



template <typename T>
QueueArray<T>::QueueArray(int queueSize){
    if (queueSize <= 0){
        cout << "Array queue size must be positive, defaulting to " << MAX_QUEUE << endl;
        maxQueueSize = MAX_QUEUE;
    }
    else
        maxQueueSize = queueSize;

    indexFront = 0;
    indexRear = maxQueueSize - 1;
    numElements = 0;
    list = new T[maxQueueSize];

} //end constructor


template <typename T>
QueueArray<T>::~QueueArray(){
    delete [] list;
}//end destructor

template <typename T>
bool QueueArray<T>::isEmpty(){
    return numElements == 0;
}

template <typename T>
bool QueueArray<T>::isFull(){
    cout << "in isFull(), numElements = " << numElements << endl;
    return numElements == MAX_QUEUE;
}


template <typename T>
void QueueArray<T>::initialize(){
    indexFront = 0;
    indexRear = MAX_QUEUE -1;
    numElements = 0;
}


template<typename T>
int QueueArray<T>::size() {
    return numElements;
}



template <typename T>
T QueueArray<T>::peek(){
    assert(!isEmpty());  //remember how an assert works - if this is false program terminates
    cout << "peek(), indexFront: " << indexFront << endl;
    return list[indexFront];
} //end peek()











template <typename T>
bool QueueArray<T>::enqueue(const T& newElement){

    bool result = false;


    if (numElements < MAX_QUEUE){
        indexRear = (indexRear + 1) % MAX_QUEUE;
        list[indexRear] = newElement;
        numElements++;
        result = true;
    }

    return result;


}//end enqueue()










template <typename T>
bool QueueArray<T>::dequeue(){
    bool result = false;


    if (!isEmpty()){
        indexFront = (indexFront + 1) % MAX_QUEUE ;
        numElements--;
        result = true;
    }

    return result;

}




template<typename T>
void QueueArray<T>::displayQueue(){

    //cout << "displayQueue(), indexFront: " << indexFront << endl;
    //cout << "displayQueue(), indexRear: " << indexRear << endl;
    if (numElements == 0)
        cout << "empty queue" << endl;
    else if (indexFront <= indexRear){

        for (int i = indexRear; i >= indexFront ; i--)
            cout << "element: " << list[i] << endl;
    }//end else
    else {
        if(indexRear >= 0)
            for (int i = indexRear; i >= 0; i--)
                cout << list[i] << endl;
        for (int i = MAX_QUEUE - 1; i >= indexFront; i--)
            cout << list[i] << endl;

    }

}//end display()


#endif //CTP_250_LAB_6_QUEUEARRAY_H
