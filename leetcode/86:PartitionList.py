"""
    https://leetcode.com/problems/partition-list/description/
    For example,
    Given 1->4->3->2->5->2 and x = 3,
            return 1->2->2->4->3->5.
    思路: 建立两个链表, 一个是存放小于3的值, 一个存放大于等于3的值
"""
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        if not head:
            return None
        # 存放小于x值的链表: 含头结点的链表
        curless = headLess = ListNode(0)
        # 存放大于x值的链表: 含头结点的链表
        curMore = headMore = ListNode(0)
        #循环源链表
        while head:
            tmp = head.next     # 记录当前头结点的下一个节点
            if head.val < x:
                curless.next = head
                head.next = None
                head = tmp
                curless = curless.next
            elif head.val >= x:
                curMore.next = head
                head.next = None
                head = tmp
                curMore = curMore.next
        # 将curLess的next指向curMore的头结点
        curless.next = headMore.next
        return headLess.next
    def show(self, head):
        px = head
        while px:
            print("%2d -> " % px.val, end = '')
            px = px.next
    def createList(self, nums):
        head = px = ListNode(0)
        for i in range(len(nums)):
            node = ListNode(nums[i])
            px.next = node
            px = px.next
        return head


if __name__ == "__main__":
    s = Solution()
    # 1->4->3->2->5->2 and x = 3
    nums = [1,4,3,2,5,2]
    x = 3
    head = s.createList(nums)
    s.show(head.next)
    print()
    h = s.partition(head.next, x)
    s.show(h)