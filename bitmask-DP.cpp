// problem Atcoder - https://atcoder.jp/contests/dp/tasks/dp_o

#include<bits/stdc++.h>
 
using namespace std;
 
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MT make_tuple
 
// #define N 311111
#define A 1111111
#define BLOCK 555 // ~sqrt(N)
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
 
const ll INF = 1e18 +5;
const int nax = 100005;
const long M = 1000000007;
 
ll dp[1<<22];
// int in_degree[nax];
// vector<int> edges[nax];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	// cout<<fixed;
	// cout<<setprecision(10);
	int t;
	// cin>>t;
	t = 1;
	while(t--){
		int n,m;
		cin>>n;
		int arr[n][n];
		for(int i=0;i<n;i++){
		    for(int j=0;j<n;j++){
		        cin>>arr[i][j];
		    }
		}
		ll x = 1<<n;
		dp[0]=1;
        for (int i=0;i<x;i++){
            int bits = __builtin_popcount (i);
            for (int j=0;j<n;j++){
                if((i & (1<<j)) == 0 && arr[bits][j]==1){
                    dp[i | (1<<j)] +=  dp[i] ;
                    dp[i | (1<<j)] %=M;
                } 
            }                
        }
        // for(int i=0;i<x;i++){
        // 	cout<<dp[i]<<" ";
        // }
        // cout<<endl;
		cout<<dp[(1<<n)-1]<<endl;
	}
}
