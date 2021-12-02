#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main(){
    int n;
    priority_queue<int, vector<int>, greater<int>> q;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int m;
        scanf("%d",&m);
        if(m==0){
            if(!q.empty()){
                printf("%d\n",q.top());
                q.pop();
            }
            else printf("0\n");
        }
        else q.push(m);
    }
}