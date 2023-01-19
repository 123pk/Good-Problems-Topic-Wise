#include <bits/stdc++.h>
using namespace std;

void find(vector<long long>&A,set<long long>&unq){
    stack<long long>P;
    for(int i=0;i<A.size();++i){
        if(P.empty()){
            P.push(A[i]);
        }
        else{
            if(P.top()<A[i]){
                while(P.top()<=A[i]){
                    long long val = P.top();
                    P.pop();
                    val = A[i]-val;
                    unq.insert(val);
                    if(P.empty())break;
                }
                P.push(A[i]);
            }
            else{
                long long val = P.top();
                val -= A[i];
                P.push(A[i]);
                unq.insert(val);
            }
        }
    }
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    
	    vector<long long>A(n);
	    for(int i=0;i<n;++i){
	        cin>>A[i];
	    }
	    
	    set<long long>unq;
	    find(A,unq);
	    reverse(A.begin(),A.end());
	    find(A,unq);
	    
	    cout<<unq.size()<<"\n";
	}
	return 0;
}
