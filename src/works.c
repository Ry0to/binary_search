#include <stdio.h>

int n;
int k;
int A[100000];

int p(int A[], int x ,int k, int n){
  int i;
  int member = 0;
  int sum = 0;
  for(i = 0; i < n; i++){
    sum += A[i];
    if (sum > x) {
      sum = A[i];
      member++;
    }
  }
  return member + 1 <= k && sum <= x;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = 1e9;
  while (ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(A, mid, k, n)) ub = mid;
    else lb = mid;
  }

  printf ("%d\n" , ub);
  return 0;
}
