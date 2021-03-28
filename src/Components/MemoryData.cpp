#include "MemoryData.hpp"

#include <iostream>

namespace Components {
	MemoryData::MemoryData() {
		m_dados = new vector<Block*>(kmendata_size);
		int i = 0;
		for(; i < m_dados->size(); i++) {
			m_dados->at(i) = new Block();
			m_dados->at(i)->setTag(i);
			m_dados->at(i)->setValidBit(true);
		}
	}

	MemoryData::~MemoryData() {
		int i = 0;
		for (; i < m_dados->size(); i++) {
			delete m_dados->at(i);
		}
		m_dados->clear();
		
		delete m_dados;
	}

	Block* MemoryData::read(const int p_pos) {
		const int pos_blocko = (int) (p_pos / Block::kblock_size);
		return m_dados->at(pos_blocko);
	}

	void MemoryData::write(Block* p_block) {
		p_block->setValidBit(true);
		p_block->setDirtyBit(false);
		m_dados->at(p_block->getTag())->setBlock(p_block);	
	}
}