#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define MAX 10001
bool check[MAX] = {false,};
vector<pair<int,int>> mArr[MAX];

void prim(){
    check[1] = true;
    priority_queue<pair<int,int>> q;
    for(auto p: mArr[1]){
        q.push(make_pair(-p.second, p.first));
    }
    int answer = 0;
    while(!q.empty()){
        pair<int,int> p = q.top();
        q.pop();
        if(!check[p.second]){
            check[p.second] = true;
            answer+= -p.first;
            int x = p.second;
            for(pair<int,int> p : mArr[x]) q.push(make_pair(-p.second, p.first));
        }
    }
    cout<<answer<<'\n';
}

int main(){
    int n=0, m=0;
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        int a=0, b=0, c=0;
        cin>>a>>b>>c;
        mArr[a].push_back(make_pair(b,c));
        mArr[b].push_back(make_pair(a,c));
    }
    prim();
    return 0;
}