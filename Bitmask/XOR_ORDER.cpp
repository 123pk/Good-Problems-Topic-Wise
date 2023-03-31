/*
Platform :- Codechef
Contest :- Codechef Starters 83
Solution Explanation :-https://www.codechef.com/viewsolution/93417731
Video Explanation Hindi :- https://youtu.be/kwwtaGYr8TI
*/
#include <bits/stdc++.h>
using namespace std;

int biggest_difference_bit(long long &a,long long&b){
    
    for(int i=30;i>=0;--i){
        long long cur = 1ll<<i;
        
        //this conditon is checking if ith bit is set in 'a'
        //and unset in 'b'
        if((a&cur) && !(b&cur)){
            return i;
        }
    }
    return 0;
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    
	    long long a,b,c;
	    cin>>a>>b>>c;
	    
	    if(a==b || b == c || a == c){
	        cout<<"-1\n";
	    }
	    else if(a<b && b<c)cout<<0<<"\n";
	    else{
	        
	        long long ans = 0;
	        
	        if(a>b){
	            //it means there is a bit that is 
	            //present in 'a' and not in 'b'
	            //we want to remove that bit from 'a' while doing 'xor' and set that bit in 'b'
	            //we want the biggest set bit of 'a' which is
	            //unset in b
	            
	            ans = (1ll<<biggest_difference_bit(a,b));
	        }
	        
	        if(b>c){
	            ans |= (1ll<<biggest_difference_bit(b,c));
	        }
	        
	        if((a^ans)<(b^ans)  && (b^ans)<(c^ans)){
	            cout<<ans<<"\n";
	        }
	        else cout<<"-1\n";
	    }
	}
	return 0;
}
