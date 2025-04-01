#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii; // (travel time, node)

// Function to compute the shortest travel time from emergency stations to the incident
int findShortestResponseTime(int n, vector<vector<pii>>& cityGraph, vector<int>& emergencyStations, int incidentLocation) {
    vector<int> minTime(n, INT_MAX); // Store shortest time to each node
    priority_queue<pii, vector<pii>, greater<pii>> pq; // Min-heap (time, node)

    // Initialize emergency stations as starting points
    for (int station : emergencyStations) {
        minTime[station] = 0;
        pq.push({0, station});
    }

    // Dijkstra's Algorithm
    while (!pq.empty()) {
        auto [currTime, node] = pq.top();
        pq.pop();

        if (currTime > minTime[node]) continue; // Skip outdated entries

        // Explore neighbors
        for (auto [neighbor, travelTime] : cityGraph[node]) {
            int newTime = currTime + travelTime;
            if (newTime < minTime[neighbor]) {
                minTime[neighbor] = newTime;
                pq.push({newTime, neighbor});
            }
        }
    }

    return minTime[incidentLocation]; // Shortest time to incident location
}

int main() {
    int n = 6; // Number of intersections (nodes)
    vector<vector<pii>> cityGraph(n);

    // Graph representation (u -> v with travel time w)
    vector<vector<int>> roads = { {0, 1, 4}, {0, 2, 2}, {1, 2, 1}, {1, 3, 5}, {2, 3, 8}, {3, 4, 3}, {4, 5, 6} };

    for (auto& road : roads) {
        int u = road[0], v = road[1], w = road[2];
        cityGraph[u].push_back({v, w});
        cityGraph[v].push_back({u, w}); // Undirected road
    }

    vector<int> emergencyStations = {0, 2}; // Locations of hospitals, fire, police stations
    int incidentLocation = 4; // Location of the incident

    int shortestTime = findShortestResponseTime(n, cityGraph, emergencyStations, incidentLocation);
    cout << "Shortest response time to incident: " << shortestTime << " minutes" << endl;

    return 0;
}
