# [3,2,2,1] k = 2
class Solution:
    """
    @param: nums: The integer array you should partition
    @param: k: An integer
    @return: The index after partition
    """
    def partitionArray(self, nums, k):
        if not nums or len(nums) == 0:
            return 0
        tail = 0
        for i in range(len(nums)):
            if nums[i] >= k:
                continue
            elif nums[i] < k:
                nums[tail], nums[i] = nums[i], nums[tail]
                tail += 1
        return tail
