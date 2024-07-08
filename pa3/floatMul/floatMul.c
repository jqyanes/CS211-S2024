#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
// https://www.tutorialspoint.com/c_standard_library/limits_h.htm
#include <limits.h>
// https://www.cplusplus.com/reference/cfloat/
#include <float.h>

#define FLOAT_SZ sizeof(float)*CHAR_BIT
#define EXP_SZ (FLOAT_SZ-FLT_MANT_DIG)
#define FRAC_SZ (FLT_MANT_DIG-1)

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
    bool sign2;
    buff = fgetc(fp);
    
    //NUMBER 1
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
    
    //NUMBER 2
    buff = fgetc(fp);
    buff = fgetc(fp);
    if (buff == '1') sign2 = 1;
    else sign2 = 0;
    bool efield2[EXP_SZ];
    bool mfield2[FRAC_SZ];
    for (int i = 0; i < EXP_SZ; i++) { // read MSB first as that is what comes first in the file
    	buff = fgetc(fp);
    	efield2[i] = buff - '0';
    }
    for (int i = 0; i < FRAC_SZ; i++) {
    	buff = fgetc(fp);
    	mfield2[i] = buff - '0';
    }

    // E
    
    //NUMBER 1
    int e = -127;
    int power = 0;
    for (int i = 0; i < EXP_SZ; i++) {
    	if (efield[i] == 0) continue;
    	int base = 1;
    	power = EXP_SZ - (i + 1);
    	for (int j = 0; j < power; j++) base = base*2;
    	e = e + base;
    }
    
    //NUMBER 2
    /* ... */
    int e2 = -127;
    int power2 = 0;
    for (int i = 0; i < EXP_SZ; i++) {
    	if (efield2[i] == 0) continue;
    	int base2 = 1;
    	power2 = EXP_SZ - (i + 1);
    	for (int j = 0; j < power2; j++) base2 = base2*2;
    	e2 = e2 + base2;
    }
    
    // M
    
    //NUMBER 1
    float m = 0;
    for (int i = 0; i < FRAC_SZ; i++) {
    	if (mfield[i] == 0) continue;
    	float mbase = 0.5;
    	for (int j = 0; j < i; j++) mbase = mbase*0.5;
    	m = m + mbase;
    }
    
    //NUMBER 2
    float m2 = 0;
    for (int i = 0; i < FRAC_SZ; i++) {
    	if (mfield2[i] == 0) continue;
    	float mbase2 = 0.5;
    	for (int j = 0; j < i; j++) mbase2 = mbase2*0.5;
    	m2 = m2 + mbase2;
    }
    
    if (e == -127) e = -126;
    else m = m + 1;
    if (e2 == -127) e2 = -126;
    else m2 = m2 + 1;
    /* ... */

    // https://www.tutorialspoint.com/c_standard_library/c_function_ldexp.htm
    double number = ldexp ( m, e );
    if ((m == 1) && (e == -127)) number = 0;
    number = sign ? -number : number;

    double number2 = ldexp ( m2, e2 );
    if ((m2 == 1) && (e2 == -127)) number = 0;
    number2 = sign2 ? -number2 : number2;

    
    
    
    //PART 2 START
    
    float value = (float)(number * number2);
    // THE SIGN BIT
    bool valsign = value<0.0;
    double testsign = 10 / value;
    if (testsign < -DBL_MAX) valsign = 1;
    printf("%d_",valsign);
    
    // THE EXP FIELD (smaller section, E = 2^(expfield - 1023)
    // find the exponent E such that the fraction will be a canonical fraction:
    // 1.0 <= fraction < 2.0
    double fraction = valsign ? -value : value;
  

    signed short trial_exp = 2046; // start by assuming largest possible exp (before infinity)
    signed short trial_max = 2046;
    signed short trial_min = 1;
    
    unsigned short bias = (1<<(EXP_SZ-1))-1; // = 1023
    signed short exp = trial_exp - bias;
    double target_min = ldexp(1, exp);
    double target_max = ldexp(2, exp);
    // do trial division until the proper exponent E is found (assume that m is normalized and so 1 < m < 2)
    if (fraction < DBL_MIN) {
    	trial_exp = 0;
    	exp = (trial_exp - bias) + 1;
    }
    else {
    	while ((fraction < target_min) || (fraction >= target_max)) {
    		if (fraction < target_min) { // trial_exp too large
    			trial_max = trial_exp;
    			trial_exp = (trial_max + trial_min) / 2;
    			exp = trial_exp - bias;
    			target_min = ldexp(1, exp);
    			target_max = ldexp(2, exp);
    		}
    		else { // trial_exp too small
    		    	trial_min = trial_exp;
    		    	trial_exp = (trial_max + trial_min) / 2;
    		    	exp = trial_exp - bias;
    			target_min = ldexp(1, exp);
    			target_max = ldexp(2, exp);
    		}
    	}
    }
    
    for ( int exp_index=EXP_SZ-1; 0<=exp_index; exp_index-- ) {
        bool exp_bit = 1&trial_exp>>exp_index;
        printf("%d",exp_bit);

    }
    printf("_");
    
    // THE FRAC FIELD (larger section, M = fracfield OR (fracfield + 1)
    // prepare the canonical fraction such that:
    // 1.0 <= fraction < 2.0
    
    /* ... */

    bool frac_array[FRAC_SZ+1]; // one extra LSB bit for rounding
    for ( int frac_index=FRAC_SZ; 0<=frac_index; frac_index-- ) {
        frac_array[frac_index] = false; // frac set to zero to enable partial credit
    }
    
    double valm = 1;
    if (fraction < DBL_MIN) m = 0;
    if ((ldexp(1, exp) != fraction) && ((fraction != 0.0) || (fraction != -0.0))) {
    	int test = 0;
    	double step = 1;
    	while (ldexp(valm, exp) != fraction) {
    		if (ldexp(valm, exp) < fraction) { //m too small
    			test = test + 1;
    			if (test == FRAC_SZ + 1) break;
    			step = step*0.5;
    			valm = valm + step;
    			frac_array[(FRAC_SZ - test + 1)] = true;
    		}
    		else { //m too large
    		    	if (test == FRAC_SZ) break;
    			valm = valm - step;
    			frac_array[(FRAC_SZ - test + 1)] = false;
    			test = test + 1;
    			step = step*0.5;
    			valm = valm + step;
    			frac_array[(FRAC_SZ - test + 1)] = true;
    		}
    	}
    }
    
    for ( int frac_index=FRAC_SZ-1; 0<=frac_index; frac_index-- ) {
        bool frac_bit = frac_array[frac_index+1]; // skipping the extra LSB bit for rounding
        printf("%d", frac_bit);
    }
    	
    /* ... */

    return(EXIT_SUCCESS);

}
