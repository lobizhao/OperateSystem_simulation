#include <iostream>
#include "LRU_cache.h"
#include "myList.cpp"

using namespace std;
int main() {
    LRU_cache lruCache = LRU_cache(2);

    myList<int> lisTest;
    lisTest.push_front(1);
    lisTest.push_back(2);
    lisTest.push_front(3);

    cout<<"the front " << lisTest.front() << endl;

    for(auto item = lisTest.begin(); item != lisTest.end(); item++){
        cout << *item << endl;
    }

    return 0;
}
