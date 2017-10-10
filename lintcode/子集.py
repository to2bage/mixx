"""
    http://www.lintcode.com/zh-cn/problem/subsets/
    给定一个含不同整数的集合，返回其所有的子集
    样例
        如果 S = [1,2,3]，有如下的解：

        [
            [3],
            [1],
            [2],
            [1,2,3],
            [1,3],
            [2,3],
            [1,2],
            []
        ]
"""
class Solution:
    
    """
    @param: nums: A set of numbers
    @return: A list of lists
    """
    #从0下标开始扫描数组, 生成子序列, 并将其加入到全局答案self.result中
    def subsets(self, nums):
        #边界条件
        if not nums:        #即nums == []
            return [[]]
        self.result = []
        self.dfs(sorted(nums), [], 0)
        return self.result
    #nums: 传入的数组; startIndex:数组nums的作用区间的开始位置; subset:局部的结果集
    #根据传入的数组nums的区间[startIndex, len(nums)-1]获得结果, 并将结果存入到subset中
    #再将subset放入全局答案self.result中
    def dfs(self, nums, subset, startIndex):
        #当扫描到数组末尾时, 将子序列加入到最终结果集self.result并且结束本次调用
        #注意: 这里要使用subset[:], 即把结果克隆一下返回
        self.result.append(subset[:])
        #面对当前元素nums[index]有两种选择:
        #1)将当前元素加入到子序列subset中
        #2)将当前元素不加入子序列subset中
        for index in range(startIndex, len(nums)):
            subset.append(nums[index])      #NO.1情况
            self.dfs(nums, subset, index + 1)
            #回溯, 不将当前元素加入子序列subset, 递归调用
            subset.pop()                    #No.2情况

if __name__ == "__main__":
    s = Solution()
    r = s.subsets([1,2,3])
    print(r)

        