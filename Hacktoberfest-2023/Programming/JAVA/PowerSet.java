/*This is the code for power set(finding all subsequences of a string) using bit manipulation */

import java.util.*;

public class PowerSet{
    public static ArrayList<String> powerset(String s)
    {
        ArrayList<String> list = new ArrayList<>();
        int n = s.length();
        int pow = (int)Math.pow(2,n);
        
        for(int i = 1;i<pow;i++){
            String str = "";
            for(int j = 0;j<n;j++){
                if((i&(1<<j))!=0){
                    str+=s.charAt(j);
                }
                
            }
            list.add(str);
        }
        Collections.sort(list);
        return list;
    }
    public static void main(String[] args) {
        String s = "abcde";
        System.out.println("All possible subsequences of a string using bit manupilation are-");
        System.out.println(powerset(s));
    }
}