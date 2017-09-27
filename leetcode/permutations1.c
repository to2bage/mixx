#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cnt = 0;                  //全局变量记录返回结果的二维数组的行数

//从[idx,...,numsSize - 1]排列
void process(int idx, int *nums, int numsSize, int *returnSize, int **pprect)
{
    if(idx >= numsSize)
    {
        //生成结果
        int *px = (int *)malloc(numsSize * sizeof(int));
        memset(px, 0, numsSize * sizeof(int));

        for(int i = 0; i < numsSize; i++)
        {
            px[i] = nums[i];
        }
        pprect[cnt++] = px;
        return;
    }

    //决策是: 当前位置的元素, 可以是数组nums中的任意一个数值
    for(int i = idx; i < numsSize; i++)
    {
        //随着i的增长, idx位置的值可以是数组nums区间[idx,...,numsSize - 1]中的任意一个值
        int tmp = nums[idx];
        nums[idx] = nums[i];
        nums[i] = tmp;
        //接着递归区间[idx + 1,...,numsSize - 1]中的排列
        process(idx + 1, nums, numsSize, returnSize, pprect);
        //为了不改变位置, 需要将idx的值交换回来
        tmp = nums[idx];
        nums[idx] = nums[i];
        nums[i] = tmp;
    }
}

int** permuteUnique(int* nums, int numsSize, int* returnSize) 
{
    if(nums == NULL || numsSize <= 0)
    {
        return NULL;
    }
    cnt = 0;
    //获得排列的个数
    int rowsSize = 1;
    for(int i = 1; i <= numsSize; i++)
    {
        rowsSize *= i;
    }
    int **pprect = (int **)malloc(rowsSize * sizeof(int *));

    process(0, nums, numsSize, returnSize, pprect);
    *returnSize = cnt;

    return pprect;
}

void showPermutation(int **nums, int rows, int cols)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            printf("%4d", nums[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    int nums[] = {4,5,6};
    int numsSize = sizeof(nums)/sizeof(int);
    int returnSize = 0;
    int **ppr = permuteUnique(nums, numsSize, &returnSize);
    showPermutation(ppr, returnSize, numsSize);

    return 0;
}
