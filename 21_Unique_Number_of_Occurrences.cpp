/*
Problem Satement -

Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

 

Example 1:

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
Example 2:

Input: arr = [1,2]
Output: false
Example 3:

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true

*/

//Code -

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> ans;
        sort(arr.begin(),arr.end());
        int i=0;
        int size = arr.size();
        while(i<size){
            int count =1;
            for(int j=i+1;j<size;j++){
                if(arr[i]==arr[j]){
                    count++;
                }
                else{
                    break;
                }
            }
            ans.push_back(count);
            i=i+count;          
        }
        int size2 = ans.size();
        sort(ans.begin(),ans.end());
        for(int k=0; k<size2-1; k++){
            if(ans[k]==ans[k+1]){
                return false;
                }
            }
        return true;
    }
};