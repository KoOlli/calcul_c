#include <stdio.h>

int main() {
  int res = 2;
  int N;
  scanf("%d", &N);
  int P = 1;
  int kol_vo_prost = 0;
  while (P <= N) {
    // algoritm nahozhdeniya (P)rostoe-chisla
    for (int i = 1; i <= P; i++) {
      int ost_del = 0;
      ost_del = P % i;
      if ((i == 1 || i == N) && ost_del == 0) {
        res = 0;
        kol_vo_prost += 1;
      } else {
        res = 1;
      }
      printf("otvet_programs = %d  ; ost_del - %d\n", res, ost_del);
    }
    P++;
    printf("kol_va_prost = %d\n", kol_vo_prost);
  }
  printf("\n\nkol_va_prost = %d\n", kol_vo_prost);
  return res;
}