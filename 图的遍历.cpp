#include<vector>
#include<queue>
#include<unordered_set>
#define SIZE 20
/**
 * 在实现图的遍历算法时，统一使用邻接表存储方式来作示范
 * 使用 visit 函数意思为访问顶点
 * 下面是一个简化版的邻接表存储形式
 * 其中 g(i) 是一个 vector 容器，存储的是 i 号顶点能够到达的所有顶点的编号
 */
vector<vector<int>> g(SIZE);

void visit(int pos) {
    return;
}

// 1.图的广度优先遍历（类似树的层次遍历）
/**
 * 保留所有顶点以及 BFS 的路径边，得到的就是 BFS 生成树
 */
void bfs(vector<vector<int>>& g, int start) {
    unordered_set<int> visited;    // 用于标记已经访问过的顶点
    queue<int> qu;                 // 辅助队列

    qu.push(start);
    
    while(!qu.empty()) {
        visit(qu.front());
        visited.insert(qu.front());
        for(int child : g[qu.front()]) {
            if(visited.count(child) == 0) {
                qu.push(child);
            }
        }
        qu.pop();
    }
}


// 2.图的深度优先遍历（类似树的先根遍历）
/**
 * 保留所有顶点以及 DFS 的路径边，得到的就是 DFS 生成树
 */
void dfs(vector<vector<int>>& g, int start) {
    static unordered_set<int> visited;

    visit(start);
    visited.insert(start);

    for(int child : g[start]) {
        if(visited.count(child) == 0) {
            dfs(g, child);
        }
    }
}