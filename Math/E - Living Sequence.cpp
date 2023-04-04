/*
Platform :- Codeforces
Contest :- Codeforces Round 863

*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    
    while(t--){
        long long k;
        cin>>k;
        
        
        int digit = 1;
        long long cur = 1;
        long long covered = 0;
        while(1){
            long long lim = cur * 9ll;
            if(lim >= k)break;
            cur = lim;
            digit++;
        }
         
        
        //now I know number of digits in my answer
        //cout<<digit<<"\n";
        vector<int> ans(digit);
        
        for(int i=0;i<digit;++i){
            //How many digits of this I want
            long long have = (digit - (i+1));
            have = powl(9,have);
            
            long long required = k/have;
            if(required>=4)ans[i] = required+1;
            else ans[i] = required;
           // cout<<have<<" "<<required<<"\n";
            long long filled = required*have;
            k -= filled;
        }
        
        
        for(auto&x:ans)cout<<x;
        cout<<"\n";
    }
}
