# Title: 199. Binary Tree Right Side View
# Difficulty: Medium
# Problem: https://leetcode.com/problems/binary-tree-right-side-view/description/?envType=study-plan-v2&envId=leetcode-75


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        self.level = 0
        self.res = []
        self.dfs(root, 1)

        return self.res

    # Implement depth-first search
    def dfs(self, node: Optional[TreeNode], curr_level: int) -> None:
        if node:
            if curr_level > self.level:
                self.res.append(node.val)
                self.level += 1
            if node.right:
                self.dfs(node.right, curr_level + 1)
            if node.left:
                self.dfs(node.left, curr_level + 1)
