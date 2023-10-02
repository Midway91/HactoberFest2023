<script>
// Javascript code to implement the approach


// Returns location of key, or -1 if not found
function BinarySearch(A, l, r, key) {
let m;

while (l < r) {
	m = l + (r - l) / 2;

	if (A[m] == key) // first comparison
	return m;

	if (A[m] < key) // second comparison
	l = m + 1;
	else
	r = m - 1;
}

return -1;
}

// This code is contributed by gfgking
</script>
