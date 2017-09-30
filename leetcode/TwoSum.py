class Solution:
    def twoSum1(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        dict = {}
        for idx, num in enumerate(nums):
            dict[num] = idx

        for indx, num in enumerate(nums):
            if target - num in dict and indx != dict[target - num]:
                return [indx, dict[target - num]]

    def twoSum(self, nums, target):
        dict = {}
        for idx, num in enumerate(nums):
            if target - num in dict:
                return [idx, dict[target - num]]
            else:
                dict[num] = idx

if __name__ == "__main__":
    s = Solution()
    r = s.twoSum([2,7,11,15], 9)
    #r = s.twoSum([3,3], 6)
    print(r)