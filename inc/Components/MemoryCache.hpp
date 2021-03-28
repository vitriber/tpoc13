#ifndef MEMORYCACHE_H	
#define MEMORYCACHE_H

#include <string>
#include <vector>
#include "Block.hpp"
#include "MemoryData.hpp"

using namespace std;

namespace Components {
	class MemoryCache {
		private:
			vector<Block*>* m_blocks;
			MemoryData* m_MD;
			Block* m_read_MD(const int p_pos);
			void m_write_MD(Block* p_block);
			static const int m_calc_tag(const int p_pos);
			static const int m_block_in(const int p_pos);
			static const int m_word_in(const int p_pos);

		public:
			MemoryCache();
			~MemoryCache();
			bool read(const int p_pos);
			void write(const int p_pos, string p_dado);
			static const int kmencache_size = 64;
	};
}

#endif