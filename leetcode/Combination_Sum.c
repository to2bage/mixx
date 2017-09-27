#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cnt = 0;

int process(int idx, int *candidatas, int candidatesSize, int target,
    int **columnSizes, int *returnSize)
{
    int res = 0;
    if(idx == candidatesSize - 1)
    {
        res = target == 0 ? 1 : 0;
    }
    else
    {
        for(int i = 0; candidatas[idx] * i <= target; i++)
        {
            res += process(idx + 1, candidatas, candidatesSize, target - i * candidatas[idx], columnSizes, returnSize);
        }
    }
    return res;
}

int** combinationSum(int* candidates, int candidatesSize, int target, 
    int** columnSizes, int* returnSize) 
{
    if(candidates == NULL || candidatesSize <= 0 || target <= 0)
    {
        return NULL;
    }
    cnt = 0;

    int **data = (int **)malloc(1000 * sizeof(int *));
    int r = process(0, candidates, candidatesSize, target, columnSizes, returnSize);
    printf("r = %d\n", r);

    return NULL;
}

int main(int argc, char *argv[])
{
    //int candidates[] = {2,3,6,7};
    int candidates[] = {5,10,25,1};
    int candidatesSize = sizeof(candidates) / sizeof(int);
    int target = 15;
    int returnSize = 0;
    int *columnSizes = (int *)malloc(100 * sizeof(int));
    memset(columnSizes, 0, 100 * sizeof(int));

    int **pprect = combinationSum(candidates, candidatesSize, target, &columnSizes, &returnSize);
    for(int i = 0; i < returnSize; i++)
    {
        for(int j = 0; j < columnSizes[i]; j++)
        {
            printf("%3d", pprect[i][j]);
        }
        printf("\n");
    }

    return 0;
}