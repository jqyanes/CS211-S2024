#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int min ( int x, int y ) {
    return x<y ? x : y;
}

int main(int argc, char* argv[])
{

    FILE* inputFile = fopen(argv[1], "r");
    if (!inputFile) {
        perror("fopen failed");
        return EXIT_FAILURE;
    }
    char source[32];
    char target[32];
    fscanf (inputFile, "%s\n%s", source, target);

    
    if (strlen(source)==0) return strlen(target);
    else if (strlen(target)==0) return strlen(source);
    
    int mat[strlen(source) + 1][strlen(target) + 1];
    //fill out first row and column first
    for (int fi = 0; fi < (strlen(source) + 1); fi++) mat[fi][0] = fi;
    for (int fj = 0; fj < (strlen(target) + 1); fj++) mat[0][fj] = fj;
    //now fill out rest of matrix
    for (int i = 1; i < (strlen(source) + 1); i++) {
    	for (int j = 1; j < (strlen(target) + 1); j++) {
    		if (source[i-1] == target[j-1]) mat[i][j] = mat[i - 1][j - 1];
    		else mat[i][j] = min(min(mat[i - 1][j], mat[i][j - 1]), mat[i - 1][j - 1]) + 1;
    	}
    }	
    
    
    printf("%d", mat[strlen(source)][strlen(target)]);
    
    return EXIT_SUCCESS;

}
