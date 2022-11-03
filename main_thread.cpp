//clang++ main_thread.cpp -fsanitize=thread

#include <pthread.h>
#include <stdio.h>

int Global;

void *Thread_interval(void *x){
  for(int i =0 ; i< 10;++i) printf(".");
  return NULL;
}
void *Thread1(void *x) {
  Global++;
  return NULL;
}

void *Thread2(void *x) {
  Thread_interval(x);
  Global--;
  printf(" %i \n", Global);
  return NULL;
}

int main() {
  pthread_t t[2];
  pthread_create(&t[0], NULL, Thread1, NULL);
  pthread_create(&t[1], NULL, Thread2, NULL);
  pthread_join(t[0], NULL);
  pthread_join(t[1], NULL);
}