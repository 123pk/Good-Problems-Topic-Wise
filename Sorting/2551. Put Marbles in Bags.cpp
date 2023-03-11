/*
Platform :- Leetcode
Problem link :- https://leetcode.com/problems/put-marbles-in-bags/description/
Video Explanation (Hindi) :- https://youtu.be/xJfTvpGbDXo
Code :- https://leetcode.com/problems/put-marbles-in-bags/submissions/913304965/
*/
 
class Solution {
public:
    
    long long putMarbles(vector<int>& weight, int k) {
        long long ans = 0;
        
        long long tot1 = 0 , tot2 = 0;
        int n = weight.size();
        // effect of one partition is 
        //sum of weights[i] + weights[i+1] 
        //if we partition between i and i+1
        vector<long long>values;
        for(int i=1;i<n;++i){
            //finding all possible sum for adjacent pairs 
            long long z = weight[i] + weight[i-1];
            values.push_back(z);
        }

        //sorting them in increasing order
        sort(values.begin(),values.end());
        int m = values.size();

        //first k-1 values will give us the minimum score
        //last k-1 values will give us the maximum score
        for(int i=0;i<(k-1);++i){
           tot1 += values[i];
           tot2 += values[m-1-i];
        }
    
        return tot2 - tot1;
    }
};
