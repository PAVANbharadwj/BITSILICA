#include <stdio.h>
int rows, cols;
void dfs(int grid[5][5], int x, int y) 
{
    if (x < 0 || y < 0 || x >= rows || y >= cols || grid[x][y] == 0)
        return;
    
    grid[x][y] = 0;

    dfs(grid, x+1, y);
    dfs(grid, x-1, y);
    dfs(grid, x, y+1);
    dfs(grid, x, y-1);
}

int countIslands(int grid[5][5])
{
    int count = 0;
    rows = cols = 5;

    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] == 1)
            {
                count++;
                dfs(grid, i, j);
            }
        }
    }
    return count;
}

int main() {
    int grid[5][5] =
     {
        {1,1,0,0,0},
        {0,1,0,0,1},
        {1,0,0,1,1},
        {0,0,0,0,0},
        {1,0,1,0,1}
    };

    printf("Number of Islands = %d", countIslands(grid));
}
