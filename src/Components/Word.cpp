#include "Word.hpp"

namespace Components{

	Word::Word(){
		this->word = "";
	}

	std::string Word::getWord(){
		return this->word;
	}

	void Word::setWord(std::string word){
		this->word = word;
	}

}