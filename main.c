#include <sys/types.h>
#include <sys/stat.h>
#include<unistd.h> 
#include <dirent.h>
#include <string.h>
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

    /* Mover las cartas */

    
    char dummy[6] = "Carta";
    char test[6];

    DIR *dp;
    struct dirent *de;
    dp = opendir("./Cartas");

    while ((de = readdir(dp)) != NULL) {
        /*printf("%s\n", de->d_name);*/

        strncpy(test,de->d_name,5);

        printf("%s\n",test);

        if (strcmp(dummy,test)== 0) printf("ecnontre carta\n");
       

    }
    
  
    closedir(dp);  

    return 0;
}