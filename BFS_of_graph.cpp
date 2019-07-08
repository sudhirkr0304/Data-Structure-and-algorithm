#include<iostream>
#include<bits/stdc++.h>

using namespace std;

/*
This is the main Depth search function 
If the vertex is visited then  leave it
If the vertex is not visited then first mark 
it visited and then go to the adjacent node of
that node , if you find out any node that is not visited then 
start the DFS of that vertex.
*/
void BFS ( list <int> lists[] , int vertex , int visited[])
{

        if(visited[vertex]==0)
        {
            visited[vertex]=1;
            queue <int> q;
            q.push(vertex);
            
            while(!q.empty())
            {
                cout<<q.front()<<" ";
                int val=q.front();
                q.pop();
                
                for(auto it=lists[val].begin(); it != lists[val].end();it++)
                {
                    if(visited[*it]==0)
                    {
                        visited[*it]=1;
                        q.push(*it);
                    }
                }
            }
            
        }


}
/*
  initialize temporary array for visited node
  start the loop for the DFS function
*/
void BFS_visited(list<int> lists[] , int vertices)
{

        int visited[vertices]={0};
        for(int i=0;i<vertices;i++)
        {

                BFS(lists,i,visited);
        }
}

/* This is a function to display Graph */
void display(list <int> lists[],int vertices)
{

        for(int i=0;i<vertices;i++)
        {
              cout<<i<<"-->";
              for(list<int> :: iterator j=lists[i].begin();j != lists[i].end();j++)
              {
                      cout<<*j<<" ";

              }
              cout<<endl;

        }
}
void add_edge(list<int> lists[] , int v1 , int v2)
{

        lists[v1].push_back(v2);
        lists[v2].push_back(v1);
}

int main()
{
        /* to input the number of vertex in graph */
        int vertices;
        printf("Enter the no of vertex :");
        cin>>vertices;

        /* to input the number of edge in graph */
        int edge;
        printf("Enter the no of edge :");
        cin>>edge;

        /* this is the list in which all the vertex are kept and
        then all the edge is added to the list */
        list <int> lists[vertices];



        for(int i=0;i<edge;i++)  //lop for no of edge
        {
                int v1,v2;
                printf("Enter the two vertex of edge");
                cin>>v1>>v2;


                add_edge(lists,v1,v2); //this will add the edge
        }


        display(lists,vertices);  /*Function to display  adjacency list Repersentation of graph */
        cout<<endl;

        BFS_visited(lists,vertices);  /* DFS function for printing DFS*/

}
