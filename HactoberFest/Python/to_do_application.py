class TodoList:
    def __init__(self):
        self.tasks = []

    def add_task(self, task):
        self.tasks.append(task)

    def remove_task(self, task):
        if task in self.tasks:
            self.tasks.remove(task)

    def list_tasks(self):
        for i, task in enumerate(self.tasks, start=1):
            print(f"{i}. {task}")

    # Additional feature: Mark tasks as complete
    def complete_task(self, task):
        if task in self.tasks:
            print(f"Completed: {task}")
            self.remove_task(task)

# Example usage
my_todo_list = TodoList()
my_todo_list.add_task("Buy groceries")
my_todo_list.add_task("Finish homework")
my_todo_list.list_tasks()
my_todo_list.complete_task("Buy groceries")
my_todo_list.list_tasks()
