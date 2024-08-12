/*

Problem Statement -

You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 
 */

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int, int>> q;
        int freshOranges = 0;
        
        // Initialize the queue with all rotten oranges
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }
        
        // If there are no fresh oranges, return 0
        if (freshOranges == 0) return 0;
        
        int minutes = 0;
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        // BFS
        while (!q.empty()) {
            int qSize = q.size();
            bool rottedThisMinute = false;
            
            for (int i = 0; i < qSize; ++i) {
                auto [x, y] = q.front();
                q.pop();
                
                for (const auto& dir : directions) {
                    int nx = x + dir[0];
                    int ny = y + dir[1];
                    
                    // If the adjacent cell is a fresh orange, rot it
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        freshOranges--;
                        rottedThisMinute = true;
                    }
                }
            }
            
            if (rottedThisMinute) {
                minutes++;
            }
        }
        
        // If there are still fresh oranges left, return -1
        return freshOranges == 0 ? minutes : -1;
    }
};