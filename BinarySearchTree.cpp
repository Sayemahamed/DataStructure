#include <bits/stdc++.h>
using namespace std;
// Start Generic Node Class
template <typename T>
class Node
{
public:
    T data;
    Node<T> *BiggerNodePoint, *SmallerNodePoint;
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
    Node<T> *Root = NULL;
    long long rightWeight = 0, leftWeight = 0, Size = 0;
    void depthFirstSearch(Node<T> *node)
    {
        if (node == NULL)
            return;
        depthFirstSearch(node->SmallerNodePoint);
        cout << node->data << ' ';
        depthFirstSearch(node->BiggerNodePoint);
    }
    Node<T> *depthFirstSearchForOverLapping(Node<T> *first, Node<T> *second)
    {
        if (first == NULL)
            return second;
        if (second == NULL)
            return first;
        Node<T> *ans = new Node<T>(first->data + second->data);
        ans->SmallerNodePoint = depthFirstSearchForOverLapping(first->SmallerNodePoint, second->SmallerNodePoint);
        ans->BiggerNodePoint = depthFirstSearchForOverLapping(first->BiggerNodePoint, second->BiggerNodePoint);
        return ans;
    }

public:
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
    GenericBinarySearchTree<T> overLapping(GenericBinarySearchTree<T> &second)
    {
        GenericBinarySearchTree<T> ans;
        ans.Root = depthFirstSearchForOverLapping(Root, second.Root);
        return ans;
    }
};
// End of Generic Binary Search Tree Class Implementation
int main()
{
    GenericBinarySearchTree<long long> aDamnedTree, first, second;
    aDamnedTree.add(10);
    aDamnedTree.add(5);
    aDamnedTree.add(4);
    aDamnedTree.add(6);
    aDamnedTree.add(15);
    aDamnedTree.add(13);
    aDamnedTree.add(16);
    aDamnedTree.add(1);
    aDamnedTree.traverse();
    cout << endl;
    first.add(3);
    first.add(2);
    first.add(1);
    first.add(4);
    first.add(5);
    first.add(6);
    first.traverse();
    cout << endl;
    second.add(3);
    second.add(2);
    second.add(1);
    second.add(4);
    second.add(5);
    second.add(6);
    second.traverse();
    cout << endl;
    first = first.overLapping(second);
    first.traverse();
}