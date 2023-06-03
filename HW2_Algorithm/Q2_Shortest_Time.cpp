#include <bits/stdc++.h>
#define INF 100000000
typedef long long ll;
using namespace std;
// Struct for the edges of the graph
struct Edge {
  ll u;  //start vertex of the edge
  ll v;  //end vertex of the edge
  ll w;  //w of the edge (u,v)
};

// Graph - it consists of edges
struct Graph {
  ll V;        // Total number of vertices in the graph
  ll E;        // Total number of edges in the graph
  struct Edge* edge;  // Array of edges
};

// Creates a graph with V vertices and E edges
struct Graph* createGraph(ll V, ll E) {
  struct Graph* graph = new Graph;
  graph->V = V;  // Total Vertices
  graph->E = E;  // Total edges

  // Array of edges for graph
  graph->edge = new Edge[E];
  return graph;
}
void SPT(ll start,ll end, Graph* graph)
{
    //Construct Shortest Path Tree using Bellman-Ford Algorithm
    ll V = graph->V;
    ll E = graph->E;

    vector<ll> dist(V, INF);
    dist[start] = 0;
    for(ll i = 0; i < V - 1; i++)	
    {		
        for(ll j = 0; j < E; j++)
        {
            int u = graph->edge[j].u;
            int v = graph->edge[j].v;
            int w = graph->edge[j].w;
            if (dist[u] != INF && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
            if (dist[v] != INF && dist[v] + w < dist[u])
                dist[u] = dist[v] + w;
        }
    }
    cout << dist[end] << endl;
}
int main()
{
    ll num_vertices, num_edges;
    cin >> num_vertices >> num_edges;
    Graph* graph = createGraph(num_vertices, num_edges);
    vector<vector<ll> > edges(num_edges, vector<ll>(4,0));
    // input the start vertex, end vertex, and the time it takes to travel from start to end for each transportation method
    for(ll i = 0; i < num_edges; i++)
    {
        //u, v, w, t1, t2, t3
        ll u, v;
        cin >> u >> v;
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2] >> edges[i][3];
        graph->edge[i].u = u-1;
        graph->edge[i].v = v-1;
    }
    ll s[3];
    cin >> s[0] >> s[1] >> s[2];
    // define each edge as the minimum time it takes to travel from one vertex to another
    for(ll i = 0; i < num_edges; i++)
    {
        ll min_time = INF;
        for(ll j = 0; j < 3; j++)
        {
            if(s[j] <= edges[i][0] && min_time > edges[i][j+1]) min_time = edges[i][j+1];
        }
        graph->edge[i].w = min_time;
    }
    ll num_test_cases;
    cin >> num_test_cases;
    for(ll i = 0; i < num_test_cases; i++)
    {
        ll start, end;
        cin >> start >> end;
        SPT(start-1, end-1, graph);
    }
    return 0;
}