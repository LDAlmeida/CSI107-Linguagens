#include <stdio.h>

double calcularProdutorioRecursivo(int m, int n) {
    if (m <= 0 || n <= 0 || m > n) {
        // Verificações de limite inválido ou reverso
        printf("Limites inválidos.\n");
        return 0.0;
    }

    if (m == n) {
        // Caso base: Produtório de um único termo
        return (m + 1.0 / m);
    }

    // Chamada recursiva para calcular o produtório
    return (calcularProdutorioRecursivo(m, n - 1) * (n + 1.0 / n));
}

int main() {
    int m, n;
    printf("Digite o limite inferior (m): ");
    scanf("%d", &m);
    printf("Digite o limite superior (n): ");
    scanf("%d", &n);

    double resultado = calcularProdutorioRecursivo(m, n);
    printf("O resultado do produtório é: %lf\n", resultado);

    return 0;
}
