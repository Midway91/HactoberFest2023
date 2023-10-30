package com.Abhi;

public class PatternQuestions {

    public static void main(String[] args) {
//        pattern5(7);
//        pattern6(5);
//        pattern17(4);
//        pattern28(5);
//        pattern30(5);
//        pattern31(5);
//        pattern7(5);
//        pattern8(5);
//        pattern9(5);
//        pattern10(5);
//        pattern11(6);
//        pattern12(5);
//        pattern13(5);
//        pattern14(5);
//        pattern15(5);

    }

    public static void pattern6(int n) {
        /*
             *
            **
           ***
          ****
         *****
        */
        for (int i = 0; i <n ; i++) {
            for(int j=0;j<n-1-i;j++){
                System.out.print(" ");
            }
            for (int stars = 0; stars <=i ; stars++) {
                System.out.print("*");

            }
            System.out.println();

        }
    }
    public static void pattern5(int n){
        /*
         *
         **
         ***
         ****
         *****
         ****
         ***
         **
         *
         */
        for(int i=0;i<2*n-1;i++){
            if(i<n){
                for(int j=0;j<=i;j++){
                    System.out.print("*");
                }
                System.out.println();
            }else{
                for(int j=0;j<2*n-i-1;j++){
                    System.out.print("*");
                }
                System.out.println();
            }
            }



    }
    public static void pattern28(int n){
        /*
             *
            * *
           * * *
          * * * *
         * * * * *
          * * * *
           * * *
            * *
             *
         */
        for (int i = 1; i <2*n; i++) {
            int numberOfCols= i<=n ? i: 2*n-i;        //This statement means if i<=n then numberCols=i else it is equal to 2n-i;
            int numberOfSpaces= n-numberOfCols;
            for (int spaces = 1; spaces <= numberOfSpaces; spaces++) {
                System.out.print(" ");

            }
            for (int cols = 1; cols <= numberOfCols ; cols++) {
                System.out.print("* ");

            }
            System.out.println();


        }
    }
    public static void pattern30(int n){
        /*
             1
           2 1 2
         3 2 1 2 3
       4 3 2 1 2 3 4
     5 4 3 2 1 2 3 4 5

         */
        for(int i=1;i<=n;i++){
            int numberOfSpaces= n-i;
            for (int spaces = 1; spaces <= numberOfSpaces ; spaces++) {
                System.out.print("  ");
            }
            for (int cols1 = i; cols1 >1 ; cols1--) {
                System.out.print(cols1+" ");

            }
            for (int cols2 = 1; cols2 <= i; cols2++) {
                System.out.print(cols2+" ");

            }
            System.out.println();
        }
    }
    public static void pattern17(int n){
        /*
         1
        212
       32123
      4321234
       32123
        212
         1
         */
        for (int row = 1; row <2*n ; row++) {
            int numberOfSpaces= row<=n ? n-row: row-n;
            for (int spaces = 1; spaces <=numberOfSpaces; spaces++) {
                System.out.print("  ");
            }
            int colValue= row<=n ? row:2*n-row;
            for (int cols1 = colValue; cols1 >=1; cols1--) {
                System.out.print(cols1+" ");

            }
            for (int cols2 = 2; cols2 <=colValue ; cols2++) {
                System.out.print(cols2+" ");

            }
            System.out.println();

        }
    }
    public static void pattern31(int n){
        /*
         4 4 4 4 4 4 4
         4 3 3 3 3 3 4
         4 3 2 2 2 3 4
         4 3 2 1 2 3 4
         4 3 2 2 2 3 4
         4 3 3 3 3 3 4
         4 4 4 4 4 4 4
         */
        //This figure is a square.
        int last=2*n-1;
        for (int row = 0; row < last; row++) {

            for (int col = 0; col < last; col++) {
                int indexValue= Math.min(Math.min(row,col),Math.min((last-1-col),(last-1-row)));

                System.out.print(n-indexValue+" ");
            }
            System.out.println();

        }

    }
    public static void pattern7(int n){
        /*
         *****
         ****
         ***
         **
         *
         */
        for (int i = 0; i < n; i++) {
            for (int stars = 0; stars < n-i; stars++) {
                System.out.print("*");

            }
            System.out.println();

        }
    }
    public static void pattern8(int n){
        /*
             *
            ***
           *****
          *******
         *********

         */
        for (int rows = 0; rows < n; rows++) {
            for (int spaces = 0; spaces < n-rows-1; spaces++) {
                System.out.print(" ");
            }
            for (int stars = 0; stars < 2*rows+1; stars++) {
                System.out.print("*");
            }
            System.out.println();


        }
    }
    public static void pattern9(int n){
        /*
         *********
          *******
           *****
            ***
             *
         */
        for (int rows = 0; rows < n; rows++) {
            for (int spaces = 0; spaces <= rows; spaces++) {
                System.out.print(" ");
            }
            for (int stars = 2*rows+1; stars <2*n; stars++) {
                System.out.print("*");
            }
            System.out.println();

        }
    }
    public static void pattern10(int n){
        /*
             *
            * *
           * * *
          * * * *
         * * * * *
         */
        for (int row = 0; row < n; row++) {
            for (int spaces = 0; spaces < n-1-row; spaces++) {
                System.out.print(" ");
            }
            for (int stars = 0; stars < row+1; stars++) {
                System.out.print("* ");

            }
            System.out.println();

        }
    }
    public static void pattern11(int n){
        /*
         * * * * *
          * * * *
           * * *
            * *
             *
         */
        for (int rows = 0; rows < n; rows++) {
            for (int spaces = 0; spaces < rows; spaces++) {
                System.out.print(" ");
            }
            for (int stars = 0; stars < n-rows; stars++) {
                System.out.print("* ");
            }
            System.out.println();

        }
    }
    public static void pattern12(int n){
        /*
         * * * * *
          * * * *
           * * *
            * *
             *
             *
            * *
           * * *
          * * * *
         * * * * *
         */
        for (int row = 0; row < 2*n; row++) {
            int reqSpaces= row<n ? row: 2*n-row-1;
            for (int spaces = 0; spaces < reqSpaces; spaces++) {
                System.out.print(" ");
            }
            int reqStars= row<n? n-row: row-n+1;
            for (int stars = 0; stars < reqStars ; stars++) {
                System.out.print("* ");
            }
            System.out.println();

        }
    }
    public static void pattern13(int n){
        /*
             *
            * *
           *   *
          *     *
         *********
         */
        for (int row = 1; row <= n; row++) {
            //spaces
            for (int spaces = 1; spaces <= n-row; spaces++) {
                System.out.print(" ");
            }
            //stars and spaces.
            for (int i = 1; i <= 2*row-1; i++) {
                if(row==n  || i==1 || i==2*row-1 ){
                    System.out.print("*");
                }else{
                    System.out.print(" ");
                }
            }
            System.out.println();
        }
    }
    public static void pattern14(int n){
        /*
         *********
          *     *
           *   *
            * *
             *
         */
        for (int row = 1; row <=n ; row++) {
            //spaces
            for (int spaces = 1; spaces < row; spaces++) {
                System.out.print(" ");
            }//hollow part and the stars.
            int endPoint= 2*n - (2*row-1);
            for (int i = 1; i <=endPoint ; i++) {
                if(row==1 || i==1 || i==endPoint){
                    System.out.print("*");
                }else{
                    System.out.print(" ");
                }
            }
            System.out.println();
        }
    }
    public static void pattern15(int n){
        /*
             *
            * *
           *   *
          *     *
         *       *
          *     *
           *   *
            * *
             *
         */
        for (int row = 1; row <2*n ; row++) {
            int reqSpaces= row<=n? n-row: row-n;
            //Equation for counting the number of spaces.
            for (int spaces = 0; spaces < reqSpaces; spaces++) {
                System.out.print(" ");
            }
            //equation for first and last star.
            int endPoint= row<=n? 2*row: 2*n - (2*(row-n));
            for (int i = 1; i < endPoint; i++) {
                if(i==1 || i==endPoint-1){          //Could have done the -1 part while making the equation as well but this looked more clean to me :)
                    System.out.print("*");
                }else{
                    System.out.print(" ");
                }
            }
            System.out.println();
        }
    }
    public static void pattern16(int n){
        /*
              1
            1   1
          1   2   1
        1   3   3   1
      1   4   6   4   1
         */


    }

}
