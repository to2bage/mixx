"""
    https://leetcode.com/problems/move-zeroes/description/
    nums = [0, 1, 0, 3, 12]  ==> [1, 3, 12, 0, 0]
"""
class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        if not nums or len(nums) == 1:
            return
        tail = 0
        for i in range(len(nums)):
            if nums[i] != 0:
                nums[tail], nums[i] = nums[i], nums[tail]
                tail += 1

if __name__ == "__main__":
    s = Solution()
    #nums = [0, 1, 0, 3, 12]
    nums = [0, 1]
    s.moveZeroes(nums)
    print(nums)