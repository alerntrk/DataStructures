#include <iostream>
using namespace std;
template<class T>
class linkList;
template<class T>
class Node{
    T data;
    Node<T> *nextP;
    public:
    friend class linkList<T>;
    Node(T &a){
        data=a;
        nextP=NULL;
    }
};
template <class T>
class linkList{
    private:
        Node<T> *headP;
        Node<T> *endP;
        void insertBegin(T);
        void insertEnd(T);
        bool isempty();
    public:
        void insert(T);
        linkList();
        ~linkList();
        void printNodes();
};
template <typename T>
linkList<T>::linkList(){headP=NULL;endP=NULL;}
template <typename T>
linkList<T>::~linkList(){
    if(!isempty()){
    Node<T> *temp;
    Node<T> *cur;
    cur=headP;
    while(cur!=NULL){
     temp=cur;    
     cur=cur->nextP;
     delete temp;
    }
}
}
template <typename T>
bool linkList<T> :: isempty(){ if(headP==NULL && endP==NULL) return true;

                             else return false;}
template <typename T>
void linkList<T> :: insertBegin(T d){
    if(isempty()){
        Node<T> *newNode=new Node<T>(d);
        newNode->data=d;
        headP=newNode;
        endP=headP;
    }
    else{
        Node<T> *newNode=new Node<T>(d);
        newNode->nextP=headP;
        headP=newNode;
    }
}
template <typename T>

void linkList<T>::insertEnd(T d){
    
        Node<T> *newNode=new Node<T>(d);
        
        endP->nextP=newNode;
        endP=newNode;
}
template <typename T>

void linkList<T>::insert(T d){
    if(isempty()) insertBegin(d);
    else{
        if(d< headP->data) insertBegin(d);
        
        else if(d>=endP->data) insertEnd(d);
        
        else{
            Node<T> *newNode=new Node<T>(d);
            Node<T> *temp=
            temp=headP;
            while(d< temp->nextP->data ){
                temp=temp->nextP;
                }
            Node<T> *p;
            p=temp->nextP;
            temp->nextP=newNode;
            newNode->nextP=p;
            }
}
}


template <typename T>
void linkList<T> :: printNodes(){
    
    Node<T> * temp=headP;
    while(temp!=NULL){
        cout<<temp->data<<"     ";
        temp=temp->nextP;
        }
    }

int main()
{
    linkList<int> test;
    test.insert(9);
    test.insert(-1);
    test.insert(76);
    test.printNodes();
    return 0;
}
