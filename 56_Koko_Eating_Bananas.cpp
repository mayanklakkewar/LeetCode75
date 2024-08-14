/*
PRoblem Statement -

Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

 

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
*/

//Code -

class Solution {
public:
    
    bool canEatAll(vector<int>& piles, int givenHour, int h) {
        int actualHour = 0;
        
        for(int &x : piles) {
            actualHour += x/givenHour;
            
            if(x%givenHour != 0)
                actualHour++;
            
        }
        
        return actualHour <= h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        
        int l = 1, r = *max_element(begin(piles), end(piles));
        
        while(l < r) {
            int mid = l + (r-l)/2;
            
            if(canEatAll(piles, mid, h)) {
                r = mid;
            } else {
                l = mid+1;
            }
            
        }
        
        return l;
    }
};