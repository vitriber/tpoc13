#include "MemoryData.hpp"

#include <iostream>

namespace Components {

MemDados::MemDados() {
	m_dados = new blocos(kmendata_size);
	unsigned int i = 0;
	for(; i < m_dados->size(); i++) {
		m_dados->at(i) = new Bloc();
		m_dados->at(i)->setTag(i);
		m_dados->at(i)->setValidBit(true);
	}
}

MemDados::~MemDados() {
	unsigned int i = 0;
	for(; i < m_dados->size(); i++) {
		delete m_dados->at(i);
	}
	m_dados->clear();
	
	delete m_dados;
}


Bloc* MemDados::read(const unsigned int p_pos)
{
	const unsigned int pos_bloco = (unsigned int) (p_pos / Bloc::kbloc_size);
	return m_dados->at(pos_bloco);
}


void MemDados::write(Bloc* p_bloc)
{
	p_bloc->setValidBit(true);
	p_bloc->setDirtyBit(false);
	m_dados->at(p_bloc->getTag())->setBloc(p_bloc);
	
}

}