#include "MemoryCache.hpp"

#include <iostream>

namespace Components {

MemCache::MemCache() {
	m_MD = new MemDados();

	m_blocos = new blocos(kmencache_size);
	unsigned int i = 0;
	for(; i < m_blocos->size(); i++) {
		m_blocos->at(i) = new Bloc();
	}
}


MemCache::~MemCache() {
	unsigned int i = 0;
	for(; i < m_blocos->size(); i++) {
		delete m_blocos->at(i);
	}
	m_blocos->clear();
	delete m_blocos;

	delete m_MD;
}


bool MemCache::read(const unsigned int p_pos) {
	bool hit = false;
	const unsigned int pos_bloco = m_bloc_in(p_pos);

	Bloc* bloco_atual = m_blocos->at(pos_bloco);

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
		bloco_atual->setBloc(m_read_MD(p_pos));
	}
	
	return hit;
}

void MemCache::write(const unsigned int p_pos, std::string p_dado) {

	const unsigned int pos_bloco = m_bloc_in(p_pos);

	bool hit = false; 
	Bloc* bloco_atual = m_blocos->at(pos_bloco);

	if (!bloco_atual->getValidBit()) { 
		bloco_atual->setValidBit(true);
	}
	else if(!bloco_atual->getDirtyBit() == m_calc_tag(p_pos)) {
		if (bloco_atual->getTag() == pos_bloco) {
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
		bloco_atual->setBloc(m_read_MD(p_pos));
		bloco_atual->setDirtyBit(false);
	}
}


Bloc* MemCache::m_read_MD(const unsigned int p_pos) {
		return m_MD->read(p_pos);
}


void MemCache::m_write_MD(Bloc* p_bloc) {
	m_MD->write(p_bloc);
}


const unsigned int MemCache::m_bloc_in(const unsigned int p_pos) {
	return (m_calc_tag(p_pos)) % kmencache_size;
}


const unsigned int MemCache::m_word_in(const unsigned int p_pos) {
	return p_pos % Bloc::kbloc_size;
}


const unsigned int MemCache::m_calc_tag(const unsigned int p_pos) {
	return ((unsigned int) (p_pos / Bloc::kbloc_size));
}

}
