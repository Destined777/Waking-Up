/* 一共有n只兔子 m个洞， 兔子和洞的距离小于等于s可以进洞， s是double，然后n行， 每行两个数，分别为兔子的x，y坐标，
  可为负数，都是double，接下来m行，每行三个数，分别为洞的x,y坐标和洞的容量（可以容纳几只兔子），输出最多洞内有几只兔子 
（使用dinic算法 将兔子和能进的洞用边连接，分别用源点连接所有的兔子节点，用汇点连接所有的洞节点）
*/
#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to, capacity, flow, rev;
};

vector<Edge> adj[500120];
int level[500120], start[500120];

void addEdge(int from, int to, int capacity) {
  Edge a = {to, capacity, 0, (int)adj[to].size()};
  Edge b = {from, 0, 0, (int)adj[from].size()};
  adj[from].push_back(a);
  adj[to].push_back(b);
}

double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

bool bfs(int source, int sink) {
    fill(level, level + 500120, -1);
    queue<int> q;
    q.push(source);
    level[source] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (const auto& edge : adj[u]) {
            if (level[edge.to] < 0 && edge.flow < edge.capacity) {
                level[edge.to] = level[u] + 1;
                q.push(edge.to);
                if (edge.to == sink) return true;
            }
        }
    }
    return false;
}

int sendFlow(int u, int flow, int sink) {
    if (u == sink) return flow;

    for (; start[u] < adj[u].size(); start[u]++) {
        Edge &edge = adj[u][start[u]];

        if (level[edge.to] == level[u] + 1 && edge.flow < edge.capacity) {
            int current_flow = min(flow, edge.capacity - edge.flow);
            int temp_flow = sendFlow(edge.to, current_flow, sink);

            if (temp_flow > 0) {
                edge.flow += temp_flow;
                adj[edge.to][edge.rev].flow -= temp_flow;
                return temp_flow;
            }
        }
    }
    return 0;
}

int maxFlow(int source, int sink) {
    int total_flow = 0;

    while (bfs(source, sink)) {
        fill(start, start + 500120, 0);
        while (int flow = sendFlow(source, 1e9, sink)) {
            total_flow += flow;
        }
    }
    return total_flow;
}

int main() { //dinic max stream
  int n, m;
  double s;
  cin >> n >> m >> s;

  vector<pair<double, double>> rabbits(n);
  vector<tuple<double, double, int>> holes(m);

  for (int i = 0; i < n; i++) {
    cin >> rabbits[i].first >> rabbits[i].second;
  }

  for (int i = 0; i < m; i++) {
    double x, y;
    int capacity;
    cin >> x >> y >> capacity;
    holes[i] = make_tuple(x, y, capacity);
  }
  const int source = 0;  // source node
  const int sink = n + m + 1; // sink node
  
  for (int i = 0; i < n; i++) {
    addEdge(source, i + 1, 1);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      double holeX = get<0>(holes[j]);
      double holeY = get<1>(holes[j]);

      if (distance(rabbits[i].first, rabbits[i].second, holeX, holeY) <= s) {
        addEdge(i + 1, n + j + 1, 1); // 兔子到洞
      }
    }
  }
  
  for (int j = 0; j < m; j++) {
     addEdge(n + j + 1, sink, get<2>(holes[j])); // 洞到汇点
  }

  int result = maxFlow(source, sink);
  cout << result << endl;
}
