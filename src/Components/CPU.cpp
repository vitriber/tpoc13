#include "CPU.hpp"

namespace Components{

	CPU::~CPU(){
		delete this->memCache;
	}

	CPU::CPU(){
		this->readings=0;
		this->writings=0;
		this->misses=0;
		this->hits=0;
		this->flag = true;
		this->memCache = new Components::MemCache();
	}

	void CPU::readCache(unsigned int position){
		this->readings++;
		bool hit = this->memCache->read(position);
		if(hit){
			this->hits++;
		} else{
			this->misses++;
		}
		std::string line = std::to_string(position);
		line.append(" 0 ");
		if(hit){
			line.append("H");
		}else{
			line.append("M");
		}
		writeTempFile(line);
	}

	void CPU::writeCache(unsigned int position, std::string data){
		this->writings++;
		this->memCache->write(position,data);

		std::string line = std::to_string(position);
		line.append(" 1 ");
		line.append(data);
		line.append(" W");
		writeTempFile(line);
	}

	void CPU::writeTempFile(std::string line){
		std::fstream saida;
		saida.open(nameTempFile, std::ofstream::app);
		if(saida.is_open()){
			saida<<line<<std::endl;
			saida.close();
		}else{
			std::cout<<"Não foi possivel abrir o arquivo temporario"<<std::endl;
		}
		
	}

	void CPU::writeFinalFile(){
		std::fstream saida, arqTemp;
		saida.open(nameFinalFile, std::ofstream::out);
		if(saida.is_open()){
			double hitRate = ((double)this->hits)/(this->readings);
			double missRate = ((double)this->misses)/this->readings;
			saida<<"READS: "<<this->readings<<std::endl;
			saida<<"WRITES: "<<this->writings<<std::endl;
			saida<<"HITS: "<<this->hits<<std::endl;
			saida<<"MISSES: "<<this->misses<<std::endl;
			saida<<"HIT RATE: "<<std::fixed<<std::setprecision(3)<<hitRate<<std::endl;
			saida<<"MISS RATE: "<<std::fixed<<std::setprecision(3)<<missRate<<std::endl;
			saida<<std::endl;

			arqTemp.open(nameTempFile, std::ofstream::in);
			if(arqTemp.is_open()){
				std::string line;
				while (std::getline(arqTemp, line)) {
				saida<<line<<std::endl;
				}
				arqTemp.close();
				remove(nameTempFile);
			}else{
				std::cout<<"Não foi possivel abrir o arquivo temporario"<<std::endl;
			}
			
			saida.close();
		}else{
			std::cout<<"Não foi possivel abrir o arquivo final"<<std::endl;
		}
	}
}