/*
Problem Statement -

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 
*/

//Code -


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int left[n];
        int right[n];
        vector<int> ans(n,1);

        //making a left array
        left[0] = 1;
        for(int i=1;i<n;i++){
            left[i] = left[i-1] * nums[i-1];        }

        //making right array
        right[n-1] = 1;
        for(int i=n-2; i>=0;i--){
            right[i] = right[i+1] * nums[i+1];
        }

        for(int i=0;i<n;i++){
            ans[i] = left[i] * right[i];
        }

        return ans;
    }
};