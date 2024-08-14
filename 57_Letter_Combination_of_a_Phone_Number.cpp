/*
Problem Statement -

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 
*/

//Code -

class Solution {
public:
   vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        
        vector<string> digitToLetters = {
            "",    "",    "abc",  "def", 
            "ghi", "jkl", "mno", 
            "pqrs", "tuv", "wxyz"
        };
        
        vector<string> result;
        string currentCombination;
        backtrack(result, digitToLetters, digits, currentCombination, 0);
        return result;
    }
    
    void backtrack(vector<string>& result, const vector<string>& digitToLetters, const string& digits, string& currentCombination, int index) {
        if (index == digits.length()) {
            result.push_back(currentCombination);
            return;
        }
        
        int digit = digits[index] - '0';
        const string& letters = digitToLetters[digit];
        
        for (char letter : letters) {
            currentCombination.push_back(letter);
            backtrack(result, digitToLetters, digits, currentCombination, index + 1);
            currentCombination.pop_back(); // backtrack
        }
    }
};