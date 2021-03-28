#ifndef PALAVRA_H
#define PALAVRA_H

#include <string>

namespace Components{

	class Word{
		private:
			std::string word;
		public:
			Word();

			std::string getWord();
			void setWord(std::string word);
	};

}

#endif

