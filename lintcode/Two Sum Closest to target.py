"""
    Given an array nums of n integers, find two integets in nums such
    that the sum is closest to a given number, target
    Return the difference between the sum of the two integers and the target
    Example: nums = [-1,2,1,-4], target = 4
             the minimum difference is 1 (4 - (2 + 1) = 1)
"""
class Solution(object):
    def twoSumClosest(self, nums, target):
        if not nums or len(nums) < 2:
            return 0
        nums.sort()
        left, right = 0, len(nums) - 1
        import sys
        minnum = sys.maxsize        #获取本机的最大整数
        while(left < right):
            value = nums[left] + nums[right]
            dist = abs(target - value)
            if dist < minnum:
                minnum = dist
            if value > target:
                right -= 1
            elif value < target:
                left += 1
            elif value == target:
                return 0        # 和与target的间距最小, 直接返回
        return minnum

if __name__ == "__main__":
    s = Solution()
    nums = [-1,2,1,-4]
    target = 4
    r = s.twoSumClosest(nums, target)
    print(r)