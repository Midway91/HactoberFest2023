public class Power_of_Two {


    class Solution {
        public boolean isPowerOfTwo(int n) {
            int cnt = 0;
            while (n > 0) {
                cnt += (n & 1);
                n >>= 1;
            }
            return cnt == 1;

        }
    }
}
class Solution {
    public boolean isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
}
