#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 987654321;
const int MAX = 100;
typedef struct
{
        int y, x;

}Dir;

 

Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

 

int N;

int graph[MAX][MAX];

bool visited[MAX][MAX];

 

void DFS(int y, int x, int cnt)

{

        visited[y][x] = true;

        graph[y][x] = cnt;

 

        for (int i = 0; i < 4; i++)

        {

                 int nextY = y + moveDir[i].y;

                 int nextX = x + moveDir[i].x;

 

                 if (0 <= nextY && nextY < N && 0 <= nextX && nextX < N)

                         if (graph[nextY][nextX] && !visited[nextY][nextX])

                                 DFS(nextY, nextX, cnt);

        }

}

 

int BFS(int cnt)

{

        queue<pair<int, int>> q;

        for(int i=0; i<N; i++)

                 for(int j=0; j<N; j++)

                         if (graph[i][j] == cnt)

                         {

                                 visited[i][j] = true;

                                 q.push(make_pair(i, j));

                         }

 

        int result = 0;

        while (!q.empty())

        {

                 int curSize = q.size();
                 for (int i = 0; i < curSize; i++)

                 {

                         int y = q.front().first;

                         int x = q.front().second;

                         q.pop();

 

                         for (int i = 0; i < 4; i++)

                         {

                                 int nextY = y + moveDir[i].y;

                                 int nextX = x + moveDir[i].x;

                                 if (0 <= nextY && nextY < N && 0 <= nextX && nextX < N)

                                 {


                                          if (graph[nextY][nextX] && graph[nextY][nextX] != cnt)

                                                  return result;


                                          else if (!graph[nextY][nextX] && !visited[nextY][nextX])

                                          {

                                                  visited[nextY][nextX] = true;

                                                  q.push(make_pair(nextY, nextX));

                                          }

                                 }

                         }

                 }

                 result++;

        }

}

 

int main(void)

{

        cin >> N;

 

        for (int i = 0; i < N; i++)

                 for (int j = 0; j < N; j++)

                         cin >> graph[i][j];

 

        int cnt = 1;

        //DFS를 통해 섬 표시

        for (int i = 0; i < N; i++)

                 for (int j = 0; j < N; j++)

                         if (graph[i][j] && !visited[i][j])

                                 DFS(i, j, cnt++);

 

        int result = INF;

        for (int i = 1; i < cnt; i++)

        {

                 memset(visited, false, sizeof(visited));

                 result = min(result, BFS(i));

        }

 

        cout << result << endl;

        return 0;

}