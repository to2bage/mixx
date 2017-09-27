#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 8
char **ans = NULL;
int cnt = 0;            //ans的当前行号
int *path = NULL;       //记录当前皇后的所在的列数

void dfs(int idx, int rows)
{
    if(idx >= rows)     //idx表示行数
    {
        //记录数据
        char *px = (char *)malloc(N * sizeof(char));
        memset(px, 0, N * sizeof(char));

        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(path[j] == i)
                {
                    px[j] = 'Q';
                }
                else
                {
                    px[j] = ',';
                }
            }
            ans[i] = px;
        }
        return;
    }

    for(int i = 0; i < N; i++)
    {
        path[idx] = i;      //当前皇后放在第idx行的皇后位置:是path[idx]
        //当将皇后放到第idx行的第i列上时, 继续遍历下一列
        dfs(idx + 1, rows);
    }
}

char **solveNQueen(int n)
{
    dfs(0, n);
    return ans;
}

void showQueen(int rows, int cols)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            printf("%4c", ans[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    ans = (char **)malloc(N * sizeof(char *));
    for(int i = 0; i < N; i++)
    {
        ans[i] = (char *)malloc(N * sizeof(char));
        memset(ans[i], 0, N * sizeof(char));
    }

    path = (int *)malloc(N * sizeof(int));
    memset(path, 0, N * sizeof(int));

    char **ppret = solveNQueen(N);

    showQueen(N, N);

    return 0;
}