#include <stdio.h>

void mostrarMenu();
void cadastro(char nomes[][50], float notas[], int *qtdAluno);
void exibirAlunos(char nomes[][50], int *qtdAluno);

int main() {
    char nomes[100][50];
    float notas[100];
    int qtdAluno = 0;

    int escolha;

    do {
        mostrarMenu();
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                cadastro(nomes, notas, &qtdAluno);
                break;
            case 2:
                exibirAlunos(nomes, &qtdAluno);
                break;
        }
    }while (escolha != 0);

}

void mostrarMenu() {
    printf("1. Cadastrar aluno e notas\n"
           "2. Exibir alunos\n"
           "3. Calcular e exibir media geral da turma\n"
           "4. Exibir alunos aprovados (Média >= 7.0)\n"
           "0. Sair\n");
    printf("Opção: ");
}

void cadastro(char nomes[][50], float notas[], int *qtdAluno) {
    printf("Digite o nome do aluno: ");
    while (getchar() != '\n');
    fgets(nomes[*qtdAluno], 50, stdin);

    printf("Digite a nota do aluno: ");
    scanf("%f", &notas[*qtdAluno]);

    (*qtdAluno)++;
}

void exibirAlunos(char nomes[][50], int *qtdAluno) {
    for (int i = 0; i < *qtdAluno; i++) {
        printf("Aluno %d: %s\n", i + 1, nomes[i]);
    }
}