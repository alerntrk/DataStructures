#include <iostream>
#include <string>
using namespace std;
template<typename T>
class Stack{
    T *data;
    int top_ind;
    int max;
public:
    Stack();
    ~Stack();
    bool push(T element);
    bool pop(T &element);
    bool isempty();
    template<class U>
    friend void showData(Stack<U> &a);
    int count;
    
};
template<typename T>
Stack<T>::Stack(){
    max=10;
    top_ind=0;
    data=new T[max];
}
template<typename T>
Stack<T>::~Stack(){
    delete [] data;
}
template<typename T>
bool Stack<T>::push(T element){
    if(top_ind>=max) return false;
    data[top_ind]=element;
    top_ind++;
    return true;
}
template<typename T>
bool Stack<T>::pop(T &element){
    if(isempty()) return false;
    element=data[--top_ind];
    return true;
    
}
template<typename T>
bool Stack<T>::isempty(){
    if(top_ind<=0) return true;
    return false;
}
template<typename T>
void showData(Stack<T> &s){
    int i=0;
    while(i<s.top_ind) {
        cout<<s.data[i]<<endl;
        i++;
    }
}

int main()
{
    Stack<int> s;
    int n=2;
    while(s.push(n)) n=n*2;
    showData(s);
    while(s.pop(n)) cout<<n<<endl;
}

