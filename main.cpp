// C++ program to print DFS traversal from a given vertex in a  given graph
#include<iostream>
#include <list>
#include <queue>

using namespace std;

// Graph class represents a directed graph using adjacency list representation
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
    void DFSUtil(int v, bool visited[]);  // A function used by DFS
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // function to add an edge to graph
    void DFS(int v);    // DFS traversal of the vertices reachable from v
    void BFS(int v);
    void BFSUtil(int v, bool visited[], queue<int, deque<int> >&);  // A function used by BFS
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::DFSUtil(int v, bool visited[])
{
    if(visited[v] == true)
        ;//return;
    cout <<v<< "  -  ";
    visited[v] = true;
    for(list<int>::iterator it=adj[v].begin(); it != adj[v].end(); it++)
    {
        if(visited[*it] == false){
            //visited[*it] = true;
            //cout << " -> "<< *it;
            DFSUtil(*it, visited);
        }
    }
}

// DFS traversal of the vertices reachable from v. It uses recursive DFSUtil()
void Graph::DFS(int v)
{
    if(v > V)
        cout <<"error"<<endl;
    if(v> sizeof(adj))
        cout <<"Out of bound access"<<endl;
    bool *visited = new bool[V];
    for (int i =0; i < V; i++)
        visited[i] = false;

    this->DFSUtil(v, visited);
}

void Graph::BFS(int v)
{
    if(v > V)
        cout <<"error"<<endl;
    if(v> sizeof(adj))
        cout <<"Out of bound access"<<endl;
    bool *visited = new bool[V];
    std::queue<int, deque<int> > Q;
    for (int i =0; i < V; i++)
        visited[i] = false;
    Q.push(v);
    while(!Q.empty())
    {
        int v = Q.front();
        Q.pop();
        visited[v] = true;
        cout << v<< " ";
        for(list<int>::iterator it=adj[v].begin(); it != adj[v].end(); it++)
        {
            if(visited[*it] == false)
                Q.push(*it);

        }
    }
}

void main_dfs()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Depth First Traversal (starting from vertex 2) - ";
    g.DFS(2);
    cout <<endl;

}
void main_bfs()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Breadth First Traversal (starting from vertex 2) - ";
    g.BFS(2);
    cout <<endl;

}

int main()
{
    main_bfs();
    return 0;
}
