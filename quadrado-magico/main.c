#include <stdio.h>
#include <stdint.h>
#include <time.h> 
#include <stdarg.h>

#define QUADRADO_MAGICO 1
#define NAO_E_QUADRADO_MAGICO 0
#define N 9
#define DIAGONAIS 2
#define TOTAL_VERIFICACOES N + N + DIAGONAIS
#define CONSTANTE_MAGICA N*(N*N+1)/2

int verificarSeQuadradoMagico(int quadrado[][N]);

int main(int argc, char *argv[]){
    
    int qm[N][N]={
        {47, 58, 69, 80, 1, 12, 23, 34, 45},
    {57, 68, 79, 9, 11, 22, 33, 44, 46},
    {67, 78, 8, 10, 21, 32, 43, 54, 56},
    {77, 7, 18, 20, 31, 42, 53, 55, 66},
    {6, 17, 19, 30, 41, 52, 63, 65, 76},
    {16, 27, 29, 40, 51, 62, 64, 75, 5},
    {26, 28, 39, 50, 61, 72, 74, 4, 15},
    {36, 38, 49, 60, 71, 73, 3, 14, 25},
    {37, 48, 59, 70, 81, 2, 13, 24, 35}
};

    if(verificarSeQuadradoMagico(qm)) printf("É um quadrado mágico!\n");
    else printf("Não é um quadrado mágico!\n");
    
    return 0;
}

int verificarSeQuadradoMagico(int quadrado[][N]){
    int count = 0;
    int soma = 0;
    int i, j = 0;
    i = 0;
  
  //verificar linhas
    for(; i < N; j++){ 
        soma += quadrado[i][j];   
        if(soma == CONSTANTE_MAGICA){
          count++;
          i++;
        }
        if((j == (N - 1))){
          if(soma > CONSTANTE_MAGICA || soma < CONSTANTE_MAGICA) return 0;
          soma = 0; 
          j = -1; 
        } 
    }
 
    //verificar colunas
    for(i = 0, j = 0, soma = 0; j < N; i++){
        soma += quadrado[i][j];
        if(soma == CONSTANTE_MAGICA){
          count++;
          j++;
        }
        if((i == (N - 1))){
          if(soma > CONSTANTE_MAGICA || soma < CONSTANTE_MAGICA) return 0;
          soma = 0;
          i = -1;
        }
    }

    for(i = 0, soma = 0; i < N; i++){
      soma += quadrado[i][i];
      if(soma == CONSTANTE_MAGICA) count++;
      if((i == (N - 1)) && soma != CONSTANTE_MAGICA) return 0;
    }
  
    for(i = 0, soma = 0; i < N; i++){
      soma += quadrado[i][N - 1 - i];
      if(soma == CONSTANTE_MAGICA) count++;
      if((i == (N - 1)) && soma != CONSTANTE_MAGICA) return 0;
    }

    return (count == TOTAL_VERIFICACOES) ? QUADRADO_MAGICO : NAO_E_QUADRADO_MAGICO;
}
