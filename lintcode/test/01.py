class Solution(object):
    def permute(self, nums):
        self.rect = []
        #self.dfs(sorted(nums), [])
        self.dfs1(sorted(nums), [], 0)
        return self.rect
    def dfs(self, nums, tmp):
        if nums == []:
            self.rect.append(tmp[:])
            return
        for i in range(len(nums)):
            tmp.append(nums[i])
            ele = nums.pop(i)
            self.dfs(nums, tmp)
            nums.insert(i, ele)
            tmp.pop()
    def dfs1(self, nums, tmp, startIndex):
        if startIndex == len(nums):
            self.rect.append(tmp[:])
            return
        for i in range(startIndex, len(nums)):
            tmp.append(nums[i])
            self.dfs1(nums, tmp, i+1)
            tmp.pop()

if __name__ == "__main__":
    s = Solution()
    r = s.permute([1,2,3])
    print(r)