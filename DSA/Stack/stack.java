package DSA;

import java.util.Stack;

public class stack {
    public static void insertatbottom(int data, Stack<Integer> s) {
        if (s.isEmpty()) {
            s.push(data);
            return;
        }
        int top = s.pop();
        insertatbottom(data, s);
        s.push(top);
    }

    public static void ReverseofStack(Stack<Integer> s) {
        Stack<Integer> reversed = new Stack<>();
        while (!s.isEmpty()) {
            int top = s.pop();
            reversed.push(top);
        }
        while (!reversed.isEmpty()) {
            System.out.println(reversed.peek());
            s.push(reversed.pop());
        }
    }

    public static void main(String[] args) {
        Stack<Integer> s = new Stack<>();
        s.push(9);
        s.push(2);
        s.push(3);
        s.push(4);
        ReverseofStack(s);
        insertatbottom(5, s);

        while (!s.isEmpty()) {
            System.out.println(s.peek());
            s.pop();
        }
    }
}

