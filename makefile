# Variables
CC=g++
CFLAGS=-Wall -g
EXEC=./tp3 
BUILDING=./build/
SRC=./src/
INCLUDE=./inc/
COMP=Components/

# Variable expansions
OBJECT:=$(patsubst $(SRC)%cpp, $(BUILDING)%o, $(wildcard $(SRC)$(COMP)*.cpp))
OBJ_COMPIL_COMMAND=$(CC) $(CFLAGS) -I $(INCLUDE)$(COMP) -c $< -o $@

# Rules
$(EXEC):	$(BUILDING)main.o
	$(CC) $(CFLAGS) -o $(EXEC) $(BUILDING)main.o $(BUILDING)$(COMP)*.o 

$(BUILDING)$(COMP) ::
	@-mkdir --parents $@

$(BUILDING)main.o:	$(BUILDING)$(COMP) $(SRC)main.cpp $(OBJECT)
	$(CC) $(CFLAGS) -I $(INCLUDE)$(COMP) -c $(SRC)main.cpp -o $(BUILDING)main.o

$(BUILDING)%.o :: $(SRC)%.cpp $(INCLUDE)%.hpp
	$(OBJ_COMPIL_COMMAND)
