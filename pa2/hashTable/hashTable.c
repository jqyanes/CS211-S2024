#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define RESTOCK "RESTOCK"
#define SHOW_STOCK "SHOW_STOCK"
#define SALE "SALE"

typedef struct HashNode {
	int count;
	char* album_name;
	struct HashNode* next;
} HashNode;

static HashNode** table = NULL;
static int table_fullness = 0, table_size = 4;

int hash(char* str) {
	unsigned long long hash = 0;
	int len = (int)strlen(str);
	for (int i = 0; i < len; i++)
    	hash += str[i] * pow(31, len - (i + 1));
	return hash % table_size;
}

void pretty_print_table() {
	printf("-------- FINAL COUNTS --------\n");
	for (int i = 0; i < table_size; i++) {
    	HashNode* node = table[i];
    	while (node) {
        	printf("%s: %d\n", node->album_name, node->count);
        	node = node->next;
    	}
	}
	printf("------------------------------\n");
}

void update(char* album, int k) {
	int index = hash(album);
	HashNode* current = table[index];
	while (current != NULL) {
    	if (strcmp(current->album_name, album) == 0) {
        	current->count += k;
        	return;
    	}
    	current = current->next;
	}


	HashNode* newNode = malloc(sizeof(HashNode));
	newNode->album_name = strdup(album);
	newNode->count = k;
	newNode->next = table[index];
	table[index] = newNode;
	table_fullness++;
}

int retrieve(char* album_name) {
	int index = hash(album_name);
	HashNode* node = table[index];
	while (node) {
    	if (strcmp(node->album_name, album_name) == 0)
        	return node->count;
    	node = node->next;
	}
	return -1;
}

void free_table() {
	for (int i = 0; i < table_size; i++) {
    	HashNode* node = table[i];
    	while (node) {
        	HashNode* temp = node;
        	node = node->next;
        	free(temp->album_name);
        	free(temp);
    	}
	}
	free(table);
}

void resize() {
	//kinda unneeded
}

int main(int argc, char* argv[]) {
	if (!argv[1]) {
    	fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
    	return EXIT_FAILURE;
	}

	FILE* fp = fopen(argv[1], "r");
	if (!fp) {
    	perror("fopen failed");
    	return EXIT_FAILURE;
	}

    
	table = calloc(table_size, sizeof(HashNode*));

	char command[20], album[150];
	int order;
	while (fscanf(fp, "%s %d %[^\n]s", command, &order, album) == 3) {
    	if (strcmp(command, SALE) == 0) {
        	int currentStock = retrieve(album);
        	if (currentStock == -1 || currentStock < order) {
            	printf("Not enough stock of %s\n", album);
        	} else {
            	update(album, -order);
        	}
    	} else if (strcmp(command, RESTOCK) == 0) {
        	update(album, order);
    	} else if (strcmp(command, SHOW_STOCK) == 0) {
        	int stock = retrieve(album);
        	if (stock == -1) {
            	printf("No stock of %s\n", album);
        	} else {
            	printf("Current stock of %s: %d\n", album, stock);
        	}
    	}
	}

	pretty_print_table();
	free_table();
	fclose(fp);

	return EXIT_SUCCESS;
}


