#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    int quickbeats = 256;

    //DEV RANDOM
    unsigned int nrandom[quickbeats];
    int ran = open("/dev/random",O_RDONLY);
    read(ran,nrandom,quickbeats);
    close(ran);
    
    printf("RANDOM\n");
    for (size_t i = 0; i < quickbeats; i++)
        printf("%02X",nrandom[i]);

    //DEV URANDOM
    unsigned int urandom[quickbeats];
    ran = open("/dev/urandom",O_RDONLY);
    read(ran,urandom,quickbeats);
    close(ran);

    printf("\n\nURANDOM\n");
    for (size_t i = 0; i < quickbeats; i++)
        printf("%02X",urandom[i]);
    
    return 0;
}