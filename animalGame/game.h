
#ifndef _GAME_
#define _GAME_

#include <string>
#include <iostream>
#include "decisionTree.h"



class Game {
    public:
	Game();
	
	void openFile(const string& filename);
	
	void saveFile(const string& filename) const;
	
	void askQuestion();
	
	void checkAnimal();
    private:
	void win();
	
	void lose();
	
	void addAnimal();
	
	void addQuestion();
	
	DecisionTree tree;
	string address;
};

#endif