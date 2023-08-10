#include <stdio.h>

void create_matrix(int n, int matrix[n][n]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
}

void sum_columns_and_lines(int n, int matrix[n][n], int sum_matrix, int sum_columns[n], int sum_lines[n]){
    int i,j;

    for(i=0; i < n; i++){//linhas 
        sum_matrix = 0;   
        for(j=0; j < n; j++){//colnunas
                sum_matrix += matrix[i][j];
        }                                            
        sum_lines[i] = sum_matrix;
    }
    
    for(i=0; i < n; i++){//colunas
        sum_matrix = 0;   
        for(j=0; j < 4; j++){//linhas
                sum_matrix += matrix[j][i]; 
        }                                 
        sum_columns[i] = sum_matrix; 
    }
    
}

void vectors_diagonal(int n, int matrix[n][n], int sum_matrix, int vector_diagonal_primary[n], int vector_diagonal_secondary[n]){
    int i, j;
    //análise das diagonais
    for(i=0; i< n; i++){
        for(j=0; j< n; j++){
            if(matrix[i][j] == 1){
                vector_diagonal_primary[i] = i+j;
                vector_diagonal_secondary[j] = j-i;
            }
        }
    }
}

int answer(int n, int matrix[n][n], int result, int sum_matrix, int sum_columns[n], int sum_lines[n], int vector_diagonal_primary[n], int vector_diagonal_secondary[n]){
    int i,j,k;

    for(i=0; i < n; i++)
        for(j=0; j < n; j++)
            if(matrix[i][j] == 1)
                sum_matrix ++;
    if(sum_matrix != n){
        result = 1;
    }else{
        //impressao pro caso das colunas e linhas
        for(i=0; i < n; i++){
            if(sum_columns[i]>=2)
                    result = 1; 
            for(j=0; j < n; j++){

                if(sum_lines[j]>=2)
                    result = 1;
            }
            for (k = i + 1; k < n; k++){
                if(vector_diagonal_primary[i] == vector_diagonal_primary[k])
                    result = 1;
                else if(vector_diagonal_secondary[i] == vector_diagonal_secondary[k])
                    result = 1; 
            }   
        }
    }
    return result;
}

void answer_print(int n, int matrix[n][n], int result, int sum_matrix, int sum_columns[n], int sum_lines[n], int vector_diagonal_primary[n], int vector_diagonal_secondary[n]){

    if(answer(n, matrix, result, sum_matrix, sum_columns, sum_lines, vector_diagonal_primary, vector_diagonal_secondary) == 1)
        printf("Nao soluciona o problema das N rainhas\n");
    else
        printf("Soluciona o problema das N rainhas\n");
}

int main(){
    
    int n;
    scanf("%d", &n);

    int matrix[n][n]; 
    int result, sum_matrix, sum_lines[4], sum_columns[4], vector_diagonal_primary[4], vector_diagonal_secondary[4];

    create_matrix(n, matrix);   
    sum_columns_and_lines(n, matrix, sum_matrix, sum_columns,sum_lines);
    vectors_diagonal(n, matrix, sum_matrix, vector_diagonal_primary, vector_diagonal_secondary); 
    answer_print(n,matrix, result, sum_matrix, sum_columns, sum_lines, vector_diagonal_primary, vector_diagonal_secondary);     
}
