class Main {
  static void sort(String []arr){
  int l=arr.length;
  for(int i=0;i<l-1;i++){
       int small=i;
    for (int j=i+1;j<l;j++){
      if (arr[j].compareTo(arr[small])<0){
      small=j;  }}
     String temp=arr[small];     
       arr[small]=arr[i];
    arr[i]=temp;
     }
    for(int j=0;j<l;j++){
      System.out.print(arr[j]+" ");
    }
   }
  public static void main(String[] args) {
    String[]arr={"AppleGreen","Apple","Orange","Mango"};
    sort(arr);
  }
}
