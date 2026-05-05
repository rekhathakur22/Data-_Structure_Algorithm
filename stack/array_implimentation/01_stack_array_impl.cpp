#include<iostream>
using namespace std;

const int MAX=5;

int stArr[MAX];
int top = -1;

// insert element into the stack
void push(int x)
{
    if(top == MAX-1){
        cout<<"stack overflow"<<endl;
    }
    top++;
    stArr[top]=x;
    cout<<"element pushed into succesfully: "<<stArr[top]<<endl;
}


void pop()
{
    if(top == -1){
        cout<<"stack underflow"<<endl;
    }
   cout<<"element poped: "<<stArr[top]<<endl;
   --top;
}

void peek()
{
    cout<<top<<endl;
}



int main()
{
    push(5);
    peek();
    push(8);
    peek();
    pop();
    peek();

    return 0;
}