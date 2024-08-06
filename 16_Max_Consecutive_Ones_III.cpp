/*

Problem Satement -

Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.


*/

// Code -

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxlen = 0;
        int l = 0;
        int r = 0, zero = 0;
        while(r<nums.size()){
            if(nums[r] == 0){
                zero++;
            }
            while(zero > k){
                if(nums[l] == 0) zero--;
                l++;
            }
            if(zero <= k){
                int len = r-l+1;
                maxlen = max(maxlen,len);
            }
            r++;
        }
        return maxlen;
    }
};