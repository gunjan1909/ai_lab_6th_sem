#include <iostream>
#include <queue>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// Define the graph structure
struct Graph
{
   int vertices;
   vector<vector<pair<int, int>>> adjList;
   vector<int> heuristic;

   Graph(int V) : vertices(V), adjList(V)
   {
      heuristic.resize(V);
   }

   // Add edges to the graph
   void addEdge(int u, int v, int weight)
   {
      adjList[u].push_back(make_pair(v, weight));
      adjList[v].push_back(make_pair(u, weight));
   }

   // Set the heuristic value for a vertex
   void setHeuristic(int vertex, int value)
   {
      heuristic[vertex] = value;
   }

   // Perform A* Search
   void AStar(int start, int end)
   {
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
      vector<int> distance(vertices, INT_MAX);
      vector<int> parent(vertices, -1);
      vector<bool> visited(vertices, false);

      pq.push(make_pair(heuristic[start], start));
      distance[start] = 0;

      while (!pq.empty())
      {
         int curr = pq.top().second;
         pq.pop();

         if (curr == end)
         {
            break;
         }

         visited[curr] = true;

         for (int i = 0; i < adjList[curr].size(); i++)
         {
            int neighbor = adjList[curr][i].first;
            int weight = adjList[curr][i].second;

            if (!visited[neighbor] && distance[curr] + weight < distance[neighbor])
            {
               distance[neighbor] = distance[curr] + weight + heuristic[neighbor];
               parent[neighbor] = curr;
               pq.push(make_pair(distance[neighbor], neighbor));
            }
         }
      }

      if (parent[end] == -1)
      {
         cout << "No path exists between " << start << " and " << end << endl;
         return;
      }

      cout << "\nPath from " << start << " to " << end << ": ";
      vector<int> path;
      int curr = end;
      while (curr != start)
      {
         path.push_back(curr);
         curr = parent[curr];
      }
      path.push_back(start);

      for (int i = path.size() - 1; i >= 0; i--)
      {
         cout << path[i] << " ";
      }
      cout << endl;
   }
};

int main()
{
   // Create a graph with 6 vertices
   Graph g(6);

   // Add edges to the graph
   g.addEdge(0, 1, 5);
   g.addEdge(0, 2, 3);
   g.addEdge(1, 3, 6);
   g.addEdge(2, 3, 2);
   g.addEdge(2, 4, 4);
   g.addEdge(3, 4, 6);
   g.addEdge(3, 5, 3);
   g.addEdge(4, 5, 5);

   // Set the heuristic values for each vertex
   g.setHeuristic(0, 8);
   g.setHeuristic(1, 7);
   g.setHeuristic(2, 6);
   g.setHeuristic(3, 2);
   g.setHeuristic(4, 4);
   g.setHeuristic(5, 0);

   // Perform A* Search from vertex 0 to vertex 5
   g.AStar(0, 5);

   return 0;
}