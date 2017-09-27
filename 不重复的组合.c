#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void permutation1(int level, int count, int *nums, int numsSize, int *data, bool *pbool)
{
    if(level >= count)
    {
        for(int i = 0; i < count; i++)
        {
            printf("%4d", data[i]);
        }
        printf("\n");
        return;
    }

    for(int i = 0; i < numsSize; i++)
    {
        if(pbool[i] == false)
        {
            pbool[i] = true;
            data[level] = nums[i];
            permutation1(level + 1, count, nums, numsSize, data, pbool);
            pbool[i] = false;
        }
    }
}
//从start开始, 已经选择selectNum个数, selectNum 相当于 level层数
void permutation(int start, int selectNum, int count, int *nums, int numsSize, int *data)
{
    if(selectNum >= count)
    {
        for(int i = 0; i < count; i++)
        {
            printf("%4d", data[i]);
        }
        printf("\n");
        return;
    }

    for(int i = start; i < numsSize; i++)
    {
        data[selectNum] = nums[i];
        permutation(i + 1, selectNum + 1, count, nums, numsSize, data);
    }
}

int main(int argc, char *argv[])
{
    int nums[] = {1,2,3,4,5,6};
    int numsSize = sizeof(nums) / sizeof(int);
    int count = 3;      //从数组nums中取出numsSize位数字, 排列出count位数字
    int *data = (int *)malloc(count * sizeof(int));
    memset(data, 0, count * sizeof(int));
    bool *pbool = (bool *)malloc(numsSize * sizeof(bool));
    memset(pbool, false, numsSize * sizeof(bool));      //布尔向量

    //permutation1(0, count, nums, numsSize, data, pbool);
    permutation(0, 0, count, nums, numsSize, data);
    return 0;
}