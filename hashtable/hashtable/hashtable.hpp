//
//  hashtable.hpp
//  hashtable
//
//  Created by Krzysztof Wasik on 03/05/2018.
//  Copyright © 2018 Krzysztof Wasik. All rights reserved.
//

#pragma once

#ifndef hashtable_hpp
#define hashtable_hpp

#include <iostream>
#include <map>
#include <string>


template<typename K, typename V>
class HashTable
{
public:
    bool isLastOpValid = false;

    void insert(const K& key, const V& value)
    {
        auto index = calcIndex(hashFunc(key));
        auto opStatus = table[index].insert(std::make_pair(key, value));

        if(true == opStatus.second)
        {
            std::cout << "Item identyfied by key " << key << " was inserted" << std::endl;
            isLastOpValid = true;
        }
        else
        {
            std::cerr << "Item identyfied by key " << key << " was not inserted" << std::endl;
            isLastOpValid = false;
        }
    }

    void remove(const K& key)
    {
        auto index = calcIndex(hashFunc(key));
        auto elementsErased = table[index].erase(key);

        if(1 == elementsErased)
        {
            std::cout << "Item identyfied by key " << key << " was removed" << std::endl;
            isLastOpValid = true;
        }
        else
        {
            std::cerr << "Item identified by key " << key << " was not removed, error occur" << std::endl;
            isLastOpValid = false;
        }
    }

    std::pair<K,V> find(const K& key)
    {
        auto index = calcIndex(hashFunc(key));
        auto it = table[index].find(key);

        if(table[index].end() != it)
        {
            isLastOpValid = true;
        }
        else isLastOpValid = false;

        return std::make_pair(it->first, it->second);
    }

private:
    static const int arraySize = 10;
    std::map<K,V> table[arraySize];

    K hashFunc(const K& key)
    {
        // for collision minimalization prime number is use for modulo operation
        K prime = 10259;
        return reinterpret_cast<K>(key) % prime;
    }

    K calcIndex(const K& hashCode)
    {
        return hashCode % arraySize;
    }
};

#endif /* hashtable_hpp */
