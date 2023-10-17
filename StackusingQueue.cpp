//push operatin is costly
#include <iostream>
#include <queue>

using namespace std;

class Stack{

    int N;
    queue<int> q1;
    queue<int> q2;
    public:

    Stack(){
        N=0;
    }

    void push(int val){
        q2.push(val);
        N++;
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
    }

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }


    void pop(){
        if(q1.empty()){
            cout <<"No elements Present" << endl;
            return;
        }
        q1.pop();
        N--;
    }

    int top(){
        return q1.front();
    }

    int size(){
        return N;
    }
};

int main(){

    Stack st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;


    return 0;
}