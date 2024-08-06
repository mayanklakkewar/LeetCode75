/*
Problem Satement -

Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

 

Example 1:

Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
Example 2:

Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
Example 3:

Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.

*/


//Code -

//O(N^2)

class Solution {
    int n;
private:
    int findMax(vector<int> nums,int skipIdx){
        int currlen =0;
        int maxlen =0;
        
        for(int i=0;i<n;i++){
            if( i == skipIdx ){
                continue;
            }
            if( nums[i] == 1){
                currlen++;
                maxlen = max(maxlen,currlen);
            }
            else{
                currlen = 0;
            }
        }
        return maxlen;
    }
public:
    int longestSubarray(vector<int>& nums) {
       n = nums.size();
       int result = 0;
       int countZero = 0;
       for(int i=0;i<n;i++){
            if(nums[i] == 0){
                countZero++;
                result = max(result,findMax(nums,i));
            }
        }
        if(countZero ==0){
            return n-1;
        }
        return result;
    }
};



//O(n)
class Solution {
    public:
    int longestSubarray(vector<int>& nums) {
        int i=0;
        int j=0;

        int result =0;
        int lastIdx =-1;

        while(j < nums.size()){
            if(nums[j] == 0){
                i = lastIdx +1;
                lastIdx = j;
            }
            result = max(result, j-i); // size = j-1+1 and deletion = -1 which is then equal to j-1
            j++;
        }
        return result;
    }
};    