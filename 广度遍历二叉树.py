class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def levelOrder1(self, root):
        if root is None:
            return []
        que = [root for i in range(10000)]
        head = 0
        tail = 1
        que[head] = root    #入队
        parentNode = root
        lastNode = root
        while head < tail:
            curNode = que[head]       #出队
            head += 1
            print(curNode.val)
            if curNode.left:
                que[tail] = curNode.left;
                lastNode = que[tail]
                tail += 1
            if curNode.right:
                que[tail] = curNode.right;
                lastNode = que[tail]
                tail += 1
            if parentNode.right == lastNode:
                print("\n")
                parentNode = lastNode
    def levelOrder2(self, root):
        if root is None:
            return []
        que = [root for x in range(1000)]
        head = 0
        tail = 1
        que[head] = root
        parentNode = root
        lastNode = root
        tmp = []
        self.rect = []
        while head < tail:
            curNode = que[head]
            head += 1
            tmp.append(curNode.val)
            if curNode.left:
                que[tail] = curNode.left
                lastNode = curNode.left
                tail += 1
            if curNode.right:
                que[tail] = curNode.right
                lastNode = curNode.right
                tail += 1
            if parentNode.right == lastNode or parentNode.left == lastNode:
                self.rect.append(tmp)
                tmp = []
                parentNode = lastNode
        self.rect.append(tmp)   

        return self.rect

if __name__ == "__main__":
    root = TreeNode(3)
    p1 = TreeNode(9)
    p2 = TreeNode(20)
    p3 = TreeNode(15)
    p4 = TreeNode(7)
    root.left = p1
    root.right = p2
    p1.left = None
    p1.right = None
    p2.left = p3
    p2.right = p4
    p3.left = None
    p3.right = None
    p4.left = None
    p4.right = None

    s = Solution()
    r = s.levelOrder2(root)
    print(r)