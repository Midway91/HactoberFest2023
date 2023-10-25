
package StudentUse;

import static java.lang.Math.min;

public class Fraction {
    private int num;
    private int den;
    public Fraction(int num , int den){
        this.den = den;
        this.num = num;
        simplify();
    }

    public void print() {

        if (den == 1){
            System.out.println(num);
        }
        else {
            System.out.println(num + " / " + den);
        }
    }
    public void setNum(int num) {
        this.num = num;
        simplify();
    }
    public void setDen(int den) {

        this.den = den;
        simplify();

    }
    public int getNum() {
        return num;
    }
    public int getDen() {
        return den;
    }

    public void simplify(){
        int gcd =1;
        int smaller = min( num , den);
        for(int i = 2; i <= smaller; i++){
            if( num%i==0 && den%i==0){
                gcd = i;
            }
        }
        num = num/gcd;
        den = den/gcd;

    }

    public void add(Fraction f2) {
        this.num = this.num* f2.den + this.den* f2.num;
        this.den = this.den* f2.den;
        print();
    }
}


//Main Function: FractionUse

package StudentUse;

public class FractionUse {
    public static void main(String[] args){
        Fraction f1 = new Fraction(2 , 20);
        f1.getNum();
        f1.getDen();
        f1.print();

        f1.setNum(3);
        f1.setDen(9);

        //int d = f1.getDen();
        //System.out.println();
        f1.print();

        //f1.setNum();
        //f1.setDen();
        //f1.print();
        Fraction f2 = new Fraction(30 , 28);
        f2.print();
        f1.add(f2);

    }
}

// The provided code consists of two Java classes: Fraction and FractionUse, which are used to work with fractions and demonstrate their usage. Let's break down the code and explain its functionality:

// Fraction Class:
// The Fraction class is used to represent a fraction and provides methods for initializing, printing, setting, getting, simplifying, and adding fractions.

// Constructor: The Fraction class has a constructor that takes two parameters, num (numerator) and den (denominator). It initializes the num and den instance variables with the provided values and then calls the simplify method to simplify the fraction.

// print Method: The print method prints the fraction in its simplest form. If the denominator is 1, it only prints the numerator as a whole number. Otherwise, it prints the fraction in the form "numerator / denominator."

// setNum and setDen Methods: These methods allow you to set the numerator and denominator of the fraction, respectively. After setting a new value, the simplify method is called to ensure the fraction remains in its simplest form.

// getNum and getDen Methods: These methods return the numerator and denominator of the fraction, respectively.

// simplify Method: The simplify method calculates the greatest common divisor (GCD) of the numerator and denominator and simplifies the fraction by dividing both the numerator and denominator by the GCD.

// add Method: The add method takes another Fraction object (f2) and adds it to the current fraction. It modifies the numerator and denominator of the current fraction to represent the sum and then prints the result.

// FractionUse Class (Main Function):
// The FractionUse class contains the main function, which demonstrates the usage of the Fraction class.

// It creates a Fraction object f1 with an initial value of 2/20, prints it, sets the numerator and denominator to new values (3 and 9, respectively), and then prints the simplified fraction.

// Another Fraction object f2 is created with an initial value of 30/28, and it is also printed.

// The add method is called on f1 to add f2 to it. The result is printed.
