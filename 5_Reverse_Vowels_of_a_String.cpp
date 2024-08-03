/* 
Problem Statement -

Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

 

Example 1:

Input: s = "hello"
Output: "holle"
Example 2:

Input: s = "leetcode"
Output: "leotcede"

*/

// Code -

class Solution {
private:
    bool ifVovel(char c){
        if(c=='a' or c=='e' or c=='i' or c=='o' or c=='u' or 
        c=='A' or c == 'E' or c == 'I' or c == 'O' or c == 'U'){
            return true;
        }
        return false;
    }
public:
    string reverseVowels(string s) {
        int n = s.length();
        int left =0, right = n-1;
        while(left<right){
            if(!ifVovel(s[left])){
                left++;
            }
            else if(!ifVovel(s[right])){
                right--;
            }
            else{
                swap(s[left],s[right]);
                left++;
                right--;
            }
        }

        return s;
    }
};

