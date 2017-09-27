
#Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None


class Solution:
    """
    @param preorder : A list of integers that preorder traversal of a tree
    @param inorder : A list of integers that inorder traversal of a tree
    @return : Root of a tree
    """
    def buildTree(self, preorder, inorder):
        # write your code here
        return self._build(preorder, 0, len(preorder), inorder, 0, len(inorder))

    def _build(self, preorder, pre_start, pre_end, inorder, in_start, in_end):
        if in_start >= in_end:
            return None

        i = in_start
        while i <= in_end:
            if preorder[pre_start] == inorder[i]:
                break;
            i += 1

        root = TreeNode(inorder[i])

        left_child_len = i - in_start
        root.left = self._build(preorder, pre_start + 1, pre_start + 1 + left_child_len, inorder, in_start, i)
        root.right = self._build(preorder, pre_start + 1 + left_child_len, pre_end, inorder, i + 1, in_end)

        return root

if __name__ == "__main__":
    s = Solution()
    preorder = [2,1,3]
    inorder = [1,2,3]
    root = s.buildTree(preorder, inorder)
    print(root.val)

