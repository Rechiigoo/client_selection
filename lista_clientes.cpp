#include <iostream>
#include <fstream>	
#include <vector>
#include <ctime> 
using namespace std;

vector<string> clientes, escogidos;

bool found(vector<string> w, string s){
	bool found = false;
	for(auto it = w.begin(); it != w.end() && !found; it++){
		found = *it == s;
	}
	return found;
}

/*
* @brief Devuelve el correo de 10 clientes aleatoriamente de manera randomizada según
correos dados
* @param argv correos de los clientes
* @ret correos de los clientes
* How to compile: g++ -std=c++11 -o lista_clientes lista_clientes.cpp
* How to use: ./lista_clientes [text file]
*/
int main(int argc, char ** argv){
	if(argc != 2){
		cout << "Debes poner el fichero de correos para leer." << endl;
		cout << "Uso del archivo: ./lista_clientes [posibles_clientes.txt]" << endl;
		return 1;
	}
	else{
    	ifstream inputFile(argv[1]);

    	if (!inputFile) {
        	std::cerr << "Error: Unable to open the file." << std::endl;
        	return 1;
    	}

		string client;
		while(inputFile >> client){
			clientes.push_back(client);
		}
		
		inputFile.close();

		ofstream outfile("clients.txt");
		streambuf *coutbuf = cout.rdbuf();
		cout.rdbuf(outfile.rdbuf());
		cout << "//////////////////////////////////////////////" << endl;
		cout << "Clients selected for this commission opening:" << endl;
		cout << "//////////////////////////////////////////////" << endl;

		int slot;
		std::srand(static_cast<unsigned int>(std::time(nullptr)));
		for(int i=0; i < 10; i++){
			slot = rand() % clientes.size();
			if(!found(escogidos, clientes[slot]))
				escogidos.push_back(clientes[slot]);
		}

		for(auto cl : escogidos){
			cout << cl << endl;
		}

		cout.rdbuf(coutbuf);

		cout << "Process finished." << endl;
	}
		
}
