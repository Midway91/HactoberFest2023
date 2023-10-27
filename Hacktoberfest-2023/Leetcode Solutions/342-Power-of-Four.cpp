class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n > 0 && (n & (n - 1)) == 0) {
            int zero_count = 0;
            while (n > 1) {
                zero_count++;
                n >>= 1;
            }
            return zero_count % 2 == 0;
        }
        return false;
    }
};
