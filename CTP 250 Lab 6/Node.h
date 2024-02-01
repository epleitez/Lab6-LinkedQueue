//
// Created by Emely Pleitez on 10/21/22.
//

#ifndef CTP_250_LAB_6_NODE_H
#define CTP_250_LAB_6_NODE_H

template <typename Type>
class Node
{
public:
    Node();
    virtual ~Node();
    Node(Type);
    Node* next;
    Type getValue();
    void setValue(Type);


private:
    Type value;
};


#include "Node.h"

using namespace std;

template <typename Type>
Node<Type>::Node()
{
    //value = 0;
    next = nullptr;
}

template <typename Type>
Node<Type>::Node(Type newValue){
    value = newValue;
    next = nullptr;
}

template <typename Type>
Node<Type>::~Node()
{
    //dtor
}

template <typename Type>
Type Node<Type>::getValue(){
    return value;
}

template <typename Type>
void Node<Type>::setValue(Type newValue){
    value = newValue;
}

#endif //CTP_250_LAB_6_NODE_H
