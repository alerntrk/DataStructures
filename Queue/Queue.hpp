#include <iostream>
using namespace std;
template <typename T>
class Qnode{
    public:
    int data;
    Qnode<T> *next;
    Qnode<T>(const int&  d=0,Qnode<T>* nxt=NULL):data(d),next(nxt){}
   };

template <typename T>

class Queue{
		Qnode<T>* root;Qnode<T>* tail;
        int length;
        void makeEmpty(){
            while(!isempty()) deque();
            
        }
    public:
        
		Queue():root(NULL),tail(NULL),length(0){}
        Queue(const Queue<T>& rhs){Queue<T>();assign(rhs);}
        ~Queue(){makeEmpty();}
        bool isempty(){ return (root==NULL);}
        void enqueue(const T& dt){
            if(isempty()) {
                root=new Qnode<T>(dt);
                tail=root;
            }
            else{
                tail->next=new Qnode<T>(dt);
                tail=tail->next;
            }
            length++;
            }
        Queue<T>& assign(const Queue<T>& rhs){
            makeEmpty();
            Qnode<T>* temp=rhs.root;
            while(temp!=NULL){
                enqueue(temp->data);
                temp=temp->next;
            }
            return (*this);
            }
        void print(){
            Qnode<T>* temp=root;
            while(temp!=NULL)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
            }  
        void deque(){
            if(isempty())throw"No element is Queue\n";
            if(root==tail) tail=root->next;
            Qnode<T>* temp=root;
            root=root->next;
            length--;
            delete temp;
        }
        int size()const{
            int c=0;
            Qnode<T>* temp=root;
            while(temp!=NULL){
                temp= temp->next;
                c++;
            }
            return c;
            }
        T front(){
            if(isempty()) throw"No element is Queue\n";
            return root->data;
        }
        T back(){
            if(isempty())throw"No element is Queue\n";
            return tail->data;
        }
        
    
};
// OR
/*! The easiest way  
#include <list>
template <class T,class container=list<T>>
class Queue{
    container cont;
    public:
    bool isempty(){
        cont.isempty();
    }
    void enqueue(const T& val){cont.push_back(val);}
    T front(){return cont.front();}
    T back(){return cont.back();}
    T dequeue(){return cont.pop_front();}
    int size(){return cont.size();}
    
};
*/

