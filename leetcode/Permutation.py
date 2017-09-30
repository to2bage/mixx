class Solution(object):
    #因为每一层都是从区间[0,len(nums)-1]中取值, 所以会出现[1,1,1]的情况
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        self.rect = []
        def dfs(nums, temp):
            #edge condition
            if len(temp) == len(nums):
                self.rect.append(temp[:])       #一定要注意这里temp[:], 完成了temp[]的深拷贝
                return
            for i in range(0, len(nums)):
                temp.append(nums[i])
                dfs(nums, temp)
                temp.pop()
        dfs(nums, [])
        return self.rect
    #去除每一层中重复的选择
    def permute1(self, nums):
        self.rect = []
        def dfs(nums, temp):
            #edge condition
            if len(temp) == len(nums):
                self.rect.append(temp[:])
                return
            for i in range(0, len(nums)):
                if nums[i] in temp:
                    continue
                temp.append(nums[i])
                dfs(nums, temp)
                temp.pop()
        dfs(nums, [])
        return self.rect
    #去除每一层重复的选择的另一种写法
    def permute2(self, nums):
        self.rect = []
        self.used = [False] * len(nums)
        def dfs(nums, temp):
            if len(temp) == len(nums):
                self.rect.append(temp[:])
                return
            for i in range(0, len(nums)):
                if self.used[i]:
                    continue
                self.used[i] = True
                temp.append(nums[i])
                dfs(nums, temp)
                self.used[i] = False
                temp.pop()
        dfs(nums, [])
        return self.rect

if __name__ == "__main__":
    s = Solution()
    print("***************")
    r = s.permute([1,2,3])
    print(r)
    print("***************")
    r = s.permute1([1,2,3])
    print(r)
    print("***************")
    r = s.permute2([1,2,3])
    print(r)