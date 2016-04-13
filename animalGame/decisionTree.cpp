


#include "decisionTree.h"


using namespace std;



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
    nodeType<string> *p = this->root;
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
	this->root = qNode;
    else if (ans == 'n' || ans == 'N')
	previous->llink = qNode;
    else
	previous->rlink = qNode;
}

string DecisionTree::addressOf(const string& item) const {
    //need the erase to get rid of the leading :
    return addressOfNode(item, this->root).erase(0,1);
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
    nodeType<string> *p = this->root;
    
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
    nodeType<string> *p = this->root;
    
    out.open(filename.c_str());
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
	}//end else
    }//end while (p != NULL)
    out.close();
}

void DecisionTree::open(const string& filename) {
    ifstream in;
    string address;
    string question;
    
    in.open(filename.c_str());
    
    in >> address;
    while (!in.eof() && address != "") {
	getline(in, question);
	question = question.erase(0, 1);
	if (address == "0")
	    address = "";
	insertByAddressQuestion(question, address);
	
	in >> address;
    }
    in.close();
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
    }//end else
}

void DecisionTree::insertByAddressQuestion(const string& question, const string& address) {
    string answers = "";
    
    for (int i = 0; i < address.length(); i+= 2)
	if (address[i] == '1')
	    answers += "n";
	else if (address[i] == '2')
	    answers += "y";
	else
	    throw invalid_argument(address + " is invalid");

    insertByAnswersQuestion(question, answers);
}

void DecisionTree::insertByAnswersQuestion(const string& question, const string& answers) {
    char ans = 'e';
    nodeType<string> *p = this->root;
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
    
    nodeType<string> *qNode = new nodeType<string>;
    qNode->info = question;
    qNode->llink = p;
    
    if (ans == 'e')
	this->root = qNode;
    else if (ans == 'n' || ans == 'N')
	previous->llink = qNode;
    else
	previous->rlink = qNode;
}
