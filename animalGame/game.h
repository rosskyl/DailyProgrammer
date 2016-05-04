
#ifndef _GAME_
#define _GAME_

#include <string>
#include <iostream>
#include "decisionTree.h"



class Game {
    public:
	void openFile(const string& filename);
	
	void saveFile(const string& filename) const;
	
	void startGame();
    private:
	void askQuestion();
	
	void checkAnimal();
	
	void win();
	
	void lose();
	
	void addAnimal();
	
	void addQuestion();
	
	DecisionTree tree;
	string address;
};

#endif