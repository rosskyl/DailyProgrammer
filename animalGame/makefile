

EXE=prog
CC=g++
OBJECTS=main.o decisionTree.o game.o

$(EXE):		$(OBJECTS)
		$(CC) -o $(EXE) $(OBJECTS)
		
main.o: 	main.cpp decisionTree.h binaryTree.h game.h
		$(CC) -c main.cpp
		
game.o:		game.cpp game.h
		$(CC) -c game.cpp
		
decisionTree.o:	decisionTree.h decisionTree.cpp
		$(CC) -c decisionTree.cpp
		
clean:
		rm -rf $(OBJECTS) *~ $(EXE)

