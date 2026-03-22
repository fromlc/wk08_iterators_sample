//------------------------------------------------------------------------------
// wk08_iterators_sample.cpp
// 
// Iterator practice with vectors and maps.
// Assumes no vector or map items are being erased!
//------------------------------------------------------------------------------
#include <iostream>
#include <unordered_map>
#include <string>
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
        << "- uses the vector's iterator and iterator type\n"
        << "- dereferences the vector's iterator\n";

    for (std::vector<int>::iterator it = values.begin();
         it != values.end(); it++)
    {
        std::cout << *it << "\n";
    }

    std::cout << "\niterator-based for loop: \n"
        << "- uses the vector's iterator\n"
        << "- shortens the iterator type with auto keyword\n"
        << "- dereferences the vector's iterator\n";

    for (auto it = values.begin(); it != values.end(); it++)
    {
        std::cout << *it << "\n";
    }

    // with maps
    std::cout << "\nmap iterator examples\n";

    // maps can be ordered (std::map) or unordered (std::unordered_map)
    std::cout << "\nmaps associate a key with a value\n";

    // use int identifier ("tag") to look up the associated name
    // this is more efficient than looking up a string! 

    std::unordered_map<int, std::string> mapIdToName;

    // map syntax looks like array syntax
    mapIdToName[1] = "LindaC";
    mapIdToName[2] = "PiperB";

    // for each key value pair
    // - split the key value pair in the for loop body
    for (auto &keyValuePair : mapIdToName)
    {
        auto &key = keyValuePair.first;
        auto &value = keyValuePair.second;

        std::cout << key << " = " << value << "\n";
    }

    // simpler - split the key value pair in the for statement
    for (auto &[key, value] : mapIdToName)
    {
        std::cout << key << " = " << value << "\n";
    }
}
