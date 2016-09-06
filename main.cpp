#include <iostream>
#include "Algorithm.h"
#include "LinkedList.h"

void printList(const ads::LinkedList& list)
{
    ads::Node* node = list.front();
    while (node->getNext() != nullptr)
    {
        std::cout << node->getValue() << std::endl;
        node = node->getNext();
    }
    std::cout << node->getValue() << std::endl;
}

int main()
{
    ads::LinkedList list;
    list.push_back(4);
    list.push_back(2);
    list.push_back(7);
    list.push_back(2);
    list.push_back(3);
    list.push_back(8);
    /*std::cout << "t: " << list.at(list.getSize() - 2)->getValue() << std::endl;
    list.remove(list.getSize() - 1);
    std::cout << "l: " << list.back()->getValue() << std::endl;*/
    ads::Node* back = list.back();
    list.clear();
    //printList(list);

    return 0;
}
