#include "../graphutils.h" 

bool hasCyc(int currentNode, bool visited[], bool currentPath[], int parents[], AdjacencyListNode* adjacencyList, int* start, int* end) {
    visited[currentNode] = true;
    currentPath[currentNode] = true;

    for (AdjacencyListNode* adj = adjacencyList[currentNode].next; adj != NULL; adj = adj->next) {
        int nextNode = adj->graphNode;
        if (!visited[nextNode]) {
            parents[nextNode] = currentNode;
            if (hasCyc(nextNode, visited, currentPath, parents, adjacencyList, start, end)) {
                return true;
            }
        } else if (currentPath[nextNode]) {
            *end = currentNode;
            *start = nextNode;
            return true;
        }
    }

    currentPath[currentNode] = false;
    return false;
}

void printCyc(int start, int end, int parents[]) {
    if (start == -1) {
        printf("DAG\n");
    } else {
        int current = end;
        // Use a temporary buffer if necessary to reverse the order of printing
        int nodes[1000]; // Assuming the cycle will not contain more than 1000 nodes
        int idx = 0;
        while (true) {
            nodes[idx++] = current;
            if (current == start) {
                break;
            }
            current = parents[current];
        }
        
        for (int i = idx - 1; i >= 0; --i) {
            printf("%d ", nodes[i]);
        }
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    AdjacencyListNode* adjacencyList;
    size_t graphNodeCount = adjMatrixToList(argv[1], &adjacencyList);

    bool* visited = calloc(graphNodeCount, sizeof(bool));
    bool* currentPath = calloc(graphNodeCount, sizeof(bool));
    int* parents = calloc(graphNodeCount, sizeof(int));
    for (size_t i = 0; i < graphNodeCount; i++) {
        parents[i] = -1;
    }

    int start = -1, end = -1;
    for (size_t i = 0; i < graphNodeCount && start == -1; i++) {
        if (!visited[i] && hasCyc(i, visited, currentPath, parents, adjacencyList, &start, &end)) {
            break;
        }
    }

    printCyc(start, end, parents);

    free(visited);
    free(currentPath);
    free(parents);
    freeAdjList(graphNodeCount, adjacencyList);

    return EXIT_SUCCESS;
}



