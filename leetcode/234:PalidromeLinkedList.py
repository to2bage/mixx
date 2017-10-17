"""
    https://leetcode.com/problems/palindrome-linked-list/description/
"""
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    # 获取链表的节点个数
    def _getCount(self, head):
        px = head
        count = 0
        while px:
            count += 1
            px = px.next
        return count
    # 获取链表的中间的节点
    def _getMid(self, head):
        slow = head
        fast = head.next
        # 
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        return slow
    # 逆置链表
    def _reverseList(self, head):
        if head.next == None:
            return head
        p1 = head
        p2 = head.next
        while p2:
            p3 = p2.next
            p2.next = p1
            p1 = p2
            p2 = p3
        head.next = None
        head = p1
        return head
    # 比较两个链表
    def _compareList(self, head1, head2):
        while head1 and head2:
            if head1.val != head2.val:
                return False
            head1 = head1.next
            head2 = head2.next
        if (not head1 and head2 != None) or (not head2 and head1 != None):
            return False
        elif not head1 and not head2:
            return True
    # 判断链表是否是回文
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if not head or head.next == None:
            return True
        mid = self._getMid(head)
        count = self._getCount(head)
        if count % 2 == 0:
            # 偶数
            right = mid.next
            mid.next = None
        else:
            # 奇数
            right = mid
        rightHead = self._reverseList(right)
        return self._compareList(head, rightHead)
    #test
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
    nums1 = [1,2,3]
    nums2 = [1,2,3]
    head1 = s.createList(nums1)
    s.show(head1.next)
    head2 = s.createList(nums2)
    print()
    s.show(head2.next)
    print()
    r = s._compareList(head1.next, head2.next)
    print(r)
