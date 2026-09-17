#include <stdio.h>

void mostrarMenu();
void cadastro(char nomes[][50], float notas[], int *qtdAluno);

int main() {
    char nomes[100][50];
    float notas[100];

    int escolha;

    do {
        mostrarMenu();
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                
        }
    }while (escolha != 0);

}

void mostrarMenu() {
    printf("1. Cadastrar aluno e notas\n"
           "3. Exibir alunos\n"
           "4. Calcular e exibir media geral da turma\n"
           "5. Exibir alunos aprovados (Média >= 7.0)\n");
    printf("Opção: ");
}

void cadastro(char nomes[][50], float notas[], int *qtdAluno) {
    printf("Digite o nome do aluno: ");
    fgets(nomes[*qtdAluno], 50, stdin);
}