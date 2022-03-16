#include <stdio.h>

int main(){
    
    FILE *txt;
    txt = fopen("adjacency_matrix_21.txt" , "r");
    int V[5][5];
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            V[i][j] = 0;
        }
    }       
    for (int i = 0; i < 5; i++)
        fscanf( txt, "%d %d %d %d %d", &V[i][0], &V[i][1], &V[i][2], &V[i][3], &V[i][4]  );
    fclose(txt);
    
    FILE *dot;
    dot = fopen("matrix.dot", "a");
    fprintf(dot, " digraph G {\n" );
    for(int i = 0; i < 5; i++){
        for( int j = i; j < 5; j++){
            for( int m = V[i][j]; m >= 1; m--){
                fprintf(dot, "\t%d -> %d\n", i + 1, j + 1 );
            }
        }
    }
    fprintf(dot, "}");
    fclose(dot);

    return 0;
}


