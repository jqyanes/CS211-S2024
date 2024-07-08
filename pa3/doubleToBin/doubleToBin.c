#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <float.h>

#define EXP_SZ 11
#define FRAC_SZ 52

int main(int argc, char *argv[]) {

    // SETUP

    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        perror("fopen failed");
        return 0;
    }

    // first, read the number
    double value;
    fscanf(fp, "%lf", &value);

    // the reference solution ('the easy way')
    // you are not allowed to print from this casted 'ref_bits' variable below
    // but, it is helpful for validating your solution
    unsigned long int ref_bits = *(unsigned long int*) &value;

    // THE SIGN BIT
    bool sign = value<0.0;
    double testsign = 10 / value;
    if (testsign < -DBL_MAX) sign = 1;
    printf("%d_",sign);
    assert (sign == (1&ref_bits>>(EXP_SZ+FRAC_SZ))); // validate your result against the reference

    // THE EXP FIELD (smaller section, E = 2^(expfield - 1023)
    // find the exponent E such that the fraction will be a canonical fraction:
    // 1.0 <= fraction < 2.0
    double fraction = sign ? -value : value;
  

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
    /* ... */

    // you get partial credit by getting the exp field correct
    // even if you print zeros for the frac field next
    // you should be able to pass test cases 0, 1, 2, 3

    // THE FRAC FIELD (larger section, M = fracfield OR (fracfield + 1)
    // prepare the canonical fraction such that:
    // 1.0 <= fraction < 2.0
    
    /* ... */

    bool frac_array[FRAC_SZ+1]; // one extra LSB bit for rounding
    for ( int frac_index=FRAC_SZ; 0<=frac_index; frac_index-- ) {
        frac_array[frac_index] = false; // frac set to zero to enable partial credit
    }
    
    double m = 1;
    if (fraction < DBL_MIN) m = 0;
    if ((ldexp(1, exp) != fraction) && ((fraction != 0.0) || (fraction != -0.0))) {
    	int test = 0;
    	double step = 1;
    	while (ldexp(m, exp) != fraction) {
    		if (ldexp(m, exp) < fraction) { //m too small
    			test = test + 1;
    			if (test == FRAC_SZ + 1) break;
    			step = step*0.5;
    			m = m + step;
    			frac_array[(FRAC_SZ - test + 1)] = true;
    		}
    		else { //m too large
    		    	if (test == FRAC_SZ) break;
    			m = m - step;
    			frac_array[(FRAC_SZ - test + 1)] = false;
    			test = test + 1;
    			step = step*0.5;
    			m = m + step;
    			frac_array[(FRAC_SZ - test + 1)] = true;
    		}
    	}
    }
    


    // rounding
    /* ... */

    for ( int exp_index=EXP_SZ-1; 0<=exp_index; exp_index-- ) {
        bool exp_bit = 1&trial_exp>>exp_index;
        printf("%d",exp_bit);

    }
    printf("_");
    
    for ( int frac_index=FRAC_SZ-1; 0<=frac_index; frac_index-- ) {
        bool frac_bit = frac_array[frac_index+1]; // skipping the extra LSB bit for rounding
        printf("%d", frac_bit);
    }

}
