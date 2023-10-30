// Program to Demonstrate user defined Exception
#include <iostream>
using namespace std;
class StackOverFlow : exception
{
};
class StackUnderFlow : exception
{
};
class Stack
{
private:
    int *stk;
    int top = -1;
    int size;

public:
    Stack(int sz)
    {
        size = sz;
        stk = new int[size];
    }
    void push(int x)
    {
        if (top == size - 1)
            throw StackOverFlow();
        top++;
        stk[top] = x;
    }
    int pop()
    {
        if (top == -1)
            throw StackUnderFlow();
        return stk[top--];
    }
};
int main()
{
    try{

    Stack s(5);
    
    
    // s.push(2);
    // s.push(3);
    // s.push(4);
    // s.push(10);
    s.push(0);
    s.push(8);
    s.pop();
    }
    catch(StackOverFlow e){
        cout<<"Stack Is Overflowing";
    }
    catch(StackUnderFlow e){
        cout<<"Stack Is Underflowing";
    }
    return 0;
}