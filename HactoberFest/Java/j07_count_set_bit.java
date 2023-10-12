  

public class j07_count_set_bit {

    static int countSetBits(int n) {
        int count = 0;
        while (n > 0) {
            n &= (n - 1);
            count++;
        }
        return count;
    }

    public static void main(String args[]) {
        int i = 3;
        System.out.println(countSetBits(i));
    }
}

