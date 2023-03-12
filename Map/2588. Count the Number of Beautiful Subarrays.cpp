/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 336
Explanation :- https://leetcode.com/problems/count-the-number-of-beautiful-subarrays/solutions/3286633/video-explain-2-approaches-o-n-log-n-c-map/?orderBy=most_votes
*/

class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long ans = 0;
        
        map<int,long long>count;
         
        //you can get a hint that in XOR we do same operation
        //if we have two set bits then XOR of them will remove that bit
        //so this whole problem comes down to finding number of subarrays with 
        //XOR values to be '0'
        count[0]++;
        int cur = 0;
        for(auto&x:nums){
            
            cur^=x;

            ans += count[cur];
            count[cur]++;
        }
        
        return ans;
    }
};```
