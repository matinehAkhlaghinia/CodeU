#include <iostream>
#include <cstring>
#include <stdbool.h>

using namespace std;


int tileIsValid(bool** mapOfTiles, int row, int col, bool** visited, int rows, int columns)
{
    return (row > -1) && (row < rows) && (col > -1) && (col < columns) && (mapOfTiles[row][col] && !visited[row][col]); 
}
 
void findTheIsland(bool** mapOfTiles, int row, int col, bool** visited, int rows, int columns)
{
   int row_[] = {-1, 0,  1, 0};
   int col_[] = {0,  1, 0, -1};

    visited[row][col] = true;
 
    for (int i = 0; i < 4; i++) {
      if (tileIsValid(mapOfTiles, row + row_[i], col + col_[i], visited, rows, columns)) {
        findTheIsland(mapOfTiles, row + row_[i], col + col_[i], visited, rows, columns);
      }
            
    }
        
}
 

int countIslands(bool** mapOfTiles, int rows, int columns)
{
    bool** visited = new bool*[rows];
    for(int i = 0; i < rows; i++)
      visited[i] = new bool[columns];
    memset(visited, 0, sizeof(&visited));
    int countIslands = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            if (mapOfTiles[i][j] && !visited[i][j]) 
            {                         
                findTheIsland(mapOfTiles, i, j, visited, rows, columns);    
                ++countIslands;                  
            }
 
    return countIslands;
}
