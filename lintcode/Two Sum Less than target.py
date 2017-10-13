class Solution(object):
    def twoSumLess(self, nums, target):
        if not nums or len(nums) < 2:
            return 0
        nums.sort()
        left, right = 0, len(nums) - 1
        count = 0
        while left < right:
            if nums[left] + nums[right] > target:
                right -= 1
            elif nums[left] + nums[right] < target:
                count += right - left
                left += 1
        return count

if __name__ == "__main__":
    s = Solution()
    nums = [2,7,11,15]
    target = 24
    r = s.twoSumLess(nums, target)
    print(r)