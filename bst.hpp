#ifndef BST_HPP
#define BST_HPP

#include <iostream>

class BST
{
private:
    struct Node;
public:
    BST();
    ~BST();
    Node* getRoot() const;
    Node* getPredecessor(int) const;
    Node* getSuccessor(int) const;
    void insert(int);
    void remove(int);
    bool search(int) const;
    void traverse(void (*)(int)) const;
    Node* getMin(Node*) const;
    Node* getMax(Node*) const;
    size_t getHeight() const;
    void printTree(Node*, int depth = 0) const;

private:
    struct Node {
        Node* _left;
        Node* _right;
        int _data;

        explicit Node(int);
        int getData() const;
    };

    Node* _root;

    Node* insert(Node*, int);
    Node* remove(Node*, int);
    Node* search(Node*, int) const;
    void traverse(Node*, void (*)(int)) const;
    int getHeight(Node*) const;
    void destroyTree(Node*);
};

#endif // BST_HPP