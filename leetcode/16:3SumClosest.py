"""
    https://leetcode.com/problems/3sum-closest/description/
"""
class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if not nums or len(nums) < 3:
            return 0
        self.rect = 0
        import sys
        num_closest = sys.maxsize
        nums.sort()
        for i in range(len(nums)):
            left, right = i + 1, len(nums) - 1
            while left < right:
                value = nums[i] + nums[left] + nums[right]
                if abs(target - value) < num_closest:
                    num_closest = abs(target - value)
                    self.rect = value
                if value > target:
                    right -= 1
                elif value < target:
                    left += 1
                elif value == target:
                    return value
        return self.rect

if __name__ == "__main__":
    s = Solution()
    nums = [-1, 2, 1, -4]
    target = 1
    r = s.threeSumClosest(nums, target)
    print(r)