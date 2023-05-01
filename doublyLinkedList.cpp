#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node{
    public:
    T data;
    Node<T> *next, *prev;
    Node(T data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};
template<typename T>
class DoublyLinkedList{
    long long siz=0;
    Node<T> *head=NULL;
    public:
    void pushBack(T data){
        if(head==NULL)
        head=new Node<T>(data);
        else{
            Node<T> *tmp=head;
            while(tmp->next!=NULL){
                tmp=tmp->next;
            }
            tmp->next=new Node<T>(data);
            tmp->next->prev=tmp;
        }
        siz++;
    }
    void pushFront(T data){
        if(head==NULL)
        head=new Node<T>(data);
        else{
            Node<T>*tmp=new Node<T>(data);
            tmp->next=head;
            head->prev=tmp;
            head=tmp;
        }
        siz++;
    }
    void traverse(){
        Node<T>*tmp=head;
        while(tmp!=NULL){
            cout<<tmp->data<<endl;
            tmp=tmp->next;
        }
    }
    long long size(){
        return siz;
    }
    void deleteByValue(T data){
        Node<T>*tmp=head;
        if(tmp->data==data){
            tmp=tmp->next;
            tmp->prev=NULL;
            head=tmp;
            siz--;
            return;
        }
        if(tmp==NULL){
            cout<<"Underflow"<<endl;
            return;
        }
        while(tmp!=NULL and tmp->data!=data){
            tmp=tmp->next;
        }
        if(tmp==NULL){
            cout<<"The Element Doesn't exist"<<endl;
            return;
        }
        if(tmp->next!=NULL){
            tmp->next->prev=tmp->prev;
        }
        if(tmp->prev!=NULL){
            tmp->prev->next=tmp->next;
        }
        siz--;
    }
};

int main()
{
    DoublyLinkedList<long long> list;
    list.pushBack(10);
    list.pushBack(20);
    list.pushBack(31);
    list.pushFront(30);
    list.traverse();
    cout<<endl<<endl;
    list.deleteByValue(30);
    list.traverse();
    cout<<endl<<endl;
    list.pushFront(30);
    list.traverse();
}