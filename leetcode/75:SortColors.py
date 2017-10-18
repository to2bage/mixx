"""
    https://leetcode.com/problems/sort-colors/description/
    1 0 2 1 2 0 1 0
"""
class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        if not nums or len(nums) == 1:
            return
        left, right = 0, len(nums) - 1
        idx = 0
        while idx <= right and left <= right:
            if nums[idx] == 0:
                nums[idx], nums[left] = nums[left], nums[idx]
                left += 1
                idx = left
            elif nums[idx] == 1:
                idx += 1
            elif nums[idx] == 2:
                nums[idx], nums[right] = nums[right], nums[idx]
                right -= 1
        
if __name__ == "__main__":
    s = Solution()
    #nums = [1, 0, 2, 1, 2, 0, 1, 0]
    #nums = [0, 1]
    nums = [0, 0]
    s.sortColors(nums)
    print(nums)