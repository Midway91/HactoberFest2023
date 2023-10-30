public class StringCompression {

    public static String compressString(String input) {
        if (input == null || input.isEmpty()) {
            return input;
        }

        StringBuilder compressed = new StringBuilder();
        int count = 1;

        for (int i = 1; i < input.length(); i++) {
            if (input.charAt(i) == input.charAt(i - 1)) {
                count++;
            } else {
                compressed.append(input.charAt(i - 1));
                if (count > 1) {
                    compressed.append(count);
                }
                count = 1;
            }
        }

        compressed.append(input.charAt(input.length() - 1));
        if (count > 1) {
            compressed.append(count);
        }

        return (compressed.length() < input.length()) ? compressed.toString() : input;
    }

    public static void main(String[] args) {
        String input = "aaaabbbccddeee";
        String compressed = compressString(input);
        System.out.println("Original String: " + input);
        System.out.println("Compressed String: " + compressed);
    }
}
