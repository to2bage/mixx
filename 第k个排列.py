'''
给定 n 和 k，求123..n组成的排列中的第 k 个排列。
首先要确认: 第一个元素是几???
'''
class Solution:
    """
    @param: n: n
    @param: k: the k th permutation
    @return: return the k-th permutation
    """
    def getPermutation(self, n, k):
        # write your code here
        ret = ""
        digits = [i for i in range(1, n+1)]   #[1,2,...,n]
        factorials = [1]
        for i in range(1, n):
            factorials.append(factorials[i-1] * i)
        for i in range(n-1, -1, -1):
            #计算出第一个元素在digits的什么位置上
            pos = (k - 1) // factorials[i]
            ret += str(digits[pos])     #取得第一位的数字, 并放入结果中
            delet(digits[pos])          #并从digits中删除已经添加到结果中的数字
            k -= pos * factorials[i]
        return ret

    