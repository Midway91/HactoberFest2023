public class MatrixMultiplication {

    public static int[][] multiplyMatrices(int[][] matrix1, int[][] matrix2) {
        int rows1 = matrix1.length;
        int cols1 = matrix1[0].length;
        int cols2 = matrix2[0].length;

        if (cols1 != matrix2.length) {
            throw new IllegalArgumentException("Matrix dimensions are incompatible for multiplication");
        }

        int[][] result = new int[rows1][cols2];

        for (int i = 0; i < rows1; i++) {
            for (int j = 0; j < cols2; j++) {
                for (int k = 0; k < cols1; k++) {
                    result[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }

        return result;
    }

    public static void printMatrix(int[][] matrix) {
        for (int[] row : matrix) {
            for (int num : row) {
                System.out.print(num + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int[][] matrix1 = {
                {1, 2},
                {3, 4}
        };

        int[][] matrix2 = {
                {5, 6},
                {7, 8}
        };

        int[][] result = multiplyMatrices(matrix1, matrix2);

        System.out.println("Matrix 1:");
        printMatrix(matrix1);

        System.out.println("Matrix 2:");
        printMatrix(matrix2);

        System.out.println("Result of multiplication:");
        printMatrix(result);
    }
}
