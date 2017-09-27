class Solution:
    """
    @param: n: n pairs
    @return: All combinations of well-formed parentheses
    """
    def generateParenthesis(self, n):
        # write your code here
        self.limit = n
        self.ret = []
        self.comb = ''
        self._generatePar('', 0, 0)
        return self.ret

    def _generatePar(self, comb, leftPars, rightPars):
        if (leftPars == self.limit) and (rightPars == self.limit):
            self.ret.append(comb)
            return
        if leftPars < self.limit:
            self._generatePar(comb + '(', leftPars + 1, rightPars)
        if rightPars < leftPars:
            self._generatePar(comb + ')', leftPars, rightPars + 1)

if __name__ == "__main__":
    s = Solution()
    n = 3
    r = s.generateParenthesis(n)
    print(r)
