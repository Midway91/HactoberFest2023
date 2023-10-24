import java.util.ArrayList;
import java.util.List;

public class Allparanthesis {
     public  static List<String> generateParenthesis(int n) {
        List <String> ways=new ArrayList<>(2*n);
        int m=n;
        int total=0;
        parant( n,m,total,ways,new String());
        return ways;
    }
    public static void parant(int n, int m,int total,List<String> ways,String s){
        if(n==0&&m==0){
            ways.add(s);
        return;
        }
        else{
        if(n>0){
            parant(n-1,m,total+1,ways,s+"(");
        }
        if(m>n)
        parant(n,m-1,total+1,ways,s+")");
    }
    }
    public static void main(String args[]){
        int n=3;
         List <String> ways=new ArrayList<>(2*n);
        int m=3;
        int total=0;
        String s="";
        parant( n,m,total,ways,s);
        System.out.println(ways.toString());
    }
}
