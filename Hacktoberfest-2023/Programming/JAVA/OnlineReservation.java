import java.util.Scanner;

public class OnlineReservation {
    private static final int MAX_SEATS = 10;
    private static boolean[] seats = new boolean[MAX_SEATS];
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.println("Hello User\n");
        System.out.println("If your Login already exists, then, click 1");
        System.out.println("If your Login does not exist, then, click 2");

        int choice = scanner.nextInt();

        if (choice == 1) {
            while (true) {
                int option = displayOptions();
                switch (option) {
                    case 1:
                        viewSeatMatrix();
                        break;
                    case 2:
                        reserveSeat();
                        break;
                    case 3:
                        cancelReservation();
                        break;
                    case 4:
                        generatePNR();
                        break;
                    case 5:
                        exitProgram();
                        break;
                    default:
                        System.out.println("Please select a valid option.");
                }
            }
        } else if (choice == 2) {
            createAccount();
        } else {
            System.out.println("Invalid choice.");
        }
    }

    private static int displayOptions() {
        System.out.println("Dear User, Please select an option:");
        System.out.println("1. View Seat Matrix");
        System.out.println("2. Reserve Seat");
        System.out.println("3. Cancel Reservation");
        System.out.println("4. PNR Generation");
        System.out.println("5. Exit");
        return scanner.nextInt();
    }

    private static void viewSeatMatrix() {
        System.out.println("\nThe Current Available Seat Map is as follows: \n");
        for (int i = 0; i < MAX_SEATS; i++) {
            if (seats[i]) {
                System.out.print("X ");
            } else {
                System.out.print((i + 1) + " ");
            }
        }
        System.out.println();
    }

    private static void reserveSeat() {
        System.out.println("Please Enter the Seat Number (1-" + MAX_SEATS + "): ");
        int seat = scanner.nextInt();
        if (seat < 1 || seat > MAX_SEATS) {
            System.out.println("Invalid Seat Number. Please select a valid seat.");
        } else if (seats[seat - 1]) {
            System.out.println("Seat is already reserved. Please select a different seat.");
        } else {
            seats[seat - 1] = true;
            System.out.println("Your seat is reserved.");
        }
    }

    private static void cancelReservation() {
        System.out.println("Enter your Seat Number (1-" + MAX_SEATS + "): ");
        int seat = scanner.nextInt();
        if (seat < 1 || seat > MAX_SEATS) {
            System.out.println("Invalid Seat Number. Please select a valid seat.");
        } else if (!seats[seat - 1]) {
            System.out.println("Seat is not reserved yet.");
        } else {
            seats[seat - 1] = false;
            System.out.println("Reserved seat is cancelled.");
        }
    }

    private static void generatePNR() {
        long random_number = (long) (Math.random() * (10000 - 0 + 1) + 0);
        System.out.println("Your PNR Number is: " + random_number);
    }

    private static void createAccount() {
        System.out.println("Please create your account.");
        System.out.println("Please create your UserName:");
        String newUsername = scanner.next();
        System.out.println("Please create your Password:");
        String newPassword = scanner.next();
        // Store the new user's information securely (e.g., in a database).
        System.out.println("Account created successfully.");
    }

    private static void exitProgram() {
        System.out.println("Exiting the program.");
        System.exit(0);
    }
}