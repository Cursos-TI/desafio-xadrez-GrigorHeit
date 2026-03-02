#include <stdio.h>
#include <locale.h>
#include <string.h>

// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.

//\x1b[47m - Fundo Branco na tabela ANSI
//\x1b[40m - Fundo Preto na tabela ANSI
//\x1b[0m  - Resetar o fundo na tabela ANSI



char *tabuleiro[8][8] = {
    {"\x1b[47m   \x1b[0m","\x1b[40m   \x1b[0m","\x1b[47m   \x1b[0m","\x1b[40m   \x1b[0m","\x1b[47m   \x1b[0m","\x1b[40m   \x1b[0m","\x1b[47m   \x1b[0m","\x1b[40m   \x1b[0m"},
    {"\x1b[40m   \x1b[0m","\x1b[47m   \x1b[0m","\x1b[40m   \x1b[0m","\x1b[47m   \x1b[0m","\x1b[40m   \x1b[0m","\x1b[47m   \x1b[0m","\x1b[40m   \x1b[0m","\x1b[47m   \x1b[0m"},
    {"\x1b[47m   \x1b[0m","\x1b[40m   \x1b[0m","\x1b[47m   \x1b[0m","\x1b[40m   \x1b[0m","\x1b[47m   \x1b[0m","\x1b[40m   \x1b[0m","\x1b[47m   \x1b[0m","\x1b[40m   \x1b[0m"},
    {"\x1b[40m   \x1b[0m","\x1b[47m   \x1b[0m","\x1b[40m   \x1b[0m","\x1b[47m   \x1b[0m","\x1b[40m   \x1b[0m","\x1b[47m   \x1b[0m","\x1b[40m   \x1b[0m","\x1b[47m   \x1b[0m"},
    {"\x1b[47m   \x1b[0m","\x1b[40m   \x1b[0m","\x1b[47m   \x1b[0m","\x1b[40m   \x1b[0m","\x1b[47m   \x1b[0m","\x1b[40m   \x1b[0m","\x1b[47m   \x1b[0m","\x1b[40m   \x1b[0m"},
    {"\x1b[40m   \x1b[0m","\x1b[47m   \x1b[0m","\x1b[40m   \x1b[0m","\x1b[47m   \x1b[0m","\x1b[40m   \x1b[0m","\x1b[47m   \x1b[0m","\x1b[40m   \x1b[0m","\x1b[47m   \x1b[0m"},
    {"\x1b[47m   \x1b[0m","\x1b[40m   \x1b[0m","\x1b[47m   \x1b[0m","\x1b[40m   \x1b[0m","\x1b[47m   \x1b[0m","\x1b[40m   \x1b[0m","\x1b[47m   \x1b[0m","\x1b[40m   \x1b[0m"},
    {"\x1b[40m   \x1b[0m","\x1b[47m   \x1b[0m","\x1b[40m   \x1b[0m","\x1b[47m   \x1b[0m","\x1b[40m   \x1b[0m","\x1b[47m   \x1b[0m","\x1b[40m   \x1b[0m","\x1b[47m   \x1b[0m"}
};

