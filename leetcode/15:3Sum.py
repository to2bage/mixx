"""
    https://leetcode.com/problems/3sum/description/
"""
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if not nums or len(nums) < 3:
            return []
        nums.sort()
        self.rect = []
        for i in range(len(nums)):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            left, right = i + 1, len(nums) - 1
            while left < right:
                value = nums[i] + nums[left] + nums[right]
                if value > 0:
                    right -= 1
                elif value < 0:
                    left += 1
                elif value == 0:
                    self.rect.append([nums[i], nums[left], nums[right]])
                    left += 1
                    right -= 1
                    while left < right and nums[left] == nums[left - 1]:
                        left += 1
                    while left < right and nums[right] == nums[right + 1]:
                        right -= 1
        return self.rect

if __name__ == "__main__":
    s = Solution()
    nums = [-1, 0, 1, 2, -1, -4]
    r = s.threeSum(nums)
    print(r)