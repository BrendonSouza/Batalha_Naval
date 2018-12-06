/*CRIADO POR BRENDON SOUZA
BATALHA NAVAL EM C, PLAYER LANÇA BOMBAS CONTRA A CPU*/


#include <stdio.h>
#include <stdlib.h> /* Contém as declarações e definições da função system()*/
#include <locale.h> /* Contém as declarações e definições da função setlocale.*/
#include <time.h>
#include <windows.h>
#define l 15
#define c 15
#define t 5
  struct Jogadas{
        int linha,coluna;
    };
int main (void)
{
    int k,j,contpontos,cont,contD,contC,contP,contS,contF;
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
contD=0;
contC=0;
contP=0;
contS=0;
contF=0;
contpontos=0;
//fim do set de variáveis
//******início das atribuições
  for(k=0;k<l;k++){//inicialmente,toda a matriz é Agua;
    for(j=0;j<c;j++){
        cpu[k][j]=A;

    }
  }

    srand(time(NULL));
    x=(rand()%2)+1; //se for 1 cresce horizontalmente, se for 2 verticalmente



    //porta-aviões horizontalmente
        if(x==1){

                slinha=rand()%15;
                scoluna=rand()%11; //foi utilizado o %11 porquê o limite para o sorteio, no caso de um porta aviões horizontal deve ser sorteados números de 0 a 11, já que ele ocupa 5 espaços

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
// *******************************O JOGO VAI COMEÇAR!!!!!!!!!!!!!!!!!!!!!
printf("      ****Batalha Naval****\n ***Desenvolvido por Brendon Souza***\n\n\n**Instruções:**\n");
printf("O jogador deve informar os números das linhas (de 0 a 14) e das colunas(0 a 14) para efetuar um tiro.\nO jogador possui 30 tiros.\n O tabuleiro do computador é ");
printf("composto por 11 embarcações: \n4 submarinos(ocupam um espaço);\n3 destroyers(ocupam 2 espaços cada);\n2 Fragatas(Ocupam 3 espaços cada);\n1 Cruzador(Ocupa 4 espaços);\n1 Porta-Aviões(ocupam 5 espaços).\n ");
printf("As embarcações são distribuidas aleatoriamente e podem estar na vertical ou na horizontal. \nBoa Sorte, Marujo!\n");
system("PAUSE");
system("cls");
for(k=0;k<l;k++){//atribui água na mátriz auxiliar, que vai mostrar o tiro
    for(j=0;j<c;j++){

        cpuaux[k][j]=A;
    }
  }
printf("    0  1  2  3  4  5  6  7  8  9  10 11 12 13 14\n");
  for(k=0;k<l;k++){
      printf("%.2d ",k);
    for(j=0;j<c;j++){
        printf(" %c ",cpuaux[k][j]);
    }
printf("\n");
  }


printf("\n\n\n");
x=0;
printf("Atenção tripulação, preparar para o ataque");
printf("\n\n\nVocê tem 30 tiros as cegas, execute-os\n\n");


printf("informe uma linha entre 0 e 14, marujo: ");
scanf("%d",& tiro[x].linha);
printf("informe uma coluna entre 0 e 14, marujo: ");
scanf("%d",& tiro[x].coluna);
    if((tiro[x].linha<0)||(tiro[x].linha>14)||(tiro[x].coluna<0)||(tiro[x].coluna>14)){//correção das coordenadas, sujeitas a alterações
        do{
            printf("coordenadas invalidas, informe números entre 0 e 14\n\n");
            printf("informe uma linha entre 0 e 14, marujo: ");
            scanf("%d",& tiro[x].linha);
            printf("informe uma coluna entre 0 e 14, marujo: ");
            scanf("%d",& tiro[x].coluna);
        }while((tiro[x].linha<0)||(tiro[x].linha>14)||(tiro[x].coluna<0)||(tiro[x].coluna>14));
    }
    if(cpu[tiro[x].linha][tiro[x].coluna]!=A){//se o tiro do usuário for em um lugar diferente de água, ou seja, em uma embarcação...
            cpuaux[tiro[x].linha][tiro[x].coluna]='X';//a matriz auiliar recebe a embarcação que está presente na matriz principal
            system("color 4F");
            switch(cpu[tiro[x].linha][tiro[x].coluna]){

                    case 'S': contpontos=50+contpontos;
                                    printf("Boa marujo, acertou um submarino!!");
                                    Sleep(1500);
                                    break;

                        case 'D':contpontos=10+contpontos;
                                    printf("Um destroyer?! Você é bom nisso!");
                                    Sleep(1500);
                                    contD++;
                                    break;
                        case 'F': contpontos=10+contpontos;
                                    printf("Fragata?? ou deveria dizer 'naufragata'? ");
                                    Sleep(1500);
                                    contF++;
                                    break;
                        case 'C': contpontos=10+contpontos;
                                    printf("Nunca cruze com o meu navio!! Acertamos um cruzador.");
                                    contC++;
                                    Sleep(1500);
                                    break;
                        case 'P': contpontos=10+contpontos;
                                    printf("Pedimos para abrir a porta, eles recusaram, nós abrimos uma. Acertamos um Porta-Aviões");
                                    Sleep(2000);
                                    contP++;
                                    break;
            }
    }
    else{
            cpuaux[tiro[x].linha][tiro[x].coluna]='O';
            system("color 1F");
            printf("Tiro no mar, melhore a pontaria marujo!!");
    }

Sleep(1000);
system("cls");
printf("    0  1  2  3  4  5  6  7  8  9  10 11 12 13 14\n");
for(k=0;k<l;k++){
        printf("%.2d ",k);
    for(j=0;j<c;j++){
        printf(" %c ",cpuaux[k][j]);
    }
  printf("\n");
  }
printf("\nPontuação %d\n",contpontos);


    for(x=1;x<t;x++){
        system("color 0F");
        printf("informe uma linha entre 0 e 14, marujo: ");
        scanf("%d",& tiro[x].linha);
        printf("informe uma coluna entre 0 e 14, marujo: ");
        scanf("%d",& tiro[x].coluna);
        if((tiro[x].linha<0)||(tiro[x].linha>14)||(tiro[x].coluna<0)||(tiro[x].coluna>14)||(cpuaux[tiro[x].linha][tiro[x].coluna]=='X')||(cpuaux[tiro[x].linha][tiro[x].coluna]=='O')){
            do{
                printf("coordenadas invalidas ou tiro repetido, informe números entre 0 e 14\n");
                printf("informe uma linha entre 0 e 14, marujo: ");
                scanf("%d",& tiro[x].linha);
                printf("informe uma coluna entre 0 e 14, marujo: ");
                scanf("%d",& tiro[x].coluna);
            }while((tiro[x].linha<0)||(tiro[x].linha>14)||(tiro[x].coluna<0)||(tiro[x].coluna>14)||(cpuaux[tiro[x].linha][tiro[x].coluna]=='X')||(cpuaux[tiro[x].linha][tiro[x].coluna]=='O'));
        }

        if(cpu[tiro[x].linha][tiro[x].coluna]!=A){//se o tiro do usuário for em um lugar diferente de água, ou seja, em uma embarcação...
                cpuaux[tiro[x].linha][tiro[x].coluna]='X';//a matriz auiliar recebe a embarcação que está presente na matriz principal
                    system("color 4F");
                switch(cpu[tiro[x].linha][tiro[x].coluna]){
                        case 'S': contpontos=50+contpontos;
                                    printf("Boa marujo, afundou um submarino!!");
                                    break;

                        case 'D':contpontos=10+contpontos;
                                    printf("Um destroyer?! Você é bom nisso!");
                                    contD++;
                                    Sleep(2000);
                                    break;
                        case 'F': contpontos=10+contpontos;
                                    printf("Fragata?? ou deveria dizer 'naufragata'? ");
                                    Sleep(2000);
                                    contF++;
                                    break;
                        case 'C': contpontos=10+contpontos;
                                    printf("Nunca cruze com o meu navio!! Acertamos um cruzador.");
                                    contC++;
                                    Sleep(2000);
                                    break;
                        case 'P': contpontos=10+contpontos;
                                    printf("Pedimos para abrir a porta, eles recusaram, nós abrimos uma. Acertamos um Porta-Aviões");
                                    Sleep(2000);
                                    contP++;
                                    break;

                }
        }//fecha o if de acerto
        else{
                cpuaux[tiro[x].linha][tiro[x].coluna]='O';
                system("color 1F");
                printf("Tiro no mar, melhore a pontaria marujo!!");
                Sleep(500);
        }
        //encerra a leitura dos tiros
    Sleep(1000);
    system("cls");
    printf("    0  1  2  3  4  5  6  7  8  9  10 11 12 13 14\n");
    for(k=0;k<l;k++){
        printf("%.2d ",k);
        for(j=0;j<c;j++){
            printf(" %c ",cpuaux[k][j]);
        }
        printf("\n");
    }
printf("\nPontuação %d\n",contpontos);
    }

    //atribui as embarcações afundadas
    for(x=0;x<t;x++){
 if(cpu[tiro[x].linha][tiro[x].coluna]!=A){//se o tiro do usuário for em um lugar diferente de água, ou seja, em uma embarcação...
                cpuaux[tiro[x].linha][tiro[x].coluna]=cpu[tiro[x].linha][tiro[x].coluna];//a matriz auiliar recebe a embarcação que está presente na matriz principal

        }//fecha o if de acerto
        else{
                cpuaux[tiro[x].linha][tiro[x].coluna]='O';
        }
//************Contador de pontos*********************
    }
    if(contP==5){
        contpontos=contpontos+10;
    }
    if(contC==4){
        contpontos=contpontos+20;
    }
    switch(contF){
        case 3: contpontos=contpontos+30;
                break;
        case 4:contpontos=contpontos+30;
                break;
        case 5:contpontos=contpontos+30;
                break;
        case 6:contpontos=contpontos+60;
                break;
    }
    switch(contD){
        case 2: contpontos=contpontos+40;
            break;
        case 3: contpontos=contpontos+40;
            break;
        case 4: contpontos=contpontos+80;
            break;
        case 5: contpontos=contpontos+80;
            break;
        case 6: contpontos=contpontos+120;
            break;
        case 7: contpontos=contpontos+120;
            break;
        case 8: contpontos=contpontos+160;
            break;
    }
system("cls");
//**********Impressão da matriz final com os erros e acertos do jogador***************
    printf("Essas foram as embarcações acertadas e os tiros no mar!\n");
    printf("    0  1  2  3  4  5  6  7  8  9  10 11 12 13 14\n");
        for(k=0;k<l;k++){
            printf("%.2d ",k);
        for(j=0;j<c;j++){
            printf(" %c ",cpuaux[k][j]);
        }
        printf("\n");
    }
printf("\nPontuação total: %d\n\n",contpontos);

getchar();
system("pause");
return 0;
}

