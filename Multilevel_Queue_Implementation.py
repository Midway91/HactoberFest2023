class MultilevelQueue:
    def __init__(self, num_queues):
        self.queues = [[] for _ in range(num_queues)]

    def enqueue(self, task, priority):
        if 0 <= priority < len(self.queues):
            self.queues[priority].append(task)
        else:
            print("Invalid priority level")

    def dequeue(self):
        for queue in self.queues:
            if queue:
                return queue.pop(0)
        return None

    def __str__(self):
        return "\n".join([f"Queue {i}: {queue}" for i, queue in enumerate(self.queues)])

# Example usage
if __name__ == "__main__":
    num_queues = 3  # Define the number of priority levels
    mq = MultilevelQueue(num_queues)

    # Enqueue some tasks with different priorities
    mq.enqueue("Task A", 0)
    mq.enqueue("Task B", 1)
    mq.enqueue("Task C", 2)
    mq.enqueue("Task D", 1)
    mq.enqueue("Task E", 0)

    # Display the contents of the queues
    print("Initial queues:")
    print(mq)

    # Dequeue tasks
    print("\nDequeue operations:")
    for _ in range(5):
        task = mq.dequeue()
        if task:
            print(f"Dequeued task: {task}")
        else:
            print("No tasks left in the queues")

    # Display the contents of the queues after dequeueing
    print("\nUpdated queues:")
    print(mq)
