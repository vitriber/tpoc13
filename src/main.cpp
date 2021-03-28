#include <string>
#include <iostream>
#include <fstream>
#include "CPU.hpp"
   
int main(int argc, char *argv[]){
	if(argc <= 1){
		std::cout<< "Por favor insira o arquivo de entrada"<<std::endl;
	}
	else{
		std::string file = argv[1];
		std::fstream fs;
		fs.open(file, std::fstream::in);

		if(fs.is_open()){
			Components::CPU* cpu = new Components::CPU();
	  		while(!fs.eof()){

				bool intructionType;
	  			unsigned int position;
	  			
	  			fs>>position;
	  			fs>>intructionType;
				  
	  			if(intructionType){
	  				std::string data;
	  				fs>>data;
	  				cpu->writeCache(position,data);
	  			}else{
	  				cpu->readCache(position);
	  			}
	  		}
	  		cpu->writeFinalFile();
	  		delete cpu;
	  		fs.close();
 		 }else{
    		std::cout<< "Ocorreu um erro ao abrir o arquivo"<<std::endl;
    		fs.close();
    		system("PAUSE");
  		}
	}
	return 0;
}