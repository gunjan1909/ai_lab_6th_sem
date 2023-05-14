#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
map<pair<int, int>, int> cost;
// returns the minimum cost in a vector( if there are multiple goal states)
vector<int> uniform_cost_search(vector<int> goal, int start)
{ // minimum cost upto goal state from starting state
   vector<int> answer;
   // create a priority queue
   priority_queue<pair<int, int>> queue;
   // set the answer vector to max value
   for (int i = 0; i < goal.size(); i++)
      answer.push_back(INT_MAX);
   // insert the starting index
   queue.push(make_pair(0, start));
   // map to store visited node
   map<int, int> visited;
   int count = 0;
   while (queue.size() > 0)
   {
      pair<int, int> p = queue.top();
      queue.pop();
      p.first *= -1;
      if (find(goal.begin(), goal.end(), p.second) != goal.end())
      {
         int index = find(goal.begin(), goal.end(), p.second) - goal.begin();
         // if a new goal is reached
         if (answer[index] == INT_MAX)
            count++;
         // if the cost is less
         if (answer[index] > p.first)
            answer[index] = p.first;
         queue.pop();
         // if all goals are reached
         if (count == goal.size())
            return answer;
      }
      // check for the non visited nodes which are adjacent to present node
      if (visited[p.second] == 0)
         for (int i = 0; i < graph[p.second].size(); i++)
         {
            // value is multiplied by -1 so that least priority is at the top
            queue.push(make_pair((p.first +
                                  cost[make_pair(p.second, graph[p.second][i])]) *
                                     -1,
                                 graph[p.second][i]));
         }
      // mark as visited
      visited[p.second] = 1;
   }
   return answer;
}
int main()
{
   graph.resize(8);
   graph[0].push_back(1);
   graph[0].push_back(2);
   graph[0].push_back(3);
   graph[1].push_back(4);
   graph[2].push_back(5);
   graph[3].push_back(7);
   graph[4].push_back(6);
   graph[5].push_back(7);
   graph[6].push_back(7);
   cost[make_pair(0, 1)] = 3;
   cost[make_pair(0, 2)] = 2;
   cost[make_pair(0, 3)] = 1;
   cost[make_pair(1, 4)] = 6;
   cost[make_pair(2, 5)] = 4;
   cost[make_pair(3, 7)] = 20;
   cost[make_pair(4, 6)] = 1;
   cost[make_pair(6, 7)] = 1;
   cost[make_pair(5, 7)] = 8;
   vector<int> goal; // set the goal there can be multiple goal states
   goal.push_back(7);
   vector<int> answer = uniform_cost_search(goal, 0);
   cout << "Minimum cost from 0 to 7 is = " << answer[0] << endl;
   return 0;
}