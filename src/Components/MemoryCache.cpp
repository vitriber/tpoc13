#include "MemoryCache.hpp"
#include <iostream>

using namespace std;

namespace Components {
	MemoryCache::MemoryCache() {
		m_MD = new MemoryData();

		m_blocks = new vector<Block*>(kmencache_size);
		unsigned int i = 0;
		for (; i < m_blocks->size(); i++) {
			m_blocks->at(i) = new Block();
		}
	}

	MemoryCache::~MemoryCache() {
		unsigned int i = 0;
		for(; i < m_blocks->size(); i++) {
			delete m_blocks->at(i);
		}
		m_blocks->clear();

		delete m_blocks;
		delete m_MD;
	}

	bool MemoryCache::read(const int p_pos) {
		bool hit = false;
		const int pos_blocko = m_block_in(p_pos);

		Block* bloco_atual = m_blocks->at(pos_blocko);

		if (bloco_atual->getValidBit()) {
			if(bloco_atual->getTag() == m_calc_tag(p_pos)) {
				hit = true;
			} 
			else {
				hit = false;
			}
		}
		else {
			hit = false;
		}

		if(!hit) {
			bloco_atual->setBlock(m_read_MD(p_pos));
		}
		
		return hit;
	}

	void MemoryCache::write(const int p_pos, string p_dado) {
		const int pos_blocko = m_block_in(p_pos);

		bool hit = false; 
		Block* bloco_atual = m_blocks->at(pos_blocko);

		if (!bloco_atual->getValidBit()) { 
			bloco_atual->setValidBit(true);
		}
		else if (!bloco_atual->getDirtyBit() == m_calc_tag(p_pos)) {
			if (bloco_atual->getTag() == pos_blocko) {
				bloco_atual->setDirtyBit(true);
				hit = true;
			}
		}

		else { 
			if (bloco_atual->getTag() == m_calc_tag(p_pos)) {
				hit = true;
			}
			else { 
				m_write_MD(bloco_atual); 
			}
		}

		if (!hit) {
			bloco_atual->setBlock(m_read_MD(p_pos));
			bloco_atual->setDirtyBit(false);
		}
	}

	Block* MemoryCache::m_read_MD(const int p_pos) {
		return m_MD->read(p_pos);
	}

	void MemoryCache::m_write_MD(Block* p_block) {
		m_MD->write(p_block);
	}

	const int MemoryCache::m_block_in(const int p_pos) {
		return (m_calc_tag(p_pos)) % kmencache_size;
	}

	const int MemoryCache::m_word_in(const int p_pos) {
		return p_pos % Block::kblock_size;
	}

	const int MemoryCache::m_calc_tag(const int p_pos) {
		return ((int) (p_pos / Block::kblock_size));
	}
}