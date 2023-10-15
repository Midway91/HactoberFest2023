class Solution {
public:
    int strongPasswordChecker(string password) {
        int n = password.length();

        // character check (replace)
        bool containsUpper = false, containsLower = false, containsDigit = false;
        for (char c : password) {
            if (!containsUpper && isupper(c)) {
                containsUpper = true;
            }
            if (!containsLower && islower(c)) {
                containsLower = true;
            }
            if (!containsDigit && isdigit(c)) {
                containsDigit = true;
            }
        }

        int c_swaps = 3 - (containsUpper + containsLower + containsDigit);

        // repeating check (replace)
        vector<int> reps;
        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && password[i] == password[j]) {
                j++;
            }
            reps.push_back(j - i);
            i = j;
        }

        // length (addition, subtraction)
        if (n < 6) {
            int adds = 6 - n;
            return max(adds, c_swaps);
        } else if (n <= 20) {
            int r_swaps = 0;
            for (int elem : reps) {
                r_swaps += elem / 3;
            }
            return max(c_swaps, r_swaps);
        } else {
            int subs = n - 20;
            int r = reps.size();
            for (int i = 0; i < r; i++) {
                if (subs >= 1 && reps[i] % 3 == 0) {
                    reps[i]--;
                    subs--;
                }
            }
            for (int i = 0; i < r; i++) {
                if (subs >= 2 && reps[i] % 3 == 1 && reps[i] > 3) {
                    reps[i] -= 2;
                    subs -= 2;
                }
            }
            for (int i = 0; i < r; i++) {
                if (subs > 0 && reps[i] > 2) {
                    int removed = min(subs, reps[i] - 2);
                    reps[i] -= removed;
                    subs -= removed;
                }
            }

            int r_swaps = 0;
            for (int elem : reps) {
                r_swaps += elem / 3;
            }
            return max(c_swaps, r_swaps) + (n - 20);
        }
    }

};
