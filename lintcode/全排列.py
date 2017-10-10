"""
    lintcode: http://www.lintcode.com/zh-cn/problem/permutations/
    全排列: [1,2,3] 全排列的个数是: P33 = 3 * 2 * 1 = 6
    样例
        给出一个列表[1,2,3]，其全排列为：
        [
            [1,2,3],
            [1,3,2],
            [2,1,3],
            [2,3,1],
            [3,1,2],
            [3,2,1]
        ]
"""
class Solution:
    """
    @param: nums: A list of integers.
    @return: A list of permutations.
    """
    def permute(self, nums):
        # write your code here
        if nums is None or len(nums) == 0:
            return []
        self.rect = []
        self.dfs(sorted(nums), [])
        return self.rect
    def dfs(self, nums, tmp):
        if not nums:
            self.rect.append(tmp[:])
            return
        #遍历nums中的每一个元素, 选择一个加入到tmp中
        #注意: 因为是排列, 所以每一次选择一个之后, 我们就需要把它从nums除去
        #然后进行回溯
        for i in range(len(nums)):
            tmp.append(nums[i])
            element = nums.pop(i)
            self.dfs(nums, tmp)
            #回溯
            nums.insert(i, element)
            tmp.pop()

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,3]
    r = s.permute(nums)
    print(r)