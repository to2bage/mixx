#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cnt = 0;

int **robot(int idx, int count, int *arr, int size, int **dp)
{
    if(count == 0)
    {
        //return [[]]
        int *px = (int *)malloc(size * sizeof(int));
        memset(px, 0, size * sizeof(int));
        dp[cnt++] = px;
        return dp;
    }

    for(int i = 0; i < size; i++)
    {
        int **dpr = robot(i + 1, count - 1, arr, size, dp);
        int *px = (int *)malloc(size * sizeof(int));
        memset(px, 0, size * sizeof(int));
        px[0] = arr[i];
        dp[cnt++] = px;
    }

}

int **subset(int *arr, int size, int *prow)
{
    int row = 8;
    *prow = row;
    int **dp = (int **)malloc(row * sizeof(int *));

    for(int i = 0; i <= size; i++)
    {
        robot(0, i, arr, size, dp);
    }
    return dp;
}

int main(int argc, char *argv[])
{
    int arr[] = {1,2,3};
    int size = sizeof(arr)/sizeof(int);
    int rows = 0;
    int **ppret = subset(arr, size, &rows);


}