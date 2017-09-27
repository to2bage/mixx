class Solution:
    # @param n: An integer.
    # return : A list of integer storing 1 to the largest number with n digits.
    def numbersByRecursion(self, n):
        self.ret = []
        if n > 0:
            self._numbersByRecursion(1, n)
        return self.ret
    def _numbersByRecursion(self, curValue, n):
        newValue = curValue * 10
        for i in range(curValue, newValue):
            self.ret.append(i)
        if n == 1:
            return
        self._numbersByRecursion(newValue, n - 1)
    '''
    def numbersByRecursion(self, n):
        limit = 1
        self.rect = []
        for i in range(n):
            limit *= 10
        self._print(1, limit)
        return self.rect
        
    def _print(self, cur, limit):
        if cur < limit:
            self.rect.append(cur)
            self._print(cur + 1, limit)
    '''
    '''
    在n变大时,比如n==5, 造成栈的溢出
    def numbersByRecursion(self, n):
        # write your code here
        maxNum = 1
        ret = []
        for i in range(n):
            maxNum *= 10
        for i in range(maxNum):
            ret.append(i)
        return ret
    '''

if __name__ == "__main__":
    s = Solution()
    print(s.numbersByRecursion(5))

