
//小技巧:队列的数组实现, 记录点坐标的队列
public static int[] qx = new int[100000];
public static int[] qy = new int[100000];

public static int check(int x, int y, char[][] grid, int tail, int rows, int cols)
{
    //条件:当前点(x,y)在grid的内部, 且当前点表示的是岛屿的一部分
    if(x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == '1')
    {
        //在符合条件后, 入队
        qx[tail] = x;
        qy[tail] = y;
        grid[x][y] = '0';       //污染, 表示访问过了
        ++tail;
    }
    return tail;
}

public static void floodfill(int x, int y, char[][]grid, int rows, int cols)
{
    int head = 0;   //队列的头
    int tail = 1;   //队列的尾 [head, tail)
    qx[0] = x;
    qy[0] = y;      //将当前坐标入队
    grid[x][y] = '0';

    while(head < tail)      //队列不为空的情况下,继续循环
    {
        //检查队列的头结点的4个方向是否符合条件
        //符合条件就入队, 并标记已经访问过了(染红了)
        tail = check(qx[head] - 1, qy[head], grid, tail, rows, cols);//up
        tail = check(qx[head], qy[head] - 1, grid, tail, rows, cols);//left
        tail = check(qx[head] + 1, qy[head], grid, tail, rows, cols);//down
        tail = check(qx[head], qy[head] + 1, grid, tail, rows, cols);//right
        head++; //头结点检查完毕后, 出队
    }
}

public int numIslands(char [][]grid)
{
    if (grid.length == 0 || grid[0].length == 0) 
    {
        return 0;
    }

    int rows = grid.length;
    int cols = grid[0].length;
    int ans = 0;

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(grid[i][j] == '1')
            {
                //当grid[i][j]==1(表示当前坐标获得的是岛屿的一部分)
                //则, 开始让红整个小岛(将岛的每一个部分的坐标添加到队列中, 并修改grid[i][j]== 0)
                floodfill(i, j, grid, rows, cols);
                ans++;
            }
        }
    }
    return ans;
}