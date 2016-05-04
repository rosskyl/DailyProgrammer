#include "decisionTree.h"
#include "game.h"


void print(string& item) {
    cout << item << "-";
}

int main() {
    /*DecisionTree tree;
    tree.open("animal.txt");
    cout << "here" << endl;
    tree.breadthFirstTraversal(print);
    cout << endl;
    /*
    string search = "animal3";
    string address = tree.addressOf(search);
    cout << "Address of " << search << ": " << tree.addressOf(search) << endl;
    cout << "Item at address " << address << ": " << tree.getByAddress(address) << endl;
    //tree.save("animal.txt");
    */
    
    Game game;
    
    game.openFile("animal.txt");
    
    game.startGame();
    
    game.saveFile("animal.txt");
    
    return 0;
}
