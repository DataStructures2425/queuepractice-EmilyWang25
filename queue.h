#include<iostream>
#include<cassert>
using namespace std;


template<typename T>
class Node{

    public:
    T val;
    Node<T>* down = nullptr;

    Node(T x){
        val = x;
    }
};

template<typename T>
class Queue{
    public:
    Node<T>* head=nullptr;
    Node<T>* tail=nullptr;
    Queue(){
        head=nullptr;
        tail=nullptr;
    }

    Queue(T x){
        tail = new Node(x);
        head = new Node(x);
    }

    void enqueue(T x){
         Node<T>* help = new Node(x);
        if(tail == nullptr){
            tail = help;
            head = help;
            return;
        }
        tail -> down = help;
        tail = help;
        if(head == nullptr){
            head = help;
        }
    }

    T dequeue(){
        assert(head!=nullptr);
        Node<T>* help = head;
        head = head->down;
        T store = help->val;
        delete(help);
        return store;
    }

    T front(){
        assert(head!=nullptr);
        return head->val;
    }

    T rear(){
        assert(tail!=nullptr);
        return tail->val;
    }

    bool isEmpty(){
        if(head == nullptr){
            return true;
        }
        return false;
    }
};
