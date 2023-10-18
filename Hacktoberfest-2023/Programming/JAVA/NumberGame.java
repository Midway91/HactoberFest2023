import java.util.Scanner;

public class NumberGame{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
    
        System.out.println(" --------- Welcome To Gokul's Number Guessing Game ---------");
        System.out.println("---------- No Rules But Only 3 Choices --------------");

        

        // --> step 3 whether the user number and guess number are correct or low or high
         
        int numberOfChoices=3;
        int score =0;
         
        String play = "yes";

        while(play.equals("yes")){
             // -> step 1 generate a random number inbetween 1 - 100;
             int randomNumberToGuess = (int) (Math.random() *100) +1;
             int numberOfTries=0;
           

            while(numberOfTries < numberOfChoices){
                System.out.println("Enter the Guess: ");
                int guess = sc.nextInt();

                if(guess == randomNumberToGuess){
                    System.out.println("Congrats! you guessed the number correctly ");
                    score++;
                    break;
                }
                else if(guess > randomNumberToGuess){
                    System.out.println("Your Guess is too high! Try Again!");
                }
                else{
                    System.out.println("Your Guess is too low! Try Again! ");
                }
                numberOfTries ++;
          }
          if(numberOfTries == numberOfChoices){
            System.out.println("Out of choices Oops ");
          }

          System.out.println("Do you want to play again? Yes or No");
          play = sc.next().toLowerCase();
       } 

       System.out.println("You won " + score + " times ");

       sc.close();
   }
}