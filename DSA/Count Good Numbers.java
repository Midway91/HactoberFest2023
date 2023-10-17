//leetcode --> 1922. Count Good Numbers
class Hactober {
    public static long mod = 1000000000+7;
    public static int countGoodNumbers(long n) {
        long odd=n/2;
        long even=(n+1)/2;
        return (int)(pow(5, even)*pow(4, odd)%mod);
    }
    public static long pow(long x, long n) {
        if(n==0) return 1;
        long temp = pow(x,n/2);
        if(n%2==0){
            return (temp*temp)%mod;
        }
        else{
            return (x*temp*temp)%mod;
        }
    }
    public static void main(String args[])
    {
        //1 <= n <= 10^15
        long n = 1;
        System.out.print(countGoodNumbers(n));
    }
}
