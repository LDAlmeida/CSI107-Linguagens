// Nível de Abstração 1: Função de Multiplicação de Matrizes
Matriz MultiplicaMatrizes(Matriz A, Matriz B);

// Nível de Abstração 2: Função de Multiplicação de Linha por Coluna
ElementoMatriz MultiplicaLinhasColunas(LinhaMatriz linhaA, ColunaMatriz colunaB);

// Nível de Abstração 3: Estruturas de Dados para Matrizes
typedef struct {
    int linhas;
    int colunas;
    double **elementos;
} Matriz;

typedef struct {
    int tamanho;
    double *elementos;
} LinhaMatriz, ColunaMatriz;

// Nível de Abstração 4: Funções Auxiliares para Manipulação de Matrizes
Matriz CriaMatriz(int linhas, int colunas);
void DestroiMatriz(Matriz matriz);
void PreencheMatriz(Matriz matriz, double valores);
LinhaMatriz ObtémLinha(Matriz matriz, int linha);
ColunaMatriz ObtémColuna(Matriz matriz, int coluna);
