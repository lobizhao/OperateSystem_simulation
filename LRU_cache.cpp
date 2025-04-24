#include <list>
#include <unordered_map>
#include <iostream>

using namespace std;

//double linked list
struct Node {
    int key, value;
    Node* prev;
    Node* next;
    Node(int key, int value): key(key), value(value),prev(nullptr), next(nullptr){}
};

class LRUCache {
public:
    //init capacity
    LRUCache(int capacity):cap(capacity){
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
    }

    ~LRUCache(){

        while (head){
            Node* n= head->next;
            delete head;
            head = n;
        }
    }

    int get(int key) {
        auto iterator = mp.find(key);
        if(iterator == mp.end()){
            return -1;
        }
        //Node* node = iterator->second;
        //last use move to head
        moveToHead(iterator->second);
        return iterator->second->value;
    }

    void put(int key, int value) {
        auto iterator = mp.find(key);
        if(iterator != mp.end()){
            Node* node = iterator->second;
            node->value = value;
            moveToHead(node);
        }else{
            Node* node = new Node(key, value);
            mp[key] = node;

            addToHead(node);
            if(mp.size() > cap){
                Node* toMoveTail = tail->prev;
                removeNode(toMoveTail);
                mp.erase(toMoveTail->key);
                delete toMoveTail;
            }
        }
    }
private:
    int cap;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> mp;

    //omg remember them please!!!
    void addToHead(Node* node){
        //set node's next as head's next address
        node->next = head->next;
        //set node's pre as head
        node->prev = head;

        //set oldFront head's prev as newFront
        head->next->prev = node;
        //finally done
        head->next = node;
    }

    void removeNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(Node* node){
        removeNode(node);
        addToHead(node);
    }

};

int main(){
    LRUCache cache(2);
    cache.put(1,1);
    cache.put(2,2);
    std::cout << cache.get(1) << "\n";
    cache.put(3,3);
    std::cout << cache.get(2) << "\n";
    cache.put(4,4);
    std::cout << cache.get(1) << "\n";
    std::cout << cache.get(3) << "\n";
    std::cout << cache.get(4) << "\n";

    return 0;
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */