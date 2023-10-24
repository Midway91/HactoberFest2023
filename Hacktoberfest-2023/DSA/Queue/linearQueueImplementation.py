# Python program to implement linear queue and it's operations using python lists


class Queue:
    def __init__(self, size):
        self.front = -1
        self.rear = -1
        self.size = size
        self.queue = [None for i in range(self.size)]

    def isEmpty(self):
        if self.rear == self.front == -1:
            return True
        else:
            return False

    def isFull(self):
        if self.rear == self.size - 1:
            return True
        else:
            return False

    def enqueue(self, element):
        if self.isFull():
            print("Queue is full!! Enqueue not possible.")
        else:
            if self.front == self.rear == -1:
                self.front = self.rear = 0
                self.queue[self.rear] = element
            else:
                self.rear += 1
                self.queue[self.rear] = element
        self.display()

    def dequeue(self):
        if self.isEmpty():
            print("Queue is Empty!!! Dequeue not possible.")
        else:
            if self.front == self.rear:
                print(f"Dequeue Element:{self.queue[self.front]}")
                self.rear = self.front = -1
                self.queue = [None for i in range(self.size)]
            else:
                print(f"Dequeue Element:{self.queue[self.front]}")
                self.front += 1

        self.display()

    def peek(self):
        if self.isEmpty():
            print(
                f"""Queue Empty.
Front Index:{self.front}
Rear Index:{self.rear}
"""
            )
        else:
            print(
                f"""Front element:{self.queue[self.front]}
Front Index:{self.front}
Rear element:{self.queue[self.rear]}
Rear Index:{self.rear}
Queue Max size:{self.size}"""
            )

    def display(self):
        if self.isEmpty():
            print("Queue Empty.")
        else:
            print("Queue:", end=" ")
            for i in range(self.rear, self.front - 1, -1):
                print(self.queue[i], end=" ")
            print("\n")


queueSize = int(input("Enter the size of the Queue:"))
queue = Queue(queueSize)

while 1:
    print(
        """
        1.Enqueue
        2.Dequeue
        3.Peek
        4.Display
        5.Exit
        """
    )
    choice = int(input("Enter Your choice:"))
    if choice == 1:
        element = int(input("Enter element to be enqueue:"))
        queue.enqueue(element)
    elif choice == 2:
        queue.dequeue()
    elif choice == 3:
        queue.peek()
    elif choice == 4:
        print("The elements of queue are:\n")
        queue.display()
    elif choice == 5:
        print("Exiting...")
        break

    else:
        print("Wrong choice!!")

