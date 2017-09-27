#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//不能解决数组nums中有重复数字的问题
void permutation(int level, int count, int *nums, int numsSize, int *data, bool *pbool)
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
            permutation(level + 1, count, nums, numsSize, data, pbool);
            pbool[i] = false;
        }
    }
}

int isDup(int *nums, int start, int end)
{
    for(int i = start; i < end; i++)
    {
        if(nums[i] == nums[end])
        {
            return 1;       //重复
        }
    }
    return 0;               //不重复
}
//
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
            //printf("*\n");
            pbool[i] = true;
            data[level] = nums[i];
            permutation1(level + 1, count, nums, numsSize, data, pbool);
            pbool[i] = false;
        }
    }
}

int main(int argc, char *argv[])
{
    int nums[] = {1,2,2,3};
    int numsSize = sizeof(nums) / sizeof(int);
    int count = 4;      //从数组nums中取出numsSize位数字, 排列出count位数字
    int *data = (int *)malloc(count * sizeof(int));
    memset(data, 0, count * sizeof(int));
    bool *pbool = (bool *)malloc(numsSize * sizeof(bool));
    memset(pbool, false, numsSize * sizeof(bool));      //布尔向量

    permutation1(0, count, nums, numsSize, data, pbool);
    return 0;
}