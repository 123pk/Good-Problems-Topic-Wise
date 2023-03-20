/*
Platform :- Codeforces Round 859 Div 4
Approach :- 
*/

#include <bits/stdc++.h>
using namespace std;

bool pattern1(string s){
    //1010
    vector<int>cur_val(26,-1);
    for(int i=0;i<s.size();++i){
        
        if(cur_val[s[i]-'a'] == -1){
            if(i%2 == 0)cur_val[s[i]-'a'] = 1;
            else cur_val[s[i]-'a'] = 0;
        }
        else{
            int val = 0;
            if(i%2 == 0)val = 1;
            
            if(cur_val[s[i]-'a'] != val)return false;
        }
    }
    return true;
}

bool pattern2(string s){
    //01010
    vector<int>cur_val(26,-1);
    for(int i=0;i<s.size();++i){
        
        if(cur_val[s[i]-'a'] == -1){
            if(i%2)cur_val[s[i]-'a'] = 1;
            else cur_val[s[i]-'a'] = 0;
        }
        else{
            int val = 0;
            if(i%2)val = 1;
            
            if(cur_val[s[i]-'a'] != val)return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin>>t;
    
    while(t--){
         int n;
         cin>>n;
         
         long long A[n];
          
          
         for(int i=0;i<n;++i){
             cin>>A[i];
              
              
         }
         
         int lim = 30;
         int ans = 0;
         
         int start = 0,end = n-1,mid = (start+end)/2;
         
         while(start<=end && lim){
             
             //we will check for all value from start tot mid
             long long tot = 0;
             cout<<"? "<<(mid-start)+1<<" ";
             for(int i=start;i<=mid;++i){
                 tot += A[i];
                 cout<<(i+1)<<" ";
             }
             cout<<endl;
             
             long long have;
             cin>>have;
             
             cout.flush();
             
             if(have == tot){
                 //it is not in this half
                 start = mid+1;
                 mid = (start+end)/2;
             }
             else{
                 ans = mid;
                 end = mid-1;
                 mid = (start+end)/2;
             }
             lim--;
             
         }
         
         
         
         cout<<"! "<<(ans+1)<<endl;
         cout.flush();
         
        
    }
}
