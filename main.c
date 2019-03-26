#include <sys/types.h>
#include <sys/stat.h>
#include<unistd.h> 
#include <dirent.h>
#include <stdio.h>

int main(){

    /*Creacion de directorios*/
    mkdir("Edicion1",S_IRUSR | S_IWUSR);
    mkdir("Edicion2", S_IRUSR | S_IWUSR);
    mkdir("Edicion3", S_IRUSR | S_IWUSR);
    mkdir("Edicion4", S_IRUSR | S_IWUSR);
    mkdir("Edicion5", S_IRUSR | S_IWUSR);
    return 0;
}