void printTabuleiro(){
    system("clear");
    printf("\n");
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            printf("%s", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

typedef enum {Norte, Sul, Leste, Oeste}direcoes;

void MoverRainha(char *direcao, int ncasasandar, char *initialPosition){
    
    // N S L O
    do {
        if (direcao != "N" && direcao != "S" && direcao != "L" && direcao != "O" && direcao != "NL" && direcao != "NO" && direcao != "SL" && direcao != "SO"){
            printf("Direção não reconhecida para a rainha");
            break;
        }
        if (direcao == "N"){
            printf("\nCima");
        } else if (direcao == "S"){
            printf("\nBaixo");
        } else if (direcao == "L"){
            printf("\nDireita");
        } else if (direcao == "O"){
            printf("\nEsquerda");
        } else if (direcao == "NL"){
            printf("\nCima, Direita");
        } else if (direcao == "NO"){
            printf("\nCima, Esquerda");
        } else if (direcao == "SL"){
            printf("\nBaixo, Direita");
        } else if (direcao == "SO"){
            printf("\nBaixo, Esquerda");
        }
        ncasasandar--;
    } while (ncasasandar > 0);
}

void MoverBispo(char *direcao, int ncasasandar, char *initialPosition){
    while (ncasasandar--) {
        if (direcao != "NL" && direcao != "NO" && direcao != "SL" && direcao != "SO"){
            printf("Direção não reconhecida para o bispo");
            break;
        }
        if (direcao == "NL"){
            printf("\nCima, Direita");
        } else if (direcao == "NO"){
            printf("\nCima, Esquerda");
        } else if (direcao == "SL"){
            printf("\nBaixo, Direita");
        } else if (direcao == "SO"){
            printf("\nBaixo, Esquerda");
        }
    }
}

void MoveTorre(char *direcao, int ncasasandar, char *initialPosition){
    for (int i = ncasasandar; i > 0; i--){
        if (direcao != "N" && direcao != "S" && direcao != "L" && direcao != "O"){
            printf("Direção não reconhecida");
            break;
        }
        if (direcao == "N"){
            printf("\nCima");
        } else if (direcao == "S"){
            printf("\nBaixo");
        } else if (direcao == "L"){
            printf("\nDireita");
        } else if (direcao == "O"){
            printf("\nEsquerda");
        }
    }
}

void MoveCavalo(char *direcao1, int ncasasandar1, char *direcao2, int ncasasandar2, char *initialPosition){
    if (direcao1 != "N" && direcao1 != "S" && direcao1 != "L" && direcao1 != "O"){
        printf("\nDireção não reconhecida para direção 1");
        return;
    }
    if (direcao2 != "N" && direcao2 != "S" && direcao2 != "L" && direcao2 != "O"){
        printf("\nDireção não reconhecida para direção 2");
        return;
    }
    if ((ncasasandar1 + ncasasandar2) != 3){
        printf("\nO número de casas andadas não foi 3");
        return;
    }
    while(ncasasandar1--){
        if (direcao1 == "N"){
            printf("\nCima");
        } else if (direcao1 == "S"){
            printf("\nBaixo");
        } else if (direcao1 == "L"){
            printf("\nDireita");
        } else if (direcao1 == "O"){
            printf("\nEsquerda");
        }
    }
    while(ncasasandar2--){
        if (direcao2 == "N"){
            printf("\nCima");
        } else if (direcao2 == "S"){
            printf("\nBaixo");
        } else if (direcao2 == "L"){
            printf("\nDireita");
        } else if (direcao2 == "O"){
            printf("\nEsquerda");
        }
    }
}

int main() {
    setlocale(LC_ALL, "utf-8");
    MoverRainha("O", 8, "");
    printf("\n");
    MoverBispo("NL", 5, "");
    printf("\n");
    MoveTorre("L", 5, "");
    printf("\n");
    MoveCavalo("S", 2, "O", 1, "");
    
    
    // Nível Novato - Movimentação das Peças
    // Sugestão: Declare variáveis constantes para representar o número de casas que cada peça pode se mover.

    // Implementação de Movimentação do Bispo
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação do Bispo em diagonal.

    // Implementação de Movimentação da Torre
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação da Torre para a direita.

    // Implementação de Movimentação da Rainha
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação da Rainha para a esquerda.

    // Nível Aventureiro - Movimentação do Cavalo
    // Sugestão: Utilize loops aninhados para simular a movimentação do Cavalo em L.
    // Um loop pode representar a movimentação horizontal e outro vertical.

    // Nível Mestre - Funções Recursivas e Loops Aninhados
    // Sugestão: Substitua as movimentações das peças por funções recursivas.
    // Exemplo: Crie uma função recursiva para o movimento do Bispo.

    // Sugestão: Implemente a movimentação do Cavalo utilizando loops com variáveis múltiplas e condições avançadas.
    // Inclua o uso de continue e break dentro dos loops.

    return 0;
}
