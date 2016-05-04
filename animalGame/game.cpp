


#include "game.h"
#include "decisionTree.h"
#include <iostream>
#include <stdexcept>

///TODO addin error checking for inputs




void Game::openFile(const string& filename) {
    tree.open(filename);
}

void Game::saveFile(const string& filename) const {
    tree.save(filename);
}

void Game::startGame() {
    address = "";
    
    cout << "Please think of an animal and press enter when finished";
    cin.ignore();
    
    askQuestion();
}

void Game::askQuestion() {
    string question = tree.getByAddress(address);
    char type = question[0];
    if (type == 'a') {
	checkAnimal();
	return;
    }
    else if (type == 'N') {
	lose();
	return;
    }
    else if (type != 'q')
	throw range_error("This should be a question: " + question);
    
    question = question.substr(2);
    cout << question << endl;
    string answer;
    cin >> answer;
    answer = answer[0];
    
    if (answer == "y" || answer == "Y")
	if (address == "")
	    address = "2";
	else
	    address = address + ".2";
    else
	if (address == "")
	    address = "1";
	else
	    address = address + ".1";
    askQuestion();
}

void Game::checkAnimal() {
    string animal = tree.getByAddress(address);
    animal = animal.substr(2);
    
    cout << "Is " << animal << " your animal?" << endl;
    string answer;
    cin >> answer;
    answer = answer[0];
    
    if (answer == "y" || answer == "Y")
	win();
    else
	lose();
}

void Game::win() {
    cout << "I win.  Would you like to play again?" << endl;
    
    string answer;
    cin >> answer;
    answer = answer[0];
    
    if (answer == "y" || answer == "Y")
	startGame();
    else
	cout << "Thank you for playing" << endl;
}

void Game::lose() {
    cout << "You win.  Please help me learn." << endl;
    char type = tree.getByAddress(address)[0];
    
    if (type == 'N')
	addAnimal();
    else
	addQuestion();
    
    cout << "Would you like to play again?" << endl;
    
    string answer;
    cin >> answer;
    answer = answer[0];
    
    if (answer == "y" || answer == "Y")
	startGame();
    else
	cout << "Thank you for playing" << endl;
}

void Game::addAnimal() {
    cout << "I don't know what that animal is.  What animal are you thinking of?" << endl;
    string animal;
    cin >> animal;
    animal = "a:" + animal;
//    address = address + ".1";
    tree.insertByAddressQuestion(animal, address);
}

void Game::addQuestion() {
    string currAnimal = tree.getByAddress(address);
    currAnimal = currAnimal.substr(2);
    
    cout << "I don't know what animal you are thinking of.  What animal are you thinking of?" << endl;
    string newAnimal;
    cin >> newAnimal;
    
    cout << "What is a good question to distinguish "
	<< currAnimal << " from " << newAnimal << "?" << endl;
    string question;
    cin >> question;
    
    question = "q:" + question;
    newAnimal = "a:" + newAnimal;
    
    tree.insertByAddress(question, newAnimal, address);
}
