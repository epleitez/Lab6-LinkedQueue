//
// Created by Emely Pleitez on 10/21/22.
//

#ifndef CTP_250_LAB_6_LINKEDQUEUE_H
#define CTP_250_LAB_6_LINKEDQUEUE_H
#include <iostream>
#include <cassert>

#include "QueueInterface.h"
#include "Node.h"

using namespace std;


template <typename T>
class LinkedQueue : public QueueInterface<T>{
public:
    bool isEmpty() ;

    bool isFull() ;

    void initialize() ;

    T peek() ;

    bool enqueue(const T& newElement) ;

    bool dequeue();

    int currentSize = 0;

    int size() ;

    LinkedQueue();

    //~LinkedQueue();

    void displayQueue();

private:
    Node<T> *queueFront;

    Node<T> *queueRear;
};


template <typename T>
LinkedQueue<T>::LinkedQueue(){
    queueFront = nullptr;
    queueRear = nullptr;
}

template <typename T>
bool LinkedQueue<T>::isEmpty(){
    return queueFront == nullptr;
}


template <typename T>
bool LinkedQueue<T>::isFull(){
    return false; //remember that a linked list can't be full
}


template <typename T>
void LinkedQueue<T>::initialize(){
    Node<T> *temp;

    while (queueFront != nullptr){
        temp = queueFront;

        queueFront = queueFront->next;

        delete temp;
    }//end while

    queueRear = nullptr;
}//end initialize


template <typename T>
bool LinkedQueue<T>::enqueue(const T& newElement){

    bool result = false;

    Node<T> *newNode;

    newNode = new Node<T>;

    newNode->setValue(newElement);
    newNode->next = nullptr;

    if (queueFront == nullptr){
        queueFront = newNode;
        queueRear = newNode;
        result = true;
    }

    else {
        queueRear->next = newNode;
        queueRear = queueRear->next;
        result = true;
    }
    if (result == true) {
        currentSize++;
    }

    return result;
}//end enqueue()


template<typename T>
T LinkedQueue<T>::peek(){
    assert(queueFront != nullptr);
    return queueFront->getValue();
}

template <typename T>
bool LinkedQueue<T>::dequeue(){
    bool result = false;

    Node<T> *temp;

    if (!isEmpty()){
        temp = queueFront;

        queueFront = queueFront->next;

        delete temp;

        if (queueFront == nullptr) //is the list empty after delete?
            queueRear = nullptr;

        result = true;

        currentSize--;

    } //end if
    else
        cout << "Empty queue, can't remove." << endl;

    return result;

}// end dequeue()


template<typename T>
int LinkedQueue<T>::size() {
    return currentSize;
} // end size()





template<typename T>
void LinkedQueue<T>::displayQueue(){
    Node<T> *temp;

    temp = queueFront;
    cout << "=====================================" << endl;
    cout << "Queue Size: " << currentSize << endl;
    cout << "-------------------------------------" << endl;
    while(temp != nullptr){
        cout << "element: " << temp->getValue() << endl;
        temp = temp->next;
    }//end while
    cout << "=====================================" << endl;

} //end display()


#endif //CTP_250_LAB_6_LINKEDQUEUE_H
