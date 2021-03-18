//
//  main.cpp
//  Stack_postfix_result
//
//  Created by Ch Muhammad Wahab on 06/11/2020.
//  Copyright © 2020 Ch Muhammad Wahab. All rights reserved.
//

#include <iostream>
#include<fstream>
using namespace std;

template<class t>
struct Node
{
    t data;
    struct Node<t>* next;
};
template<class t>
class stack{
    struct Node<t>* top;
    
public:
    stack(){
        top=NULL;
    }
    void push(const t &data)
    {
        struct Node<t>* temp;
        temp = new Node<t>;
        if (!temp)
        {
            cout << "\nHeap Overflow";
            exit(1);
        }
        cout<<data<<" pushed into stack\n";
        temp->data = data;
        
        temp->next = top;
        
        top = temp;
    }
    
    bool empty() const
    {
        return top == NULL;
    }
    t top_value() const
    {
        if (!empty())
        {
            return top->data;
        }
        else{
            cout<<"Stack Underflow" << endl;
            return 0;
        }
    }
    void pop()
    {
        struct Node<t>* temp;
        if (top == NULL)
        {
            cout << "\nStack Underflow" << endl;
        }
        else
        {
            
            temp = top;
            top = top->next;
            temp->next = NULL;
            delete temp;
        }
        
    }
    void stack_status(){
        cout<<"Current Status of Stack\n";
        struct Node<t> *temp;
        temp=top;
        if(temp==NULL){
            cout<<"Stack Underflow!\n";
        }
        while(temp!=NULL){
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }
    ~stack(){
        while (!empty()) {
            pop();
        }
    }
};
void postfix_to_result(const char* str){
    bool found=false;
    int v1,v2;
    stack<int> s;
    for (int i=0; i<strlen(str); i++) {
    
        if(isdigit(str[i])){
            s.push(str[i]-'0');
            s.stack_status();
        }
        else{
        switch (str[i]) {
            case '*':
                found=true;
                cout<<"We have * operator as input!\n";
                if(s.empty()){
                    cout<<"No operand found !\nInavlid expression!\n";
                    exit(1);
                }
                v1=s.top_value();
                s.pop();
                cout<<v1<<" poped out of stack!\n";
                if(s.empty()){
                    cout<<"No operand found !\nInavlid expression!\n";
                    exit(1);
                }
                v2=s.top_value();
                s.pop();
                cout<<v2<<" poped out of stack!\n";
                cout<<v2<<"*"<<v1<<":"<<v2*v1<<endl;
                s.push(v2*v1);
                s.stack_status();
                break;
            case '-':
                found=true;
                cout<<"We have - operator as input!\n";
                if(s.empty()){
                    cout<<"No operand found !\nInavlid expression!\n";
                    exit(1);
                }
                v1=s.top_value();
                s.pop();
                cout<<v1<<" poped out of stack!\n";
                if(s.empty()){
                    cout<<"No operand found !\nInavlid expression!\n";
                    exit(1);
                };
                v2=s.top_value();
                s.pop();
                 cout<<v2<<" poped out of stack!\n";
                cout<<v2<<"-"<<v1<<":"<<v2-v1<<endl;
                s.push(v2-v1);
                 s.stack_status();
                break;
            case '+':
                found=true;
                cout<<"We have + operator as input!\n";
                if(s.empty()){
                    cout<<"No operand found !\nInavlid expression!\n";
                    exit(1);
                }
                v1=s.top_value();
                s.pop();
                 cout<<v1<<" poped out of stack!\n";
                if(s.empty()){
                    cout<<"No operand found !\nInavlid expression!\n";
                    exit(1);
                }
                v2=s.top_value();
                s.pop();
                 cout<<v2<<" poped out of stack!\n";
                cout<<v2<<"+"<<v1<<":"<<v2+v1<<endl;
                s.push(v2+v1);
                 s.stack_status();
                break;
            case '/':
                found=true;
                cout<<"We have / operator as input!\n";
                if(s.empty()){
                    cout<<"No operand found !\nInavlid expression!\n";
                    exit(1);
                }
                v1=s.top_value();
                s.pop();cout<<v1<<" poped out of stack!\n";
                if(s.empty()){
                    cout<<"No operand found !\nInavlid expression!\n";
                    exit(1);
                }
                v2=s.top_value();
                s.pop();cout<<v2<<" poped out of stack!\n";
                cout<<v2<<"/"<<v1<<":"<<v2/v1<<endl;
                s.push(v2/v1);
                 s.stack_status();
                break;
        }
        }
    
    }
    int result=s.top_value();
    s.pop();
    if(!s.empty() && found==false){
        
        cout<<"No operator found!\nInvalid expression!\n";
    }
    else
    cout<<"Final result: "<<result<<'\n';
}

int main(int argc, const char * argv[]) {
//    if(argc<2){
//        cout<<"No file found in command line!"<<endl;
//        exit(1);
//    }
//    cout<<"Expression read from Command line argument:"<<argv[1]<<endl;
//    cout<<"Total number of letters:"<<strlen(argv[1])<<endl;
    postfix_to_result("1+8/2*5-4+6-3");
  
    return 0;
    
}
