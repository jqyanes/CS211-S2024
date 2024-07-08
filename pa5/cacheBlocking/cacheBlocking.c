#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <complex.h>
#include <stdbool.h>

/* Markers used to bound trace regions of interest */
volatile char MARKER_START, MARKER_END;

int main(int argc, char* argv[])
{

    /* Record marker addresses */
    FILE* marker_fp = fopen(".marker","w");
    assert(marker_fp);
    fprintf(marker_fp, "%llx\n%llx",
        (unsigned long long int) &MARKER_START,
        (unsigned long long int) &MARKER_END );
    fclose(marker_fp);

    if (argc!=3) {
        printf("Usage: ./matMul <matrix_a_file> <matrix_b_file>\n");
        exit(EXIT_FAILURE);
    }

    FILE* matrix_a_fp = fopen(argv[1], "r");
    if (!matrix_a_fp) {
        perror("fopen failed");
        return EXIT_FAILURE;
    }
    size_t n;
    int ret = fscanf(matrix_a_fp, "%ld\n", &n);
    assert (ret==1);
    complex* a = calloc( n*n, sizeof(complex) );
    for ( size_t i=0; i<n; i++ ) {
        for ( size_t k=0; k<n; k++ ) {
            double real, imag;
            ret = fscanf(matrix_a_fp, "(%lf%lfj) ", &real, &imag);
            assert (ret==2);
            // printf("real=%lf\n",real);
            // printf("imag=%lf\n",imag);
            a[i*n+k] = CMPLX(real, imag);
        }
        ret = fscanf(matrix_a_fp, "\n");
    }
    fclose(matrix_a_fp);

    FILE* matrix_b_fp = fopen(argv[2], "r");
    if (!matrix_b_fp) {
        perror("fopen failed");
        return EXIT_FAILURE;
    }
    size_t m;
    ret = fscanf(matrix_b_fp, "%ld\n", &m);
    assert (ret==1);
    assert( n==m );
    complex* b = calloc( n*n, sizeof(complex) );
    for ( size_t k=0; k<n; k++ ) {
        for ( size_t j=0; j<n; j++ ) {
            double real, imag;
            ret = fscanf(matrix_b_fp, "(%lf%lfj) ", &real, &imag);
            assert (ret==2);
            // printf("real=%lf\n",real);
            // printf("imag=%lf\n",imag);
            b[k*n+j] = CMPLX(real, imag);
        }
        ret = fscanf(matrix_b_fp, "\n");
    }
    fclose(matrix_b_fp);

    complex* c = calloc( n*n, sizeof(complex) );
    MARKER_START = 211;

    // jki     TEXTBOOK PAGE 673
    //for ( size_t j=0; j<n; j++ ) {
    //    for ( size_t k=0; k<n; k++ ) {
    //        complex r = b[k*n+j];
    //        for ( size_t i=0; i<n; i++ ) {
    //            c[i*n+j] += a[i*n+k] * r;
    //        }
    //    }
    //}
    
    //using kij  (progress: 9/30)
    //for ( size_t k=0; k<n; k++ ) {
    //    for ( size_t i=0; i<n; i++ ) {
    //        complex r = a[i*n+k];
    //       for ( size_t j=0; j<n; j++ ) c[i*n+j] += r * b[k*n+j];
    //    }
    //}
    
    
    //using writeup (progress: 9/30)
    //int bsize = 2;
    //if (n % 2 != 0) bsize = 1; 	//placeholder
    //for (size_t kk = 0; kk < n; kk += bsize) {
    //	for (size_t jj = 0; jj < n; jj += bsize) {
    //		for (size_t i = 0; i < n; i++) {
    //			for (size_t j = jj; j < jj + bsize; j++) {
    //				complex sum = c[i*n + j];
    //				for (size_t k = kk; k < kk + bsize; k++) {
    //					sum += a[i*n+k] * b[k*n+j];
    //				}
    //				c[i*n + j] = sum;
    //			}
    //		}
    //	}
    //}
    
    //modified writeup (dealing with fringe)
    	//REMEMBER HOW TO MULTIPLY MATRICES
    	//C[i][j] = sum of (A[i][k] * B[k][j])
    	//corresponding blocks must be compatible:
    		// # A COLS = # B ROWS     
    	//see ximera.osu.edu/oerlinalg/LinearAlgebra/MAT-0023/main
    		//and math.stackexchange.com/questions/787909/block-matrix-multiplication
    int bsize = 3; 
    bool fringe = false;
    if (n % bsize != 0) fringe = true;
    
    // n is even
    if (!fringe) {
    	if (n == bsize) {
    		for ( size_t k=0; k<n; k++ ) {
        		for ( size_t i=0; i<n; i++ ) {
            			complex r = a[i*n+k];
           			for ( size_t j=0; j<n; j++ ) c[i*n+j] += r * b[k*n+j];
        		}		
    		}
    	}
    	else {
    		for (size_t kk = 0; kk < n; kk += bsize) {
    			for (size_t jj = 0; jj < n; jj += bsize) {
    				for (size_t i = 0; i < n; i++) {
    					for (size_t j = jj; j < jj + bsize; j++) {
    						complex sum = c[i*n + j];
    						for (size_t k = kk; k < kk + bsize; k++) sum += a[i*n+k] * b[k*n+j];
    						c[i*n + j] = sum;
    					}
    				}
    			}
    		}
    	}
    }
    
    // n is odd
    else {
    	size_t kk = 0;
    	while (kk < n) {
    		int bsizeR = bsize;
    		if (kk == 0) bsizeR = n%bsize;
    		size_t jj = 0;
    		while (jj < n) {
    			int bsizeC = bsize;
    			if (jj == 0) bsizeC = n%bsize;
    			for (size_t i = 0; i < n; i++) {
    				for (size_t j = jj; j < jj + bsizeC; j++) {
    					complex sum = c[i*n + j];
    					for (size_t k = kk; k < kk + bsizeR; k++) sum += a[i*n+k] * b[k*n+j];
    					c[i*n + j] = sum;
    				}
    			}
    			jj += bsizeC;
    		}
    		kk += bsizeR;
    	}
    }
    
    		
    		
    		
    
    
    
    
    MARKER_END = 211;

    for ( size_t i=0; i<n; i++ ) {
        for ( size_t j=0; j<n; j++ ) {
            if (cimag(c[i*n+j])<0) {
                printf( "(%.12lf%.12lfj) ", creal(c[i*n+j]), cimag(c[i*n+j]) );
            } else {
                printf( "(%.12lf+%.12lfj) ", creal(c[i*n+j]), cimag(c[i*n+j]) );
            }
        }
        printf( "\n" );
    }

    free(c);
    free(b);
    free(a);
    exit(EXIT_SUCCESS);

}
