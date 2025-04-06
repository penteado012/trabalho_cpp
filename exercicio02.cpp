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
		cout << "Essa mensagem é um dado políndromo.";
	} else {
		cout << "Essa mensagem não é um dado políndromo";
	}
	return 0;
}