#ifndef BLOC_H
#define BLOC_H

#include "Word.hpp"

#include <vector>

namespace Components{

typedef std::vector<Word*> words;

	class Bloc{
		private:
			bool m_bitValid;
			bool m_bitDirty;
			unsigned int m_tag;

			words* m_bloc;

		public:
			static const unsigned int kbloc_size = 4;

			Bloc();
			~Bloc();

			bool getDirtyBit();
			void setDirtyBit(bool p_bitDirty);
			bool getValidBit();
			void setValidBit(bool p_bitValid);
			const unsigned int getTag();
			void setTag(const unsigned int p_tag);
			words* getBloc();
			void setBloc(words* p_bloc);
			void setBloc(Bloc* p_bloc); 
	};

}

#endif

