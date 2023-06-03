#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void dfs(int vertex, vector<vector<int> >& adjacency_matrix, vector<bool>& visited, vector<int>& component) 
{
    visited[vertex] = true;
    component.push_back(vertex);
    for (int neighbor = 0; neighbor < adjacency_matrix[vertex].size(); neighbor++) {
        if (adjacency_matrix[vertex][neighbor] == 1 && !visited[neighbor]) {
            dfs(neighbor, adjacency_matrix, visited, component);
        }
    }
}
void printConnected(vector<vector<int> >& adjacency_matrix)
{
    vector<bool> visited(adjacency_matrix.size(), false);
    for (int vertex = 0; vertex < adjacency_matrix.size(); vertex++) {
        if (!visited[vertex]) {
            vector<int> component;
            dfs(vertex, adjacency_matrix, visited, component);
            sort(component.begin(), component.end() );
            for (int i = 0; i < component.size(); i++) {
                cout << component[i] << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int num_vetices;
    cin >> num_vetices;
    vector< vector<int> > adjacency_matrix(num_vetices, vector<int>(num_vetices, 0));
    for(int i = 0; i < num_vetices; i++)
        for(int j = 0; j < num_vetices; j++)
        {
            cin >> adjacency_matrix[i][j];
        }
    printConnected(adjacency_matrix);
    return 0;
}
