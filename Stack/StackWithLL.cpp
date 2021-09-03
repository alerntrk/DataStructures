#include <iostream>
#include <stdlib.h>

using namespace std;
void menu();
void close();
class stack{
    public:
    int data;
    stack *next;
};
class beginningOfstack:public stack{
    public:
    bool count=0;
    void push(stack **top,stack *m);
    void pop(stack **top);
    void display(stack *top);
};
void beginningOfstack::push(stack **top,stack *m){
  
  if(count==0)
 {
  
  cout<<"enter a data: ";
  cin>>data;
  next=NULL;
  *top=m;
 }
 else{
  stack *n=new stack;
  cout<<"enter a data: ";
  cin>>n->data;
  n->next=(*top);
  (*top)=n;
 }
 count=1;
 int c=0;
 invalid:
 cout<<"new element is push pushed succesfully do you want to return menu (1) or not(2)"<<endl;
 cin>>c;
 if(c==1)
    menu();
 else if(c==2)
    close();
 else 
    goto invalid;
 system("cls");
}
void beginningOfstack::pop(stack **top){
    bool flag=0;
    if(*top==NULL){
        cout<<"stack is empty"<<endl;
        flag=1;
    }
    else{
    cout<<"popped element is "<<(*top)->data<<endl;
    stack *p=(*top);
    *top=(*top)->next;
    delete p;}
    int c=0;
    
    if(!flag)
    cout<<"popping is done do you want to return menu (1) or not(2)"<<endl;
    else cout<<"do you want to return menu (1) or not(2)"<<endl;
    
 invalid:
 cout<<"enter your choice please: ";
 cin>>c;
 if(c==1)
    menu();
 else if(c==2)
    close();
 else 
    goto invalid;
 system("cls");
}
void beginningOfstack::display(stack *top){
    stack *p=top;
    while(p!=NULL){
        cout<<p->data<<endl;
        p=p->next;
    }
       int c=0;
 invalid:     
cout<<"do you want to return menu (1) or not(2)"<<endl;
 cin>>c;
 if(c==1)
    menu();
 else if(c==2)
    close();
 else 
    goto invalid;
 system("cls");
}
    
void close(){
    system("cls");
    cout<<"program is ended";
}
beginningOfstack *m=new beginningOfstack;
stack *top=NULL;
void menu(){
    cout<<"push :1\npop :2\ndisplay :3"<<endl;
    int c;
    invalid:
    cout<<"enter your choice: ";
    cin>>c;
    static int count=0;
    
    switch (c){
        case 1:
        system("cls");
         m->push(&top,m);
         break;
        case 2:
        system("cls");
          m->pop(&top);
          break;
        case 3:
          system("cls");
          m->display(top);
          break;
        default:
           system("cls");
            goto invalid;
    
}}
int main(){
  menu();
}
