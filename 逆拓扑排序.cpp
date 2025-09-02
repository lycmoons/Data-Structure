#include<vector>
#include<stack>
using namespace std;

/**
 * 逆拓扑排序也是仅针对有向无环图（DAG）
 * 与拓扑排序的区别在于优先排出出度为 0 的顶点
 * 
 * 主要有两种做法：
 *      1.通过出度表来进行拓扑排序
 *      2.通过 dfs 进行拓扑排序
 * 
 * 数据结构使用简化版的邻接表进行存储
 *      g[i] 表示存储 i 号顶点能一步到达的顶点编号
 */
vector<vector<int>> g;


// 1.通过出度表来进行拓扑排序
vector<int> topoSort(vector<vector<int>>& g) {
    int n = g.size();
    vector<int> ans;    // 最终的拓扑排序序列

    // 获取 DAG 的顶点出度表
    vector<int> outdegree(n, 0);
    for(int i = 0; i < n; i++) {
        outdegree[i] = g[i].size();
    }

    // 存储每一个顶点的所有父节点，用于更新出度表
    vector<vector<int>> parents(n);
    for(int i = 0; i < n; i++) {
        for(int child : g[i]) {
            parents[child].push_back(i);
        }
    }

    // 初始化栈，将最初出度为 0 的顶点全部放入栈中
    stack<int> st;
    for(int i = 0; i < n; i++) {
        if(outdegree[i] == 0) {
            st.push(i);
        }
    }

    // 开始拓扑排序
    while(!st.empty()) {
        int vertex = st.top();
        st.pop();
        ans.push_back(vertex);

        // 更新出度表，将出度变为 0 的顶点入栈
        for(int parent : parents[vertex]) {
            outdegree[parent]--;
            if(outdegree[parent] == 0) {
                st.push(parent);
            }
        }
    }

    return ans;
}



// 2.通过 dfs 进行拓扑排序
void dfs(vector<vector<int>>& g, int start, vector<bool>& visited, vector<int>& ans) {
    for(int child : g[start]) {
        if(!visited[child]) {
            dfs(g, child, visited, ans);
        }
    }

    // 当 start 的子节点全部访问完，说明 start 的出度已经变为 0
    visited[start] = true;
    ans.push_back(start);
}

vector<int> topoSort(vector<vector<int>>& g) {
    int n = g.size();
    vector<int> ans;
    vector<bool> visited(n, false);
 
    // 这个 dfs 算法可以从任意顶点出发
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(g, i, visited, ans);
        }
    }
}