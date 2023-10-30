import java.util.ArrayList;
import java.util.Scanner;

public class ToDoList {
    public static void main(String[] args) {
        ArrayList<String> tasks = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);
        boolean isRunning = true;

        while (isRunning) {
            System.out.println("ToDo List Options:");
            System.out.println("1. Add a task");
            System.out.println("2. View tasks");
            System.out.println("3. Update a task");
            System.out.println("4. Remove a task");
            System.out.println("5. Quit");
            System.out.print("Enter your choice: ");

            int choice = scanner.nextInt();
            scanner.nextLine(); // Consume the newline character

            switch (choice) {
                case 1:
                    System.out.print("Enter a new task: ");
                    String newTask = scanner.nextLine();
                    tasks.add(newTask);
                    System.out.println("Task added: " + newTask);
                    break;
                case 2:
                    if (tasks.isEmpty()) {
                        System.out.println("No tasks in the list.");
                    } else {
                        System.out.println("Tasks in the list:");
                        for (int i = 0; i < tasks.size(); i++) {
                            System.out.println((i + 1) + ". " + tasks.get(i));
                        }
                    }
                    break;
                case 3:
                    if (tasks.isEmpty()) {
                        System.out.println("No tasks in the list.");
                    } else {
                        System.out.print("Enter the task number to update: ");
                        int taskNumber = scanner.nextInt();
                        scanner.nextLine(); // Consume the newline character
                        if (taskNumber >= 1 && taskNumber <= tasks.size()) {
                            System.out.print("Enter the updated task: ");
                            String updatedTask = scanner.nextLine();
                            tasks.set(taskNumber - 1, updatedTask);
                            System.out.println("Task updated.");
                        } else {
                            System.out.println("Invalid task number.");
                        }
                    }
                    break;
                case 4:
                    if (tasks.isEmpty()) {
                        System.out.println("No tasks in the list.");
                    } else {
                        System.out.print("Enter the task number to remove: ");
                        int taskNumber = scanner.nextInt();
                        scanner.nextLine(); // Consume the newline character
                        if (taskNumber >= 1 && taskNumber <= tasks.size()) {
                            String removedTask = tasks.remove(taskNumber - 1);
                            System.out.println("Task removed: " + removedTask);
                        } else {
                            System.out.println("Invalid task number.");
                        }
                    }
                    break;
                case 5:
                    isRunning = false;
                    System.out.println("Goodbye!");
                    break;
                default:
                    System.out.println("Invalid choice. Please select a valid option.");
            }
        }
        scanner.close();
    }
}
