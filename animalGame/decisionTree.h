

#ifndef _DECISION_TREE_
#define _DECISION_TREE_

#include <string>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <queue>
#include "binaryTree.h"

using namespace std;

///left is no, right is yes
class DecisionTree: public binaryTreeType<string> {
    public:
	//question that moves the animal at address to the no part of address and animalName goes into the yes
	void insertByAddress(const string& question, const string& animalName, const string& address);
	
	//goes down the tree based off of the answers and puts question into the result and puts what was there into the no part
	//and the animal into the yes part
	void insertByAnswers(const string& question, const string& animalName, const string& answers);
	
	string addressOf(const string& item) const;
	
	string getByAddress(const string& address) const;
	
	string getByAnswers(const string& answers) const;
	
	void save(const string& filename) const;
	
	void open(const string& filename);
    private:
	string addressOfNode(const string& item, nodeType<string> *p) const;
	
	void insertByAddressQuestion(const string& question, const string& address);
	
	void insertByAnswersQuestion(const string& question, const string& answers);
};//end class DecisionTree: public binaryTreeType<string>

#endif
