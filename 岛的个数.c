/*
    leetcode: 第200题
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//定义队列
int qx[10000] = {0};      //记录队列中点的x坐标
int qy[10000] = {0};      //记录队列中点的y坐标

void check(int x, int y, char **grid, int gridRowSize, int gridColSize, int *ptail)
{
    if(x >= 0 && x < gridRowSize && y >= 0 && y < gridColSize && grid[x][y] == '1')
    {
        //点(x, y)符合要求, 入队
        qx[*ptail] = x;
        qy[*ptail] = y;

        //标记点(x, y)已经访问过了
        grid[x][y] = '0';
        //队列尾索引后移
        (*ptail) = (*ptail) + 1;
    }
}

void floodfill(int xpos, int ypos, char **grid, int gridRowSize, int gridColSize)
{
    //定义队列的头的索引
    int head = 0;
    //定义队列的尾部索引
    int tail = 1;   //不包含

    //当前点入队
    qx[0] = xpos;
    qy[0] = ypos;
    //grid[xpos][ypos] = '0';
    //当队列不为空时, 循环执行代码
    while(head < tail)
    {
        //取出队列的头元素
        int x = qx[head];
        int y = qy[head];
       
        //搜索点(x,y)的四个方向的元素是否符合条件
        //符合条件就入队, 并标记已经访问过了
        check(x - 1, y, grid, gridRowSize, gridColSize, &tail);
        check(x, y + 1, grid, gridRowSize, gridColSize, &tail);
        check(x + 1, y, grid, gridRowSize, gridColSize, &tail);
        check(x, y - 1, grid, gridRowSize, gridColSize, &tail);

         //出队
         head++;
    }

}

int numIslands(char** grid, int gridRowSize, int gridColSize) 
{
    int ans = 0;
    if(grid == NULL || (gridRowSize == 0 && gridColSize == 0))
    {
        return 0;
    }

    for(int row = 0; row < gridRowSize; row++)
    {
        for(int col = 0; col < gridColSize; col++)
        {
            if(grid[row][col] == '1')
            {
                floodfill(row, col, grid, gridRowSize, gridColSize);
                ans++;
            }
        }
    }
    return ans;
}

int main(int argc, char *argv[])
{
    /*
    char grid[4][5] = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };
    */
    char **grid = (char **)malloc(4 * sizeof(char *));
    char p1[] = {'1', '1', '1', '1', '0'};
    char p2[] = {'1', '1', '0', '1', '0'};
    char p3[] = {'1', '1', '0', '0', '0'};
    char p4[] = {'0', '0', '0', '0', '0'};
    grid[0] = p1;
    grid[1] = p2;
    grid[2] = p3;
    grid[3] = p4;

    int rect = numIslands(grid, 4, 5);
    printf("rect = %2d\n", rect);

    return 0;
}