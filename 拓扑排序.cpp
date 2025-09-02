#include<vector>
#include<stack>
using namespace std;

/**
 * 拓扑排序仅针对有向无环图（DAG）
 * 主要有两种做法：
 *      1.通过入度表来进行拓扑排序
 *      2.通过 dfs 进行拓扑排序
 * 
 * 数据结构使用简化版的邻接表进行存储
 *      g[i] 表示存储 i 号顶点能一步到达的顶点编号
 */
vector<vector<int>> g;


// 1.通过入度表来进行拓扑排序
vector<int> topoSort(vector<vector<int>>& g) {
    int n = g.size();
    vector<int> ans;    // 最终的拓扑排序序列

    // 获取 DAG 的顶点入度表
    vector<int> indegree(n, 0);
    for(int i = 0; i < n; i++) {
        for(int child : g[i]) {
            indegree[child]++;
        }
    }

    // 初始化栈，将最初入度为 0 的顶点全部放入栈中
    stack<int> st;
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            st.push(i);
        }
    }

    // 开始拓扑排序
    while(!st.empty()) {
        int vertex = st.top();
        st.pop();
        ans.push_back(vertex);

        // 更新入度表，将入度变为 0 的顶点入栈
        for(int child : g[vertex]) {
            indegree[child]--;
            if(indegree[child] == 0) {
                st.push(child);
            }
        }
    }

    return ans;
}



// 2.通过 dfs 进行拓扑排序