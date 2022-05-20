#include <stdio.h>

int main(void) {
  int L, sum = 0;

  printf("Define the amount of numbers in the sequence: ");
  scanf("%i", &L);

  for (int i=1; i<=L; i++) {
    if (i == 1) {
        sum += i-1;
        printf("%i\n", sum);
        sum += i;
        printf("%i\n", sum);
    } else {
        sum += i-1;
        printf("%i\n")
    }
  }
}