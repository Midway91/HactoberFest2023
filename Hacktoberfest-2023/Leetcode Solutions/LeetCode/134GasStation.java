public class Gas_Station {

	public class Solution {
	    public int canCompleteCircuit(int[] gas, int[] cost) {

	        // skip valid check
	        if (gas.length == 0) {
	            return 0;
            }

	        int[] diff = new int[gas.length];
	        for (int i = 0; i < diff.length; i++) {
	            diff[i] = gas[i] - cost[i]; // meaning gas left when arriving next station
	        }

	        int sum = 0;
	        int total = 0;
	        int index = 0;
	        for (int i = 0; i < diff.length; i++) {

	            sum += diff[i];
	            total += diff[i];

	            if (sum < 0)    {
	                sum = 0;
	                index = i + 1; // sum from last loop, i-1, current is pointing to i
	            }

	        }

	        return total >= 0? index : -1;
	    }
	}
}

############

class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int n = gas.length;
        int i = n - 1, j = n - 1;
        int cnt = 0, s = 0;
        while (cnt < n) {
            s += gas[j] - cost[j];
            ++cnt;
            j = (j + 1) % n;
            while (s < 0 && cnt < n) {
                --i;
                s += gas[i] - cost[i];
                ++cnt;
            }
        }
        return s < 0 ? -1 : i;
    }
}
