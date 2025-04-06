#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

string formatarBibliografico(string nomeCompleto) {
    istringstream iss(nomeCompleto);
    vector<string> partes;
    string palavra;

    while (iss >> palavra) {
        partes.push_back(palavra);
    }

    if (partes.size() == 0) return "";

    string sobrenome = partes.back();
    partes.pop_back();

    for (size_t i = 0; i < sobrenome.size(); i++) {
    sobrenome[i] = static_cast<char>(toupper(static_cast<unsigned char>(sobrenome[i])));
	}


    string resultado = sobrenome + ", ";

    if (!partes.empty()) {
        resultado += partes[0];
    }

    for (size_t i = 1; i < partes.size(); i++) {
        resultado += " ";
        resultado += static_cast<char>(toupper(static_cast<unsigned char>(partes[i][0])));
        resultado += ".";
    }

    return resultado;
}

int main() {
    ifstream arquivo("nomes.txt");
    if (!arquivo) {
        cerr << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }

    string linha;
    while (getline(arquivo, linha)) {
        cout << formatarBibliografico(linha) << endl;
    }

    arquivo.close();
    return 0;
}
