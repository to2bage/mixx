"""
    http://www.lintcode.com/zh-cn/problem/permutations-ii/
    给出一个具有重复数字的列表，找出列表所有不同的排列。
    样例
        给出列表 [1,2,2]，不同的排列有：

        [
            [1,2,2],
            [2,1,2],
            [2,2,1]
        ]
    子集的个数: 2^3 = 8
"""
class Solution:
    """
    @param: :  A list of integers
    @return: A list of unique permutations
    """

    def permuteUnique(self, nums):
        # write your code here
        if nums is None:
            return []
        self.rect = []
        self.dfs(sorted(nums), [])
        return self.rect
    def dfs(self, nums, tmp):
        if not nums:
            self.rect.append(tmp[:])
            return
        for i in range(len(nums)):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            tmp.append(nums[i])
            element = nums.pop(i)
            self.dfs(nums, tmp)
            nums.insert(i, element)
            tmp.pop()

if __name__ == "__main__":
    s = Solution()
    r = s.permuteUnique([1,2,2])
    print(r)