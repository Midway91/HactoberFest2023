//bubble sort in c
#include <stdio.h>
#include <conio.h>
int main()
{
    int arr[100], num, i, j;
    int temp;
    printf("How much you want to enter num: ");
    scanf("%d", &num);
    printf("Enter the number: ");
    for (i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < num - 1; i++)
    {
        for (j = 0; j < num - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Sorted Array are: ");
    for (i = 0; i < num; i++)
    {
        printf("%d,", arr[i]);
    }

    return 0;
}