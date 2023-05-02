#include <bits/stdc++.h>
using namespace std;
// Graph class represents a directed graph using adjacency list representation
class Graph
{
public:
   map<int, bool> visited;
   map<int, list<int>> adj;
   // function to add an edge to graph
   void addEdge(int v, int w);
   // DFS traversal of the vertices reachable from v
   void DFS(int v);
};
void Graph::addEdge(int v, int w)
{
   adj[v].push_back(w); // Add w to v’s list.
}
void Graph::DFS(int v)
{ // Mark the current node as visited and print it
   visited[v] = true;
   cout << v << " ";
   // Recur for all the vertices adjacent to this vertex
   list<int>::iterator i;
   for (i = adj[v].begin(); i != adj[v].end(); ++i)
      if (!visited[*i])
         DFS(*i);
}
int main()
{ // Create a graph given in the above diagram
   Graph g;
   g.addEdge(0, 1);
   g.addEdge(0, 2);
   g.addEdge(1, 2);
   g.addEdge(2, 0);
   g.addEdge(2, 3);
   g.addEdge(3, 3);
   g.addEdge(0, 4);
   g.addEdge(1, 4);
   g.addEdge(2, 4);
   g.addEdge(3, 4);
   cout << "Following is Depth First Traversal (starting from vertex 2) \n";
   // Function call
   g.DFS(0);
   return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
struct Node
{
   int data;
   struct Node *left, *right;
   Node(int data)
   {
      this->data = data;
      left = right = NULL;
   }
};
void printPreorder(struct Node *node)
{
   if (node == NULL)
      return;
   cout << node->data << " ";
   printPreorder(node->left);
   printPreorder(node->right);
}
int main()
{
   struct Node *root = new Node(1);
   root->left = new Node(2);
   root->right = new Node(3);
   root->left->left = new Node(4);
   root->left->right = new Node(5);

   cout << "\nPreorder traversal of binary tree is \n";
   printPreorder(root);

   return 0;
}
*/