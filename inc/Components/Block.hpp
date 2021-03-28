#ifndef BLOCK_H
#define BLOCK_H

#include "Word.hpp"
#include <vector>

using namespace std;

namespace Components{

typedef vector<Word*> words;
	class Block{
		private:
			bool m_bitValid;
			bool m_bitDirty;
			int m_tag;
			words* m_block;

		public:
			Block();
			~Block();
			static const int kblock_size = 4;
			bool getDirtyBit();
			void setDirtyBit(bool p_bitDirty);
			bool getValidBit();
			void setValidBit(bool p_bitValid);
			const int getTag();
			void setTag(const int p_tag);
			words* getBlock();
			void setBlock(words* p_block);
			void setBlock(Block* p_block); 
	};
}

#endif