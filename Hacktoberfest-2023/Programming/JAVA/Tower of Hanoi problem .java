import java.util.Scanner;

public class TowerOfHanoi {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of disks: ");
        int numDisks = scanner.nextInt();

        // Towers are represented as A, B, C
        char source = 'A';
        char auxiliary = 'B';
        char destination = 'C';

        towerOfHanoi(numDisks, source, destination, auxiliary);
    }

    public static void towerOfHanoi(int numDisks, char source, char destination, char auxiliary) {
        if (numDisks == 1) {
            System.out.println("Move disk 1 from " + source + " to " + destination);
            return;
        }

        towerOfHanoi(numDisks - 1, source, auxiliary, destination);
        System.out.println("Move disk " + numDisks + " from " + source + " to " + destination);
        towerOfHanoi(numDisks - 1, auxiliary, destination, source);
    }
}
