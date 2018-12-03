/*CRIADO POR BRENDON SOUZA
BATALHA NAVAL EM C, PLAYER LANÇA BOMBAS CONTRA A CPU*/


#include <stdio.h>
#include <stdlib.h> /* Contém as declarações e definições da função system()*/
#include <locale.h> /* Contém as declarações e definições da função setlocale.*/
#include <time.h>
#include <windows.h>
#define l 15
#define c 15
  struct Jogadas{
        int linha,coluna;
    };
int main (void)
{
    int k,j,contpontos,cont;
    char cpuaux[l][c],cpu[l][c], pav,cru,sub,des,fra,A;
    int slinha,scoluna,x,y,z,v,w;
    setlocale(LC_ALL,"portuguese");

 struct Jogadas tiro[30];

pav='P';
cru='C';
sub='S';
des='D';
fra='F';
A='~';
  for(k=0;k<l;k++){
    for(j=0;j<c;j++){
        cpu[k][j]=A;
        printf("%c ",cpu[k][j]);
    }
  printf("\n");
  }

    srand(time(NULL));
    x=(rand()%2)+1; //se for 1 cresce horizontalmente, se for 2 verticalmente



    //porta-aviões horizontalmente
        if(x==1){

                slinha=rand()%15;
                scoluna=rand()%11; //foi utilizado o %12 porquê o limite para o sorteio, no caso de um porta aviões horizontal deve ser sorteados números de 0 a 11, já que ele ocupa 4 espaços

                for(j=scoluna;j<scoluna+5;j++){//o +4 serve para determinar o limite da minha embarcação
                    cpu[slinha][j]=pav;
                }

            }
        else{

                scoluna=rand()%15;
                slinha=rand()%11; //foi utilizado o %12, pois o limite para o sorteio dessa vez tem de ser nas linhas, já que a coluna é fixa
                for(k=slinha;k<slinha+5;k++){//o +4 serve para determinar o limite da minha embarcação
                    cpu[k][scoluna]=pav;

                }
            }
 //****************************Encerra a atribuição do porta-aviões******************************

  //*************************** Atribuição do cruzador**************************
  //novo sorteio
    y=(rand()%2)+1;

  if(y==1){ //Cruzador horizontal
   do{

   slinha=rand()%15;
   scoluna=rand()%12;
   }while(cpu[slinha][scoluna]!=A|| cpu[slinha][scoluna+1]!=A|| cpu[slinha][scoluna+2]!=A|| cpu[slinha][scoluna+3]!=A);
 for(j=scoluna;j<scoluna+4;j++){
        cpu[slinha][j]=cru;
    }
  }

  else{ //cruzador vertical
    do{

        slinha=rand()%12;
        scoluna=rand()%15;
    }while(cpu[slinha][scoluna]!=A|| cpu[slinha+1][scoluna]!=A|| cpu[slinha+2][scoluna]!=A|| cpu[slinha+3][scoluna]!=A);
 for(k=slinha;k<slinha+4;k++){
        cpu[k][scoluna]=cru;
    }
  }
//****************************** FIM DO CRUZADOR*******************************

//*****************************COMEÇA A ATRIBUIÇÃO DA FRAGATA************************************
for(cont=0;cont<2;cont++){ //o for mais externo controla a quantidade de fragatas geradas
    z=((rand()%2))+1;
    if(z==1){
        do{

            slinha=rand()%15;
            scoluna=rand()%13;
        }while(cpu[slinha][scoluna]!=A|| cpu[slinha][scoluna+1]!=A|| cpu[slinha][scoluna+2]!=A);
        for(j=scoluna;j<scoluna+3;j++){
                cpu[slinha][j]=fra;
        }
    }
    else{
        do{

            slinha=rand()%13;
            scoluna=rand()%15;
        }while(cpu[slinha][scoluna]!=A|| cpu[slinha+1][scoluna]!=A|| cpu[slinha+2][scoluna]!=A);
        for(k=slinha;k<slinha+3;k++){
                cpu[k][scoluna]=fra;
        }
    }
}
//***************************FIM DA ATRIBUIÇÃO DA FRAGATA***************************
//*****************************ATRIBUIÇÃO DO DESTROYER**********************************
for(cont=0;cont<3;cont++){
    v=(rand()%2)+1;
    if(v==1){
        do{
            slinha=rand()%15;
            scoluna=rand()%14;
          }while(cpu[slinha][scoluna]!=A|| cpu[slinha][scoluna+1]!=A);
        for(j=scoluna;j<scoluna+2;j++){
                cpu[slinha][j]=des;
        }

    }
    else{
        do{
            slinha=rand()%14;
            scoluna=rand()%15;
          }while(cpu[slinha][scoluna]!=A|| cpu[slinha+1][scoluna]!=A);
        for(k=slinha;k<slinha+2;k++){
                cpu[k][scoluna]=des;
        }
    }
}

//*************************FIM DA ATRIBUIÇÃO DO DESTROYER*************************
//**********************INICIO DA ATRIBUIÇÃO DO SUBMARINO********************
for(cont=0;cont<4;cont++){
        do{
            slinha=rand()%15;
            scoluna=rand()%15;
          }while(cpu[slinha][scoluna]!=A);
        cpu[slinha][scoluna]=sub;
}
//************************FIM DA ATRIBUIÇÃO DO SUBMARINO*****************************
//************************FIM DAS ATRIBUIÇÕES DAS EMBARCAÇÕES**************************

printf("\n\n\n");

printf("Atenção tripulação, preparar para o ataque");
system("color 60");
