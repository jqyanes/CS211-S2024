#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
// https://www.tutorialspoint.com/c_standard_library/limits_h.htm
#include <limits.h>
#include <string.h>

int main(int argc, char *argv[]) {

    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        perror("fopen failed");
        return EXIT_FAILURE;
    }

    // SETUP

    // first, read the minuend (number to be subtracted from)
    char buff;
    bool minuend[CHAR_BIT]; // suggested that you store bits as array of bools; minuend[0] is the LSB
    for (int i=CHAR_BIT-1; 0<=i; i--) { // read MSB first as that is what comes first in the file
    	buff = fgetc(fp);
    	if (buff == '0') minuend[i] = 0;
    	else minuend[i] = 1;
        /* ... */
    }

    // notice that you are reading two different lines; caution with reading
    /* ... */

    // second, read the subtrahend (number to subtract)
    buff = fgetc(fp);
    bool subtrahend[CHAR_BIT]; // suggested that you store bits as array of bools; subtrahend[0] is the LSB
    for (int i=CHAR_BIT-1; 0<=i; i--) { // read MSB first as that is what comes first in the file
    	buff = fgetc(fp);
    	if (buff == '0') subtrahend[i] = 0;
    	else subtrahend[i] = 1;
        /* ... */
    }

    // WE WILL DO SUBTRACTION BY NEGATING THE SUBTRAHEND AND ADD THAT TO THE MINUEND

    // Negate the subtrahend
    // flip all bits
    for (int i=CHAR_BIT-1; 0<=i; i--) { // read MSB first as that is what comes first in the file
    	if (subtrahend[i] == 1) subtrahend[i] = 0;
    	else subtrahend[i] = 1;
    }
    /* ... */

    // add one
    //bool carry = true; // to implement the 'add one' logic, we do binary addition logic with carry set to true at the beginning
    for (int i=0; i<CHAR_BIT; i++) { // iterate from LSB to MSB
    	if (subtrahend[i] == 0) {
    		subtrahend[i] = 1;
		break;
	}
	else subtrahend[i] = 0;
    }

    // Add the minuend and the negated subtrahend
    bool difference[CHAR_BIT];
    bool carry = false;
    for (int i=0; i<CHAR_BIT; i++) {
    	if ((subtrahend[i] == 0)  && minuend[i] == 0) {
    		if (carry == false) {
    			difference[i] = 0;
    			continue;
    		}
    		difference[i] = 1;
    		carry = false;
    		continue;
    	}
    	else if ((subtrahend[i] == 1) && (minuend[i] == 1)) {
    		if (carry == false) {
    			difference[i] = 0;
    			carry = true;
    			continue;
    		}
    		difference[i] = 1;
    		//carry is still true
    		continue;
    	}
    	else {
    		if (carry == false) {
    			difference[i] = 1;
    			continue;
    		}
    		difference[i] = 0;
    		//carry is still true
    		continue;
    	}
    }
    /* ... */

    // print the difference bit string
    for (int i=CHAR_BIT-1; 0<=i; i--) {
        printf("%d",difference[i]);
    }

    return EXIT_SUCCESS;

}
