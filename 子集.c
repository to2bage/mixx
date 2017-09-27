#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cnt = 0;

void process(int idx, int *arr, int size, int **dp, int *pbool)
{
    if(idx >= size)
    {
        /*
        int sz = 0;
        //获得布尔向量中1的个数
        for(int i = 0; i < size; i++)
        {
            if(pbool[i] == 1)
            {
                sz++;
            }
        }
        */
        //根据sz生成数组
        int *px = (int *)malloc(size * sizeof(int));
        memset(px, 0, size * sizeof(int));
        //int j = 0;
        for(int i = 0; i < size; i++)
        {
            if(pbool[i] == 1)
            {
                px[i] = arr[i];
            }
        }
        dp[cnt++] = px;

        return;
    }
    //选择idx索引的元素
    pbool[idx] = 1;
    process(idx + 1, arr, size, dp, pbool);
    //不选择idx索引的元素
    pbool[idx] = 0;
    process(idx + 1, arr, size, dp, pbool);
}

int **subsets(int *arr, int size, int *prows)
{
    int count = 1;
    for(int i = size; i > 0; i--)
    {
        count *=i;
    }
    count++;
    *prows = count;
    int **dp = (int **)malloc(count * sizeof(int *));
    //定义布尔向量
    int *pbool = (int *)malloc(size * sizeof(int));
    memset(pbool, 0, size * sizeof(int));
    
    process(0, arr, size, dp, pbool);
    return dp;
}

int main(int argc, char *argv[])
{
    int arr[] = {1,2,3};
    int size = sizeof(arr)/sizeof(int);
    int rows = 0;

    int **ppret = subsets(arr, size, &rows);
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < size; j++)
        {
            printf("%4d", ppret[i][j]);
        }
        printf("\n");
    }

    return 0;
}