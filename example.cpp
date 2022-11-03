#include <iostream>

int main(int argc, char **argv){
    int *p, value;
   if (argc < 1)
       return 0;
   char msg[16] = "example";
   int pos = atoi(argv[1]);
   msg[pos]= 0 ;
   std::cout << msg << std::endl;
   return 0 ;
}
