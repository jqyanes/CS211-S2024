#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

bool is_prime(int n){

  if (n<2)
    return false;

  for (int i=2; i<=sqrt(n); i++)
    if ((n%i)==0)
      return false;

  return true;
}

int main(int argc, char* argv[]) {

  // Open the filename given as the first command line argument for reading
  FILE* fp = fopen(argv[1], "r");
  if (!fp) {
    perror("fopen failed");
    return EXIT_FAILURE;
  }

  char buf[256];

  char* string = fgets(buf, 256, fp);
  long x = strtol(string, NULL, 10);
  int p = 0;
  long test = 0;
  while (test < x) {
  p = p + 1;
  test = pow(2, p - 1) * (pow(2, p) - 1);
  }
  if ((test == x) && (is_prime(p))) {
    // Printing in C.
    // %d is the format specifier for integer numbers.
    // \n is the newline character
    printf( "%d \n", (int) (pow(2,p) - 1));
  } else {
    printf("-1\n");
  }
  return 0;
}
