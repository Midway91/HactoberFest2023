public class NQueenProblem {
	final int N = 4;

	// A utility function to print solution
	void printSolution(int board[][])
	{
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (board[i][j] == 1)
					System.out.print("Q ");
				else
					System.out.print(". ");
			}
			System.out.println();
		}
	}

	boolean isSafe(int board[][], int row, int col)
	{
		int i, j;

		// Check this row on left side
		for (i = 0; i < col; i++)
			if (board[row][i] == 1)
				return false;

		// Check upper diagonal on left side
		for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
			if (board[i][j] == 1)
				return false;

		// Check lower diagonal on left side
		for (i = row, j = col; j >= 0 && i < N; i++, j--)
			if (board[i][j] == 1)
				return false;

		return true;
	}

	// A recursive to solve N Queen problem
	boolean solveNQUtil(int board[][], int col)
	{
		// Base case: If all queens are placed
		// then return true
		if (col >= N)
			return true;

		// Consider this column and try placing
		// this queen in all rows one by one
		for (int i = 0; i < N; i++) {
			
			// Check if the queen can be placed on
			// board[i][col]
			if (isSafe(board, i, col)) {
				
				// Place this queen in board[i][col]
				board[i][col] = 1;

				if (solveNQUtil(board, col + 1) == true)
					return true;

				board[i][col] = 0; // BACKTRACK
			}
		}
		return false;
	}

	boolean solveNQ()
	{
		int board[][] = { { 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 } };

		if (solveNQUtil(board, 0) == false) {
			System.out.print("Solution does not exist");
			return false;
		}

		printSolution(board);
		return true;
	}

	// Driver program to test above function
	public static void main(String args[])
	{
		NQueenProblem Queen = new NQueenProblem();
		Queen.solveNQ();
	}
}
