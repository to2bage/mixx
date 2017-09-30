class Solution(object):
    def __init__(self):
        self.kMaxValue = 10000
        self.temp = [0] * 20001 #All the integers in the array will be in the range of [-10000, 10000]
        self.ans = 0

    def arrayPairSum(self, nums):
        for i in range(len(nums)):
            self.temp[nums[i] + self.kMaxValue] += 1    

        #跳过数组temp中的0值
        n = -1 * self.kMaxValue
        first = True
        while(n < self.kMaxValue):
            if self.temp[n + self.kMaxValue] == 0:
                n += 1
                continue
            #print(n + self.kMaxValue)
            #此时找到了第一个值为非0的元素
            if first == True:
                self.ans = self.ans + n
                first = False
            elif first == False:
                first = True
            self.temp[n + self.kMaxValue] -= 1
                
        return self.ans

if __name__ == "__main__":
    s = Solution()
    r = s.arrayPairSum([1,2,3,4])
    print(r)