"""
    https://leetcode.com/problems/minimum-size-subarray-sum/description/
    Given an array of n positive integers and a positive integer s,
    find the minimal length of a contiguous subarray of which the sum >= s.
    if there isn't one, return 0 instead
    For example, given the array [2,3,1,2,4,3] and s = 7
    the subarray [4,3] has the minimal length under the problem constraint.
    返回最小长度
"""
class Solution(object):
    def minSubArrayLen(self, s, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """
        sum = 0
        res = float('inf')          # float的最大值
        #print(res)                 # inf
        head = 0                    # 窗口的起始点位置

        for i in range(len(nums)):
            sum += nums[i]

            while sum >= s:
                res = min(res, i - head + 1)
                sum -= nums[head]
                head += 1
        # res初始值为无穷大, 如果数组nums中的所有元素和都小于s, 则此时返回res为无穷大
        # 根据题意, 要判断一下此时的res值
        return res if res <= len(nums) else 0  

if __name__ == "__main__":
    sol = Solution()
    nums = [2,3,1,2,4,3]
    s = 7
    r = sol.minSubArrayLen(s, nums)
    print(r)