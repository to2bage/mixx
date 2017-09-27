#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

#define N 8
int a[N];       //a[i]表示第i行的皇后,所在的位置是a[i]列

void show()
{
    int data[N][N] = {0};
    static int cnt = 0;
    printf("No. %2d:\n", cnt++);

    for(int i = 0; i < N; i++)
    {
        data[i][a[i]] = 1;
    }
    //show
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(data[i][j] == 1)
            {
                //表示皇后的位置
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

int check(int idx)              //检查第idx行的皇后的位置是否合法
{
    for(int i = 0; i < idx; i++)
    {
        if(a[i] == a [idx] || abs(i - idx) == abs(a[i] - a[idx]))
        {
            return 0;   //不合法
        }
    }
    return 1;           //合法
}

void sovlerNQueen(int idx)        //递归第idx行的皇后的位置
{
    if(idx >= N)
    {
        return;
    }

    for(int i = 0; i < N; i++)
    {
        a[idx] = i;   //第idx行要放皇后, 位置可以是[0,N-1]种选择
        //判定皇后放在i位置是否合法
        if(check(idx) == 1)
        {
            if(idx == N - 1)
            {
                show();                         //判定合格, 记录了最后一次的a[idx]的值
            }
            else
            {
                sovlerNQueen(idx + 1);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    sovlerNQueen(0);

    return 0;
}