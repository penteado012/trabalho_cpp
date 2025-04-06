#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

// Função para posicionar o cursor no console
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    string mensagem;

    cout << "Digite uma mensagem: ";
    getline(cin, mensagem);

    int larguraTela = 80;
    int colunaInicial = (larguraTela - mensagem.length()) / 2;

    // Mostra a mensagem na linha 5, centralizada
    gotoxy(colunaInicial, 5);
    cout << mensagem;

    Sleep(1000); // Espera 1 segundo antes da animação

    // Faz cada letra cair até a linha 20
    for (int i = 0; i < mensagem.length(); i++) {
        for (int linha = 5; linha < 20; linha++) {
            gotoxy(colunaInicial + i, linha);
            cout << mensagem[i];
            Sleep(200);
            gotoxy(colunaInicial + i, linha); // Apaga a anterior
            cout << ' ';
        }
        // Escreve na linha final
        gotoxy(colunaInicial + i, 20);
        cout << mensagem[i];
    }

    gotoxy(0, 22); // Move o cursor pra baixo no final
    return 0;
}
