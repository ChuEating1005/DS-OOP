#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

void dfs(int node, int treasure_room, vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& paths) {
    path.push_back(node);

    if (node == treasure_room) {
        paths.push_back(path);
    } else {
        for (int next : graph[node]) {
            dfs(next, treasure_room, graph, path, paths);
        }
    }

    path.pop_back();
}

vector<vector<int>> findPaths(int n, int m, vector<pair<int, int>>& connections, int start_room, int treasure_room) {
    // Create adjacency list representation of the graph
    vector<vector<int>> graph(n);
    for (const auto& connection : connections) {
        int room1 = connection.first;
        int room2 = connection.second;
        graph[room1].push_back(room2);
    }

    vector<int> path;
    vector<vector<int>> paths;
    dfs(start_room, treasure_room, graph, path, paths);

    // Sort the paths in ascending order
    sort(paths.begin(), paths.end());

    return paths;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> connections(m);
    for (int i = 0; i < m; i++) {
        int room1, room2;
        cin >> room1 >> room2;
        connections[i] = make_pair(room1, room2);
    }

    int start_room, treasure_room;
    cin >> start_room >> treasure_room;

    vector<vector<int>> paths = findPaths(n, m, connections, start_room, treasure_room);

    // Print the paths
    if (paths.empty()) {
        cout << -1 << endl;
    } else {
        for (const auto& path : paths) {
            for (int room : path) {
                cout << room << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
