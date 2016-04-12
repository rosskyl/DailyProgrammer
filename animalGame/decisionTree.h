

#ifndef _DECISION_TREE_
#define _DECISION_TREE_

#include <string>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <queue>
#include "binaryTree.h"

using namespace std;

///TODO look at ~/csis352/test.cpp for string operations

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
    private:
	string addressOfNode(const string& item, nodeType<string> *p) const;
};//end class DecisionTree: public binaryTreeType<string>


void DecisionTree::insertByAddress(const string& question, const string& animalName, const string& address) {
    string answers = "";
    
    for (int i = 0; i < address.length(); i+= 2)
	if (address[i] == '1')
	    answers += "n";
	else if (address[i] == '2')
	    answers += "y";
	else
	    throw invalid_argument(address + " is invalid");

    insertByAnswers(question, animalName, answers);
}

void DecisionTree::insertByAnswers(const string& question, const string& animalName, const string& answers = "") {
    char ans = 'e';
    nodeType<string> *p = binaryTreeType<string>::root;
    nodeType<string> *previous;
    
    for (int i = 0; i < answers.length(); i++) {
	ans = answers[i];
	previous = p;
	if ( (ans == 'n') || ans == 'N')
	    p = p->llink;
	else if (ans == 'y' || ans == 'Y' )
	    p = p->rlink;
	else
	    throw invalid_argument(answers + " is invalid");
    }//end for (int i = 0; i < answers.length(); i++)
    
    nodeType<string> *animNode = new nodeType<string>;
    animNode->info = animalName;
    
    nodeType<string> *qNode = new nodeType<string>;
    qNode->info = question;
    qNode->llink = p;
    qNode->rlink = animNode;
    
    if (ans == 'e')
	binaryTreeType<string>::root = qNode;
    else if (ans == 'n' || ans == 'N')
	previous->llink = qNode;
    else
	previous->rlink = qNode;
}

string DecisionTree::addressOf(const string& item) const {
    //need the erase to get rid of the leading :
    return addressOfNode(item, binaryTreeType<string>::root).erase(0,1);
}

string DecisionTree::getByAddress(const string& address) const {
    string answers = "";
    
    for (int i = 0; i < address.length(); i+= 2)
	if (address[i] == '1')
	    answers += "n";
	else if (address[i] == '2')
	    answers += "y";
	else
	    throw invalid_argument(address + " is invalid");
    return getByAnswers(answers);
}

string DecisionTree::getByAnswers(const string& answers) const {
    char ans = 'e';
    nodeType<string> *p = binaryTreeType<string>::root;
    
    for (int i = 0; i < answers.length(); i++) {
	ans = answers[i];
	if ( (ans == 'n') || ans == 'N')
	    p = p->llink;
	else if (ans == 'y' || ans == 'Y' )
	    p = p->rlink;
	else
	    throw invalid_argument(answers + " is invalid");
    }//end for (int i = 0; i < answers.length(); i++)
    return p->info;
}

void DecisionTree::save(const string& filename) const {
    ofstream out;
    queue< nodeType<string>* > q;
    nodeType<string> *p = binaryTreeType<string>::root;
    
    //out.open(filename);
    out.open("animal.txt");
    while (p != NULL) {
	out << addressOf(p->info) << " " << p->info << endl;
	if (p->llink != NULL)
	    q.push(p->llink);
	if (p->rlink != NULL)
	    q.push(p->rlink);
	if (q.empty())
	    p = NULL;
	else {
	    p = q.front();
	    q.pop();
	}
    }
}

string DecisionTree::addressOfNode(const string& item, nodeType<string> *p) const {
    if (p == NULL)
	return "";
    else if (p->info == item)
	return ".0";
    else {
	if (addressOfNode(item, p->llink) == ".0")
	    return ".1";
	else if (addressOfNode(item, p->rlink) == ".0")
	    return ".2";
	else if (addressOfNode(item, p->llink) != "")
	    return ".1" + addressOfNode(item, p->llink);
	else if (addressOfNode(item, p->rlink) != "")
	    return ".2" + addressOfNode(item, p->rlink);
	else
	    return "";
    }
}




#endif
