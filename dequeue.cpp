#include<bits/stdc++.h>
using namespace std;
template <typename T>
class Node{
    public:
    T data;
    Node<T>*next,*prev;
    Node(){
        this->next = NULL;
        this->prev = NULL;
    }
    Node(T data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
template<typename T>
class DQ{
    long long siz=0;
    Node<T>* head=new Node<T>(),* tail=new Node<T>();
    void headTraverse(){
        Node<T>* tmp = head->next;
        while(tmp!=tail){
            cout<<tmp->data<<endl;
            tmp=tmp->next;
        }
    }
    void tailTraversal(){
        Node<T>* tmp = tail->prev;
        while(tmp!=head){
            cout<<tmp->data<<endl;
            tmp=tmp->prev;
        }
    }
    public:
    DQ(){
        head->next = tail;
        tail->prev = head;
    }
    void pushBack(T data){
        Node<T>* tmp =new Node<T>(data);
        tmp->prev=tail->prev;
        tail->prev->next = tmp;
        tail->prev=tmp;
        tmp->next = tail;
        siz++;
    }
    void pushFront(T data){
        Node<T>* tmp=new Node<T>(data);
        tmp->next=head->next;
        head->next->prev=tmp;
        head->next=tmp;
        tmp->prev=head;
        siz++;
    }
    long long size(){return siz;}
};
int main(){
    DQ<long long> dq;
    dq.pushFront(40);
    dq.pushFront(30);
    dq.pushBack(1);
    dq.pushBack(10);
    dq.pushBack(20);
    dq.pushFront(10);
    // dq.headTraverse();
    // cout<<endl<<endl;
    // dq.tailTraversal();
    cout<<dq.size()<<endl;
}