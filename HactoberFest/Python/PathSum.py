# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
# A leaf is a node with no children.
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        def dfs(node, csum):
            if not node:
                return False
            csum += node.val 
            if not node.left and not node.right:
                if csum == targetSum:
                    return True
                else: return False        
            return (dfs(node.left,csum) or dfs(node.right,csum))
        return dfs(root,0) 
