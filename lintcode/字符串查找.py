'''
    对于一个给定的 source 字符串和一个 target 字符串，你应该在 source 字符串中找出 target 字符串出现的第一个位置(从0开始)。如果不存在，则返回 -1。
    样例
        如果 source = "source" 和 target = "target"，返回 -1。
        如果 source = "abcdabcdefg" 和 target = "bcd"，返回 1。
'''

class Solution:
    """
    @param: source: source string to be scanned.
    @param: target: target string containing the sequence of characters to match
    @return: a index to the first occurrence of target in source, or -1  if target is not part of source.
    """
    def strStr(self, source, target):
        # write your code here
        #源字符串, 目标字符串是NULL 或者是源字符串是空串
        if source is None or target is None or len(source) < len(target):
            return -1
        #目标字符串是空串
        if not target or not source:
            return 0
        flag = 0
        for i in range(len(source) - len(target) + 1):
            flag = 0
            for j in range(len(target)):
                if source[i + j] != target[j]:
                    flag = 1
                    break
            if flag == 0:
                return i

if __name__ == "__main__":
    s = Solution()
    source = "abcdabcdefg"
    target = "bcd"
    r = s.strStr(source, target)
    print(r)

"""
abcdabcdefg
        bcd
"""