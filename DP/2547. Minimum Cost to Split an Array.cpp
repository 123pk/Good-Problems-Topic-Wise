/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 329
Approach :- We will use (Recursion + Memoisation) , 
            we will try to find for ith index what is the minimum cost I can get from if I consider [0,i] array
            we have two option either to partition at ith index or not .
            Like knapsack and we try all possible combination of partition using recursion and memoisation.
            We maintain on frequency array ,if fre[ele] == 2,then we add 2 to 'importance value' and for all fre[ele]>2 we increment by '1'
            at the end the (score = importance_value + k + cost_from_(i-1) )
Time Complexity :- O(n^2)
*/
class Solution {
public:
    long long dp[1003];
    long long find(int i,long long k,vector<int>&nums){
        
         if(dp[i]!=-1)return dp[i];
        
        int count[1003]={0};
        long long c = 0,val=1e18;
        for(int j=i;j>=0;--j){
            count[nums[j]]++;
            if(count[nums[j]] == 2){
                c+=2;
            }
            else if(count[nums[j]]>2) c++;
            long long cur = 0;
            if((j-1)>=0)cur += find(j-1,k,nums);
            val = min(val,cur+c+k);
        }
        //cout<<(i+1)<<" "<<val<<"\n";
        return dp[i] = val;
    }
    
    int minCost(vector<int>& nums, int k) {
         memset(dp,-1,sizeof(dp));
        int n = nums.size();
        long long ex = k;
       // cout<<"\n";
        return find(n-1,ex,nums);
    }
};
