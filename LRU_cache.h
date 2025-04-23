//
// Created by admin on 2025/4/21.
//

#ifndef OPERATESYSTEM_SIMULATION_LRU_CACHE_H
#define OPERATESYSTEM_SIMULATION_LRU_CACHE_H

#include <list>
#include <unordered_map>

class LRU_cache {
public:
    LRU_cache(int capacity);
    int get(int key);
    void put(int key, int value);
private:
    //capacity
    int cap;
    //double list
    std::list<std::pair<int, int>> data;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache;



};


#endif //OPERATESYSTEM_SIMULATION_LRU_CACHE_H
