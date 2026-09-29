#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here

  // PASCAL TRAINGLE OR THE NCR FORMULA 
  // HERE THE SECOND LOOP DOESNOT GO FOR THE VALUES 0 AND 1 IT STARTS LOOPING FROM 2
  
	int N;
	cin>>N;
	
	vector<vector<int>>C(N+1,vector<int>(N+1,0));
    
    for(int n=0;n<=N;n++){
        C[n][0]=C[n][n]=1;
        for(int r=1;r<n;r++){
            C[n][r]=C[n-1][r]+C[n-1][r-1];
            
        }
        
    }cout<<C[0][1]<<endl;
    
    
    
}
