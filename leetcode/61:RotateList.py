"""
    61: https://leetcode.com/problems/rotate-list/description/
"""
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    # 获得链表的长度
    def getLength(self, head):
        if not head:
            return 0
        length = 0
        px = head
        while px:
            length += 1
            px = px.next
        return length
        
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if not head or head.next == None:
            return head
        # 因为k可能超过链表的长度
        len = self.getLength(head)
        k %= len
        # 定义dummy
        dummy = curr = ListNode(0)
        dummy.next = head
        # 移动head
        for i in range(k):
            head = head.next
        # 移动curr
        while head.next:
            curr = curr.next
            head = head.next
        curr = curr.next
        # 建立新的连接
        head.next = dummy.next
        dummy.next = curr.next
        curr.next = None
        #return
        return dummy.next


