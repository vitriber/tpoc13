#include <string>
#include <iostream>
#include <fstream>
#include "CPU.hpp"

using namespace std;

int main(int argc, char *argv[]){
	if (argc <= 1) {
		cout << "Por favor insira o arquivo de entrada" << endl;
	}
	else {
		string file = argv[1];
		fstream fs;
		fs.open(file, fstream::in);

		if (fs.is_open()) {
			Components::CPU* cpu = new Components::CPU();
	  		while (!fs.eof()) {
				bool intructionType;
	  			int position;
	  			
	  			fs >> position;
	  			fs >> intructionType;
				  
	  			if (intructionType) {
	  				string data;
	  				fs >> data;
	  				cpu->writeCache(position,data);
	  			}
				else {
	  				cpu->readCache(position);
	  			}
	  		}
	  		cpu->writeFinalFile();
	  		delete cpu;
	  		fs.close();
 		 }
		  else {
    		cout << "Ocorreu um erro ao abrir o arquivo" << endl;
    		fs.close();
    		system("PAUSE");
  		}
	}
	return 0;
}