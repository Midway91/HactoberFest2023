public class LevenshteinDistance {

    public static int calculateDistance(String str1, String str2) {
        int[][] dp = new int[str1.length() + 1][str2.length() + 1];

        for (int i = 0; i <= str1.length(); i++) {
            for (int j = 0; j <= str2.length(); j++) {
                if (i == 0) {
                    dp[i][j] = j;
                } else if (j == 0) {
                    dp[i][j] = i;
                } else if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + Math.min(Math.min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
                }
            }
        }

        return dp[str1.length()][str2.length()];
    }

    public static void main(String[] args) {
        String str1 = "kitten";
        String str2 = "sitting";

        int distance = calculateDistance(str1, str2);
        System.out.println("The edit distance between '" + str1 + "' and '" + str2 + "' is: " + distance);
    }
}
