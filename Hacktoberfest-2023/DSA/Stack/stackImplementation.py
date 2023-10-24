# Python program to implement stack and it's operations using python lists
# use class for defining stack for simple understanding
class Stack:
    # initialize top of stack with it's maximum size
    def __init__(self, size):
        self.size = size
        self.top = -1
        self.stack = []

    def isFull(self):
        if self.top >= self.size - 1:
            return True
        else:
            return False

    def isEmpty(self):
        if self.top == -1:
            return True
        else:
            return False

    # Push method for the stack
    def pushToStack(self, element):
        if self.isFull():
            print("Stack is full!! Push element not possible.")
        else:
            self.top += 1
            self.stack.insert(self.top, element)

    # Peek method for the stack
    def peekInStack(self):
        if self.isEmpty():
            print("Stack Empty.")
        else:
            print(
                f"The top element is {self.stack[self.top]} and the top is {self.top}"
            )

    # Pop method for the stack
    def popFromStack(self):
        if self.isEmpty():
            print("Stack is empty!!Pop element not possible.")
        else:
            poppedElement = self.stack[(self.top)]
            self.stack = self.stack[: self.top]
            self.top -= 1
            print(f"The popped element is {poppedElement}")

    # Display method for the stack
    def displayStack(self):
        if self.isEmpty():
            print("Stack Empty.")
        else:
            for i in range(self.top, -1, -1):
                print(self.stack[i])


# Take size for the stack
stackSize = int(input("Enter the max size of the stack: "))
# Initialize a stack object with the size
stackObject = Stack(stackSize)
# Run the menu until the user chooses to terminate
while 1:
    print(
        """Enter Your Choice:
          1.Push to stack
          2.Pop from stack
          3.Peek
          4.Display
          5.Exit
          """
    )
    choice = int(input("Enter Your choice:"))
    if choice == 1:
        element = int(input("Enter element to be pushed:"))
        stackObject.pushToStack(element)
    elif choice == 2:
        stackObject.popFromStack()
    elif choice == 3:
        stackObject.peekInStack()
    elif choice == 4:
        print("The elements of stack are:\n")
        stackObject.displayStack()
    elif choice == 5:
        print("Exiting...")
        break
    else:
        print("Wrong choice!!")
