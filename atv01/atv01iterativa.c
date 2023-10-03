#include <stdio.h>

double calcularProdutorioIterativo(int m, int n) {
    if (m <= 0 || n <= 0 || m > n) {
        // Verificações de limite inválido ou reverso
        printf("Limites inválidos.\n");
        return 0.0;
    }

    double resultado = 1.0;
    for (int i = m; i <= n; i++) {
        resultado *= (i + 1.0 / i);
    }
    return resultado;
}

int main() {
    int m, n;
    printf("Digite o limite inferior (m): ");
    scanf("%d", &m);
    printf("Digite o limite superior (n): ");
    scanf("%d", &n);

    double resultado = calcularProdutorioIterativo(m, n);
    printf("O resultado do produtório é: %lf\n", resultado);

    return 0;
}
