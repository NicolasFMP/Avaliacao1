#include <stdio.h>
#include <string.h>

//Prototipos das funcoes
void exibirMenu();
void cadastro(char nomes[][50], float notas[][3], int *qtdAluno);
void exibirAlunos(char nomes[][50],float notas[][3], int qtdAluno);
void exibirMediaTurma(float notas[][3],int qtdAluno);
void exibirMaiorMenorNota(float notas[][3], int qtdAluno);
void exibirAlunosAprovados(char nomes[][50], float notas[][3], int qtdAluno);

void exibirEstatisticasRecursivas(float notas[][3], int qtdAluno);
float somarNotasRecursivo(float notas[][3], int qtdAluno);
int contarAprovadosRecursivo(float notas[][3], int qtdAluno);

//Funcao main
int main() {
    char nomes[100][50];
    float notas[100][3];
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
                exibirAlunos(nomes, notas, qtdAluno);
                break;
            case 3:
                exibirMediaTurma(notas, qtdAluno);
                break;
            case 4:
                exibirMaiorMenorNota(notas, qtdAluno);
                break;
            case 5:
                exibirAlunosAprovados(nomes, notas, qtdAluno);
                break;
            case 6:
                exibirEstatisticasRecursivas(notas, qtdAluno);
                break;
            default:
                if (escolha != 0) {
                    printf("Opcao invalida\n");
                }
        }
    }while (escolha != 0);

    return 0;
}

//Exibe o menu
void exibirMenu() {
    printf("\n1. Cadastrar aluno e notas\n"
           "2. Exibir alunos\n"
           "3. Calcular e exibir media geral da turma\n"
           "4. Maior e menor nota\n"
           "5. Exibir alunos aprovados (Média >= 7.0)\n"
           "6. Exibir estatisticas de forma recursiva\n"
           "0. Sair\n");
    printf("Opção: ");
}

//Cadastra o aluno e suas notas
void cadastro(char nomes[][50], float notas[][3], int *qtdAluno) {
    if (*qtdAluno >= 100) {
        printf("Limite de alunos atingido\n");
        return;
    }

    printf("Digite o nome do aluno: ");
    while (getchar() != '\n');

    fgets(nomes[*qtdAluno], 50, stdin);
    nomes[*qtdAluno][strcspn(nomes[*qtdAluno], "\n")] = '\0';

    for (int i = 0; i < 3; i++) {
        printf("Digite a nota %d: ", i + 1);
        scanf("%f", &notas[*qtdAluno][i]);
    }

    (*qtdAluno)++;
}

//Exibe os alunos e suas notas
void exibirAlunos(char nomes[][50],float notas[][3], int qtdAluno) {
    if (qtdAluno == 0) {
        printf("Nenhum aluno cadastrado\n");
        return;
    }

    for (int i = 0; i < qtdAluno; i++) {
        printf("Aluno %d: %s\n", i + 1, nomes[i]);

        for (int j = 0; j < 3; j++) {
            printf("    Nota %d: %.2f\n", j + 1, notas[i][j]);
        }
    }
}

//Exibe a media da turma
void exibirMediaTurma(float notas[][3],int qtdAluno) {
    if (qtdAluno == 0) {
        printf("Nenhum aluno cadastrado\n");
        return;
    }

    float soma = 0.0;
    
    for (int i = 0; i < qtdAluno; i++) {
        for (int j = 0; j < 3; j++) {
            soma += notas[i][j];
        }
        
    }

    printf("Media da turma: %.2f\n", soma / (qtdAluno * 3));
}

//Exibe a maior e menor nota
void exibirMaiorMenorNota(float notas[][3], int qtdAluno) {
    if (qtdAluno == 0) {
        printf("Nenhum aluno cadastrado\n");
        return;
    }

    float maior = notas[0][0];
    float menor = notas[0][0];

    for (int i = 0; i < qtdAluno; i++) {
        for (int j = 0; j < 3; j++) {
            if (notas[i][j] > maior) {
                maior = notas[i][j];
            }

            if (notas[i][j] < menor) {
                menor = notas[i][j];
            }
        }
    }

    printf("Maior nota: %.2f\n", maior);
    printf("Menor nota: %.2f\n", menor);
}

//Exibe os alunos aprovados
void exibirAlunosAprovados(char nomes[][50], float notas[][3], int qtdAluno) {
    if (qtdAluno == 0) {
        printf("Nenhum aluno cadastrado\n");
        return;
    }

    int aprovados = 0;

    printf("Alunos aprovados:\n");
    
    for (int i = 0; i < qtdAluno; i++) {
        float soma = 0.0;

        for (int j = 0; j < 3; j++) {
            soma += notas[i][j];
        }

        float media = soma / 3;

        if (media >= 7.0) {
            aprovados++;
            printf("%s: %.2f\n", nomes[i], media);
        }

    }

    printf("Total de alunos aprovados: %d\n", aprovados);
}

//--------------------Recursivas--------------------

//Exibe soma das notas e numero de aprovados
void exibirEstatisticasRecursivas(float notas[][3], int qtdAluno) {
    if (qtdAluno == 0) {
        printf("Nenhum aluno cadastrado\n");
        return;
    }

    float soma = somarNotasRecursivo(notas, qtdAluno);
    int aprovados = contarAprovadosRecursivo(notas, qtdAluno);

    printf("Somatorio das notas: %.2f\n", soma);
    printf("Aprovados: %d\n", aprovados);
}

//Soma as notas
float somarNotasRecursivo(float notas[][3], int qtdAluno) {
    //Caso base
    if (qtdAluno == 0) {
        return 0;
    }

    int i = qtdAluno - 1;

    return notas[i][0] + notas[i][1] + notas[i][2] + somarNotasRecursivo(notas, qtdAluno - 1);
}

//Conta os alunos aprovados
int contarAprovadosRecursivo(float notas[][3], int qtdAluno) {
    //Caso base
    if (qtdAluno == 0) {
        return 0;
    }

    int i = qtdAluno - 1;

    float media = (notas[i][0] + notas[i][1] + notas[i][2]) / 3;

    if (media >= 7.0) {
        return 1 + contarAprovadosRecursivo(notas, qtdAluno - 1);
    }

    return contarAprovadosRecursivo(notas, qtdAluno - 1);
}