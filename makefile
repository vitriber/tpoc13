all: tp03 clean

tp03: block.o cpu.o memoryCache.o memoryData.o word.o main.o
	g++ -w block.o cpu.o memoryCache.o memoryData.o word.o main.o -o tp03

block.o: Block.cpp Block.hpp Word.cpp Word.hpp
	g++ -w -c Block.cpp Block.hpp Word.cpp Word.hpp

cpu.o: CPU.cpp CPU.hpp MemoryCache.hpp MemoryCache.cpp Block.cpp Block.hpp Word.cpp Word.hpp MemoryData.cpp MemoryData.hpp
	g++ -w -c CPU.cpp CPU.hpp MemoryCache.hpp MemoryCache.cpp Block.cpp Block.hpp Word.cpp Word.hpp MemoryData.cpp MemoryData.hpp

memoryCache.o: MemoryCache.cpp MemoryCache.hpp Block.cpp Block.hpp Word.cpp Word.hpp MemoryData.cpp MemoryData.hpp
	g++ -w -c MemoryCache.cpp MemoryCache.hpp Block.cpp Block.hpp Word.cpp Word.hpp MemoryData.cpp MemoryData.hpp

memoryData.o: MemoryData.cpp MemoryData.hpp Block.cpp Block.hpp Word.cpp Word.hpp
	g++ -w -c MemoryData.cpp MemoryData.hpp Block.cpp Block.hpp Word.cpp Word.hpp

word.o: Word.cpp Word.hpp
	g++ -w -c Word.cpp Word.hpp

main.o: CPU.cpp CPU.hpp MemoryCache.hpp MemoryCache.cpp Block.cpp Block.hpp Word.cpp Word.hpp MemoryData.cpp MemoryData.hpp
	g++ -w -c CPU.cpp CPU.hpp MemoryCache.hpp MemoryCache.cpp Block.cpp Block.hpp Word.cpp Word.hpp MemoryData.cpp MemoryData.hpp

clean:
	rm block.o cpu.o memoryCache.o memoryData.o word.o main.o