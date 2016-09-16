#include <bits/stdc++.h>
using namespace std;
bool arr[1005][1005];

bool check_bipertite(vector<vector<int> > g, int n){
	int color[n];
	for(int i =0;i<n;i++){
		color[i] = 0;
	}
	for(int i=0;i<n;i++){
		if(color[i]==0){
			queue<int> q;
			q.push(i);
			color[i] = 1;
			while(!q.empty()){
				int x = q.front();
				q.pop();
				for(int j=0;j<g[x].size();j++){
					int tmp = g[x][j];
					if(color[tmp]==0){
						if(color[x]==1){
							color[tmp] = 2;
						}
						if(color[x]==2){
							color[tmp] = 1;
						}
						q.push(tmp);
					}
					else{
						if(x!= tmp && color[tmp] == color[x]){
							return false;
						}
					}
				}
			}
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				arr[i][j]=0;
			}
		}
		for(int i=0;i<m;i++){
			int x,y;
			cin>>x>>y;
			arr[x-1][y-1] = 1;
			arr[y-1][x-1] = 1;
		}
		vector<vector<int> > comp;
		for(int i=0;i<n;i++){
			vector<int> a;
			comp.push_back(a);
		}
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				if(arr[i][j]==0 && arr[j][i]==0){
					comp[i].push_back(j);
					comp[j].push_back(i);
				}
			}
		}
		
		if(n==1 && n==2){
			cout<<"YES"<<endl;
		}
		else if(check_bipertite(comp,n)){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
		
	}
	return 0;
}