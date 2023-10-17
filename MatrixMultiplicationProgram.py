def matrix_multiply(A, B):
    # Get the number of rows and columns for each matrix
    rows_A = len(A)
    cols_A = len(A[0])
    rows_B = len(B)
    cols_B = len(B[0])

    # Check if the matrices can be multiplied
    if cols_A != rows_B:
        return "Matrices cannot be multiplied. The number of columns in A must be equal to the number of rows in B."

    # Create an empty result matrix
    result = [[0 for _ in range(cols_B)] for _ in range(rows_A)]

    # Perform matrix multiplication
    for i in range(rows_A):
        for j in range(cols_B):
            for k in range(cols_A):
                result[i][j] += A[i][k] * B[k][j]

    return result

# Example matrices
matrix_A = [
    [1, 2],
    [3, 4]
]

matrix_B = [
    [5, 6],
    [7, 8]
]

# Multiply the matrices
result = matrix_multiply(matrix_A, matrix_B)

# Print the result
for row in result:
    print(row)
