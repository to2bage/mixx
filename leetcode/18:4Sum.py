"""
    https://leetcode.com/problems/4sum/description/
"""
class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        if not nums or len(nums) < 4:
            return []
        self.rect = []
        self.kSum(sorted(nums), target, 4, [])
        return self.rect
    def kSum(self, nums, target, k, tmp):
        if k == 2:
            left, right = 0, len(nums) - 1
            while left < right:
                value = nums[left] + nums[right]
                if value > target:
                    right -= 1
                elif value < target:
                    left += 1
                elif value == target:
                    tmp.extend([nums[left], nums[right]])
                    if tmp not in self.rect:
                        self.rect.append(tmp[:])
                    tmp.pop()
                    tmp.pop()
                    left += 1
                    right -= 1
                    #return
            #tmp = []
            return
        else:
            left = 0
            while left < len(nums) - k + 1:
                tmp.extend([nums[left]])
                self.kSum(nums[left+1:], target - nums[left], k - 1, tmp)
                tmp.pop()
                #print(tmp)              #test
                left += 1

if __name__ == "__main__":
    s = Solution()
    #nums = [1, 0, -1, 0, -2, 2]         # [-2, -1, 0, 0, 1, 2]
    #target = 0
    nums = [-3, -2, -1, 0, 0, 1, 2, 3]
    target = 0
    r = s.fourSum(nums, target)
    print(r)
