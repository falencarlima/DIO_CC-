#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para desenhar a tabela do jogo
void desenhar_tabela(char tabela[3][3]) {
    printf("\n");
    printf(" %c | %c | %c \n", tabela[0][0], tabela[0][1], tabela[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", tabela[1][0], tabela[1][1], tabela[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", tabela[2][0], tabela[2][1], tabela[2][2]);
    printf("\n");
}

// Função para verificar se o jogo acabou
int verificar_fim(char tabela[3][3]) {
    // Verifica se alguma linha possui três símbolos iguais
    for (int i = 0; i < 3; i++) {
        if (tabela[i][0] == tabela[i][1] && tabela[i][1] == tabela[i][2] && tabela[i][0] != ' ') {
            return 1;
        }
    }
    // Verifica se alguma coluna possui três símbolos iguais
    for (int j = 0; j < 3; j++) {
        if (tabela[0][j] == tabela[1][j] && tabela[1][j] == tabela[2][j] && tabela[0][j] != ' ') {
            return 1;
        }
    }
    // Verifica se alguma diagonal possui três símbolos iguais
    if ((tabela[0][0] == tabela[1][1] && tabela[1][1] == tabela[2][2] && tabela[0][0] != ' ') ||
        (tabela[0][2] == tabela[1][1] && tabela[1][1] == tabela[2][0] && tabela[0][2] != ' ')) {
        return 1;
    }
    // Verifica se o jogo empatou
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabela[i][j] == ' ') {
                return 0; // Ainda existem espaços vazios, o jogo não terminou
            }
        }
    }
    return -1; // O jogo empatou
}

// Função para a jogada do usuário
void jogada_usuario(char tabela[3][3], char simbolo) {
    int linha, coluna;
    do {
        printf("Digite a linha (0, 1 ou 2): ");
        scanf("%d", &linha);
        printf("Digite a coluna (0, 1 ou 2): ");
        scanf("%d", &coluna);
        if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || tabela[linha][coluna] != ' ') {
            printf("Jogada inválida. Por favor, tente novamente.\n");
        }
    } while (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || tabela[linha][coluna] != ' ');
    tabela[linha][coluna] = simbolo;
}

// Função para a jogada da CPU (escolhe uma posição aleatória disponível)
void jogada_cpu(char tabela[3][3], char simbolo) {
    int linha, coluna;
    do {
        linha = rand() % 3; // Gera um número aleatório entre 0 e 2 para a linha
        coluna = rand() % 3; // Gera um número aleatório entre 0 e 2 para a coluna
    } while (tabela[linha][coluna] != ' '); // Verifica se a posição está vazia
    tabela[linha][coluna] = simbolo;
}

// Função principal do jogo
void usuario_cpu() {
    char tabela[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    char simbolo_usuario, simbolo_cpu;
    int fim;

    printf("Escolha o seu símbolo (X ou O): ");
    scanf(" %c", &simbolo_usuario);

    if (simbolo_usuario == 'X' || simbolo_usuario == 'x') {
        simbolo_cpu = 'O';
    } else {
        simbolo_cpu = 'X';
    }

    while (1) {
        desenhar_tabela(tabela);
        jogada_usuario(tabela, simbolo_usuario);
        fim = verificar_fim(tabela);
        if (fim == 1) {
            desenhar_tabela(tabela);
            printf("Você ganhou!\n");
            break;
        } else if (fim == -1) {
            desenhar_tabela(tabela);
            printf("Empate!\n");
            break;
        }

        jogada_cpu(tabela, simbolo_cpu);
        fim = verificar_fim(tabela);
        if (fim == 1) {
            desenhar_tabela(tabela);
            printf("A CPU ganhou!\n");
            break;
        } else if (fim == -1) {
            desenhar_tabela(tabela);
            printf("Empate!\n");
            break;
        }
    }
}

int main() {
    srand(time(NULL)); // Inicializa a semente para geração de números aleatórios
    usuario_cpu();
    return 0;
}
