/*
Platform :- Codeforces
Contest :- Codeforces Round #845 (Div. 2) and ByteRace 2023
Approach :- We want to cover all the vvalues from 1 to m or we want a group where the factors of numbers in that group union to all the values from (1 to m) 
            We can find the factors of a value in O(sqrt(A[i])) . 
            So the basic idea is to sort the values in increasing order ,then we maintain on SET which store the factors we need to find 
            Once the set becomes empty ,it means that we have found all the factors .
            We also maintain one 'left' pointer . which points to the smallest element of our group. The score is 'current' value - 'smallest' element. 
            We move the pointer if ( SET is empty) till the time it becomes un empty of started pointer to current value
 Time Complexity :- O(n*log n + O(n*sqrt(n))
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        
        set<int>unq;
        //storing the factors
        for(int i=1;i<=m;++i)unq.insert(i);
        
        vector<int>A(n);
        for(int i=0;i<n;++i)cin>>A[i];
        
        sort(A.begin(),A.end());
        int ans = -1;
        int start = 0;
        
        map<int,int>fre;
        for(int i=0;i<n;++i){
            //let us find the factos
            for(int j=1;j*j<=A[i];++j){
                if(A[i]%j == 0){
                    
                    if(j<=m && unq.size()){
                        if(unq.find(j)!=unq.end()){
                            unq.erase(j);
                        }
                        
                    }fre[j]++;
                    
                    if((A[i]/j)<=m && unq.size()){
                        if(unq.find(A[i]/j)!=unq.end()){
                            unq.erase(A[i]/j);
                        }
                        
                    }fre[A[i]/j]++;
                }
            }
             
            //we got all the factors
            if(unq.empty()){
              
                if(ans == -1){
                    ans = (A[i]-A[start]);
                }
                else{
                    ans = min(ans,A[i]-A[start]);
                }
                
                //I will moev my start pointer until I have that
                while(start<i && unq.empty()){
                    //get the factors of start value
                    for(int j=1;j*j<=A[start];++j){
                      if(A[start]%j == 0){
                           
                          
                         if(j<=m && fre[j] == 1){
                             unq.insert(j);
                         }
                         fre[j]--;
                         if((A[start]/j)<=m && fre[A[start]/j] == 1){
                             unq.insert(A[start]/j);
                             
                         }
                         fre[A[start]/j]--;
                      }
                    }
                 
                     
                     start++;
                    if(unq.empty()){
                       ans = min(ans,A[i]-A[start]);
                        
                    }
                    else{
                        //start++;
                        break;
                    }
                }
            }
        }
        
        cout<<ans<<"\n";
    }
}
