#include <sys/types.h>
#include <sys/stat.h>
#include<unistd.h> 
#include <dirent.h>
#include <stdio.h>

int main(){

    /*Creacion de directorios*/
    mkdir("Edicion1",0755);
    mkdir("Edicion1/Normales",0755);
    mkdir("Edicion1/Magicas",0755);
    mkdir("Edicion1/Raras",0755);
    mkdir("Edicion2",0755);
    mkdir("Edicion2/Normales",0755);
    mkdir("Edicion2/Magicas",0755);
    mkdir("Edicion2/Raras",0755);
    mkdir("Edicion3",0755);
    mkdir("Edicion3/Normales",0755);
    mkdir("Edicion3/Magicas",0755);
    mkdir("Edicion3/Raras",0755);
    mkdir("Edicion4",0755);
    mkdir("Edicion4/Normales",0755);
    mkdir("Edicion4/Magicas",0755);
    mkdir("Edicion4/Raras",0755);
    mkdir("Edicion5",0755);
    mkdir("Edicion5/Normales",0755);
    mkdir("Edicion5/Magicas",0755);
    mkdir("Edicion5/Raras",0755);


    DIR *dp;
    struct dirent *de;
    dp = opendir("./");

    while ((de = readdir(dp)) != NULL) {
        printf("%s\n", de->d_name);
        chdir(de->d_name);

    }
    
  
    closedir(dp);  

    return 0;
}