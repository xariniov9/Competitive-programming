#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

bool FindUnassignedLocation(int** grid, int N, int &row, int &col){
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == 0)
                return true;
    return false;
}

int Sqrt(int N){
    int i=0;
    for(i = 1; i * i<N; i++)
    ;
    return i;
}

bool UsedInRow(int** grid, int N, int row, int num){
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}

bool UsedInCol(int** grid, int N, int col, int num){
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}

bool UsedInBox(int** grid, int N, int boxStartRow, int boxStartCol, int num){
    int box = Sqrt(N);
    for (int row = 0; row < box; row++)
        for (int col = 0; col < box; col++)
            if (grid[row+boxStartRow][col+boxStartCol] == num)
                return true;
    return false;
}

bool containsAbove(int** grid, int N, int boxStartRow, int boxStartCol, int num){
    if(boxStartRow < 0 || boxStartCol < 0 || boxStartRow >= N || boxStartCol >= N)
        return true;
    for(int col = 0; col *col < N; col++){
        if(grid[boxStartRow][col + boxStartCol] == num )
            return 1;
    }
    return 0;
}

bool containsBelow(int** grid, int N, int boxStartRow, int boxStartCol, int num){
    if(boxStartRow < 0 || boxStartCol < 0||boxStartRow >= N || boxStartCol >= N)
        return true;

    for(int col = 0; col * col< N; col++){
        if(grid[ boxStartRow][col + boxStartCol] == num){
           // printf("below yes\n");
            return 1;
        }
    }
   // printf("below no\n");
    return 0;
}

bool containsLeft(int** grid, int N, int boxStartRow, int boxStartCol, int num){
    if(boxStartRow < 0 || boxStartCol < 0 || boxStartRow >= N || boxStartCol >= N)
        return true;
    for(int row = 0; row * row < N; row++){
        if(grid[row + boxStartRow][boxStartCol] == num)
            return true;
    }
    return false;
}

bool containsRight(int** grid, int N,  int boxStartRow, int boxStartCol, int num){
    if(boxStartRow < 0 || boxStartCol < 0 || boxStartRow >= N || boxStartCol >= N)
        return true;
    for(int row = 0; row * row < N; row++){
        if(grid[row + boxStartRow][boxStartCol] == num){
        //    printf("right yes\n");
            return true;
        }
    }
   // printf("right no\n");
    return false;
}
bool isSafe(int** grid, int N, int row, int col, int num){
    int box = Sqrt(N);
   bool flag = !UsedInRow(grid, N, row, num) &&
           !UsedInCol(grid, N, col, num) &&
           !UsedInBox(grid, N, row - row%box , col - col%box, num)
           ;
    return flag;
}

bool isSafe1(int** grid, int N, int row, int col, int num){
    int box = Sqrt(N);
        return containsBelow(grid, N, row + box, col - col%box, num) &&
           containsRight(grid, N, row - row%box, col + box, num);
}


int prop5(int N, int ** grid){
    //return true;
    if(grid[0][0] != 1)
        return 0;
    bool flag = true;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            flag = flag && isSafe1(grid, N, i, j, grid[i][j]);
    return flag;

}
    int SolveMagicSquare(int input1_size_rows, int input1_size_cols, int** grid){
        if(grid[0][0] == 0 || grid[0][0] == 1){
            grid[0][0] = 1;
        } else
            return false;
        if(input1_size_rows != input1_size_cols)
            return false;
        int row, col;
        if (!FindUnassignedLocation(grid, input1_size_rows, row, col))
            return prop5(input1_size_rows, grid);
        for (int num = 1; num <= input1_size_rows; num++){
            if (isSafe(grid, input1_size_rows, row, col, num)){
                grid[row][col] = num;
                if (SolveMagicSquare(input1_size_rows, input1_size_cols, grid))
                    return true;
                grid[row][col] = 0;
            }
        }
        return false;
    }

int grid1[4][4] = {{1, 0,0,0}, {0,0,2,0}, {0,3,0,0}, {0,0,0,4}};
int main(){

    int** grid = new int*[4];
    for(int i=0; i<4; ++i)
        grid[i] = new int[4];
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            grid[i][j] = grid1[i][j];
    printf("%d\n", SolveMagicSquare(4, 4, grid));
   /* for(int i=0; i<4; i++){
        for(int j=0; j<4; j++)
            printf("%d ",grid[i][j]);
        printf("\n");
    }*/
    //int N = 4;
    //printf("box : %d\n",sqrt(N));
}
