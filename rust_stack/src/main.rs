use std::io;

#[derive(Debug)]
struct Stack<T> {
    items: Vec<T>,
}

impl<T> Stack<T> {
    fn new() -> Self {
        Stack { items: Vec::new() }
    }

    fn push(&mut self, item: T) {
        self.items.push(item);
    }

    fn pop(&mut self) -> Option<T> {
        self.items.pop()
    }

    fn peek(&self) -> Option<&T> {
        self.items.last()
    }

    fn is_empty(&self) -> bool {
        self.items.is_empty()
    }
}

fn main() {
    let mut stack = Stack::new();
    loop {
        println!("Choose an operation:");
        println!("1: Push");
        println!("2: Pop");
        println!("3: Peek");
        println!("4: Check if empty");
        println!("5: Quit");

        let mut choice = String::new();
        io::stdin()
            .read_line(&mut choice)
            .expect("Failed to read line");

        match choice.trim().parse::<u32>() {
            Ok(1) => {
                println!("Enter a value to push:");
                let mut value = String::new();
                io::stdin()
                    .read_line(&mut value)
                    .expect("Failed to read line");
                let value: i32 = match value.trim().parse() {
                    Ok(num) => num,
                    Err(_) => {
                        println!("Invalid input. Please enter a number.");
                        continue;
                    }
                };
                stack.push(value);
                println!("Value pushed.");
            }
            Ok(2) => match stack.pop() {
                Some(value) => println!("Popped value: {}", value),
                None => println!("Stack is empty."),
            },
            Ok(3) => match stack.peek() {
                Some(value) => println!("Top value: {}", value),
                None => println!("Stack is empty."),
            },
            Ok(4) => {
                if stack.is_empty() {
                    println!("Stack is empty.");
                } else {
                    println!("Stack is not empty.");
                }
            }
            Ok(5) => break,
            _ => println!("Invalid choice. Please try again."),
        }
    }
}
