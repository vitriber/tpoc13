all: tp03 clean

tp03: block.o cpu.o memoryCache.o memoryData.o word.o main.o
	g++ -w block.o cpu.o memoryCache.o memoryData.o word.o main.o -o tp03

block.o: ./src/Components/Block.cpp ./inc/Components/Block.hpp ./src/Components/Word.cpp ./inc/Components/Word.hpp
	g++ -w -c ./src/Components/Block.cpp ./inc/Components/Block.hpp ./src/Components/Word.cpp ./inc/Components/Word.hpp

cpu.o: ./src/Components/CPU.cpp ./inc/Components/CPU.hpp ./inc/Components/MemoryCache.hpp ./src/Components/MemoryCache.cpp ./src/Components/Block.cpp ./inc/Components/Block.hpp ./src/Components/Word.cpp ./inc/Components/Word.hpp ./src/Components/MemoryData.cpp ./inc/Components/MemoryData.hpp
	g++ -w -c ./src/Components/CPU.cpp ./inc/Components/CPU.hpp ./inc/Components/MemoryCache.hpp ./src/Components/MemoryCache.cpp ./src/Components/Block.cpp ./inc/Components/Block.hpp ./src/Components/Word.cpp ./inc/Components/Word.hpp ./src/Components/MemoryData.cpp ./inc/Components/MemoryData.hpp

memoryCache.o: ./src/Components/MemoryCache.cpp ./inc/Components/MemoryCache.hpp ./src/Components/Block.cpp ./inc/Components/Block.hpp ./src/Components/Word.cpp ./inc/Components/Word.hpp ./src/Components/MemoryData.cpp ./inc/Components/MemoryData.hpp
	g++ -w -c ./src/Components/MemoryCache.cpp ./inc/Components/MemoryCache.hpp ./src/Components/Block.cpp ./inc/Components/Block.hpp ./src/Components/Word.cpp ./inc/Components/Word.hpp ./src/Components/MemoryData.cpp ./inc/Components/MemoryData.hpp

memoryData.o: ./src/Components/MemoryData.cpp ./inc/Components/MemoryData.hpp ./src/Components/Block.cpp ./inc/Components/Block.hpp ./src/Components/Word.cpp ./inc/Components/Word.hpp
	g++ -w -c ./src/Components/MemoryData.cpp ./inc/Components/MemoryData.hpp ./src/Components/Block.cpp ./inc/Components/Block.hpp ./src/Components/Word.cpp ./inc/Components/Word.hpp

word.o: ./src/Components/Word.cpp ./inc/Components/Word.hpp
	g++ -w -c ./src/Components/Word.cpp ./inc/Components/Word.hpp

main.o: ./src/Components/CPU.cpp ./inc/Components/CPU.hpp ./inc/Components/MemoryCache.hpp ./src/Components/MemoryCache.cpp ./src/Components/Block.cpp ./inc/Components/Block.hpp ./src/Components/Word.cpp ./inc/Components/Word.hpp ./src/Components/MemoryData.cpp ./inc/Components/MemoryData.hpp ./src/main.cpp
	g++ -w -c ./src/Components/CPU.cpp ./inc/Components/CPU.hpp ./inc/Components/MemoryCache.hpp ./src/Components/MemoryCache.cpp ./src/Components/Block.cpp ./inc/Components/Block.hpp ./src/Components/Word.cpp ./inc/Components/Word.hpp ./src/Components/MemoryData.cpp ./inc/Components/MemoryData.hpp ./src/main.cpp

clean:
	rm block.o cpu.o memoryCache.o memoryData.o word.o main.o Block.hpp.gch CPU.hpp.gch MemoryCache.hpp.gch MemoryData.hpp.gch Word.hpp.gch