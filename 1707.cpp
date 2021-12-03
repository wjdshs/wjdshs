#include<iostream>
#include<vector>
using namespace std;

vector<int> a[1001];
bool check[1001];

bool answer[1001];

void dfs2(int node);

void dfs1(int node){
    check[node]=true;
    for(int i=0;i<a[node].size();i++){
        int next=a[node][i];
        answer[node]=true;
        if(check[next]==false) dfs2(next);
    }
}

void dfs2(int node){
    check[node]=true;
    for(int i=0;i<a[node].size();i++){
        int next=a[node][i];
        if(check[next]==false) dfs1(next);
    }
}

int main(){
    int k;
    bool ok=true;
    scanf("%d", &k);
    while(k--){
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i=0;i<m;i++){
            int u, v;
            scanf("%d %d", &u, &v);
            a[u].push_back(v);
            a[v].push_back(u);
        }
        for(int i=1;i<=n;i++){
            if(check[i]==false){
                dfs1(i);
            }   
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<a[i].size();j++){
                int k=a[i][j];
                if(answer[i]==answer[j]) ok=false;
            }
        }
        printf("%s\n", ok ? "NO" : "YES");
    }
}