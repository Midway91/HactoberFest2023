def input_matrix(rows, cols):
    matrix = []
    for i in range(rows):
        row = [int(x) for x in input().split()]
        if len(row) != cols:
            print("Number of elements in the row must match the number of columns.")
            exit(0)
        matrix.append(row)
    return matrix

rows1 = int(input("Enter the number of rows for the first matrix: "))
cols1 = int(input("Enter the number of columns for the first matrix: "))
print("Enter the elements of the first matrix rowise:")
matrix1 = input_matrix(rows1, cols1)

rows2 = int(input("Enter the number of rows for the second matrix: "))
cols2 = int(input("Enter the number of columns for the second matrix: "))
print("Enter the elements of the second matrix rowise:")
matrix2 = input_matrix(rows2, cols2)

result = [[0 for x in range(cols2)] for x in range(rows1)]

for i in range(rows1):
    for j in range(cols2):
        for k in range(cols1):
            result[i][j] += matrix1[i][k] * matrix2[k][j]

print("Resultant Matrix:")
for row in result:
    print(row)