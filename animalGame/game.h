
#ifndef _GAME_
#define _GAME_

#include <string>
#include <iostream>
#include "decisionTree.h"



class Game {
    public:
	//Name:			openFile
	//Description:		Opens the file at filename
	//Preconditions:	filename must exist in the format
	//				address q:question
	//				address a:animal
	//			only 1 and 2 are allowed, for example 1.2.1
	//			0 is the root question
	//Postconditions:	all the questions and animals in filename are added to the tree
	//Input:		filename(string) can be absolute or relative path
	//Output:		None
	void openFile(const string& filename);
	
	//Name:			saveFile
	//Description:		saves the file at filename
	//Preconditions:	none
	//Postconditions:	all the questions and animals in filename are saved to the file in the format
	//				address q:question
	//				address a:animal
	//			only 1 and 2 are allowed, for example 1.2.1
	//			0 is the root question
	//Input:		filename(string) can be absolute or relative path
	//Output:		None
	void saveFile(const string& filename) const;
	
	//Name:			startGame
	//Description:		Starts the game in an endless loop until the user decides not to play again
	//Preconditoins:	None
	//Postconditions:	None
	//Input:		None
	//Output:		None
	void startGame();
    private:
	//Name:			askQuestion
	//Description:		asks the question at address
	//Preconditoins:	None
	//Postconditions:	address is changed
	//Input:		None
	//Output:		None
	void askQuestion();
	
	//Name:			checkAnimal
	//Description:		Checks the animal at address to see if it is the one the user is thinking of
	//Preconditoins:	None
	//Postconditions:	None
	//Input:		None
	//Output:		None
	void checkAnimal();
	
	//Name:			win
	//Description:		shows the winning message for if the computer wins
	//Preconditoins:	None
	//Postconditions:	None
	//Input:		None
	//Output:		None
	void win();
	
	//Name:			lose
	//Description:		shows the losing message for if the computer loses
	//Preconditoins:	None
	//Postconditions:	None
	//Input:		None
	//Output:		None
	void lose();
	
	//Name:			addAnimal
	//Description:		adds an animal into the tree
	//Preconditoins:	None
	//Postconditions:	animal added into the tree
	//Input:		None
	//Output:		None
	void addAnimal();
	
	//Name:			addQuestion
	//Description:		adds an animal and question into the tree
	//Preconditoins:	None
	//Postconditions:	animal and question added into the tree
	//Input:		None
	//Output:		None
	void addQuestion();
	
	//The tree for all of the questions and animals
	DecisionTree tree;
	
	//The address that the game is currently on
	string address;
};

#endif