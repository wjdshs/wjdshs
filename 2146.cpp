#include<iostream>
#include<queue>
#include<deque>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
int N,m = 9999999;
int maze[101][101];
int visited[101][101];
int number[101][101];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
int bfs(int cnt) {
    queue < pair < int,int > > q;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            if(maze[i][j] == 1 && number[i][j] == cnt) {
                q.push(make_pair(i,j));
                visited[i][j] = 1;
            }
        }
    }
    int step = 0;
    while(!q.empty()) {
        int qsize = q.size();
        for(int i=0; i<qsize; i++) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            for(int i=0; i<4; i++) {
                int newy = y + dy[i];
                int newx = x + dx[i];
                if(newy > N || newy <= 0 || newx > N || newx <= 0)
                    continue;
                if(visited[newy][newx])
                    continue;
                if(maze[newy][newx] && number[newy][newx] != cnt)
                    return step;
                if(maze[newy][newx] == 0) {
                    visited[newy][newx] = 1;
                    q.push(make_pair(newy,newx));
                }
            }
        }
        step++;
    }
}
 
void seperate(int y, int x, int cnt) {
    queue < pair < int,int > > q;
    visited[y][x] = 1;
    number[y][x] = cnt;
    q.push(make_pair(y,x));
    while(!q.empty()) {
        int ny = q.front().first;
        int nx = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int newy = ny + dy[i];
            int newx = nx + dx[i];
            if(newy > N || newy <= 0 || newx > N || newx <= 0)
                continue;
            if(visited[newy][newx])
                continue;
            if(maze[newy][newx] == 1) {
                visited[newy][newx] = 1;
                q.push(make_pair(newy,newx));
                number[newy][newx] = cnt;
            }
        }
    }
}
 
int main() {
    int cnt = 0;
    scanf("%d",&N);
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            scanf("%1d",&maze[i][j]);
        }
    }
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            if(visited[i][j] == 0 && maze[i][j] == 1) {
                cnt++;
                seperate(i,j,cnt);
            }
        }
    }
    for(int i=1; i<=cnt; i++) {
        memset(visited,0,sizeof(visited));
        m = min(m,bfs(i));
    }
    printf("%d\n",m);
}