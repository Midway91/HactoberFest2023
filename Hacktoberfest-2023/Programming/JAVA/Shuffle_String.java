/* Write a function that analyzes how well your previous function randomly shuffles the string */

import java.util.Arrays;
import java.util.Random;

public class StringShuffler {
    public static void main(String[] args) {
        // Test Case
        String originalString = "abcdefg";
        String shuffledString = shuffleString(originalString);
        double quality = analyzeShuffleQuality(originalString, shuffledString);
        System.out.println("Original string: " + originalString);
        System.out.println("Shuffled string: " + shuffledString);
        System.out.println("Shuffle quality: " + quality);
    }

    public static String shuffleString(String str) {
        char[] chars = str.toCharArray();
        Random random = new Random();
        for (int i = chars.length - 1; i > 0; i--) {
            int j = random.nextInt(i + 1);
            char temp = chars[i];
            chars[i] = chars[j];
            chars[j] = temp;
        }
        return new String(chars);
    }

    public static double analyzeShuffleQuality(String original, String shuffled) {
        int hammingDistance = 0;
        for (int i = 0; i < original.length(); i++) {
            if (original.charAt(i) != shuffled.charAt(i)) {
                hammingDistance++;
            }
        }
        return (double) hammingDistance / original.length();
    }
}
