//------------------------------------------------------------------------------
// wk08_iterators_sample.cpp
// 
// Iterator practice with vectors and maps.
// Assumes no vector or map items are being erased!
// 
// Code modified from The Cherno's Iterators in C++ video on YouTube
// https://youtu.be/SgcHcbQ0RCQ?si=Y1bp7dp-2TDu9Xmb
//------------------------------------------------------------------------------
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main()
{
    // with vectors
    std::cout << "\nvector iterator examples\n";

    std::vector<int> values = { 1, 2, 3, 4, 5 };

    // for loop - more efficient to only call .size() once
    // type of loop control variable i matches .size() return type
    std::cout << "\nfor loop: \n";

    size_t size = values.size();
    for (size_t i = 0; i < size; i++)
    {
        std::cout << values.at(i) << "\n";
    }

    std::cout << "\nrange-based for loop: \n"
        << "- cleaner code\n"
        << "- uses the vector's iterator\n";

    for (int v : values)
    {
        std::cout << v << "\n";
    }

    std::cout << "\niterator-based for loop: \n"
        << "- uses the vector's iterator type and iterator (it)\n"
        << "- the iterator (it) points to each vector item\n"
        << "- dereferences the vector's iterator (*it)\n";

    for (std::vector<int>::iterator it = values.begin();
         it != values.end(); it++)
    {
        std::cout << *it << "\n";
    }

    std::cout << "\niterator-based for loop: \n"
        << "- uses the vector's iterator (it)\n"
        << "- the iterator (it) points to each vector item\n"
        << "- shortens the iterator type with auto keyword\n"
        << "- dereferences the vector's iterator (*it)\n";

    for (auto it = values.begin(); it != values.end(); it++)
    {
        std::cout << *it << "\n";
    }

    // with maps
    std::cout << "\nmap iterator examples:\n";

    // maps can be ordered (std::map) or unordered (std::unordered_map)
    std::cout << "- maps associate a key (\"tag\") with a value\n";
    std::cout << "- each map entry is a key-value pair:\n";
    std::cout << "\tentry.first is the key (\"tag\")\n";
    std::cout << "\tentry.second is the key's associated value\n";
    std::cout << "- here the number is the tag, the name is the value\n";

    // use int identifier ("tag") to look up the associated name
    // this is more efficient than looking up a string! 

    // unordered map std::unordered_map<keyType, valueType>
    std::unordered_map<int, std::string> uMapIdToName;

    // map syntax looks like array syntax, but it's not the same
    // - the number in the brackets is not an index, it's a tag
    uMapIdToName[2] = "LindaC";
    uMapIdToName[1] = "PiperB";

    std::cout << "\nunordered map does not order tags\n";

    // for each key value pair
    // - range-based for loop uses the unordered map's iterator
    // - split the key value pair in the for loop body
    // - references avoid unwanted data copying
    for (auto &keyValuePair : uMapIdToName)
    {
        auto& key = keyValuePair.first;
        auto& value = keyValuePair.second;

        std::cout << key << " = " << value << "\n";
    }

    // simpler - split the key value pair in the for statement
    // - references avoid unwanted data copying
    for (auto& [key, value] : uMapIdToName)
    {
        std::cout << key << " = " << value << "\n";
    }

    // ordered map std::map<keyType, valueType>
    // slower than unordered map because items are sorted
    std::map<int, std::string> oMapIdToName;

    // map syntax looks like array syntax, but it's not the same
    // - the number in the brackets is not an index, it's a tag
    oMapIdToName[2] = "LindaC";
    oMapIdToName[1] = "PiperB";

    std::cout << "\nordered map does order tags\n";

    // - range-based for loop uses the ordered map's iterator
    for (auto& [key, value] : oMapIdToName)
    {
        std::cout << key << " = " << value << "\n";
    }

    return 0;
}
