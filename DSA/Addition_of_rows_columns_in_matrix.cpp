#include <iostream>
using namespace std;

class TWODARRAY
{
private:
    int A[100][100];
    int m;
    int n;

public:
    void inputmatrix();
    void rowSum();
    void columnSum();
    void display_rowSum();
    void display_columnSum();
    void display_maxrow();
    void display_maxcol();
};

void TWODARRAY::inputmatrix()
{
    cout << "Enter the size of row : ";
    cin >> m;
    cout << "Enter the size of column :";
    cin >> n;

    cout << "\nInput the matrix: " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }
}

void TWODARRAY::rowSum()
{
    int sum;
    for (int i = 0; i < m; i++)
    {
        sum = 0;

        for (int j = 0; j < n; j++)
        {
            sum = sum + A[i][j];
        }

        cout << "Sum of row " << i + 1 << " is: " << sum << endl;
    }
}

void TWODARRAY::columnSum()
{
    int sum;
    for (int i = 0; i < n; i++)
    {
        sum = 0;

        for (int j = 0; j < m; j++)
        {
            sum = sum + A[j][i];
        }

        cout << "Sum of column " << i + 1 << " is: " << sum << endl;
    }
}

void TWODARRAY::display_rowSum()
{
    cout << "\nSum of each row: \n" << endl;
    rowSum();
}

void TWODARRAY::display_columnSum()
{
    cout << "\nSum of each column: \n" << endl;
    columnSum();
}

void TWODARRAY::display_maxrow()
{
    for (int i = 0; i < m; i++)
    {
        int max = A[i][0];

        for (int j = 1; j < n; j++)
        {
            if (A[i][j] > max)
            {
                max = A[i][j];
            }
        }

        cout << "\nMaximum element in row " << i + 1 << " is: " << max << endl;
    }
}

void TWODARRAY::display_maxcol()
{
    for (int i = 0; i < n; i++)
    {
        int max = A[i][0];

        for (int j = 1; j < m; j++)
        {
            if (A[i][j] > max)
            {
                max = A[i][j];
            }
        }

        cout << "\nMaximum element in column " << i + 1 << " is: " << max << endl;
    }
}

int main()
{
    TWODARRAY array1;
    array1.inputmatrix();
    array1.display_rowSum();
    array1.display_columnSum();
    array1.display_maxrow();
    array1.display_maxcol();

    return 0;
}
