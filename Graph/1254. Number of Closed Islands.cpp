/*
Platform :- Leetcode
Approach:- We traverse through the matrix and if we found a cell with water that is not visited by us , we start our bfs from it and mark it as closed island
           , if while doing bfs we can go to any of the boundarys we unmark it as closed island .
           If everything goes fine and we are didn't reach any boundarys , then this is a closed island.
           We mark the water cells too such that we don't visit them multiple times .
Time Complexity :- O(m*n)
*/
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m));
        int dx[] = {0,0,-1,+1};
        int dy[] = {-1,+1,0,0};
        queue<pair<int,int>>bfs;
        int ans = 0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j] == 1)continue;
               if(vis[i][j] == 0){
                   ans++;
                   int f = 0;
                   bfs.push({i,j});
                    vis[i][j]++;
                   while(!bfs.empty()){
                       pair<int,int>temp = bfs.front();
                       bfs.pop();
                       int x = temp.first;
                       int y = temp.second;

                       if((x == 0) || (x == n-1) || (y == 0) || (y == m-1))f=1;
                      // cout<<x<<" "<<y<<" have the following \n";
                       for(int k=0;k<4;++k){
                           int cur_x = x + dx[k];
                           int cur_y = y + dy[k];

                           if((0<=cur_x && cur_x<n) && (0<=cur_y && cur_y<m)){
                               //it is valid point
                              // cout<<cur_x<<' '<<cur_y<<"\n";
                               if(grid[cur_x][cur_y] == 0){
                                   if(vis[cur_x][cur_y] == 0){
                                    
                                       vis[cur_x][cur_y]++;
                                       bfs.push({cur_x,cur_y});
                                   }
                               }
                           }
                       }
                   }
                   if(f)ans--;

                   cout<<"\n"<< i<<" "<<j<<" give me "<<ans<<"\n";
               }
            }
        }

        return ans;
        
    }
};
