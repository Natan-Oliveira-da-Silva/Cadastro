#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//data de produção: 21/06/2024
int main(){
    char nome[50];
    char cidade[50];
    int numero;
    int idade;
    char letra;
    int mais_um;
    int digitou_errado;
    
    FILE* arquivo;
    arquivo = fopen("pessoas_cadastradas.txt","r+");
    if(arquivo==0){
        printf("Não foi possivel abrir o arquivo.\nPROGRAMA ENCERRADO");
        exit(1);
    }
    printf("                       +----------------+\n");
    printf("                       |                |\n");
    printf("                       |    CADASTRO    |\n");
    printf("                       |                |\n");
    printf("                       +----------------+\n\n\n");
    printf("As informacoes cadastradas aqui serao adicionadas ao banco de dados.\n");
    do{
        printf("\nDigite o nome da pessoa que voce quer adicionar\n");
        scanf("%s",&nome);
        printf("Em que cidade %s mora?\n",nome);
        scanf("%s",&cidade);
        printf("Quantos anos %s tem?\n",nome);
        scanf("%d",&idade);
        printf("Qual eh o numero de celular de %s?\n",nome);
        scanf("%d",&numero);
        printf("\nTUDO CERTO!\n%s foi adicionado ao banco de dados.\n\n",nome);
        do{
            printf("\nQuer adicionar mais alguem a lista?\nS --> Sim\nN --> Nao\n");
            scanf(" %c",&letra);
            digitou_errado=0;
            if (letra=='S'||letra=='s'){
                mais_um=1;
            }else if(letra=='N'||letra=='n'){
                mais_um=0;
            }else{
                printf("Desculpe. Nao consegui entender...\n");
                digitou_errado=1;
            }
        }while(digitou_errado);
        fseek(arquivo,0,SEEK_END);
        fprintf(arquivo,"\n%s|%s|%d|%d",nome,cidade,idade,numero);
        
    }while(mais_um);
    fclose(arquivo);
    printf("\nPROGRAMA ENCERRADO");
    
    return 0;
}
