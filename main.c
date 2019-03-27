#include <sys/types.h>
#include <sys/stat.h>
#include<unistd.h> 
#include <dirent.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

struct carta{
    char nom[20];
    char tipo[20];
    char ed[20];
    char num[20];

};

int main(){
    int i;
    int largo;

    struct carta mazo[20];

    /*strcpy(mazo[0].nom,"asd");
    printf("funciono %s\n",mazo[0].nom); */
    struct carta joker;

    FILE *fp;
    char line[20];
    char comp;

    char path[100];
    char directorio[100];

    int opcion;
    int opcion2;

    char camino1 [100];
    char camino2 [100];
  
    int contador;


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
                largo =  strlen(line);


                if (line[largo -1]== '\n') line[largo -1] = '\0';
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

            printf("%s\n",path);
            rename(de->d_name,path);
            
            

        } 
       

    }
    
  
    closedir(dp); 

    /* Navegador */

    dp = opendir("./");
   
    while(true){

        printf("-------------------\n");
        printf("Escoger Edicion:\n");
        printf("1/2/3/4/5\n");
        printf("6 para salir\n");

        scanf("%d", &opcion);

        if (opcion == 1){
            strcpy(camino1,"./Edicion1/");
            while (true){
                printf("-------------------\n");
                printf("Escoger Tipo:\n");
                printf("1.- Magica/ 2.- Normal/ 3.- Rara\n");
                printf("4 para salir\n");
                scanf("%d", &opcion2);

                if (opcion2 == 1){
                    strcpy(camino2,"Magica");

                    strcat(camino1,camino2);

                    dp = opendir(camino1);

                    contador = 0;
                    while ((de = readdir(dp)) != NULL){
                        printf("%s\n",de->d_name);
                        /*
                        strcpy(test,de->d_name);

                        if (strlen(test) >=  13){

                            fp = fopen(de->d_name,"r");
                            for (i =0; i<4; i++){
                                fgets(line,20,fp);
                                largo =  strlen(line);
                                if (line[largo -1]== '\n') line[largo -1] = '\0';



                                
                                if (i== 0) strcpy(collection[contador].nom ,line);
                                else if (i == 1) strcpy(collection[contador].tipo ,line);
                                else if (i == 2) strcpy(collection[contador].ed,line);
                                else strcpy(collection[contador].num,line);
                            } 
                            fclose(fp);
                            contador ++; 
                        } */

                    
                        /* printf("%s\n",collection[0].nom); */

                    }
                    
                    
                }
            

                else break;
            }
        }
        else if (opcion == 2){
            chdir("Edicion2");
        }

        else if (opcion == 3){
            chdir("Edicion3");
        }

        else if (opcion == 4) {
            chdir("Edicion4");
        }

        else if (opcion == 5){
            chdir("Edicion5");
        }

        else break;
        

    }

    return 0;
}