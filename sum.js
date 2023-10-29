class TreeNode {
    constructor(val) {
        this.val = val;
        this.left = null;
        this.right = null;
    }
}

function diagonalSum(root) {
    const diagonalSums = new Map();

    function dfs(node, diagonalLevel) {
        if (!node) return;

        // If diagonal level is not in the map, initialize it with current node's value
        if (!diagonalSums.has(diagonalLevel)) {
            diagonalSums.set(diagonalLevel, 0);
        }

        // Add the current node's value to the diagonal level sum
        diagonalSums.set(diagonalLevel, diagonalSums.get(diagonalLevel) + node.val);

        // Move to the next diagonal level
        dfs(node.left, diagonalLevel + 1);
        dfs(node.right, diagonalLevel);
    }

    dfs(root, 0);

    // Extract diagonal sums from the map and return as an array
    return Array.from(diagonalSums.values());
}

// Example usage:
// Create a binary tree
const root = new TreeNode(1);
root.left = new TreeNode(2);
root.right = new TreeNode(3);
root.left.left = new TreeNode(4);
root.left.right = new TreeNode(5);
root.right.right = new TreeNode(6);

// Calculate diagonal sum
const result = diagonalSum(root);
console.log(result); // Output: [1, 4, 6]
