#include<vector>
#include<queue>
using namespace std;

#define INT_MAX 2147483647

/**
 * 最短路径算法有两种：
 *      1.单源最短路径算法       -> 求图中某一个特定的顶点到其他顶点的最短路径
 *      2.点对点最短路径算法     -> 求图中任意两个顶点之间的最短路径
 */


// 1.使用 BFS 算法，设计无权图的单源最短路径算法
/**
 * 使用 dish 数组来保存 start 点到其他每个点的最短距离
 * 使用 path 数组来保存 start 点到其他点的最短路径的前驱
 */
void bfs(vector<vector<int>>& g, int start, vector<int>& dist, vector<int>& path) {
    int n = g.size();
    dist.resize(n);
    path.resize(n, -1);
    vector<bool> visited(n, false);    // 标记顶点是否已经被访问过
    queue<int> qu;
    qu.push(start);

    while(!qu.empty()) {
        visited[qu.front()] = true;
        for(int child : g[qu.front()]) {
            if(!visited[child]) {
                path[child] = qu.front();
                dist[child] = dist[qu.front()] + 1;
                qu.push(child);
            }
        }
        qu.pop();
    }
}


// 2.使用 Dijkstra 算法，设计无权图或带权图的单源最短路径算法
/**
 * 只适用于带权图中的边权都是非负数的情况（⚠️⚠️⚠️重点注意⚠️⚠️⚠️）
 * 
 * 使用 dish 数组来保存 start 点到其他每个点的最短距离
 * 使用 path 数组来保存 start 点到其他点的最短路径的前驱
 */
void dijkstra(vector<vector<pair<int, int>>>& g, int start, vector<int>& dist, vector<int>& path) {
    int n = g.size();
    dist.resize(n, INT_MAX);
    path.resize(n, -1);

    vector<bool> fin(n, false);      // 表示顶点是否已经找到最短路径
    fin[start] = true;
    dist[start] = 0;

    // 从 start 顶点出发，初始化 dist 和 path 数组
    for(auto child : g[start]) {
        dist[child.first] = child.second;
        path[child.first] = start;
    }

    // 进行 n - 1 次循环，找 start 顶点到其他 n - 1 个顶点之间的距离
    for(int i = 0; i < n - 1; i++) {
        // 找当前未确定最短路径的顶点中路径最短的
        int index;
        int mn = INT_MAX;
        for(int j = 0; j < n; j++) {
            if(!fin[j]) {
                if(dist[j] < mn) {
                    mn = dist[j];
                    index = j;
                }
            }
        }

        // 设定为已找到最短路径
        fin[index] = true;

        // 从本轮确定的最短路径出发，更新目前还未确定最短路径的顶点的最短路径
        for(auto child : g[index]) {
            if(!fin[child.first]) {
                int newDist = dist[index] + child.second;
                if(newDist < dist[child.first]) {
                    dist[child.first] = newDist;
                    path[child.first] = index;
                }
            }
        }
    }
}


// 3.使用 Floyd 算法，设计无权图或带权图的点对点最短路径算法
/**
 * 能解决带负权值的图的最短路径问题
 * 但当负权值的边出现在一个回路中时，可能无法解决（沿着回路走可能越走路径越小）
 * 
 * 其中 dist 和 path 都是一个 n * n 的数组
 * dist[i][j] 表示从 i 号顶点到 j 号顶点的最短距离
 * path[i][j] 表示从 i 号顶点到 j 号顶点的最短路径在到达 j 号顶点之前的那个顶点
 */
void floyd(vector<vector<pair<int, int>>>& g, vector<vector<int>>& dist, vector<vector<int>>& path) {
    int n = g.size();
    vector<int> temp1(n, INT_MAX);
    vector<int> temp2(n, -1);
    dist.resize(n, temp1);
    path.resize(n, temp2);
    for(int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }

    // 首先初始化 dist 和 path 数组（不经过任何中间点的情况）
    for(int i = 0; i < n; i++) {
        for(auto child : g[i]) {
            dist[i][child.first] = child.second;
            path[i][child.first] = i;
        }
    }

    // 依次以 0 号顶点到 n - 1 号顶点为中间点更新 dist 和 path 数组
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(j == i && k == i && j == k) continue;  // 跳过不需要更新的路径
                if(dist[j][i] == INT_MAX && dist[i][k] == INT_MAX) continue;  // 跳过无法以 i 号顶点为中间点的路径
                int newLength = dist[j][i] + dist[i][k];
                if(newLength < dist[j][k]) {
                    dist[j][k] = newLength;
                    path[j][k] = path[i][k];
                }
            }
        }
    }
}