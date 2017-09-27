#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 4

char **dp = NULL;   //棋盘
int *path = NULL;   //path[i]: 第i行的皇后在棋盘中的列数是path[i]

//dp表示棋盘的二维数组, n表示棋盘的行数(列数).棋盘的行数和列数相等
void clearDp(char **dp, int n)
{
    for(int i = 0; i < n; i++)
    {
        memset(dp[i], 0, N * sizeof(char));
    }
}

void showChess()
{
    //
    clearDp(dp, N);             //这里必须要清除
    //
    static int cnt = 0;
    printf("No.%2d:\n", ++cnt);
    for(int i = 0; i < N; i++)
    {
        dp[i][path[i]] = 1;         //数组path[i]的值记录了第i行皇后, 在棋盘中的列数
    }
    //打印棋盘
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

int check(int idx)         //idx表示当前行
{
    //判定当前行idx的皇后的位置是否合法: 即当前行idx的皇后与之前的所有皇后进行判定
    for(int i = 0; i < idx; i++)
    {
        if(path[idx] == path[i] || abs(idx - i) == abs(path[idx] - path[i]))
        {
            //path[idx]== path[i]当前行idx的列数是否与行[0..idx-1]的列数相同
            return 0;   //判定不合格
        }
    }
    return 1;           //判定合格
}

void dfs(int idx, int n)        //推断皇后在行idx的可能位置; n表示棋盘行数的最大值
{
    if(idx >= n)
    {
        return;
    }

    for(int i = 0; i < n; i++)
    {
        path[idx] = i;
        if(check(idx) == 1)     //如果当前行的皇后判定合格: 有两种情况
        {
            if(idx == n - 1)    //1. 此时当前行已经是最后一行了, 就显示出结果
            {
                showChess();
            }
            else                //2.此时当前行不是最后一行 , 则继续判定下一行的皇后的位置
            {
                dfs(idx + 1, n);
            }
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
    

    dfs(0, N);          //从0行开始推断 ,行数的最大值是N
    return 0;
}
