class Solution(object):
    def threeSumClosest(self, nums, target):
        if not nums or len(nums) < 3:
            return 0
        nums.sort()
        import sys
        minnum = sys.maxsize
        result = 0
        for i in range(len(nums)-2):
            left, right = i + 1, len(nums) - 1
            target = target - nums[i]
            while left < right:
                value = nums[left] + nums[right]
                distance = abs(target - value)
                if distance < minnum:
                    minnum = distance
                    result = nums[i] + nums[left] + nums[right]
                    print(result)
                if value > target:
                    right -= 1
                elif value < target:
                    left += 1
                elif value == target:
                    return nums[i] + nums[left] + nums[right]
        return result

if __name__ == "__main__":
    s = Solution()
    nums = [-1, 2, 1, -4]
    target = 1
    r = s.threeSumClosest(nums, target)
    print(r)
            
