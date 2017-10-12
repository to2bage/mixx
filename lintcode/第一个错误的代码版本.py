"""
    http://www.lintcode.com/zh-cn/problem/first-bad-version/
    代码库的版本号是从 1 到 n 的整数。某一天，有人提交了错误版本的代码，因此造成自身及之后版本的代码在单元测试中均出错。请找出第一个错误的版本号。
    你可以通过 isBadVersion 的接口来判断版本号 version 是否在单元测试中出错，具体接口详情和调用方法请见代码的注释部分。
    样例
        给出 n=5
        调用isBadVersion(3)，得到false
        调用isBadVersion(5)，得到true
        调用isBadVersion(4)，得到true
        此时我们可以断定4是第一个错误的版本号
"""
"""
class SVNRepo:
    @classmethod
    def isBadVersion(cls, id)
        # Run unit tests to check whether verison `id` is a bad version
        # return true if unit tests passed else false.
You can use SVNRepo.isBadVersion(10) to check whether version 10 is a 
bad version.
"""


class Solution:
    """
    @param: n: An integer
    @return: An integer which is the first bad version.
    """
    def findFirstBadVersion(self, n):
        # write your code here
        left, end = 0, n
        #二分法查找: left + 1 < end至少保证序列中有3个元素
        #当只有2个元素时,跳出while循环
        while left + 1 < end:
            mid = left + (end - left) // 2
            if SVNRepo.isBadVersion(mid):
                #mid是错误的版本号
                end = mid       #不需要mid-1: 奇数数组会出错
            else:
                #mid是正确的版本号
                left = mid
        #此时只要判断left和end指向的元素是否是错误的版本号
        #因为, 题目要求是找出第一个错误的版本号的位置, 所以先判断left,再判断end
        if SVNRepo.isBadVersion(left):
            return left
        else:
            return end