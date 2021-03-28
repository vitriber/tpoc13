#include "Bloc.hpp"

#include <iostream>

namespace Components{

	Bloc::Bloc(){
		this->m_bitDirty = false;
		this->m_bitValid = false;
		this->m_tag = 0;

		m_bloc = new words(kbloc_size);
		unsigned int i = 0;
		for(; i<kbloc_size; i++){
			Word* word = new Word();
			this->m_bloc->at(i) = word;
		}

	}

	Bloc::~Bloc(){
		unsigned int i = 0;
		for(; i < m_bloc->size(); i++) {
			delete m_bloc->at(i);
		}
		m_bloc->clear();
		delete m_bloc;
	}

	bool Bloc::getDirtyBit(){
		return this->m_bitDirty;
	}
	
	void Bloc::setDirtyBit(bool p_sujo){
		this->m_bitDirty = p_sujo;
	}

	bool Bloc::getValidBit(){
		return this->m_bitValid;
	}

	void Bloc::setValidBit(bool p_bitValid){
		this->m_bitValid = p_bitValid;
	}

	const unsigned int Bloc::getTag() {
		return this->m_tag;
	}

	void Bloc::setTag(const unsigned int p_tag){
		this->m_tag = p_tag;
	}

	words* Bloc::getBloc(){
		return this->m_bloc;
	}

	void Bloc::setBloc(words* p_bloc){
		this->m_bloc = p_bloc;
	}

	void Bloc::setBloc(Bloc* p_bloc) {
		this->m_bitDirty = p_bloc->getDirtyBit();
		this->m_bitValid = p_bloc->getValidBit();
		this->m_tag = p_bloc->getTag();

		unsigned int i = 0;
		for(; i < m_bloc->size(); i++) {
			m_bloc->at(i)->setWord(p_bloc->getBloc()->at(i)->getWord());
		}
	}
}