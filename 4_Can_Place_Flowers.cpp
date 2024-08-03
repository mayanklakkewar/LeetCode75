/*
Problem Statement -

You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

 

Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
Example 2:

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false

*/

// Code -

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();
        if(n==0) return true;
        int count = 0;
        for(int i=0;i<len;i++){
            if(flowerbed[i]==0){
                bool leftEmpty   = (i == 0) || (flowerbed[i-1] == 0);
                
                bool rightEmpty  = (i == len-1) || (flowerbed[i+1] == 0);
                
                if(leftEmpty && rightEmpty){
                    flowerbed[i] = 1;
                    n--;
                    if(n==0){
                        return true;
                    }
                }
            }
        }   
        return false;
    }
};