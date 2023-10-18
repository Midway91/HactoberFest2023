import java.util.*;

public class AverageOfNumber{
     public static void main(String[] args){
          Scanner sc = new Scanner(System.in);
          int n = sc.nextInt();
          int sum=0;
          for(int i=1;i<=n;i++){
               sum+=sc.nextInt();
          }
          int average = sum/n;
          System.out.println(average);
     }
}