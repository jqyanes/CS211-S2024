#include "../graphutils.h" // header for functions to load and free adjacencyList
#include "../queue/queue.h" // header for queue

// A program to solve a maze that may contain cycles using BFS

int main ( int argc, char* argv[] ) {

    // First, read the query file to get the source and target nodes in the maze
    FILE* queries = fopen(argv[2], "r");
    if (!queries) {
        perror("fopen failed");
        return EXIT_FAILURE;
    }
    size_t source;
    size_t target;
    fscanf (queries, "%ld\n%ld", &source, &target);
    fclose(queries);
    /* ... */

    // READ INPUT FILE TO CREATE GRAPH ADJACENCY LIST
    AdjacencyListNode* adjacencyList = NULL;
    size_t graphNodeCount = adjMatrixToList(argv[1], &adjacencyList);
    /* ... */

    // USE A QUEUE TO PERFORM BFS
    Queue queue = { .front=NULL, .back=NULL };

    // An array that keeps track of who is the parent node of each graph node we visit
    graphNode_t* parents = calloc( graphNodeCount, sizeof(graphNode_t) );
    for (size_t i=0; i<graphNodeCount; i++) {
        parents[i] = -1; // -1 indicates that a nodes is not yet visited
    }
    parents[source] = source;

    /* ... */
    size_t current = source;
    AdjacencyListNode* dest = adjacencyList[current].next;
    while ( current != target ) {
        // so long as we haven't found the target node yet, iterate through the adjacency list
        // add each neighbor that has not been visited yet (has no parents) to the queue of nodes to visit
        while (dest) {
        	if (parents[dest->graphNode] == -1) {
        		enqueue(&queue, &(dest->graphNode));
        		parents[dest->graphNode] = current;
        	}
        	dest = dest->next;
        }
        /* ... */

        // Visit the next node at the front of the queue of nodes to visit
        current = *(graphNode_t*)dequeue(&queue);
        printf("%ld", parents[current]);
        printf(" ");
        printf("%ld", current);
        printf("\n");
        dest = adjacencyList[current].next;
        /* ... */
    }

    // Now that we've found the target graph node, use the parent array to print maze solution
    // Print the sequence of edges that takes us from the source to the target node
    /* ... */

    // free any queued graph nodes that we never visited because we already solved the maze
    while ( queue.front ) {
        /* ... */
        dequeue(&queue);
    }
    free (parents);
    freeAdjList ( graphNodeCount, adjacencyList );

    return EXIT_SUCCESS;
}
