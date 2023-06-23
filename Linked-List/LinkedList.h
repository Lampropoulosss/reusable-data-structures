#pragma once

template <typename T>
class Node
{
public:
    Node(T, long int i = 1); // Constructor function
    void setData(T);
    T getData();
    void setNext(Node *);
    Node *getNext();
    long int getID();

private:
    T data;
    long int id;
    Node *next = nullptr;
};

template <typename U>
class LinkedList
{
public:
    LinkedList(U);
    ~LinkedList();
    Node<U> *add(U);
    Node<U> *search(U);
    bool deleteNode(long int);

private:
    Node<U> *head;
    Node<U> *previous = nullptr;
};

// Implementation
template <typename T>
Node<T>::Node(T d, long int i) : data(d), id(i) {} // Constructor function

template <typename T>
void Node<T>::setData(T data)
{
    this->data = data;
}

template <typename T>
T Node<T>::getData()
{
    return this->data;
}

template <typename T>
void Node<T>::setNext(Node *nextNode)
{
    this->next = nextNode;
}

template <typename T>
Node<T> *Node<T>::getNext()
{
    return this->next;
}

template <typename T>
long int Node<T>::getID()
{
    return this->id;
}

template <typename U>
LinkedList<U>::LinkedList(U data)
{
    this->head = new Node<U>(data);
    this->previous = this->head;
}

template <typename U>
Node<U> *LinkedList<U>::add(U data)
{
    Node<U> *newNode = new Node<U>(data, (previous->getID()) + 1);
    previous->setNext(newNode);
    previous = newNode;
    return newNode;
}

template <typename U>
Node<U> *LinkedList<U>::search(U data)
{
    Node<U> *current = head;
    while (current != nullptr)
    {
        if (current->getData() == data)
        {
            break;
        }
        current = current->getNext();
    }
    return current;
}

template <typename U>
bool LinkedList<U>::deleteNode(long int id)
{
    Node<U> *current = head;
    Node<U> *previousNode = nullptr;
    bool result = false;

    while (current != nullptr)
    {
        if (current->getID() == id)
        {
            if (previousNode != nullptr)
            {
                previousNode->setNext(current->getNext());
            }
            else
            {
                head = current->getNext();
            }

            delete current;
            result = true;

            break;
        }
        previousNode = current;
        current = current->getNext();
    }

    return result;
}

template <typename U>
LinkedList<U>::~LinkedList()
{
    Node<U> *current = head;
    Node<U> *next;

    while (current != nullptr)
    {
        next = current->getNext();
        delete current;
        current = next;
    }
}