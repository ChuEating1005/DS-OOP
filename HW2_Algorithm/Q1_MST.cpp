#include <bits/stdc++.h>
#define Edge pair<ll, pair<ll,ll> >
typedef long long ll;
using namespace std;
void MST(int num_vertices, vector<vector<ll> > graph)
{
    //Use Prim's Algorithm to find the MST and its cost
    ll min_cost = 0;
    ll in_set = 1;
    priority_queue <Edge, vector<Edge>, greater<Edge> > pq;
    vector<bool> sel(num_vertices, false);
    sel[0] = true;
    // add all edges from vertex 0 to the priority queue
    for(ll i = 0; i < num_vertices; i++) if(graph[0][i] != 0)
    {
        pq.push(make_pair(graph[0][i], make_pair(0, i)));
    }
    while( in_set < num_vertices)
    {
        Edge e = pq.top();
        pq.pop();
        // if both vertices are already in the set, ignore this edge
        if(sel[e.second.second] == true) continue;
        // else add the edge to the MST
        min_cost += e.first;
        ll x = e.second.second;
        // add all edges from vertex x to the priority queue
        for(ll i = 0; i < num_vertices; i++) if(graph[x][i] != 0 && sel[i] == false)
        {
            pq.push(make_pair(graph[x][i], make_pair(x, i)));
        }
        sel[x] = true;
        in_set ++;
    }
    cout << min_cost << endl;
}
int main()
{
    ll num_vertices;
    cin >> num_vertices;
    // input the adjacency matrix of the graph
    vector<vector<ll> > graph(num_vertices, vector<ll>(num_vertices, 0));
    ll u, v ,w;
    // input the weight for each edge
    while(cin >> u >> v >> w)
    {
        graph[u][v] = w;
        graph[v][u] = w;
    }
    MST(num_vertices, graph);
    return 0;
}