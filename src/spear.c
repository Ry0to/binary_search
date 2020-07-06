#include <stdio.h>

int n;
int k;
int A[100000];

int p(int A[], int x ,int k, int n){
  int i;
  int sum = 0;
  for(i = 0; i < n; i++){
    sum += A[i] / x;
  }
  return sum >= k;
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
    if(p(A, mid, k, n)) lb = mid;
    else ub = mid;
  }

  printf ("%d\n" , lb);


  return 0;
}
