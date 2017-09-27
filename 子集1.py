class Solution:
    
    """
    @param: nums: A set of numbers
    @return: A list of lists
    """
    def subsets(self, nums):
        ret = []
        nums.sort()
        for i in range(len(nums) + 1):
            combs = self._subsets(nums, 0, i)
            for comb in combs:
                ret.append(comb)
        return ret
    # 数组numbers, 从位置pos开始, 包含k个元素的所有组合
    def _subsets(self, numbers, pos, k):
        rect = []
        if k == 0:          #包含0个元素,意味着子集是空集
            return [[]]
        for i in range(pos, len(numbers), 1):           #从第i个元素开始的子集
            combs = self._subsets(numbers, i + 1, k - 1)        #简化为: 从第i+1个元素开始的子集
            if combs:
                if combs != [[]]:
                    for comb in combs:
                        new_comb = [numbers[i]]        #首先添加第i个元素到子集当中
                        new_comb.extend(comb)          #再添加从第i+1个元素开始的子集
                        rect.append(new_comb)
                else:
                    rect.append([numbers[i]])
        return rect

if __name__ == "__main__":
    nums = [1,2,3]
    s = Solution()
    r = s.subsets(nums)
    print(r)