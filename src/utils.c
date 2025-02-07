#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

void printarr(int a[], int n) {
  for (int i = 0; i < n; i++) {
    printf(COLOR_BOLD "%d " COLOR_OFF, a[i]);
  }
}

void print_ascii(char *filename) {
  char read_string[MAX_LEN];
  FILE *fptr = NULL;
  if ((fptr = fopen(filename, "r")) == NULL) {
    fprintf(stderr, "error opening %s\n", filename);
  }
  while (fgets(read_string, sizeof(read_string), fptr) != NULL) {
    printf("%s", read_string);
  }
  fclose(fptr);
}

void swap(int a[], int i, int j) {
  int tmp = a[i];
  a[i] = a[j];
  a[j] = tmp;
}


void clearscreen(void) {
#ifdef _WIN32
    system("cls");
#elif defined(unix) || defined(__unix__) || defined(__unix) ||                 \
    (defined(__APPLE__) && defined(__MACH__))
    system("clear");
#else
#error "OS not supported."
#endif
}

