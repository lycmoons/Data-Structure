#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
#define SIZE 20
#define INT_MAX 2147483647
/**
 * 最小生成树（MST）的概念：
 *      对于一个带边权重的无向图
 *      在其所有的生成树（极小连通生成子图）中
 *      保留下来的边权重之和最小的生成树就是其最小生成树
 * 
 * 使用的数据结构示例还是简化的邻接表：
 *      g[i] 表示与 i 号顶点相连的所有边和顶点信息
 *      g[i][0].first 表示与 i 号顶点相连的第一个顶点的编号
 *      g[i][0].second 表示与 i 号顶点相连的第一个顶点的边的权重
 */
vector<vector<pair<int, int>>> g(SIZE);


// 1.Prim 算法（默认从 0 号顶点开始）
int prim(vector<vector<pair<int, int>>>& g) {
    int n = g.size();
    vector<bool> isJoin(n, false);        // 标记当前各个顶点是否已加入生成树中
    vector<int> lowestCost(n, INT_MAX);   // 标记当前还没有加入生成树中的顶点连入生成树的最小代价
    int totalCost = 0;                    // 存储最终生成树的边权重之和

    // 初始从 0 号节点开始构建生成树
    isJoin[0] = true;
    lowestCost[0] = 0;
    for(auto child : g[0]) {
        lowestCost[child.first] = child.second;
    }

    // 进行 n - 1 次循环，构建生成树
    for(int i = 0; i < n - 1; i++) {
        // 找到当前连入生成树的最小代价
        int mn = INT_MAX;
        int index = -1;
        for(int j = 0; j < n; j++) {
            if(!isJoin[j]) {
                if(lowestCost[j] < mn) {
                    index = j;
                    mn = lowestCost[j];
                }
            }
        }

        // 将这个最小代价的顶点连入生成树
        cout << "本次连入生成树的顶点为" << index << "号顶点" << endl;
        cout << "消耗的代价为（边权重）为" << mn << endl;
        totalCost += mn;

        // 更新其他顶点连入新的生成树的最小代价
        lowestCost[index] = 0;
        for(auto child : g[index]) {
            if(!isJoin[child.first]) {
                if(child.second < lowestCost[child.first]) {
                    lowestCost[child.first] = child.second;
                }
            }
        }
    }

    return totalCost;
}





// 2.Kruskal
/**
 * Kruskal 算法使用的数据结构不是邻接形式
 * 而是边信息的数组
 */
class Edge {
public:
    int v1;       // 这条边连接的第一个顶点
    int v2;       // 这条边连接的第二个顶点
    int weight;   // 这条边的权重
}

// 让边按照权重从小到大排序
bool compare(Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}

int kruskal(vector<Edge>& g, int n) {
    sort(g.begin(), g.end(), compare);   // 对所有边进行排序
    vector<int> group(n);                // 用于标记当前的顶点属于哪一个组
    int totalCost = 0;                   // 存储最终生成树的边权重之和

    // 初始情况下每一个顶点都是不连通的
    for(int i = 0; i < n; i++) {
        group[i] = i;
    }

    // 开始遍历所有边，若边的两端并不连通就应用这一条边
    int cnt = 0;
    for(Edge edge : g) {
        if(group[edge.v1] != group[edge.v2]) {
            cout << "本次连接的顶点为" << edge.v1 << "和" << edge.v2 << endl;
            cout << "消耗的代价为（边权重）为" << edge.weight << endl;
            totalCost += edge.weight;

            // 将 v2 顶点所在的组全部并入到 v1 顶点所在的组中
            int oldGroup = group[edge.v2];
            for(int i = 0; i < n; i++) {
                if(group[i] == oldGroup) {
                    group[i] = group[edge.v1];
                }
            }

            // 判断是否已经得到最小生成树、
            cnt++;
            if(cnt == n - 1) break;
        }
    }

    return totalCost;
}