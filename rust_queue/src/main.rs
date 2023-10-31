use std::collections::VecDeque;
use std::io;

#[derive(Debug)]
struct Queue<T> {
    items: VecDeque<T>,
}

impl<T> Queue<T> {
    fn new() -> Self {
        Queue {
            items: VecDeque::new(),
        }
    }

    fn enqueue(&mut self, item: T) {
        self.items.push_back(item);
    }

    fn dequeue(&mut self) -> Option<T> {
        self.items.pop_front()
    }

    fn peek(&self) -> Option<&T> {
        self.items.front()
    }

    fn is_empty(&self) -> bool {
        self.items.is_empty()
    }
}

fn main() {
    let mut queue = Queue::new();

    loop {
        println!("Choose an operation:");
        println!("1: Enqueue");
        println!("2: Dequeue");
        println!("3: Peek");
        println!("4: Check if empty");
        println!("5: Quit");

        let mut choice = String::new();
        io::stdin()
            .read_line(&mut choice)
            .expect("Failed to read line");

        match choice.trim().parse::<u32>() {
            Ok(1) => {
                println!("Enter a value to enqueue:");
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
                queue.enqueue(value);
                println!("Value enqueued.");
            }
            Ok(2) => match queue.dequeue() {
                Some(value) => println!("Dequeued value: {}", value),
                None => println!("Queue is empty."),
            },
            Ok(3) => match queue.peek() {
                Some(value) => println!("Front value: {}", value),
                None => println!("Queue is empty."),
            },
            Ok(4) => {
                if queue.is_empty() {
                    println!("Queue is empty.");
                } else {
                    println!("Queue is not empty.");
                }
            }
            Ok(5) => break,
            _ => println!("Invalid choice. Please try again."),
        }
    }
}
