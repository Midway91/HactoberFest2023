public class StringAll {
    public static void main(String[] args) {
        String str = "Ankit Lakra";
        
        // Length of the string
        int length = str.length();
        System.out.println("Length: " + length);
        
        // Concatenation
        String concatenated = str.concat(" Welcome");
        System.out.println("Concatenated: " + concatenated);

        //charAt
        char ch = str.charAt(1);
        System.out.println("CharAt: " + ch);
        
        // Starts with
        Boolean start = str.startsWith("A");
        System.out.println("Start with: " + start);

        // End with
        Boolean end = str.endsWith("A");
        System.out.println("End with: " + end);

        // Equals
        Boolean eq = str.equals("A");
        System.out.println("Is Equal: " + eq);

        // Index of a character
        int indexOfW = str.indexOf('k');
        System.out.println("Index of 'K': " + indexOfW);   

        // Last index of character
        int indexOfR = str.lastIndexOf('r');
        System.out.println("Index of 'R': " + indexOfR);  
        
        // Replace
        String replaced = str.replace("Lakra", "MCA");
        System.out.println(replaced);
        
        // Substring
        String substring = str.substring(6);
        System.out.println("Substring: " + substring);

        //String Lowercase
         String lowercase = str.toLowerCase();
         System.out.println("Lowercase: " + lowercase);

        // String Uppercase
        String uppercase = str.toUpperCase();
        System.out.println("Uppercase: " + uppercase);

        // String Trim
        String trim = str.trim();
        System.out.println("Trim: " + trim);

    }
}
