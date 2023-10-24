import java.util.Random;

public class generator {
    public static void main(String[] args) {
        System.out.println("Password 1: " + generate_password(8, true, true, true, true));
        System.out.println("Password 2: " + generate_password(14, true, false, true, false));
        System.out.println("Password 3: " + generate_password(20, false, true, false, true));
    }

    static String generate_password(int size, boolean upper, boolean lower, boolean number, boolean special) {
        String upper_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        String lower_chars = "abcdefghijklmnopqrstuvwxyz";
        String number_chars = "1234567890";
        String special_chars = "!@#$%^&*()_+-/.,<>?;':\"[]{}\\|`~";

        String chars = "";
        if (upper) {
            chars += upper_chars;
        }
        if (lower) {
            chars += lower_chars;
        }
        if (number) {
            chars += number_chars;
        }
        if (special) {
            chars += special_chars;
        }
        String password = "";
        int count = 0;
        if (upper) {
            password += upper_chars.charAt((int) (Math.random() * upper_chars.length()));
            count++;
        }
        if (lower) {
            password += lower_chars.charAt((int) (Math.random() * lower_chars.length()));
            count++;
        }
        if (number) {
            password += number_chars.charAt((int) (Math.random() * number_chars.length()));
            count++;
        }
        if(special){
            password += special_chars.charAt((int) (Math.random() * special_chars.length()));
            count++;
        }
        Random rnd = new Random();
        while (password.length() < size-count) {
            int index = (int) (rnd.nextFloat() * chars.length());
            password += chars.charAt(index);
        }
        String shuffled = "";
        while (password.length() > 0) {
            int index = (int) (rnd.nextFloat() * password.length());
            shuffled += password.charAt(index);
            password = password.substring(0, index) + password.substring(index + 1);
        }
        return shuffled;
    }
}
