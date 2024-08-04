/*
Problem Satement -

Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

 

Example 1:

Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.
Example 2:

Input: nums = [5,4,3,2,1]
Output: false
Explanation: No triplet exists.
Example 3:

Input: nums = [2,1,5,0,4,6]
Output: true
Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.

*/

//Code -

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int num1 = INT_MAX;
        int num2 = INT_MAX;
        for(int i=0;i<n;i++){
            int num3 = nums[i];

            if(num3 <= num1){
                num1 = num3;
            }
            else if(num3 <= num2){
                num2 = num3;
            }
            else{
                return true;
            }
        }
        return false;
    }
};