
#Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None



class Solution:
    """
    @param: root: The root of binary tree.
    @return: An integer
    """
    def maxPathSum(self, root):
        # write your code here
        if not root:
            return 0
        self.max = -100000000
        self._maxPathSum(root)
        return self.max

    def _maxPathSum(self, node):
        leftsum = 0
        rightsum = 0
        if node.left:
            leftsum = self._maxPathSum(node.left)
        if node.right:
            rightsum = self._maxPathSum(node.right)
        sub_max = max(leftsum + node.val, rightsum + node.val)
        sub_max = max(sub_max, node.val)
        sub_max = max(sub_max, node.val + leftsum + rightsum)
        self.max = sub_max if sub_max > self.max else self.max

        return max(max(leftsum + node.val, rightsum + node.val), node.val)
        

if __name__ == "__main__":
    root = TreeNode(1)
    leftchild = TreeNode(2)
    rightchild = TreeNode(3)
    root.left = leftchild
    root.right = rightchild

    s = Solution()
    r = s.maxPathSum(root)
    print("max = %4d" % r)