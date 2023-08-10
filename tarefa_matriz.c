#include <stdio.h>
#include <stdlib.h>

void carregando_valores_na_matriz(int valor_linha, int valor_colunas, int matriz[valor_linha][valor_colunas]){
    int counter = 1;
    for (int i = 0; i < valor_linha; i++)
        for (int j = 0; j < valor_colunas; j++){ 
            matriz[i][j] = counter;
            counter++;
        }
}
void imprimindo_a_matriz(int valor_linha, int valor_colunas, int matriz[valor_linha][valor_colunas]){

    printf("MATRIZ\n");
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++)
            printf("%d\t", matriz[i][j]); 
        printf("\n"); 
    }
}
void imprimindo_a_diagonal_principal(int valor_linha, int valor_colunas, int matriz[valor_linha][valor_colunas]){
    
    printf("DIAGONAL PRINCIPAL: \n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++){
            if (i == j)
                printf(" %d", matriz[i][j]);
            else
                printf("\t");
        }printf("\n");
    }
}
void imprimindo_a_diagonal_secundaria(int valor_linha, int valor_colunas, int matriz[valor_linha][valor_colunas]){

    printf("DIAGONAL SECUNDÁRIA: \n");
    for (int i = 0; i < valor_linha; i++){ 
        for (int j = 0; j < valor_colunas; j++){ 
            if (i + j == 4)
                printf(" %d", matriz[i][j]);
            else
                printf("\t");
        }printf("\n");
    }
}
void imprimindo_a_matriz_triangular_inferior(int valor_linha, int valor_colunas, int matriz[valor_linha][valor_colunas]){
    
    printf("MATRIZ TRIANGULAR INFERIOR: \n");
    for (int i = 0; i < valor_linha; i++){ 
        for (int j = 0; j < valor_colunas; j++){
            if (matriz[i][j] < matriz[i][i]) 
                printf("%d\t", matriz[i][j]);
            else
                printf("\t");
        }printf("\n");
    }
}
void imprimindo_a_matriz_triangular_superior(int valor_linha, int valor_colunas, int matriz[valor_linha][valor_colunas]){

    printf("MATRIZ TRIANGULAR SUPERIOR: \n");
    for (int i = 0; i < valor_linha; i++){ 
        for (int j = 0; j < valor_colunas; j++){
            if (matriz[i][j] > matriz[i][i]) 
                printf("%d\t", matriz[i][j]);
            else
                printf("\t");
        }printf("\n");
    }
}
void imprimindo_a_matriz_triangular_secundaria_inferior(int valor_linha, int valor_colunas, int matriz[valor_linha][valor_colunas]){

    printf("MATRIZ TRAINGULAR SECUNDÁRIA INFERIOR: \n");
    for (int i = 0; i < valor_linha; i++){
        for (int j = 0; j < valor_colunas; j++){ 
            if (i + j > 4)
                printf("%d\t", matriz[i][j]);
            else
                printf("\t");
        }printf("\n");
    }
}
void imprimindo_a_matriz_triangular_secundaria_superior(int valor_linha, int valor_colunas, int matriz[valor_linha][valor_colunas]){

    printf("MATRIZ TRAINGULAR SECUNDÁRIA SUPERIOR: \n");
    for (int i = 0; i < valor_linha; i++){ 
        for (int j = 0; j < valor_colunas; j++){ 
            if (i + j < 4)
                printf("%d\t", matriz[i][j]);
            else
                printf("\t");
        }printf("\n");
    }   
}

int main(){
    int matriz[5][5];
    carregando_valores_na_matriz(5,5, matriz); 
    imprimindo_a_matriz(5, 5, matriz);
    imprimindo_a_diagonal_principal(5, 5, matriz); 
    imprimindo_a_diagonal_secundaria(5, 5, matriz); 
    imprimindo_a_matriz_triangular_inferior(5, 5, matriz);
    imprimindo_a_matriz_triangular_superior(5, 5, matriz); 
    imprimindo_a_matriz_triangular_secundaria_inferior(5, 5, matriz);
    imprimindo_a_matriz_triangular_secundaria_superior(5, 5, matriz);
    return 0;
}