/*
Platform :- Leetcode
Approach :- So the basic idea is to dfs and we find the max length path we can get to if we start from some cell (i,j) we use 2d matrix to store it and later use that value
            if required so that we don't compute for same cell again and again (Dynamic Programming).
            We have four option to move from any cell (left,right ,up and down)
            we check all the four option if it is valid to move and we have not already visited and find its value we go there and finnd the value ,mark it visited.
Time Complexity :- O(m*n)
*/
class Solution {
public:
    
    int find(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&score,vector<vector<int>>&vis){
        vis[i][j]++;
       
        int val = 0;
         
        if((i-1)>=0 && matrix[i-1][j]<matrix[i][j]){
            if(score[i-1][j]){
                val = max(val,score[i-1][j]);
            }
            else if(vis[i-1][j] == 0){
               val = max(val,find(i-1,j,matrix,score,vis));    
            }
        }
        
        if((i+1)<matrix.size() && matrix[i+1][j]<matrix[i][j]){
            if(score[i+1][j]){
                val = max(val,score[i+1][j]);
            }
            else if(vis[i+1][j] == 0){
               val = max(val,find(i+1,j,matrix,score,vis));    
            }
        }
        
        if((j-1)>=0 && matrix[i][j-1]<matrix[i][j]){
            if(score[i][j-1]){
                val = max(val,score[i][j-1]);
            }
            else if(vis[i][j-1] == 0){
               val = max(val,find(i,j-1,matrix,score,vis));    
            }
        }
        
        if((j+1)<matrix[0].size() && matrix[i][j+1]<matrix[i][j]){
            if(score[i][j+1]){
                val = max(val,score[i][j+1]);
            }
            else if(vis[i][j+1] == 0){
               val = max(val,find(i,j+1,matrix,score,vis));    
            }
        }
            
            
        return score[i][j] = 1+val;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>>score(n,vector<int>(m));
        vector<vector<int>>vis = score;
      //  cout<<n<<" "<<m<<endl;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(vis[i][j])continue;
                int val = find(i,j,matrix,score,vis);
                ans = max(ans,val);
               // cout<<val<<" ";
            }
             
        }
        
        return ans;
    }
};
