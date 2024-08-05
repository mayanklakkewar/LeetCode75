/*
Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

 

Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
Example 2:

Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.
Example 3:

Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.

*/

//Code - 

class Solution {
private:
    bool isVovel(char c){
        if( c== 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u'){
            return true;
        }
        return false;
    }
public:
    int maxVowels(string s, int k) {
        int count = 0;
        int j=0;
        for(int i=0;i<k;i++){
            if(isVovel(s[i])){
                count++;
            }
            j++;
        }
        int maxCount = count;
        int left = 0;
        int right = k;
        while(right < s.length()){
            if(isVovel(s[left])){
                count--;
                left++;
            }
            else left++;

            if(isVovel(s[right])){
                count++;
                right++;
            }
            else right++;

            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};