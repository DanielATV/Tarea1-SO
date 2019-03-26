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

    char path[100];

    /*Creacion de directorios*/
    mkdir("Edicion1",0755);
    mkdir("Edicion1/Normal",0755);
    mkdir("Edicion1/Magica",0755);
    mkdir("Edicion1/Rara",0755);
    mkdir("Edicion2",0755);
    mkdir("Edicion2/Normal",0755);
    mkdir("Edicion2/Magica",0755);
    mkdir("Edicion2/Rara",0755);
    mkdir("Edicion3",0755);
    mkdir("Edicion3/Normal",0755);
    mkdir("Edicion3/Magica",0755);
    mkdir("Edicion3/Rara",0755);
    mkdir("Edicion4",0755);
    mkdir("Edicion4/Normal",0755);
    mkdir("Edicion4/Magica",0755);
    mkdir("Edicion4/Rara",0755);
    mkdir("Edicion5",0755);
    mkdir("Edicion5/Normal",0755);
    mkdir("Edicion5/Magica",0755);
    mkdir("Edicion5/Rara",0755);

    /* Mover las cartas */

    
    char dummy[6] = "Carta";
    char test[6];


    DIR *dp;
    struct dirent *de;
    dp = opendir("./");

    while ((de = readdir(dp)) != NULL) {

        strcpy(test,de->d_name);

        if (strlen(test) >=  13){/* si el nombre es muy largo es carta */
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
            
            strcpy(path , "./");
            strcat(path,joker.ed);
            strcat(path,"/");
            strcat(path,joker.tipo);
            strcat(path,"/");
            strcat(path, de->d_name);
            
            rename("Carta_001.txt","../Carta_001.txt");

        } 
       

    }
    
  
    closedir(dp);  

    return 0;
}