/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 333
Approach :- https://leetcode.com/problems/count-the-number-of-square-free-subsets/solutions/3204813/video-explanation-hindi-o-2-19-worst-case-bitmask-c/?orderBy=most_votes
*/
class Solution {
public:
    long long mod = 1e9+7;
    int not_allowed[31];
   
    long long power(long long a,long long b){
        long long res = 1ll;
        
        while(b){
            if(b%2){
                res*=a;
                res%=mod;
            }
            b>>=1ll;
            a*=a;
            a%=mod;
        }
        return res;
    }
    
    int squareFreeSubsets(vector<int>& nums) {
         
         
        memset(not_allowed,0,sizeof(not_allowed));
        for(int i=2;i<=5;++i){
            int cur = i*i;
            for(int j=cur;j<=30;j+=cur){
                not_allowed[j]++;
            }
        }
        vector<long long>z;
        vector<long long>fre(31);
        
        for(auto&x:nums){
            fre[x]++;
          //we are taking only valid values 
            if(not_allowed[x] == 0){
                z.push_back(x);
                //after adding to our valid array we mark this also so we don't add them again in array                 
                not_allowed[x]++;
            }
        }
        
        long long ex = 1;
        if(not_allowed[1]){
// only for '1' we have 2^fre[1] options
            ex = power(2ll,fre[1]);
            ex--;
        }
       
         int n = z.size();
         
        
        long long ans = 0;
        int lim = (1<<n);
        
//finding all subsequency usignn bitmask
        for(int i=1;i<=lim;++i){
            long long pro = 1;
            long long gc = 1;
            int f = 0,g = 0;
            long long val = 1,e = 1;
            
 
            for(int j=0;j<n;++j){
                if(i & (1<<j)){
                    gc = __gcd(pro,z[j]);
                    g = 1;

                   //if GCD >1 it means we have square factor
                    if(gc>1){
                        f=1;
                        break;
                    }
                    pro*=z[j];
                    if(z[j] != 1){
                        val*=fre[z[j]];
                        val%=mod;
                    }
                    else e = ex;
                     
                }
            }
            
            if(f);
            else if(g){
                val*=e;
                val%=mod;
                ans += val;
                ans%=mod;
            }
        }
        
        int fin = ans;
        return fin;
    }
};
