import java.util.Scanner;

/**
 * N-Queens Problem:
 * @author Rishab Kumar (<a href="https://github.com/Rishab-Kumar-R">Git-Rishab-Kumar-R</a>)
 * Problem Statement:
 * Given an N x N chessboard, the task is to find and return all arrangements
 * in which N queens can be placed on the board such that no two queens attack each other.
 *
 * Example:
 * For N = 6, there are 4 possible arrangements:
 * Arrangement 1:
 * ".Q....",
 * "...Q..",
 * ".....Q",
 * "Q.....",
 * "..Q...",
 * "....Q."
 *
 * Arrangement 2:
 * "..Q...",
 * ".....Q",
 * ".Q....",
 * "....Q.",
 * "Q.....",
 * "...Q.."
 *
 * Arrangement 3:
 * "...Q..",
 * "Q.....",
 * "....Q.",
 * ".Q....",
 * ".....Q",
 * "..Q..."
 *
 * Arrangement 4:
 * "....Q.",
 * "..Q...",
 * "Q.....",
 * ".....Q",
 * "...Q..",
 * ".Q...."
 *
 * Brute Force Approach:
 * Generate all possible arrangements to place N queens on an N x N board.
 * Check each board to ensure queens are placed safely. Include the arrangement in
 * the solution set if it is safe, otherwise, ignore it.
 *
 * Optimized Solution (Backtracking):
 * Start with the first column and place a queen in the first row.
 * Try placing the queen in a row in the second column.
 * If placing the second queen in the second column attacks any of the previous queens,
 * change the row in the second column. Otherwise, move to the next column and try to place the next queen.
 * If there is no row where a queen can be placed such that it doesn't attack previous queens,
 * go back to the previous column and change the row of the previous queen.
 * Keep doing this until the last queen is placed safely.
 * If there is no such way, return an empty list as the solution.
 */

public class NQueens {

    /**
     * Solves the N-Queens problem and prints the solutions.
     *
     * @param boardSize The size of the chessboard (number of rows and columns).
     */
    public static void solveNQueens(int boardSize) {
        if (boardSize < 1) {
            System.out.println("Invalid board size. Please enter a positive integer.");
            return;
        }

        if (boardSize < 4) {
            System.out.println("No solution exists for board size less than 4.");
            return;
        }

        int[] queensInRows = new int[boardSize];
        solveNQueensUtil(boardSize, 0, queensInRows);
    }


    /**
     * Recursive utility function to solve the N-Queens problem.
     *
     * @param boardSize      The size of the chessboard.
     * @param currentRow     The current row being considered.
     * @param queensInRows   Array to store the column positions of queens.
     */
    private static void solveNQueensUtil(int boardSize, int currentRow, int[] queensInRows) {
        // If we have placed queens in all rows, print the solution
        if (currentRow == boardSize) {
            printSolution(queensInRows);
            return;
        }

        // Try placing a queen in each column of the current row
        for (int currentCol = 0; currentCol < boardSize; currentCol++) {
            if (isSafe(currentRow, currentCol, queensInRows)) {
                // Place the queen and move on to the next row
                queensInRows[currentRow] = currentCol;
                solveNQueensUtil(boardSize, currentRow + 1, queensInRows);
            }
        }
    }

    /**
     * Checks if placing a queen at the current position is safe.
     *
     * @param currentRow     The current row.
     * @param currentCol     The current column.
     * @param queensInRows   Array storing queen positions in previous rows.
     * @return True if placing a queen is safe, false otherwise.
     */
    private static boolean isSafe(int currentRow, int currentCol, int[] queensInRows) {
        // Check if placing a queen at the current position is safe
        for (int previousRow = 0; previousRow < currentRow; previousRow++) {
            int previousCol = queensInRows[previousRow];

            // Check if there is a queen in the same column or diagonals
            if (previousCol == currentCol || Math.abs(previousRow - currentRow) == Math.abs(previousCol - currentCol)) {
                return false;
            }
        }
        return true;
    }

    /**
     * Prints the chessboard with queens placed.
     *
     * @param queensInRows   Array storing queen positions for each row.
     */
    private static void printSolution(int[] queensInRows) {
        // Print the chessboard with queens placed
        int boardSize = queensInRows.length;
        for (int queensInRow : queensInRows) {
            for (int col = 0; col < boardSize; col++) {
                if (queensInRow == col) {
                    System.out.print("Q ");
                } else {
                    System.out.print(". ");
                }
            }
            System.out.println();
        }
        System.out.println();
    }

    /**
     * Main method to take user input and solve the N-Queens problem.
     *
     * @param args Command line arguments (not used in this program).
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the board size (N): ");
        int boardSize = scanner.nextInt();

        // Added edge case handling for board sizes less than 4
        if (boardSize < 1) {
            System.out.println("Invalid board size. Please enter a positive integer.");
        } else {
            solveNQueens(boardSize);
        }

        scanner.close();
    }
}
