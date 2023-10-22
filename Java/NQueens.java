/*
The N Queen is the problem of placing N chess queens on an N×N chessboard so that no two queens attack each other. For example, the following is a solution for 4 Queen problem.


The expected output is a binary matrix which has 1s for the blocks where queens are placed. For example, following is the output matrix for above 4 queen solution.

              { 0,  1,  0,  0}
              { 0,  0,  0,  1}
              { 1,  0,  0,  0}
              { 0,  0,  1,  0}
 */

import java.util.Scanner;

public class NQueens {
 
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of queens: ");
        int n = sc.nextInt();
        nQueens(n);
    }
 
    private static void nQueens(int noOfQueens) {
        int [] board = new int[noOfQueens];
        placeQueen(board, 0, noOfQueens);
    }
 
    private static void placeQueen(int[] board, int current, int noOfQueens) {
        if (current == noOfQueens) {
            displayQueens(board);
            return;
        }
 
        for (int i = 0; i < noOfQueens; i++) {
            board[current] = i;
            if (noKill(board, current)) {
                placeQueen(board, current + 1, noOfQueens);
            }
        }
    }
 
    private static boolean noKill(int[] board, int currentColumnOfQueen) {
 
        for (int i = 0; i < currentColumnOfQueen; i++) {
            // same row
            if (board[i] == board[currentColumnOfQueen])
                return false;
 
            // Diagonal
            if ((currentColumnOfQueen - i) == Math.abs(board[currentColumnOfQueen]- board[i])) {
                return false;
            }
        }
        return true;
    }
 
    private static void displayQueens(int[] board) {
        System.out.print("\n");
 
        for (int value : board)
            System.out.printf(value + "%3s" ," ");
 
        System.out.print("\n\n");
 
        int n = board.length;
 
        for (int i = 0; i < n; i++) {
            for (int value : board) {
                if (value == i)
                    System.out.print("Q\t");
                else
                    System.out.print("*\t");
            }
            System.out.print("\n");
        }
    }
}