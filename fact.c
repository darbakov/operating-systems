#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "fun.h"

size_t n = 6;

void run_fact() {
  size_t res = fact(n);
  printf("Fact of %ld is %ld  subprocess \n", n, res);
}


int main(){

  printf("Run!\n");
  size_t cpid;
  
  if ((cpid = fork()) == 0) {
    run_fact();
  } else {

    size_t res = fact(n);
    printf("Fact of %ld is %ld.\n", n, res);
  }
  if (cpid!=0) {
    int rc;
    waitpid(cpid, &rc, 0);
    printf("A Child process killed.\n");
  }
  return 0;
}
