#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	string msg, msginvertida;
	
	cout << "Digite uma palavra: " << endl;
	getline(cin, msg);
	
	msg.erase(remove(msg.begin(), msg.end(), ' '), msg.end());
	msginvertida = msg;
	
	reverse(msg.begin(), msg.end());
	
	if(msg == msginvertida) {
		cout << "Essa mensagem � um dado pol�ndromo.";
	} else {
		cout << "Essa mensagem n�o � um dado pol�ndromo";
	}
	return 0;
}