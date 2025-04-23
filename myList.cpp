//
// Created by admin on 2025/4/22.
//

//for size t
#include <cstddef>
#include <iostream>

using namespace std;

template<typename T>
class myList {
private:
    struct Node{
        T data;
        Node* prev;
        Node* next;
        Node(const T& v):
                data(v),
                prev(nullptr),
                next(nullptr){}
    };
    //point to head
    Node* head;
    //point to tail
    Node* tail;
    //current elements counts
    size_t count;

public:
    myList(): head(nullptr), tail(nullptr), count(0){}

    ~myList(){
        clean();
    }
    bool empty()const{
        return count == 0;
    }
    size_t size()const{
        return count;

    }
    //get front and back
    T& front(){
        if(empty()){
            cout << "List is empty "<< endl;
        }
        return head->data;
    }
    T& back(){
        if(empty()){
            cout << "List is empty" << endl;
        }
        return tail->data;
    }

    //inset front and back
    void push_front(const T& value){
        Node* temp = new Node(value);
        if(empty()){
            head = tail = temp;
        } else{
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        count++;
    }
    void push_back(const T& value){
        Node* temp = new Node(value);
        if(empty()){
            tail = head = temp;
        }else{
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
        count++;
    }

    //delete
    void pop_front(){
        if(empty()){
            return;
        }

        Node* temp = head;
        if(head == tail){
            head = tail = nullptr;
        }else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        count--;
    }
    void pop_back(){
        if(empty()){
            return;
        }
        Node* temp = tail;
        if(tail == head){
            tail = head = nullptr;
        }else{
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        count--;
    }

    //clean
    void clean(){
        while (!empty()){
            pop_front();
        }
    }

    //iterator
    class iterator{
        Node* current;
    public:
        iterator(Node* p): current(p){}
        T& operator*() const {
            return current->data;
        };
        iterator& operator++(){
            current = current->next;
            return *this;
        }
        iterator operator++(int){
            iterator tmp = *this;
            ++*this;
            return tmp;
        }
        bool operator!=(const iterator& x)const {
            return current != x.current;
        }
    };

    iterator begin(){
        return iterator(head);
    }
    iterator end(){
        return iterator(nullptr);
    }

};

