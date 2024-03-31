#include "bst.hpp"
#include <iostream>

void printNodeData(int data)
{
    std::cout << data << " ";
}

int main()
{
    BST bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);
    bst.insert(25);
    bst.insert(1);


    bst.printTree(bst.getRoot());

    std::cout << "Inorder Traversal: ";
    bst.traverse(printNodeData);
    std::cout << std::endl;

    int valueToSearch = 4;
    if (bst.search(valueToSearch))
    {
        std::cout << valueToSearch << " found in the tree." << std::endl;
    }
    else
    {
        std::cout << valueToSearch << " not found in the tree." << std::endl;
    }

    std::cout << "Minimum value: " << bst.getMin(bst.getRoot())->getData() << std::endl;
    std::cout << "Maximum value: " << bst.getMax(bst.getRoot())->getData() << std::endl;

    std::cout << "Predecessor of 40: " << bst.getPredecessor(40)->getData() << std::endl;
    std::cout << "Successor of 40: " << bst.getSuccessor(40)->getData() << std::endl;

    bst.remove(40);
    bst.printTree(bst.getRoot());

    std::cout << "Height of the tree: " << bst.getHeight() << std::endl;

    return 0;
}
