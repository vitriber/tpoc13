#ifndef MEMORYCACHE_H	
#define MEMORYCACHE_H

#include "Bloc.hpp"
#include "MemoryData.hpp"

#include <string>
#include <vector>

namespace Components{

	class MemCache{
		private:
			blocos* m_blocos;
			MemDados* m_MD;
			Bloc* m_read_MD(const unsigned int p_pos);
			void m_write_MD(Bloc* p_bloc);

			static const unsigned int m_calc_tag(const unsigned int p_pos);
			static const unsigned int m_bloc_in(const unsigned int p_pos);
			static const unsigned int m_word_in(const unsigned int p_pos);
		public:
			static const unsigned int kmencache_size = 64;

			MemCache();
			~MemCache();
			bool read(const unsigned int p_pos);
			void write(const unsigned int p_pos, std::string p_dado);
	};

}

#endif
