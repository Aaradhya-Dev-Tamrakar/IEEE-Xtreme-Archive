#include <cstdio>

int index(int value, int N) {
  if (N == 1) {
    return 1;
  } else if (value % 2 == 1)
    return (N / 2) + index(value / 2 + 1, (N / 2) + (N % 2));
  else
    return index(value / 2, N / 2);
}

int main(void) {
  int N, M;
  scanf("%d%d", &N, &M);
  int val;
  scanf("%d", &val);
  bool ok = true;
  int j = index(val, N);
  //printf("%d ", j);
  for (int i = 1; i < M; i++) {
    scanf("%d", &val);
    j++;
    if (index(val, N) != j) {
      ok = false;
    }
    //printf("%d ", index(val, N));
  }
  //printf("\n");
  if (ok) {
    printf("1\n");
  } else {
    printf("0\n");
  }
  return 0;
}
