#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define EXP_SZ 8
#define FRAC_SZ 23

int main(int argc, char *argv[]) {

    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        perror("fopen failed");
        return EXIT_FAILURE;
    }

    // SETUP

    // first, read the binary number representation of float point number
    char buff;
    bool sign;
    buff = fgetc(fp);
    
    if (buff == '1') sign = 1;
    else sign = 0;
    bool efield[EXP_SZ];
    bool mfield[FRAC_SZ];
    for (int i = 0; i < EXP_SZ; i++) { // read MSB first as that is what comes first in the file
    	buff = fgetc(fp);
    	efield[i] = buff - '0';
    }
    for (int i = 0; i < FRAC_SZ; i++) {
    	buff = fgetc(fp);
    	mfield[i] = buff - '0';
    }

    // E
    int e = -127;
    int power = 0;
    for (int i = 0; i < EXP_SZ; i++) {
    	if (efield[i] == 0) continue;
    	int base = 1;
    	power = EXP_SZ - (i + 1);
    	for (int j = 0; j < power; j++) base = base*2;
    	e = e + base;
    }
    /* ... */

    // M
    float m = 0;
    for (int i = 0; i < FRAC_SZ; i++) {
    	if (mfield[i] == 0) continue;
    	float mbase = 0.5;
    	for (int j = 0; j < i; j++) mbase = mbase*0.5;
    	m = m + mbase;
    }
    
    if (e == -127) e = -126;
    else m = m + 1;
    /* ... */

    // https://www.tutorialspoint.com/c_standard_library/c_function_ldexp.htm
    double number = ldexp ( m, e );
    if ((m == 1) && (e == -127)) number = 0;
    number = sign ? -number : number;
    printf("%e", number);

    return EXIT_SUCCESS;

}
