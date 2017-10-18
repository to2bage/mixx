"""
    http://www.lintcode.com/zh-cn/problem/sort-letters-by-case/
    给定一个只包含字母的字符串，按照先小写字母后大写字母的顺序进行排序。
    给出"abAcD"，一个可能的答案为"acbAD"
"""
class Solution:
    """
    @param: chars: The letter array you should sort by Case
    @return: nothing
    """
    def sortLetters(self, chars):
        if len(chars) <= 1:
            return
        tail = 0
        for i in range(len(chars)):
            if ord(chars[i]) >= ord('a') and ord(chars[i]) <= ord('z'):
                chars[tail], chars[i] = chars[i], chars[tail]
                tail += 1
    
if __name__ == "__main__":
    s = Solution()
    chars = "abAcD"
    s.sortLetters(chars)
    print(chars)