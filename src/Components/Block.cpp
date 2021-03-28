#include "Block.hpp"
#include <iostream>

namespace Components{

	Block::Block() {
		this->m_bitDirty = false;
		this->m_bitValid = false;
		this->m_tag = 0;

		m_block = new words(kblock_size);
		int i = 0;
		for (; i < kblock_size; i++) {
			Word* word = new Word();
			this->m_block->at(i) = word;
		}
	}

	Block::~Block() {
		int i = 0;
		for (; i < m_block->size(); i++) {
			delete m_block->at(i);
		}
		m_block->clear();
		delete m_block;
	}

	bool Block::getDirtyBit(){
		return this->m_bitDirty;
	}
	
	void Block::setDirtyBit(bool p_sujo){
		this->m_bitDirty = p_sujo;
	}

	bool Block::getValidBit(){
		return this->m_bitValid;
	}

	void Block::setValidBit(bool p_bitValid){
		this->m_bitValid = p_bitValid;
	}

	const int Block::getTag() {
		return this->m_tag;
	}

	void Block::setTag(const int p_tag){
		this->m_tag = p_tag;
	}

	words* Block::getBlock(){
		return this->m_block;
	}

	void Block::setBlock(words* p_block){
		this->m_block = p_block;
	}

	void Block::setBlock(Block* p_block) {
		this->m_bitDirty = p_block->getDirtyBit();
		this->m_bitValid = p_block->getValidBit();
		this->m_tag = p_block->getTag();

		int i = 0;
		for(; i < m_block->size(); i++) {
			m_block->at(i)->setWord(p_block->getBlock()->at(i)->getWord());
		}
	}
}