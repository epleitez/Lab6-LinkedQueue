//
// Created by Emely Pleitez on 10/21/22.
//

#ifndef CTP_250_LAB_6_QUEUEINTERFACE_H
#define CTP_250_LAB_6_QUEUEINTERFACE_H

template <typename T>
class QueueInterface
{
public:

    virtual bool isEmpty() = 0;

    virtual bool isFull() = 0;

    virtual void initialize() = 0;

    virtual T peek() = 0;

    virtual bool enqueue(const T& newElement) = 0;

    virtual bool dequeue() = 0;

    virtual int size() = 0;


};

#endif //CTP_250_LAB_6_QUEUEINTERFACE_H
