
#ifndef _GAME_
#define _GAME_

#include <string>
#include <iostream>
#include "decisionTree.h"



class Game {
    public:
	Game();
    private:
	DecisionTree tree;
	
	string address;
};

#endif