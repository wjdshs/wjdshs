#include <cstdio>
#include <stack>
#include <vector>
using namespace std;

struct Edge{
    int to;
    int cost;
    Edge(int to, int cost) : to(to), cost(cost) {}
};

vector<Edge> a[1001];
int dist[1001];
bool check[1001];
int from[1001];
int inf = 1000000000;

int main(){
    int n;
    scanf("%d",&n);
    int m;
    scanf("%d",&m);
    for(int i=0; i<m; i++){
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        a[x].push_back(Edge(y,z));
    }
    int start, end;
    scanf("%d %d",&start,&end);
    for(int i=1; i<=n; i++){
        dist[i] = inf;
    } 
    dist[start] = 0;
    from[start] = -1;
    for(int k=0; k<n-1; k++){
        int m = inf+1;
        int x = -1;
        for(int i=1; i<=n; i++){
            if(check[i] == false && m > dist[i]){
                m = dist[i];
                x = i;
            }
        }
        check[x] = true;
        for(int i=0; i<a[x].size(); i++){
            int y = a[x][i].to;
            if(dist[y] > dist[x] + a[x][i].cost){
                dist[y] = dist[x] + a[x][i].cost;
                from[y] = x;
            }
        }
    }
    printf("%d\n",dist[end]);
    stack<int> st;
    int x = end;
    while(x != -1){
        st.push(x);
        x = from[x];
    }
    printf("%d\n",st.size());
    while(!st.empty()){
        printf("%d ",st.top());
        st.pop();
    }
    printf("\n");
    return 0;
}