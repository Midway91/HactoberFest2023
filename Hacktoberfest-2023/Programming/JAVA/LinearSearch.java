package HactoberFest2023.HactoberFest.Java;

public class LinearSearch {
    public static void main(String[] args){
        int[] arr= {2,3,5,6,7,8};
        int item= 5;
        int temp=0;

        for(int i=0; i<arr.length; i++){
            if(arr[i]==item){
                System.out.println("item is present at "+i+" index position.");
                temp=temp+1;
            }
        }
        if(temp==0){
            System.out.println("item is not found in the list.");
        }
    } 
}
