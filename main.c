#include <stdio.h>
#include <string.h>

void exibirMenu();
void cadastro(char nomes[][50], float notas[], int *qtdAluno);
void exibirAlunos(char nomes[][50],float notas[], int *qtdAluno);
void exibirMediaTurma(float notas[],int *qtdAluno);
void exibirAlunosAprovados(char nomes[][50], float notas[], int *qtdAluno);

int main() {
    char nomes[100][50];
    float notas[100];
    int qtdAluno = 0;

    int escolha;

    do {
        exibirMenu();
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                cadastro(nomes, notas, &qtdAluno);
                break;
            case 2:
                exibirAlunos(nomes, notas, &qtdAluno);
                break;
            case 3:
                exibirMediaTurma(notas, &qtdAluno);
                break;
            case 4:
                exibirAlunosAprovados(nomes, notas, &qtdAluno);
                break;
            default:
                if (escolha != 0) {
                    printf("Opcao invalida\n");
                }
        }
    }while (escolha != 0);

}

void exibirMenu() {
    printf("\n1. Cadastrar aluno e notas\n"
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
    nomes[*qtdAluno][strcspn(nomes[*qtdAluno], "\n")] = '\0';

    printf("Digite a nota do aluno: ");
    scanf("%f", &notas[*qtdAluno]);

    (*qtdAluno)++;
}

void exibirAlunos(char nomes[][50],float notas[], int *qtdAluno) {
    for (int i = 0; i < *qtdAluno; i++) {
        printf("Aluno %d: %s, %.2f\n", i + 1, nomes[i], notas[i]);
    }
}

void exibirMediaTurma(float notas[],int *qtdAluno) {
    if (*qtdAluno == 0) {
        printf("Nenhum aluno cadastrado\n");
        return;
    }

    float soma = 0.0;
    
    for (int i = 0; i < *qtdAluno; i++) {
        soma += notas[i];
    }

    printf("Media da turma: %.2f", soma / *qtdAluno);
}

void exibirAlunosAprovados(char nomes[][50], float notas[], int *qtdAluno) {
    printf("Alunos aprovados:\n");
    for (int i = 0; i < *qtdAluno; i++) {
        if (notas[i] >= 7.0) {
            printf("%s: %.2f\n", nomes[i], notas[i]);
        }
    }
}