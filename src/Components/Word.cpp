#include "Word.hpp"

using namespace std;

namespace Components{
	Word::Word() {
		this->word = "";
	}

	string Word::getWord(){
		return this->word;
	}

	void Word::setWord(string word) {
		this->word = word;
	}
}