#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 8
char **dp = NULL;
int *path = NULL;
int *lie = NULL;
int *zhengxie = NULL;
int *fanxie = NULL;

void clearDp(char **dp, int n)
{
    for(int i = 0; i < n; i++)
    {
        memset(dp[i], 0, N * sizeof(char));
    }
}

void showChess()
{
    clearDp(dp, N);

    for(int i = 0; i < N; i++)
    {
        dp[i][path[i]] = 1;
    }

    static int cnt = 0;
    printf("No.%2d:\n", ++cnt);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(dp[i][j] == 1)
            {
                printf("●"); 
            }
            else
            {
                printf("○");
            }
        }
        printf("\n");
    }
}


void dfs(int idx, int n)
{
    if(idx >= n)
    {
        showChess();
        return;
    }

    for(int col = 0; col < n; col++)
    {
        if(lie[col] != 1 && zhengxie[idx + col] != 1 && fanxie[idx - col + n - 1] != 1)
        {
            path[idx] = col;
            lie[col] = 1;
            zhengxie[idx + col] = 1;
            fanxie[idx - col + n - 1] = 1;

            dfs(idx + 1, n);
            //重要, 也是容易忘记的地方. 在当前递归结束时, 要还原现场
            lie[col] = 0;
            zhengxie[idx + col] = 0;
            fanxie[idx - col + n - 1] = 0;
        }
    }
}


int main(int argc, char *argv[])
{
    dp = (char **)malloc(N * sizeof(char *));
    for(int i = 0; i < N; i++)
    {
        dp[i] = (char *)malloc(N * sizeof(char));
        memset(dp[i], 0, N * sizeof(char));
    }
    
    path = (int *)malloc(N * sizeof(int));
    memset(path, 0, N * sizeof(int));
    
    lie = (int *)malloc(100 * sizeof(int));
    memset(lie, 0, N * sizeof(int));

    zhengxie = (int *)malloc(100 * sizeof(int));
    memset(zhengxie, 0, 100 * sizeof(int));

    fanxie = (int *)malloc(100 * sizeof(int));
    memset(fanxie, 0, 100 * sizeof(int));

    dfs(0, N);


    return 0;
}