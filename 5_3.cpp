#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return false; // Already connected, cycle detected

        // Union by rank
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }
};

// Function to find the Minimum Spanning Tree (MST) cost
int minCostToConnectCities(int n, vector<vector<int>>& edges) {
    sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b) {
        return a[2] < b[2]; // Sort edges by cost
    });

    DSU dsu(n);
    int totalCost = 0, edgesUsed = 0;

    for (auto& edge : edges) {
        int u = edge[0], v = edge[1], cost = edge[2];
        if (dsu.unite(u, v)) {
            totalCost += cost;
            edgesUsed++;
            if (edgesUsed == n - 1) return totalCost; // MST complete
        }
    }

    return -1; // Not all cities are connected
}

int main() {
    int n = 4; // Number of cities (nodes)
    vector<vector<int>> edges = { {0, 1, 5}, {1, 2, 10}, {2, 3, 7}, {0, 3, 8}, {1, 3, 6} };

    int minCost = minCostToConnectCities(n, edges);
    cout << "Minimum Cost to Connect All Cities: " << minCost << endl;

    return 0;
}
