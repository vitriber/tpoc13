#ifndef CPU_H
#define CPU_H
#include <string>
#include <fstream> 
#include <iostream>
#include <iomanip>
#include <cstring>
#include "MemoryCache.hpp"

using namespace std;

namespace Components {
	class CPU {
		private:
			static constexpr const char* nameFinalFile = "./output/result.txt";
			static constexpr const char* nameTempFile = "./output/resultTemp.txt";

			void writeTempFile(string line);
			Components::MemoryCache* MemoryCache;
			int readings;
			int writings;
			int misses;
			int hits;
			bool flag;

		public:
			CPU();
			~CPU();
			void readCache(int position);
			void writeCache(int position, string data);
			void writeFinalFile();
	};
}

#endif