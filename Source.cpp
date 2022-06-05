#include "Header.h"

int main() {
    ofstream output;
    output.open("output.txt",ios_base::trunc);
    Node *tree = NULL;
    readData(tree);
    
    printTree(tree,output);
    output << endl;

    printEqual(tree,output);
    output << endl;


    printSquare(tree,output);
    output << endl;


    deleteSquare(tree);
    printReverse(tree,output);
    output << endl; 
    
    return 0;
}