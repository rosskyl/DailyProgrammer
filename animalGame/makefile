

EXE=prog
CC=g++
OBJECTS=main.o
$(EXE):		$(OBJECTS)
		$(CC) -o $(EXE) $(OBJECTS)
		
main.o: 	main.cpp decisionTree.h binaryTree.h 
		$(CC) -c main.cpp
		
clean:
		rm -rf $(OBJECTS) *~ $(EXE)

