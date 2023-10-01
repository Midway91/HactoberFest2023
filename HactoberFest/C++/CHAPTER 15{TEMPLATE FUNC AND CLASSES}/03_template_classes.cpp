#include<iostream>
using namespace std;
template <class T>
class Stack
{
    private:
        T *stk;
        int top;
        int size;
    public:
        Stack(int sz){
            size = sz;
            top = -1;
            stk = new T[size];
        }
        void push(T x);
        T pop();
};
template <class T>
void Stack<T>::push(T x){
    if(top == size-1){
        cout<<"Stack Is Full";
    }
    else
    {
        top++;
        stk[top] = x;
    }
}
template <class T>
T Stack<T>::pop(){
    T x = 0;
    if(top == -1){
        cout<<"Stack Is Empty";
    }
    else{
        x = stk[top];
        top--;
    }
    return x;
}

int main()
{
    Stack<int> s(10);
    Stack<float> s1(12);
    return 0;
}