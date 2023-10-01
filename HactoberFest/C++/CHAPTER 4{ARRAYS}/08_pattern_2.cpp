#include <iostream>
using namespace std;
int main()
{
    int count = 1;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i >= j)
            {

                cout << "*"
                     << "\t";
            }
        }

        cout << endl;
    }
    return 0;
}