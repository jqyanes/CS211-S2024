#include "../graphutils.h" // header for functions to load and free adjacencyList

// A program to find the minimum spanning tree of a weighted undirected graph using Prim's algorithm

int main ( int argc, char* argv[] ) {

    // READ INPUT FILE TO CREATE GRAPH ADJACENCY LIST
    AdjacencyListNode* adjacencyList = NULL;
    size_t graphNodeCount = adjMatrixToList(argv[1], &adjacencyList);
    
    //records if a node is visited
    graphNode_t* parents = calloc( graphNodeCount, sizeof(graphNode_t) );
    for (size_t i=0; i<graphNodeCount; i++) {
        parents[i] = -1; // -1 indicates that a nodes is not yet visited
    }
    /* ... */
    parents[0] = 0;
    
    AdjacencyListNode* dest = NULL;
    for (unsigned iter = 0; iter < graphNodeCount - 1; iter++) {
    	double minWeight = DBL_MAX;
    	graphNode_t minSource = 0;
    	graphNode_t minDest = -1;
	for (size_t source = 0; source < graphNodeCount; source++) {
		if (parents[source] != -1) {
    			dest = adjacencyList[source].next;
    		}
    		while (dest) {
    			if ((parents[dest->graphNode] == -1) && (dest->weight < minWeight)) {
    				minWeight = dest->weight;
    				minDest = dest->graphNode;
    				minSource = source;
    			}
    			dest = dest->next;
    		}
    	}	
    	parents[minDest] = minSource;
    }
    /* ... */
    
    for (size_t i = 1; i < graphNodeCount; i++) {
	printf("%ld", parents[i]);
	printf(" ");
	printf("%ld", i);
	printf("\n");
    }

    free(parents);
    freeAdjList( graphNodeCount, adjacencyList );

    return EXIT_SUCCESS;
}
