class TreeNode:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

def kth_ancestor(root, node, k):
    if root is None:
        return None
    
    if root.key == node:
        return k

    left_k = kth_ancestor(root.left, node, k)
    if left_k is not None:
        if left_k == 0:
            print("K-th ancestor:", root.key)
        return left_k - 1
    
    right_k = kth_ancestor(root.right, node, k)
    if right_k is not None:
        if right_k == 0:
            print("K-th ancestor:", root.key)
        return right_k - 1

# Example usage:
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.left = TreeNode(4)
root.left.right = TreeNode(5)
root.right.left = TreeNode(6)
root.right.right = TreeNode(7)

k = 2
node_to_find = 7
kth_ancestor(root, node_to_find, k)
