class Solution:
    """
    @param: A: an integer array
    @return: 
    """
    def sortIntegers2(self, A):
        pos = self._achor(A, 0, len(A) - 1)
        self.sortIntegers2(A[0:pos])
        self.sortIntegers2(A[pos+1:len(A)])

    def _achor(self, A, start, end):
        if start == end:
            return start
        i,j = start,start+1
        achor = A[start]
        while j <= end:
            if A[j] < achor:
                #self._swap(A[i], A[j])
                tmp = A[i]
                A[i] = A[j]
                A[j] = tmp

                i += 1
                j += 1
            elif A[j] >= achor:
                j += 1
        return i


if __name__ == "__main__":
    s = Solution()
    #A = [3,2,1,4,5]
    #A = [3]
    #A = [2,1]
    A = [3,2,1]
    
    pos = s._achor(A, 0, 2)
    print("%2d => %3d" % (pos, A[pos]))
    print(A)
    
    '''
    s.sortIntegers2(A)
    print(A)
    '''