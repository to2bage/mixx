class Solution:
    """
    @param: numbers: Give an array numbers of n integer
    @return: Find all unique triplets in the array which gives the sum of zero.
    """
    def threeSum(self, numbers):
        # write your code here
        rect = []
        for i in range(len(numbers) - 2):
            for j in range(i + 1, len(numbers) - 1):
                ret = 0 - (numbers[i] + numbers[j])
                for k in range(j + 1, len(numbers)):
                    if numbers[k] == ret:
                        r = []
                        r.append(numbers[i])
                        r.append(numbers[j])
                        r.append(ret)
                        r.sort()

                        if not rect:
                            rect.append(r)
                        if r not in rect:
                            rect.append(r)
                        rect.sort() 
                        break;
                        
        return rect

if __name__ == "__main__":
    s = Solution()
    #numbers = [-1, 0, 1, 2, -1, -4]
    #numbers = [-1,1,0]
    #numbers = [1,0,-1,-1,-1,-1,0,1,1,1]
    numbers = [-2,-3,5,-1,-4,5,-11,7,1,2,3,4,-7,-1,-2,-3,-4,-5]
    ret = s.threeSum(numbers)
    print(ret)
    print("===================================\n")
    '''
    num = [(-1,0,1)]
    ret = num.index((-1,0,1))
    print(ret)
    '''
        