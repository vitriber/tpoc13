#ifndef CPU_H
#define CPU_H
#include <string>
#include <fstream> 
#include <iostream>
#include <iomanip>
#include <cstring>
#include "MemoryCache.hpp"

namespace Components{
	class CPU{
	private:
		static constexpr const char* nameFinalFile = "./output/result.txt";
		static constexpr const char* nameTempFile  = "./output/resultTemp.txt";

		void writeTempFile(std::string line);
		Components::MemCache* memCache;
		unsigned int readings;
		unsigned int writings;
		unsigned int misses;
		unsigned int hits;	
		bool flag;
	public:
		void readCache(unsigned int position);
		void writeCache(unsigned int position, std::string data);
		void writeFinalFile();
		~CPU();
		CPU();
	};
	
}

#endif