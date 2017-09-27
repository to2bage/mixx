#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp(const void *n1, void *n2)
{
    int *num1 = (int *)n1;
    int *num2 = (int *)n2;
    return *num1 > *num2 ? 1 : 0;
}

int** threeSum1(int* nums, int numsSize, int* returnSize) 
{
    //首先对数组nums进行排序
    qsort(nums, numsSize, sizeof(int), comp);
    /*
    for(int i = 0; i < numsSize; i++)
    {
        printf("%3d", nums[i]);
    }
    printf("\n");
    */
    //2Sum + 1Sum
    int sum = 0;                        //三个数的和
    for(int i = 0; i < numsSize; i++)
    {
        int *pstart = nums + i + 1;
        int *pend = nums + numsSize - 1;
        while(pstart < pend)
        {
            if(*pstart + *pend > sum - nums[i])
            {
                pend--;
            }
            else if(*pstart + *pend < sum - nums[i])
            {
                pstart++;
            }
            else if(*pstart + *pend == sum - nums[i])
            {
                printf("%d, %d, %d\n", nums[i], *pstart, *pend);
                pstart++;
                if(pstart < pend && *pstart == *(pstart + 1))
                {
                    pstart++;
                }
                pend--;
                if(pstart < pend && *pend == *(pend - 1))
                {
                    pend--;
                }
                //pstart++;
                //pend--;
            }
            
        }
    }
    return NULL;
}

int cnt = 0;
int** threeSum2(int* nums, int numsSize, int* returnSize) 
{
    cnt = 0;
    //首先对数组nums进行排序
    qsort(nums, numsSize, sizeof(int), comp);
    //定义返回的二维数组
    int **dp = (int **)malloc(1000000 * sizeof(int *));

    //2Sum + 1Sum
    int sum = 0;                        //三个数的和
    for(int i = 0; i < numsSize; i++)
    {
        if(i > 0 && nums[i] == nums[i-1])
        {
            continue;
        }
        int *pstart = nums + i + 1;
        int *pend = nums + numsSize - 1;
        while(pstart < pend)
        {
            if(*pstart + *pend > sum - nums[i])
            {
                pend--;
            }
            else if(*pstart + *pend < sum - nums[i])
            {
                pstart++;
            }
            else if(*pstart + *pend == sum - nums[i])
            {
                //printf("%d, %d, %d\n", nums[i], *pstart, *pend);
                int *px = (int *)malloc(3 * sizeof(int));
                memset(px, 0, 3 * sizeof(int));
                px[0] = nums[i];
                px[1] = *pstart;
                px[2] = *pend;
                dp[cnt++] = px;
                pstart++;
                pend--;
            }
            
        }
    }
    *returnSize = cnt;
    return dp;
}

int** threeSum3(int* nums, int numsSize, int* returnSize) 
{
    cnt = 0;
    //首先对数组nums进行排序
    qsort(nums, numsSize, sizeof(int), comp);
    //定义返回的二维数组
    int **dp = (int **)malloc(1000000 * sizeof(int *));

    //2Sum + 1Sum
    int sum = 0;                        //三个数的和
    for(int i = 0; i < numsSize; i++)
    {
        if(i > 0 && nums[i] == nums[i-1])
        {
            continue;
        }
        int *pstart = nums + i + 1;
        int *pend = nums + numsSize - 1;
        while(pstart < pend)
        {
            if(*pstart + *pend > sum - nums[i])
            {
                pend--;
            }
            else if(*pstart + *pend < sum - nums[i])
            {
                pstart++;
            }
            else if(*pstart + *pend == sum - nums[i])
            {
                //printf("%d, %d, %d\n", nums[i], *pstart, *pend);
                int *px = (int *)malloc(3 * sizeof(int));
                memset(px, 0, 3 * sizeof(int));
                px[0] = nums[i];
                px[1] = *pstart;
                px[2] = *pend;
                dp[cnt++] = px;
                if(*pstart == *(pstart + 1))
                {
                    pstart += 2;
                }
                else
                {
                    pstart++;
                }
                if(*pend == *(pend - 1))
                {
                    pend -= 2;
                }
                else
                {
                    pend--;
                }
                //pstart++;
                //pend--;
            }
            
        }
    }
    *returnSize = cnt;
    return dp;
}

