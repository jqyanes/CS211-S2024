#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

// Author: Pedro Torres

size_t anyToInteger(char* source, int base, int digitCount) {
    // Implement logic to convert the source string to integer representation
    // Remember to return the integer value
    size_t repr = 0;
    char* alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    size_t power = 0;
    for (int i = 0; i < digitCount; i++) {
    	if (isdigit(source[i])) {
    		if (source[i] == '0') continue;
    		power = base;
    		for (int j = 1; j < (digitCount - (i + 1)); j++) power = power*base;
    		if ((digitCount - (i + 1)) == 0) power = 1;
    		repr = repr + (size_t)(power * (source[i] - '0'));
    	}
    	else {
    		char *letter = strchr(alphabet, source[i]);
    		int aztoi = letter - alphabet;
		power = base;
    		for (int j = 1; j < (digitCount - (i + 1)); j++) power = power*base;
    		if ((digitCount - (i + 1)) == 0) power = 1;
    		repr = repr + (size_t)(power * (aztoi + 10));
    	}
    }
    /* ... */
    return repr;
}

void integerToAny(char* result, size_t repr, int base, char* reversed) {
    // Implement the logic to convert the represented value to any base
    // Store this value as a string in the 'result' array
    char* alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int index = 0;
    int mod = 0;
    size_t storage = repr;
    while (storage >= base) {
    	mod = storage % base;
    	storage = storage/base;
    	if (mod < 10) reversed[index] = mod + '0';
    	else {
    	reversed[index] = alphabet[mod - 10];
    	}
    	index++;
    }
    mod = storage % base;
    if (mod < 10) reversed[index] = mod + '0';
    else {
    	reversed[index] = alphabet[mod - 10];
    }
    /* ... */
    for (int i = 0; i < strlen(reversed); i++) {
    	result[i] = reversed[strlen(reversed) - (i + 1)];
    }	
    return;
}

int main(int argc, char* argv[]) {
    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        perror("fopen failed");
        return EXIT_FAILURE;
    }

    int digitCount;
    int sourceBase;
    int destBase;

    if (!fscanf(fp, "%d\n", &digitCount)) {
      perror("reading the input digit count failed");
      exit(EXIT_FAILURE);
    }

    if (!fscanf(fp, "%d\n", &sourceBase)) {
      perror("reading the source base failed");
      exit(EXIT_FAILURE);
    }

    if (!fscanf(fp, "%d\n", &destBase)) {
      perror("reading the destination base failed");
      exit(EXIT_FAILURE);
    }

    char* sourceNum = calloc(sizeof(char), digitCount+1);

    if (!fscanf(fp, "%s\n", sourceNum)) {
      perror("reading the source number");
      exit(EXIT_FAILURE);
    }

    size_t repr;

    repr = anyToInteger(sourceNum, sourceBase, digitCount);

    // Size 65 accounts for the largest digit result (64 bit binary) + 1 null operator
    char* result = (char*)calloc(sizeof(char), 65);
    char* reversed = (char*)calloc(sizeof(char), 65);
    integerToAny(result, repr, destBase, reversed);

    // Print string
    printf("%s", result);
    /* ... */

    free(sourceNum);
    free(result);
    free(reversed);
    return EXIT_SUCCESS;
}
