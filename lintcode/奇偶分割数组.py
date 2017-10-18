"""
    http://www.lintcode.com/zh-cn/problem/partition-array-by-odd-and-even/
    分割一个整数数组，使得奇数在前偶数在后。
    给定 [1, 2, 3, 4]，返回 [1, 3, 2, 4]
"""
class Solution:
    """
    @param: nums: an array of integers
    @return: nothing
    """
    def partitionArray(self, nums):
        if not nums:
            return
        tail = 0
        for i in range(len(nums)):
            if nums[i] % 2 != 0:
                #奇数
                nums[tail], nums[i] = nums[i], nums[tail]
                tail += 1

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,3,4]
    s.partitionArray(nums)
    print(nums)