import java.util.Scanner;

class PalindromeChecker {
    public static void main(String[] args){
        
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a string:");
        String s = sc.nextLine();
        
        for(int i=0; i<s.length()/2; i++)
        {
            if(s.charAt(i)!=s.charAt(s.length()-i-1))
            {
                System.out.println('"'+s+'"'+" is not a palindrome string.");
                return;
            }
        }
        
        System.out.println('"'+s+'"'+" is a palindrome string.");
    }
}
