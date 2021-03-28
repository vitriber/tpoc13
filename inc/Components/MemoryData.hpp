#ifndef MEMDADOS_H
#define MEMDADOS_H

#include "Bloc.hpp"

namespace Components {

typedef std::vector<Bloc*> blocos;

	class MemDados {
		private:
			const unsigned int m_bloc_in(const unsigned int p_pos);

			blocos* m_dados;
		public:
			static const unsigned int kmendata_size = 256;

			MemDados();
			~MemDados();

			Bloc* read(const unsigned int p_pos);
			void write(Bloc* p_bloc);
	};

}

#endif
