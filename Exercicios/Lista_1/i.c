#include <stdio.h>

int main(){

  int n;
  scanf("%d", &n);

  int vet[n];
  long sum = 0;
  for(int i = 0; i < n; i++){
    scanf("%d", &vet[i]);
    sum += vet[i];
  }

  long mean = sum / n;
  int flag = 0;

  for(int i = 0; i < n; i++){
    if(vet[i] > mean){
      if(flag){
        printf(" ");
      }
      printf("%d", vet[i]);
      flag = 1;
    }
  }

  if(flag == 0){
    printf("0\n");
  }  

  return 0;
}