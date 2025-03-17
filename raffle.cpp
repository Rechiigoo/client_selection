#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

vector<string> participants;
string chosen;

int main(int argc, char ** argv){
	if(argc != 2){
		cout << "Need to have a .txt file as a secondary argument." << endl;
		cout << "Proper file usage: ./raffle [raffle.txt]" << endl;
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
			participants.push_back(client);
		}
		
		inputFile.close();

		cout << "Generating winners, please wait..." << endl;

		ofstream outfile("raffle_winner.txt");
		
		cout << "//////////////////////////////////////////////" << endl;
		cout << "Raffle winner:" << endl;
		cout << "//////////////////////////////////////////////" << endl;


		std::srand(static_cast<unsigned int>(std::time(nullptr)));
		
		int winner = rand() % participants.size();
        int winner2;

        cout << "\nWinner is: " << participants[winner];

        std::srand(static_cast<unsigned int>(std::time(nullptr))+12345);
        winner2 = rand() % participants.size();

        while(participants[winner2] == participants[winner]){
            std::srand(static_cast<unsigned int>(std::time(nullptr))+843588);
            winner2 = rand() % participants.size();
        }
        
        cout << "\nSecond winner is: " << participants[winner2] << endl;

        outfile << "winner 1: " << participants[winner] << endl;
        outfile << "winner 2: " << participants[winner2] << endl;


		cout << "\nProcess finished." << endl;
	}
		
}