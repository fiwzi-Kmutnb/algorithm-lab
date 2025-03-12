#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
typedef pair<int, int> pii;

int primMST(int n, vector<vector<pii>> &adj, int start) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<bool> inMST(n + 1, false);
    vector<int> key(n + 1, INT_MAX); 
    
    pq.push({0, start});
    key[start] = 0;
    int totalWeight = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int weight = pq.top().first;
        pq.pop();

        if (inMST[u]) continue;

        inMST[u] = true; 
        totalWeight += weight;
        // cout << "Debug: " << weight << " " << u << endl;

        for (auto &[v, w] : adj[u]) {
            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                // cout << "Debug2: " << v << " " << w << " " << u << endl;
                pq.push({w, v});
            }
        }
    }

    return totalWeight;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pii>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int start;
    cin >> start;

    cout << primMST(n, adj, start) << endl;

    return 0;
}
