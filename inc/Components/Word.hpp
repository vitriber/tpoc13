#ifndef PALAVRA_H
#define PALAVRA_H

#include <string>

using namespace std;

namespace Components{

	class Word{
		private:
			string word;

		public:
			Word();
			string getWord();
			void setWord(string word);
	};
}

#endif