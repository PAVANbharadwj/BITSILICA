#include <stdio.h>
#define ROW 4
#define COL 5

int grid[ROW][COL] =
 {
    {1,1,0,0,1},
    {1,0,0,1,1},
    {0,0,1,1,0},
    {1,1,0,0,1}
};

int dfsArea(int r, int c) 
{
    if (r < 0 || c < 0 || r >= ROW || c >= COL || grid[r][c] == 0)
        return 0;

    grid[r][c] = 0;
    return 1 + dfsArea(r+1,c) + dfsArea(r-1,c) + dfsArea(r,c+1) + dfsArea(r,c-1);
}

int largestIsland() {
    int max = 0;

    for(int r=0; r<ROW; r++){
        for(int c=0; c<COL; c++){
            if(grid[r][c] == 1){
                int area = dfsArea(r,c);
                if(area > max) max = area;
            }
        }
    }
    return max;
}

int main()
{
    printf("Largest Island Area = %d\n", largestIsland());
    return 0;
}
