// Dijkstra’s algorithm

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void dijkstra(int numVertices, vector<vector<pair<int, int>>> &adjacency, int startNode) {
    vector<int> distances(numVertices, INT_MAX);
    distances[startNode] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    minHeap.push({0, startNode});

    while (!minHeap.empty()) {
        int currentNode = minHeap.top().second;
        int currentDist = minHeap.top().first;
        minHeap.pop();

        if (currentDist > distances[currentNode])
            continue;

        for (auto &connection : adjacency[currentNode]) {
            int nextNode = connection.first;
            int edgeWeight = connection.second;

            if (distances[currentNode] + edgeWeight < distances[nextNode]) {
                distances[nextNode] = distances[currentNode] + edgeWeight;
                minHeap.push({distances[nextNode], nextNode});
            }
        }
    }

    cout << "Node ID\tShortest Distance\n";
    for (int i = 0; i < numVertices; i++)
        cout << i << "\t" << distances[i] << "\n";
}

int main() {
    int vertexCount, edgeCount;
    cout << "Specify vertex count and edge count: ";
    cin >> vertexCount >> edgeCount;

    vector<vector<pair<int, int>>> graphAdj(vertexCount);

    cout << "Input edges as (source destination weight):\n";
    for (int i = 0; i < edgeCount; i++) {
        int sourceNode, destNode, weight;
        cin >> sourceNode >> destNode >> weight;
        graphAdj[sourceNode].push_back({destNode, weight});
        graphAdj[destNode].push_back({sourceNode, weight}); // Remove this line for directed graph
    }

    int originNode;
    cout << "Specify starting node: ";
    cin >> originNode;

    dijkstra(vertexCount, graphAdj, originNode);
    return 0;
}
