#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

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

    gotoxy(colunaInicial, 5);
    cout << mensagem;

    Sleep(1000);

    for (int i = 0; i < mensagem.length(); i++) {
        for (int linha = 5; linha < 20; linha++) {
            gotoxy(colunaInicial + i, linha);
            cout << mensagem[i];
            Sleep(200);
            gotoxy(colunaInicial + i, linha);
            cout << ' ';
        }
        // Escreve na linha final
        gotoxy(colunaInicial + i, 20);
        cout << mensagem[i];
    }

    gotoxy(0, 22);
    return 0;
}
