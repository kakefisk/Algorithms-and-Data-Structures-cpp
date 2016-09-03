#include <iostream>
#include "Algorithm.h"
#include "LinkedList.h"

int main()
{
    ads::LinkedList list;
    list.push_back(4);
    list.push_back(2);
    list.push_back(7);

    ads::Node* node = list.front();
    //list.insert(3, 5);
    while (node->getNext() != nullptr)
    {
        std::cout << node->getValue() << std::endl;
        node = node->getNext();
    }
    std::cout << node->getValue() << std::endl;
    std::cout << list.at(1)->getValue() << std::endl;

    return 0;
}
