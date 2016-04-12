#include "decisionTree.h"


void print(string& item) {
    cout << item << " ";
}

int main() {
    DecisionTree tree;
    tree.insertByAnswers("question1", "animal1");
    tree.insertByAnswers("question2", "animal2", "n");
    tree.insertByAnswers("question3", "animal3", "nn");
    tree.insertByAnswers("question4", "animal4", "y");
    tree.insertByAddress("question5", "animal5", "1.1.1");
    
    tree.breadthFirstTraversal(print);
    cout << endl;
    
    string search = "animal3";
    string address = tree.addressOf(search);
    cout << "Address of " << search << ": " << tree.addressOf(search) << endl;
    cout << "Item at address " << address << ": " << tree.getByAddress(address) << endl;
    tree.save("");
    return 0;
}
