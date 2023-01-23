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
private:
    void depthFirstSearch(Node<T> *node)
    {
        if (node == NULL)
            return;
        depthFirstSearch(node->SmallerNodePoint);
        cout << node->data << ' ';
        depthFirstSearch(node->BiggerNodePoint);
    }

public:
    Node<T> *Root = NULL;
    long long rightWeight = 0, leftWeight = 0, Size = 0;
    void add(T data)
    {
        if (Root == NULL)
        {
            Root = new Node<T>(data);
        }
        else
        {
            bool bigNode = false, smallNode = false;
            Node<T> *temp = Root;
            Node<T> *New = new Node<T>(data);
            if (temp->data < data)
            {
                bigNode = true;
                smallNode = false;
            }
            else
            {
                smallNode = true;
                bigNode = false;
            }
            while (true)
            {
                if (temp->BiggerNodePoint == NULL and bigNode)
                    break;
                if (temp->SmallerNodePoint == NULL and smallNode)
                    break;
                if (temp->data < data)
                {
                    temp = temp->BiggerNodePoint;
                }
                else
                {
                    temp = temp->SmallerNodePoint;
                }
                if (temp->data < data)
                {
                    bigNode = true;
                    smallNode = false;
                }
                else
                {
                    smallNode = true;
                    bigNode = false;
                }
            }
            if (bigNode)
            {
                rightWeight++;
                temp->BiggerNodePoint = New;
            }
            else
            {
                leftWeight++;
                temp->SmallerNodePoint = New;
            }
        }
    }
    void traverse()
    {
        depthFirstSearch(Root);
        cout << endl;
    }
};
// End of Generic Binary Search Tree Class Implementation
int main()
{
    GenericBinarySearchTree<long long> aDamnedTree;
    aDamnedTree.add(10);
    aDamnedTree.add(5);
    aDamnedTree.add(4);
    aDamnedTree.add(6);
    aDamnedTree.add(15);
    aDamnedTree.add(13);
    aDamnedTree.add(16);
    aDamnedTree.add(1);
    aDamnedTree.traverse();
}