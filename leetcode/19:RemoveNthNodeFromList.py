"""
    https://leetcode.com/problems/remove-nth-node-from-end-of-list/
"""
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        if not head:
            return head
        # 头结点
        dummy = cur = ListNode(0)
        dummy.next = head
        for i in range(n):
            head = head.next
        while head:
            cur = cur.next
            head = head.next
        #删除节点
        cur.next = cur.next.next
        return dummy.next

