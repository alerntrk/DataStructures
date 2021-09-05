#ifndef 	_VECTOR_H
#define 	_VECTOR_H

#include <iostream>
using namespace std;
template<class T>
void _swap(T& x,T& y){
    T temp=x;
    x=y;
    y=temp;
}

template<class T>
class vector{
    private:
        T* data;
        int ind;
        int cap;
        void shrink(){
              if(ind<=cap/2){
                cap = cap/2;
                T *temp=new T[cap];
                for(int i=0;i<size();i++) temp[i]=data[i];
                delete[] data;
                data=temp;
                }
            }
            
            
        
        void growth(){
            if(ind>=cap){
                cap = cap*2;
                T *temp=new T[cap];
                for(int i=0;i<size();i++) temp[i]=data[i];
                delete[] data;
                data=temp;
                }
            }
        void reset(int ind=0,int cap=1){
            delete[] data;
            this->ind=ind;
            this->cap=cap;
            data=NULL;
        }
        
    public:
        vector() : data(NULL),ind(0),cap(1){
           data = new T[cap];
            
        }
        vector(int n,const T& t=T()) : vector<T>(){
            for(int i=0;i<n;i++) push_back(t);
        }
        vector(const T* first,const T* last) : vector<T>(){
            while(first!=last) push_back(*first)++;
            
        }
        vector(const vector<T>& v){*this=v;}
        ~vector(){reset();}
        int size()const{return ind;}
        int capacity()const{return cap;}
        void push_back(const T& a){growth();data[ind++]=a;}
        bool isEmpty()const{return size()==0;}
        void pop_back(){
            if(isEmpty())
            throw("\n ERROR !!! vector is empty...");
             ind--;
             shrink();
          }
        T front()const{
            if(isEmpty())
              throw("\n ERROR !!! vector is empty...");
            return data[0];
        }
        T back()const{
          if(isEmpty())
            throw("\n ERROR !!! vector is empty...");
          return data[ind-1];  
        } 
        T* begin()const{
            return data;
        }
        T* end()const{
            return data+size();
        }
        
        T& at(int indx){
            if(indx>=0 && indx<size()) return data[indx];
            throw "ERROR index overflow\n"; 
        }
        T& operator[](int indx){
            return at(indx);
        }
        void clear(){
            reset();
            data=new T[cap];
        }
        void insert(const T* pos,const T value){
            if(begin()<=pos && pos <=end()){
                int index=pos-begin();
                push_back(value);
                for(int i=size()-1;i>index;i--){
                    _swap(data[i],data[i-1]);
            }}
            else
                throw "ERROR : insert";
        }

        void insert(const T* pos,int n,const T value) {
            int index = pos-begin();
            for(int i=0;i<index;i++) insert(begin()+index+i,value);
        }
        void insert(const T*pos,const T* first,const T* last){
            int index=pos-begin();
            while(first!=last)
                insert(begin()+index++,*first++);
        }
        void erase(const T* pos){
            if(begin()<=pos && pos <=end()){
                int index=pos-begin();
                for(int i=index;i<size();i++)
                    data[i]=data[i+1];
                pop_back();
                }
        }
        
        void erase(const T* first,const T* last){
            int f=first-begin();
            int l=last-begin();
            while(f!=l--) erase(begin()+f);        
        }
        void assign(const vector<T>& rhs){
            reset(rhs.size(),rhs.capacity());
            data = new T[capacity()];
            for(int i=0;i<size();i++){
                data[i]=rhs.data[i];
                }}
        void operator =(const vector<T>& rhs){
            assign(rhs);
        }
        
        
};
#endif
