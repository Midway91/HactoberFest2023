#include <iostream>

// returns higher value
#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {

    // how many n'th terms
    int sequences = 10;
    
    int a = 0;
    int b = 0;
    printf("%d ", a); // start 0
    while (sequences > 0)
    {
        int val = max(a + b, 1);
        a = b;
        b = val;
        printf("%d ", val);
        sequences--;
    }

    return 0;
}
