/*
Platform :- Leetcode
Approach :- So we will try to solve this recursively first ,
            We need to two pointer one at 'start' and one at 'end' ,  now we compare the value 
            -Case 1 if then are same
                   - we move both start and end and find for (start+1,end-1)+2
            -Case 2 if they are not same
                    - we move the start pointer and find the max len I can get for (start+1,end)
                    - we move th end pointer and find the max len for ( start,end-1)
                    - max of both is what we care
            -- Termination case :- 
                - WHEN start == end -  return 1
                - when start+1 == end 
                    -- if start == end return 2
                    -- return 1 as it will work as middle element
           Now recursion will give us TLE so we will use (Memoisation) to get it accepted
Time Complexity :- O(n*m)
*/
class Solution {
public:
    int dp[1001][1001];

    int find(int i,int j,string&s){
        if(dp[i][j] != -1)return dp[i][j];

        if((j-i)<=1){
            if(i == j)return dp[i][j] = 1;
            else {
                if(s[i] == s[j])return dp[i][j] = 2;
                else return dp[i][j] = 1;
            }
        }
        else{
            //I hae twoo option
            //either to find match for the first character or ith character
            int val = 0 ;

            if(s[i] == s[j]){
                val = 2 + find(i+1,j-1,s);
            }
            else{
                //move the end pointer first and check the biggest length 
                //I can get

                val = find(i,j-1,s);

                //here we are moving the start pointer
                val = max(val,find(i+1,j,s));
                
            }
            //cout<<i<<"-"<<j<<" ->"<<val<<"\n";
             return dp[i][j] = val;
        }
    }

    int longestPalindromeSubseq(string s) {
         
        memset(dp,-1,sizeof(dp));
        int n = s.size();
        int z = find(0,n-1,s);
        return max(1,dp[0][n-1]);

    }
};
