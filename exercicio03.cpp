#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

string formatarNome(string nomeCompleto) {
    istringstream iss(nomeCompleto);
    vector<string> partes;
    string palavra;

   
    while (iss >> palavra) {
        partes.push_back(palavra);
    }

    if (partes.size() < 2) return nomeCompleto;

    string sobrenome = partes.back();
    partes.pop_back();

    string nome;
    for (size_t i = 0; i < partes.size(); i++) {
        nome += partes[i];
        if (i != partes.size() - 1) nome += " ";
    }

    return sobrenome + ", " + nome;
}

int main() {
    ifstream arquivo("nomes.txt");
    if (!arquivo) {
        cerr << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }

    string linha;
    while (getline(arquivo, linha)) {
        cout << formatarNome(linha) << endl;
    }

    arquivo.close();
    return 0;
}
