#include <bits/stdc++.h>
using namespace std;
// modulo one using the fermat little principle sucht that the power always wraps around the p-1


// modulo binary exponentiation
long long solve(int a ,int n , int mod){
    long long res=1;
    while(n){
        if(n&1){
            res=(res*a)%mod;
            
        }
        a=(a*a)%mod;
        n=n/2;
        
    }
    return res;
    
}

int main() {
	// your code goes here
	// now we are calculating the a^b^c mod k 
	int a ,b,c,k;
	cin>>a>>b>>c>>k;
	long long exp=solve(b,c,k-1);
	long long ans=solve(a,exp,k);
	cout<<ans<<endl;
	
}
