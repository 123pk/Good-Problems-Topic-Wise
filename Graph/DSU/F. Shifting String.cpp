/*
Platform :- Codeforces
Contest :- Codeforces Round 797 Div 3
Approach :- Here each permutation value can act as a node , and we are goinng to form a cycle from them ,
            we will have 'x' disjoint set union or components and all having cycle.
            We will find the string formed by the component , then we will find the minimum operation to find the 
            intial string again . Atmax 'n' - length of intial string . 
            So we will have 'x' no of such minimum operations and the final answer is LCM of all the values.
 Time Complexity :- O(n)
*/
#include<bits/stdc++.h>
using namespace std;

long long find(string&s ,string& t){
    int idx = 0;
    
    for(int i=1;i<=(s.size()-t.size());++i){
        
        int f = 0;
        for(int j=0;j<t.size();++j){
            if(t[j] != s[j+i]){
                f=1;
                break;
            }
        }
        
        if(f == 0)return i;
    }
    return 1;
}

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        string s;
        cin>>s;
        
        long long ans = 1;
        int A[n];
        for(int i=0;i<n;++i){
            cin>>A[i];
            
            //0 based indexing
            A[i]--;
        }
        
        vector<int>vis(n);
        for(int i=0;i<n;++i){
            if(vis[A[i]])continue;
            
            queue<int>bfs;
            bfs.push(A[i]);
            int c = 0;
            string temp = "";
            temp += s[A[i]];
            vis[A[i]]++;
            
            while(!bfs.empty()){
               
                int cur = bfs.front();  
                bfs.pop();
                
                int next = A[cur];
                if(vis[next])break;
                
                temp += s[next];
                vis[next]++;
                bfs.push(next);
            }
            
            string fin = temp + temp;
            //cout<<temp<<" "<<fin<<" --> ";
            long long score = find(fin,temp);
            
             ans = (ans*score)/__gcd(ans,score);
             
             
        }
        
        cout<<ans<<"\n";
    }
}
