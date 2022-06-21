#pragma once
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int x) {
    Node *p = new Node;
    p->data = x;
    p->left = NULL;
    p->right = NULL;  
    return p;
}

Node *insertNode(Node *p, int x) {
    if (p == NULL) {
        Node *temp = createNode(x);
        return temp;
    }
    else {
        if (x < p->data)
            p->left = insertNode(p->left,x);
        else 
            p->right = insertNode(p->right,x);
    }
    return t;
} 

void readData(Node *&p) {
    int n,x;
    ifstream data;
    data.open("data.txt");
    data >> n;
    for (int i=0; i<n; i++) {
        data >> x;
        p = insertNode(p,x);
    }
    data.close();
}

void printTree(Node *p, ofstream &output) {
    if (p!= NULL) {
        printTree(p->left,output);
        output << p->data << " ";
        printTree(p->right,output);
    }
}

int countLeft(Node *p){
    if(p == NULL) 
        return 0;
    int num_l=0;

    if(p->left != NULL) 
        num_l = countLeft(p->left)+1;
    return num_l;
}

int countRight(Node *p){
    if(p == NULL) 
        return 0;
    int num_r=0;

    if(p->right != NULL) 
        num_r = countLeft(p->right)+1;
    return num_r;
}

void printEqual(Node *p,ofstream &output) {
    if (p != NULL) {
        printEqual(p->left,output);
        if (countLeft(p) == countRight(p))
            output << p->data << " ";
        printEqual(p->right,output);
    }
}

bool isSquare(int x) {
    int i = sqrt(x);
    if (i*i == x) 
        return true;
    return false;
}

void printSquare(Node *p,ofstream &output) {
    if (p != NULL) {
        printSquare(p->left,output);
        if (isSquare(p->data) == true)
            output << p->data << " ";
        printSquare(p->right,output);
    }
}

Node* minValueNode(Node* p) {
    Node* current = p;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

Node* deleteNode(Node* p, int key) {
    if (p == NULL)
        return p;
    if (key < p->data)
        p->left = deleteNode(p->left, key);
    else if (key > p->data)
        p->right = deleteNode(p->right, key);
    else {
        if (p->left==NULL && p->right==NULL)
            return NULL;
        else if (p->left == NULL) {
            Node* temp = p->right;
            delete p;
            return temp;
        }
        else if (p->right == NULL) {
            Node* temp = p->left;
            delete p;
            return temp;
        }
        Node* temp = minValueNode(p->right);
        p->data = temp->data;
        p->right = deleteNode(p->right, temp->data);
    }
    return p;
}


void deleteSquare(Node *p) {
    int arr[] = {1,4,16,25};
    for (int i=0; i<4; i++) {
        p = deleteNode(p,arr[i]);
    }
}

void printReverse(Node *p, ofstream &output) {
    if (p!= NULL) {
        printReverse(p->right,output);
        output << p->data << " ";
        printReverse(p->left,output);
    }
}
