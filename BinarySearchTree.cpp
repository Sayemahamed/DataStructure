#include <bits/stdc++.h>
using namespace std;
// Start Generic Node Class
template <typename T>
class Node
{
public:
    T data;
    Node *BiggerNodePoint, *SmallerNodePoint;
    Node(){};
    Node(T data)
    {
        this->data = data;
        this->BiggerNodePoint = NULL;
        this->SmallerNodePoint = NULL;
    }
};
// End of Generic Node Class

// Start of Generic Binary Search Tree Class Implementation
template <typename T>
class GenericBinarySearchTree
{
public:
    Node<T> *Root = NULL;
    long long rightWeight = 0, leftWeight = 0, Size = 0;
    void add(T data)
    {
        if (Root == NULL)
        {
            root = new Node<T>(data);
        }
        else
        {
            Node<T> *temp = Root;
            Node<T> *New = new Node<T>(data);
        }
    }
};
// End of Generic Binary Search Tree Class Implementation
int main()
{
}