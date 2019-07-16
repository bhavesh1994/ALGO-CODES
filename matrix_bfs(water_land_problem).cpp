#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m,k;
    cin>>n>>m>>k;
    int arr[n+2][m+2];
    int visited[n+2][m+2];
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m+1;j++){
            visited[i][j] = 0;
            arr[i][j] = 3;
        }
    }
    // input
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        for(int j=0;j<m;j++){
            if(s[j]=='*'){
                arr[i][j+1]=1;
            }
            else{
                arr[i][j+1] = 0;
            }
        }
    }
    int lakes =0;
    vector<pair<int,pair<int,int> > > v;
    // bfs //
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(visited[i][j]==0 && arr[i][j]==0){
                queue<pair<int,int> > q;
                q.push(make_pair(i,j));
                int ans = 1;
                int f = 0;
                visited[i][j] =1;
                while(!q.empty()){
                    int x= q.front().first;
                    int y= q.front().second;
//                  cout<<x<<" "<<y<<endl;
                    q.pop();
                    if(arr[(x+1)][y]==0 && visited[(x+1)][y]==0){
                        q.push(make_pair(x+1,y));
                        visited[(x+1)][y]=1;
//                      cout<<"yo1"<<endl;
                        ans++;
                    }
                    else if(arr[(x+1)][y]==3){
                        f=1;
//                      break;
                    }
                    if(arr[(x-1)][y]==0 && visited[(x-1)][y]==0){
                        q.push(make_pair(x-1,y));
                         visited[(x-1)][y]=1;
                         ans++;
//                       cout<<"yo2"<<endl;
                    }
                    else if(arr[(x-1)][y]==3){
                        f=1;
//                      break;
                    }
                    if(arr[(x)][y+1]==0 && visited[(x)][y+1]==0){
                        q.push(make_pair(x,y+1));
                        visited[(x)][y+1]=1;
                        ans++;
//                      cout<<"yo3"<<endl;
                    }
                    else if(arr[(x)][y+1]==3){
                        f=1;
//                      break;
                    }
                    if(arr[x][y-1]==0 && visited[(x)][y-1]==0){
                        q.push(make_pair(x,y-1));
                        visited[x][y-1]=1;
                        ans++;
//                      cout<<"yo4"<<endl;
                    }
                    else if(arr[(x)][y-1]==3){
                        f=1;
//                      break;
                    }
                }
                if(f==0){
                    v.push_back(make_pair(ans,make_pair(i,j)));
                    lakes++;
                }
            }
        }
    }
    int ans =0;
    // cout<<lakes<<endl;
    // for(int i=0;i<(v.size());i++){
    //  cout<<v[i].second.first<<" "<<v[i].second.second<<" "<<v[i].first<<endl;
    // }
    sort(v.begin(),v.end());
    // cout<<"after"<<endl;
    // for(int i=0;i<(v.size());i++){
    //  cout<<v[i].second.first<<" "<<v[i].second.second<<" "<<v[i].first<<endl;
    // }
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m+1;j++){
            visited[i][j] = 0;
        //  arr[i][j] = 3;
        }
    }
    
    for(int i=0;i<(v.size()-k);i++){
        ans+= v[i].first;
        queue<pair<int,int> > q;
//      cout<<v[i].second.first<<" "<<v[i].second.second<<endl;
        arr[v[i].second.first][v[i].second.second] = 1;
        q.push(make_pair(v[i].second.first,v[i].second.second));
        while(!q.empty()){
            int x= q.front().first;
            int y= q.front().second;
            visited[x][y] = 1;
            q.pop();
            arr[(x)][y]=1;
            if(arr[(x+1)][y]==0 && visited[(x+1)][y]==0){
                q.push(make_pair(x+1,y));
                visited[(x+1)][y]=1;
                arr[(x+1)][y]=1;
            }
            if(arr[(x-1)][y]==0 && visited[(x-1)][y]==0){
                q.push(make_pair(x-1,y));
                 visited[(x-1)][y]=1;
                 arr[(x-1)][y]=1;
            }
            if(arr[(x)][y+1]==0 && visited[(x)][y+1]==0){
                q.push(make_pair(x,y+1));
                visited[(x)][y+1]=1;
                arr[(x)][y+1]=1;
            }
            
            if(arr[x][y-1]==0 && visited[(x)][y-1]==0){
                q.push(make_pair(x,y-1));
                visited[x][y-1]=1;
                arr[x][y-1]=1;
            }
        }
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
        //  visited[i][j] = 0;
            if(arr[i][j]==0){
                cout<<'.';
            }
            else{
                cout<<"*";
            }
            
        }
        cout<<endl;
    }
    return 0;
}