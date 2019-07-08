#include<iostream>
#include<bits/stdc++.h>

using namespace std;


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
        int vertices;
        printf("Enter the no of vertices :");
        cin>>vertices;

        int edge;
        printf("Enter the no of edge :");
        cin>>edge;

        list <int> lists[vertices];


        for(int i=0;i<edge;i++)
        {
                int v1,v2;
                printf("Enter the two vertces of edge");
                cin>>v1>>v2;


                add_edge(lists,v1,v2);
        }


        display(lists,vertices);
}