int** threeSum(int* nums, int numsSize, int* returnSize) 
{
    cnt = 0;
    //首先对数组nums进行排序
    qsort(nums, numsSize, sizeof(int), comp);
    //定义返回的二维数组
    int **dp = (int **)malloc(1000000 * sizeof(int *));

    //2Sum + 1Sum
    int sum = 0;                        //三个数的和
    for(int i = 0; i < numsSize; i++)
    {
        //判断是否nums[i]和下一个元素值是否相等, 相等就跳过
        if(i > 0 && nums[i] == nums[i-1])
        {
            continue;
        }
        int *pstart = nums + i + 1;
        int *pend = nums + numsSize - 1;
        while(pstart < pend)
        {
            if(*pstart + *pend > sum - nums[i])
            {
                pend--;
            }
            else if(*pstart + *pend < sum - nums[i])
            {
                pstart++;
            }
            else if(*pstart + *pend == sum - nums[i])
            {
                //printf("%d, %d, %d\n", nums[i], *pstart, *pend);
                int *px = (int *)malloc(3 * sizeof(int));
                memset(px, 0, 3 * sizeof(int));
                px[0] = nums[i];
                px[1] = *pstart;
                px[2] = *pend;
                dp[cnt++] = px;
                while(*pstart == *(pstart + 1))
                {
                    pstart++;
                }
                pstart++;
               
                while(*pend == *(pend - 1))
                {
                    pend--;
                }
                pend--;
               
                //pstart++;
                //pend--;
            }
            
        }
    }
    *returnSize = cnt;
    return dp;
}

void sumOfThree1(int start, int level, int count, int *nums, int numsSize, int *data)
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

    for(int i = start; i < numsSize; i++)
    {
        data[level] = nums[i];
        sumOfThree1(i + 1, level + 1, count, nums, numsSize, data);
    }
}
void sumOfThree(int start, int level, int curSum, int count, int *nums, int numsSize, int *data)
{
    if(level >= count)
    {
        //printf("curSum = %d\n", curSum);
        if(curSum == 0)
        {
            for(int i = 0; i < count; i++)
            {
                printf("%4d", data[i]);
            }
            printf("\n");
        }
        return;
    }

    for(int i = start; i < numsSize; i++)
    {
        data[level] = nums[i];
        sumOfThree(i + 1, level + 1, curSum + data[level], count, nums, numsSize, data);
    }
}

int main(int argc, char *argv[])
{
    {
        //int nums[] = {-1, 0, 1, 2, -1, -4};
        //int nums[] = {-2,0,0,2,2};
        int nums[] = {-2,0,3,-1,4,0,3,4,1,1,1,-3,-5,4,0};
        int numsSize = sizeof(nums) / sizeof(int);
        int returnSize = 0;
        int **pp = threeSum(nums, numsSize, &returnSize);               //完美
        for(int i = 0; i < returnSize; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                printf("%3d", pp[i][j]);
            }
            printf("\n");
        }

    }
    {
        /*
        //从数组nums的numsSize个元素中, 选取count个元素
        int nums[] = {-1, 0, 1, 2, -1, -4};
        //int nums[] = {1,2,3,4,5,6};
        int numsSize = sizeof(nums) / sizeof(int);
        int curSum = 0;
        int count = 3;

        int *data = (int *)malloc(count * sizeof(int));
        memset(data, 0, count * sizeof(int));

        sumOfThree(0, 0, 0, count, nums, numsSize, data);
        */
    }

    return 0;
}