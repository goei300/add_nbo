#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <stdio.h>
#include <cstdint>
#define MAX_LENGTH 33

using namespace std;
int main(int argc, char* argv[]) {

    if(argc != 3){
        printf("We need 2 arguments\n");
        return 0;
    }

    uint32_t a1,a2;
    uint32_t tmp;
    FILE* f=fopen(argv[1], "rb");
    FILE* f2=fopen(argv[2],"rb");
    if (f == nullptr||f2==nullptr) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    int cnt=4;
    a1=0x0;
    while((tmp=fgetc(f))!=unsigned(EOF)){
        for(int i=1;i<cnt;i++){
            tmp =tmp <<8;
        }
        a1 += tmp;
        cnt--;
    }
    cnt=4;
    a2=0x0;
    while((tmp=fgetc(f2))!=unsigned(EOF)){
        for(int i=1;i<cnt;i++){
            tmp =tmp <<8;
        }
        a2 += tmp;
        cnt--;
    }
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",a1,a1,a2,a2,a1+a2,a1+a2);
    
    fclose(f);
    fclose(f2);
    return 0;

}
