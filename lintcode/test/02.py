class Solution(object):
    def threeSumClosest(self, nums, target):
        if not nums or len(nums) < 3:
            return 0
        nums.sort()
        import sys
        minnum = sys.maxsize
        result = 0
        for i in range(len(nums)-2):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            left, right = i + 1, len(nums) - 1
            tag = target - nums[i]
            while left < right:
                value = nums[left] + nums[right]
                distance = abs(tag - value)
                if distance < minnum:
                    minnum = distance
                    result = nums[i] + nums[left] + nums[right]
                    #print(result)
                if value > tag:
                    right -= 1
                elif value < tag:
                    left += 1
                elif value == tag:
                    return nums[i] + nums[left] + nums[right]
        return result
    

if __name__ == "__main__":
    s = Solution()
    nums = [-1, 2, 1, -4]
    target = 1

    #nums = [-1,0,1,2,-1,-4] # [-4, -1, -1, 0, 1, 1]
    #target = 0

    #nums = [2,7,11,15]
    #target = 3
    r = s.threeSumClosest(nums, target)
    print(r)
            
