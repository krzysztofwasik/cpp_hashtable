//
//  main.cpp
//  Basic implementation of hash table using fixed size array and std::map to guarantee uniqueness of items inserted into table.
//
//  Created by Krzysztof Wasik on 02/05/2018.
//  Copyright © 2018 Krzysztof Wasik. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>

#include "hashtable.hpp"

int main(int argc, const char * argv[]) {
   
    HashTable<unsigned long, std::string> table = HashTable<unsigned long, std::string>();

    std::cout << "> Inserting work data, format <long,string>" << std::endl;
    table.insert(801212000111, "Kamil Stoch");
    table.insert(701119111333, "Adam Malysz");
    table.insert(101217800111, "Karas Stoch");
    table.insert(301110001333, "Adam Burak");
    table.insert(301110001333, "Adam Burak Junior");

    unsigned long itemKeyToRemove = 701119111333;
    std::cout << "> Removing item identyfied by key " << itemKeyToRemove << std::endl;
    table.remove(itemKeyToRemove);

    std::cout << "> Searching for removed item identyfied by key " << itemKeyToRemove << std::endl;
    auto item = table.find(itemKeyToRemove);
    if(!table.isLastOpValid)
    {
        std::cout << "> Removed earlier item was not found as expected" << std::endl;
    }
    else
    {
        std::cerr << "> Removed earlier item was found, earlier remove operarion failed. Data may be inconsistent" << std::endl;
        std::cerr << " Found item that was not expected key / value: " << item.first << " / " << item.second << std::endl;
    }

    unsigned long itemKeyToFind = 801212000111;
    std::cout << "> Searching for item identyfied by key " << itemKeyToFind << std::endl;
    auto foundItem = table.find(itemKeyToFind);
    if(table.isLastOpValid)
    {
        std::cout << "> Item found as expected, item value that match item key is " << foundItem.second << std::endl;
    }
    else
    {
        std::cerr << "> Item was found" << std::endl;
    }
    
    return 0;
}
