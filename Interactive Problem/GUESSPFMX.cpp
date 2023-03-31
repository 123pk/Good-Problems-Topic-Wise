/*
Platform :- Codechef 
Contest :- Codechef Starters 83
Solution :- https://www.codechef.com/viewsolution/93353939
Video Explanation Hindi :- https://youtu.be/1TAB_tnd0Kg
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        vector<int>A(n);
        for(int i=0;i<n;++i)A[i] = i+1;
        
        int lim = n-1;
        int j = n-1;
        int c = 1;
        while(lim--){
            cout<<"? ";
            for(auto&x:A)cout<<x<<" ";
            cout<<endl;
            cout.flush();
            
            
            int len;
            cin>>len;
            vector<int>temp(len);
            for(int i=0;i<len;++i)cin>>temp[i];
            
            int m = temp.size();
            
            //We are moving current max value to right position
            // for maximum value correct position is very end 
            //for 2nd max correct position is 2nd last ..and so on
            swap(A[j],A[temp[m-c]-1]);
            j--;
            c++;
            
            cout.flush();
            temp.clear();
            
        }
        
        vector<int>ans(n);
        for(int i=0;i<n;++i){
            ans[A[i]-1] = i+1;
        }
        
        cout<<"! ";
        for(auto&x:ans)cout<<x<<" ";
        cout<<endl;
        int f;
        cin>>f;
        cout<<endl;
        cout.flush();
    }
}
