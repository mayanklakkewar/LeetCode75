/*
Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj) such that row ri and column cj are equal.

A row and column pair is considered equal if they contain the same elements in the same order (i.e., an equal array).

 

Example 1:


Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
Output: 1
Explanation: There is 1 equal row and column pair:
- (Row 2, Column 1): [2,7,7]
Example 2:


Input: grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
Output: 3
Explanation: There are 3 equal row and column pairs:
- (Row 0, Column 0): [3,1,2,2]
- (Row 2, Column 2): [2,4,2,2]
- (Row 3, Column 2): [2,4,2,2]
 
*/

//Code -

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {

        // O(n^3) Solution
        // int n = grid.size();
        // int count=0;

        // for(int r = 0; r<n; r++){
        //     for(int c = 0; c<n; c++){
        //         int isEqual = 1;
        //         for(int i=0;i<n;i++){
        //             if(grid[r][i] != grid[i][c]){
        //                 isEqual = 0;
        //                 break;
        //             }
        //         }
        //         if(isEqual){
        //             count+=isEqual;
        //         }
        //     }
        // }
        // return count;


        // O(n^2) Solution
        //Solving through maps
        map<vector<int>,int> mp;
        int n = grid.size();
        int count =0;
        
        for(int row =0; row <n; row++){
            mp[grid[row]]++;
        }

        for(int c=0; c<n; c++){
            vector<int> temp;
            for(int r=0; r<n; r++){
                temp.push_back(grid[r][c]);
            }
            count += mp[temp];// checking is the temp avilable in map
        }
        return count;
    }
};