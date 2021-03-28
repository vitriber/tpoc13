#include "CPU.hpp"

using namespace std;

namespace Components{
	CPU::CPU() {
		this->nameFinalFile = "./output/result.txt";
		this->nameTempFile = "./output/resultTemp.txt";
		this->readings=0;
		this->writings=0;
		this->misses=0;
		this->hits=0;
		this->flag = true;
		this->MemoryCache = new Components::MemoryCache();
	}

	CPU::~CPU(){
		delete this->MemoryCache;
	}

	void CPU::readCache(int position){
		this->readings++;
		bool hit = this->MemoryCache->read(position);
		if (hit) {
			this->hits++;
		}
		else {
			this->misses++;
		}
		string line = to_string(position);
		line.append(" 0 ");
		if (hit) {
			line.append("H");
		}
		else {
			line.append("M");
		}
		writeTempFile(line);
	}

	void CPU::writeCache(int position, string data){
		this->writings++;
		this->MemoryCache->write(position,data);

		string line = to_string(position);
		line.append(" 1 ");
		line.append(data);
		line.append(" W");
		writeTempFile(line);
	}

	void CPU::writeTempFile(string line){
		fstream exit;
		exit.open(nameTempFile, ofstream::app);
		if (exit.is_open()) {
			exit << line << endl;
			exit.close();
		}
		else {
			cout << "Nao foi possivel abrir o arquivo temporario" << endl;
		}
	}

	void CPU::writeFinalFile(){
		fstream exit, tempFile;
		exit.open(nameFinalFile, ofstream::out);
		if (exit.is_open()) {
			double hitRate = ((double)this->hits)/(this->readings);
			double missRate = ((double)this->misses)/this->readings;
			exit << "READS: " << this->readings << endl;
			exit << "WRITES: " << this->writings << endl;
			exit << "HITS: " << this->hits << endl;
			exit << "MISSES: " << this->misses << endl;
			exit << "HIT RATE: " << fixed<< setprecision(3) << hitRate << endl;
			exit << "MISS RATE: " << fixed<< setprecision(3) << missRate << endl;
			exit << endl;

			tempFile.open(nameTempFile, ofstream::in);
			if(tempFile.is_open()){
				string line;
				while (getline(tempFile, line)) {
				exit<<line<<endl;
				}
				tempFile.close();
				remove(this->nameTempFile);
			}
			else {
				cout << "Nao foi possivel abrir o arquivo temporario" << endl;
			}
			
			exit.close();
		}
		else {
			cout << "Nao foi possivel abrir o arquivo final" << endl;
		}
	}
}