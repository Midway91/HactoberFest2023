import java.util.Scanner;

public class TowerOfHanoi {
    static void towerOfHanoi(int numberOfRings, String src, String helper, String dest) {
        if (numberOfRings == 1) {
            System.out.println("Transfer disk " + numberOfRings + " from " + src + " to " + dest);
            return;
        }
        // transfer top n-1 from src to helper using dest as helper
        towerOfHanoi(numberOfRings - 1, src, dest, helper);
        // transfer nth from src to dest
        System.out.println("transfer disk " + numberOfRings + " from " + src + " to " + helper);
        // transfer n-1 from helper to dest using src as 'helper'
        towerOfHanoi(numberOfRings - 1, helper, src, dest);
    }

    public static void main(String[] args) {
        System.out.println("RULES OF TOWER OF HANOI : ");
        System.out.println("1. You can only move one disk at a time.");
        System.out.println("2. You cannot place a bigger disk on top of a smaller disk.");
        System.out.println("Enter the number of rings : ");
        Scanner scanner = new Scanner(System.in);
        int input = scanner.nextInt();
        towerOfHanoi(input, "A", "B", "C");
    }
}
