#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct for edge in graph 
struct edge
{
	int src,dest;
};

//structure for the connected graph 
struct graph
{
	// number of vertices and edges
	int v,e;
	//graph is an array of edges 
	struct edge * edge;
};
//function to create graph with v vertices and e edges 
struct graph * createGraph(int v,int e)
{
	struct graph* graph = (struct graph*) malloc( sizeof(struct graph) );
	graph->v = v;
	graph->e = e;
	graph->edge = (struct edge *) malloc(graph->e *sizeof(struct edge));
	return graph;
}
//finds subset of element i
int find(int parent[],int i)
{
	if(parent[i] == -1)
		return i;
	return find(parent,parent[i]);
}
void Union(int parent[],int x,int y)
{
	int xset = find(parent,x);
	int yset = find(parent,y);
	parent[xset] = yset;
}

int iscycle(struct graph * graph)
{
	int * parent = (int*) malloc(graph->v * sizeof(int));
	//initialisation of parent
	// no idea lol
	memset(parent, -1, sizeof(int) * graph->v);
	for(int i = 0; i < graph->e; ++i)
    {
        int x = find(parent, graph->edge[i].src);
        int y = find(parent, graph->edge[i].dest);
 
        if (x == y)
            return 1;
 
        Union(parent, x, y);
    }
    return 0;
}

int main(int argc, char const *argv[])
{
	/* Let us create following graph
         0
        |  \
        |    \
        1-----2 
        */
    int V = 3, E = 3;
    struct graph* graph = createGraph(V, E);
 
    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
 
    // add edge 1-2
    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;
 
    // add edge 0-2
    graph->edge[2].src = 0;
    graph->edge[2].dest = 2;
 
    if (iscycle(graph))
        printf( "graph contains cycle" );
    else
        printf( "graph doesn't contain cycle" );
 	

 	/* Let us create following graph
 	0--1--2--3
         
    int V = 4, E = 3;
    struct graph* graph = createGraph(V, E);
 
    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
 
    // add edge 1-2
    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;

    // add edge 2-3
    graph->edge[2].src = 2;
    graph->edge[2].dest = 3;
 
    if (iscycle(graph))
        printf( "graph contains cycle" );
    else
        printf( "graph doesn't contain cycle" );*/
 
	return 0;
}