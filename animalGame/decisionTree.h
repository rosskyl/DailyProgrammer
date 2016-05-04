

#ifndef _DECISION_TREE_
#define _DECISION_TREE_

#include <string>
#include <iostream>
#include <stdexcept>
#include <fstream>

#include "binaryTree.h"

using namespace std;

//left is no, right is yes
//1 is no, 2 is yes
//root is at 0-not included in anything
class DecisionTree: public binaryTreeType<string> {
    public:
	//Name:			insertByAddress
	//Description:		inserts question into the address and moves what was there to the no part of question
	//			and puts answer into the yes part of question
	//Preconditions:	None
	//Postconditions:	Question, answer added and what was in address is moved down a level
	//Input:		question(string)
	//			answer(string)
	//			address(string in the format of 1.1.2.2 (only 1 and 2 allowed)
	//Output:		None
	//Throws:		invalid_argument if address is an invalid address (things other than 1 and 2 or not a valid node)
	void insertByAddress(const string& question, const string& answer, const string& address) throw (invalid_argument);
	
	//Name:			insertByAnswers
	//Description:		Finds the address that the answers would lead to and inserts inserts question 
	//			into the address and moves what was there to the no part of question
	//			and puts answer into the yes part of question
	//Preconditions:	None
	//Postconditions:	Question, answer added and what was in address is moved down a level
	//Input:		question(string)
	//			answer(string)
	//			answers(string in the format of ynynnn (only y and n allowed)
	//Output:		None
	//Throws:		invalid_argument if answers is an invalid address (things other than y and n or not a valid node)
	void insertByAnswers(const string& question, const string& answer, const string& answers) throw (invalid_argument);
	
	//Name:			addressOf
	//Description:		finds the address of item in the format of 1.2.2.1
	//Preconditions:	item is in the tree
	//Postconditions:	None
	//Input:		item(string)
	//Output:		string in the format of 1.2.1 (only 1 and 2)
	string addressOf(const string& item) const;
	
	//Name:			getByAddress
	//Description:		gets the item at address
	//Preconditions:	Address exists
	//Postconditions:	None
	//Input:		address(string in the format of 1.1.2.2 (only 1 and 2 allowed)
	//Output:		string item
	//Throws:		invalid_argument if address is an invalid address (things other than 1 and 2 or not a valid node)
	string getByAddress(const string& address) const throw (invalid_argument);
	
	//Name:			getByAnswers
	//Description:		Finds the address that the answers would lead to and gets the item there
	//Preconditions:	Address exists
	//Postconditions:	None
	//Input:		answers(string in the format of ynynnn (only y and n allowed)
	//Output:		string item
	//Throws:		invalid_argument if answers is an invalid address (things other than y and n or not a valid node)
	string getByAnswers(const string& answers) const throw (invalid_argument);
	
	//Name:			save
	//Description:		saves the tree to the file at filename
	//Preconditions:	None
	//Postconditions:	file is the following format:
	//				0 q:root question
	//				1 q:question
	//				2 a:answer
	//				1.1 a:answer
	//Input:		filename(string) absolute or relative
	//Output:		None
	void save(const string& filename) const;
	
	//Name:			open
	//Description:		opens the file at filename
	//Preconditions:	file is the following format:
	//				0 q:root question
	//				1 q:question
	//				2 a:answer
	//				1.1 a:answer
	//Postconditions:	items in filename are read into the tree
	//Input:		filename(string) absolute or relative
	//Output:		None
	void open(const string& filename);
	
	//Name:			insertByAddressQuestion
	//Description:		inserts question into the address and moves what was there to the no part of question
	//Preconditions:	None
	//Postconditions:	Question added and what was in address is moved down a level
	//Input:		question(string)
	//			address(string in the format of 1.1.2.2 (only 1 and 2 allowed)
	//Output:		None
	//Throws:		invalid_argument if address is an invalid address (things other than 1 and 2 or not a valid node)
	void insertByAddressQuestion(const string& question, const string& address) throw (invalid_argument);
	
	//Name:			insertByAnswersQuestion
	//Description:		Finds the address that the answers would lead to and inserts inserts question 
	//			into the address and moves what was there to the no part of question
	//Preconditions:	None
	//Postconditions:	Question added and what was in address is moved down a level
	//Input:		question(string)
	//			answers(string in the format of ynynnn (only y and n allowed)
	//Output:		None
	//Throws:		invalid_argument if answers is an invalid address (things other than y and n or not a valid node)
	void insertByAnswersQuestion(const string& question, const string& answers) throw (invalid_argument);
    private:
	//Name:			addressOfNode
	//Description:		finds the item in the subtree of p
	//Preconditions:	item is in the tree
	//Postconditions:	none
	//Input:		item(string)
	//			p(nodeType<string>) subtree that is searched
	//Output:		string address of item
	string addressOfNode(const string& item, nodeType<string> *p) const;
};//end class DecisionTree: public binaryTreeType<string>

#endif
