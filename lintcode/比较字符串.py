"""
    http://www.lintcode.com/zh-cn/problem/compare-strings/
    比较两个字符串A和B，确定A中是否包含B中所有的字符。字符串A和B中的字符都是 大写字母
    注意事项: 在 A 中出现的 B 字符串里的字符不需要连续或者有序。
    样例
        给出 A = "ABCD" B = "ACD"，返回 true
        给出 A = "ABCD" B = "AABC"， 返回 false
        ord(char)=>ascii  chr(int)=>char 
"""
class Solution:
    """
    @param: A: A string
    @param: B: A string
    @return: if string A contains all of the characters in B return true else return false
    """
    def compareStrings(self, A, B):
        # write your code here
        if not A and not B:
            return True
        if len(A) < len(B):
            return False
        #列表hash的索引字符的ascii, 值是字符的个数
        hash = [0] * 26
        for i in range(len(A)):
            hash[ord(A[i]) - ord('A')] += 1
        '''
        for i in range(len(hash)):
            print(hash[i])
        '''
        for i in range(len(B)):
            if hash[ord(B[i]) - ord('A')] == 0:
                #字符串B中的字符不在字符串A中
                return False
            elif hash[ord(B[i]) - ord('A')] != 0:
                #字符串B中的字符在字符串A中
                hash[ord(B[i]) - ord('A')] -= 1
        return True

if __name__ == "__main__":
    s = Solution()
    A = "AAAAAAAAAAAABBBBBCDD"
    #B = "ACD"
    B = "ABCCDD"
    r = s.compareStrings(A, B)
    print(r)