/******************************************************************************
 *  Compute the square root using Newton's method. Package it
 *  in a static method.
 ******************************************************************************/

public class Newton {

    // return the square root of c, computed using Newton's method
    public static double sqrt(double c) {
        if (c < 0) return Double.NaN;
        double EPSILON = 1E-15;
        double t = c;
        while (Math.abs(t - c/t) > EPSILON*t)
            t = (c/t + t) / 2.0;
        return t;
    }

    // overloaded version in which user specifies the error tolerance epsilon
    public static double sqrt(double c, double epsilon) {
        if (c < 0) return Double.NaN;
        double t = c;
        while (Math.abs(t - c/t) > epsilon*t)
            t = (c/t + t) / 2.0;
        return t;
    }


    // test client
    public static void main(String[] args) {

        // parse command-line arguments
        double[] a = new double[args.length];
        for (int i = 0; i < args.length; i++) {
            a[i] = Double.parseDouble(args[i]);
        }

        // compute square root for each command line parameter
        for (int i = 0; i < a.length; i++) {
            double x = sqrt(a[i]);
