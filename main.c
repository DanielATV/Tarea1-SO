#include <sys/types.h>
#include <sys/stat.h>
#include<unistd.h> 
#include <dirent.h>
#include <string.h>
#include <stdio.h>

struct carta{
    char nom[20];
    char tipo[20];
    char ed[20];
    char num[20];

};

int main(){
    int i;

    struct carta collection[20];
    struct carta joker;

    FILE *fp;
    char line[20];

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
    dp = opendir("./");

    while ((de = readdir(dp)) != NULL) {
        /*printf("%s\n", de->d_name);*/

        strncpy(test,de->d_name,5);

        if (strcmp(dummy,test)== 0){
            printf("ecnontre carta %s\n",de->d_name);
            fp = fopen(de->d_name,"r");
            for (i =0; i<4; i++){
                
                fgets(line,20,fp);
                if (i== 0) strcpy(joker.nom ,line);
                else if (i == 1) strcpy(joker.tipo ,line);
                else if (i == 2) strcpy(joker.ed,line);
                else strcpy(joker.num,line);
            }
            fclose(fp);

            printf("%s %s %s %s \n", joker.nom, joker.tipo, joker.ed, joker.num);
            /* rename("Carta1.txt","./Edicion1/Carta1.txt"); */

        } 
       

    }
    
  
    closedir(dp);  

    return 0;
}