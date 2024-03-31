#include "bst.hpp"

BST::BST()
    : _root {nullptr} {}

BST::~BST()
{
    destroyTree(_root);
}

void BST::destroyTree(Node* node)
{
    if (node != nullptr)
    {
        destroyTree(node->_left);
        destroyTree(node->_right);
        delete node;
    }
}

BST::Node* BST::getRoot() const
{
    return _root;
}

BST::Node* BST::getPredecessor(int data) const
{
    Node* pred = nullptr;
    Node* curr = _root;

    while (curr && curr->_data != data)
    {
        if (curr->_data < data)
        {
            pred = curr;
            curr = curr->_right;
        }
        else
        {
            curr = curr->_left;
        }
    }

    if (!curr || !curr->_left)
    {
        return pred;
    }

    return getMax(curr->_left);
}

BST::Node* BST::getSuccessor(int data) const
{
    Node* suc = nullptr;
    Node* curr = _root;

    while (curr && curr->_data != data)
    {
        if (curr->_data > data)
        {
            suc = curr;
            curr = curr->_left;
        }
        else
        {
            curr = curr->_right;
        }
    }

    if (!curr || !curr->_right)
    {
        return suc;
    }

    return getMax(curr->_right);
}

void BST::insert(int data)
{
    _root = insert(_root, data);
}

BST::Node* BST::insert(BST::Node* node, int data)
{
    if (node == nullptr)
    {
        return new Node(data);
    }

    if (data <= node->_data)
    {
        node->_left = insert(node->_left, data);
    }
    else
    {
        node->_right = insert(node->_right, data);
    }

    return node;
}

void BST::remove(int data)
{
    _root = remove(_root, data);
}

BST::Node* BST::remove(BST::Node* node, int data)
{
    if (node == nullptr)
    {
        return node;
    }
    if (node->_data < data)
    {
        node->_right = remove(node->_right, data);
    }
    else if (node->_data > data)
    {
        node->_left = remove(node->_left, data);
    }
    else
    {
        if (node->_left == nullptr)
        {
            Node* tmp = node->_right;
            delete node;
            return tmp;
        }
        else if (node->_right == nullptr)
        {
            Node* tmp = node->_left;
            delete node;
            return tmp;
        }
        else
        {
            Node* tmp = getMax(node->_left);
            node->_data = tmp->_data;
            node->_left = remove(node->_left, tmp->_data);
        }
    }

    return node;
}

bool BST::search(int data) const
{
    return search(_root, data) != nullptr;
}

BST::Node* BST::search(Node* node, int data) const
{
    if (node == nullptr || node->_data == data)
    {
        return node;
    }

    if (data <= node->_data)
    {
        return search(node->_left, data);
    }
    else
    {
        return search(node->_right, data);
    }
}

void BST::traverse(void (*func)(int)) const
{
    traverse(_root, func);
}

void BST::traverse(BST::Node* node, void (*func)(int)) const
{
    if (node != nullptr)
    {
        // preorder
        // func(node->_data);
        traverse(node->_left, func);
        // inorder
        func(node->_data);
        traverse(node->_right, func);
        // postorder
        // func(node->_data);
    }
}

BST::Node* BST::getMin(BST::Node* node) const
{
    Node* curr = node;
    while (curr->_left != nullptr)
    {
        curr = curr->_left;
    }

    return curr;
}

BST::Node* BST::getMax(BST::Node* node) const
{
    Node* curr = node;
    while (curr->_right != nullptr)
    {
        curr = curr->_right;
    }

    return curr;
}

size_t BST::getHeight() const
{
    return getHeight(_root);
}

int BST::getHeight(BST::Node* node) const
{
    if (node == nullptr)
    {
        return -1;
    }

    return std::max(getHeight(node->_left), getHeight(node->_right)) + 1;
}

void BST::printTree(Node* node, int depth) const
{
    if (node != nullptr)
    {
        printTree(node->_right, depth + 1);
        std::cout << std::string(depth * 4, ' ') << node->_data << std::endl;
        printTree(node->_left, depth + 1);
    }
}

BST::Node::Node(int data)
    : _left {nullptr}
    , _right {nullptr}
    , _data {data} {}

int BST::Node::getData() const
{
    return _data;
}