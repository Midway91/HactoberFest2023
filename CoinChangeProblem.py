// JavaScript Implementation

// Function to check if it is possible to make a change of
// target cents using exactly k coins from the given coins
// array of size n
function can_make_change(target, k, coins, n) {
	// If target and k are both 0, then we have found a
	// valid combination of coins
	if (target === 0 && k === 0) {
		return true;
	}
	// If n becomes 0 or target or k becomes negative, then
	// the current combination of coins is not valid
	if (n === 0 || target < 0 || k < 0) {
		return false;
	}
	// we can either include the current coin or exclude it
	// We check if it is possible to make the change by
	// including the current coin or excluding it
	return can_make_change(target - coins[n - 1], k - 1, coins, n) || can_make_change(target, k, coins, n - 1);
}

let n = 5;
let k = 3;
let target = 11;
let coins = [1, 10, 5, 8, 6];

// Check if it is possible to make the change using 'k'
// coins from the 'coins' array to get 'target' cents
let result = can_make_change(target, k, coins, n);

// Print the result
if (result) {
	console.log("1");
} else {
	console.log("0");
}

// This code is contributed by Tapesh(tapeshdua420)
