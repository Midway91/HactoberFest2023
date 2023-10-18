class matrixMultiplication {
    public static int[][] multiplyMatrices(int[][] matrix1, int[][] matrix2) {
        int rows1= matrix1.length;
        int columns1= matrix1[0].length;
        int columns2= matrix2[0].length;

        int[][] result= new int[rows1][columns2];

        // perform matrix multiplication

        for(int i=0; i<rows1; i++){
            for(int j=0; j<columns2; j++){
                for(int k=0; k<columns1; k++){
                    result[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }

        return result;
    }

    public static void main(String[] args) {
        int[][] matrix1={
            {1,2,3},
            {4,5,6}
        };

        int[][] matrix2={
            {7,8},
            {9,10},
            {11,12}
        };

        int[][] product= multiplyMatrices(matrix1, matrix2);

        System.out.println("Matrix1:");
        printMatrix(matrix1);

        System.out.println("Matrix2:");
        printMatrix(matrix2);

        System.out.println("Product of matrices:");
        printMatrix(product);
    }

    public static void printMatrix(int[][] matrix) {
        int rows= matrix.length;
        int columns= matrix[0].length;

        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                System.out.print(matrix[i][j]+" ");
            }
            System.out.println();
        }
        System.out.println();
    }
}
