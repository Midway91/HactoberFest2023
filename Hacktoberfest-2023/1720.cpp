// Xor ka inverse Xor hota hai
// The inverse is XOR!

// If you have:

// c = a^b;
// You can get a or b back if you have the other value available:

// a = c^b; // or b^c (order is not important)
// b = c^a; // or a^c
// For example if a = 5, b = 3 (and thus c = 6 as you mentioned) you get:

// b=0011 (3)            a=0101 (5)
// c=0110 (6) XOR   or   c=0110 (6) XOR
// ----------            ----------
// a=0101 (5)            b=0011 (3)

// 3 ^ 4 = 7
// The following statements are true :

// 4 ^ 7 = 3

// 3 ^ 7 = 4

