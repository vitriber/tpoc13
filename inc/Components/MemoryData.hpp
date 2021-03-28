#ifndef MEMORYDATA_H
#define MEMORYDATA_H

#include "Block.hpp"

using namespace std;

namespace Components {
	class MemoryData {
		private:
			const int m_block_in(const int p_pos);
			vector<Block*>* m_dados;

		public:
			MemoryData();
			~MemoryData();
			Block* read(const int p_pos);
			void write(Block* p_block);
			static const int kmendata_size = 256;
	};
}

#endif