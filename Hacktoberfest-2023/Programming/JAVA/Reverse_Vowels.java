// Problem Statement: Reverse vowels in a given string

import java.util.*;
public class Reverse_Vowels {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a string");
        String s = sc.nextLine();
        s = reverseVowels(s);
        System.out.println("The string with reverse vowels: ");
        System.out.println(s);
    }

    private static String reverseVowels(String s) {
        String vowel = "AEIOUaeiou";
        int end = s.length() - 1;
        char ar[] = s.toCharArray();
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (vowel.indexOf(ch) >= 0) {
                for (int j = end; j > i; j--) {
                    char c2 = s.charAt(j);
                    if (vowel.indexOf(c2) >= 0) {
                        char t = ar[i];
                        ar[i] = ar[j];
                        ar[j] = t;
                        end = j - 1;
                        break;
                    }
                }
            }
        }
        return new String(ar, 0, s.length());
    }

}
