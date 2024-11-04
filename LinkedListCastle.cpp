// LinkedListCastle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

//This class just makes nodes.  The other class will create the list.
class CastleNode {
public: 
    //Constructor
    CastleNode(int position, string wallName, CastleNode* nextPtr) {
        next = nextPtr;
        num = position;
        name = wallName;
    }

    //Pointer
    CastleNode* next = nullptr;

    //Data
    int num = 0;
    string name = "";
 
};

class CastleList {
public:
    CastleNode* head = new CastleNode(0, "KEYSTONE piece the wall will not stand without", nullptr);
    //Constructor takes the parameters to build the first castle node.
    //Add node at a specified position
    //need a current node, and a next node.
    //While the current node's next is not equal to nullptr or head
    //Keep looping to see if the index num matches the given num.
    void addAtPos(int pos, string name) {
        cout << "Adding " << name << " at specified position " << pos << endl;
        //Assumes that head != nullptr
        CastleNode* temp = head;
        CastleNode* nextNext = nullptr;
        while (temp->next != nullptr) {
            if (temp->num == (pos - 1) && temp->next != nullptr) {
                //Create a new node here
                nextNext = temp->next;
                temp->next = new CastleNode(pos, name, nextNext);
            
                //Success
            }
            else if (temp->num == pos && temp->next == nullptr) {
                temp->next = new CastleNode(pos, name, nextNext);
          
                //Success
            }
            temp = temp->next;
        }
        temp = head;
        while (temp != nullptr && temp->num != (pos)) {
            temp = temp->next;
        }
        temp = temp->next;
        while (temp != nullptr) {
            temp->num += 1;
            temp = temp->next;
        }
        //Not found in while loop

    }

    void addAtBeg(string name) {
        CastleNode* newNode = new CastleNode(0, name, head);
        head = newNode;
        CastleNode* temp = head;
        while (temp->next != nullptr) {
            temp->next->num += 1;
            temp = temp->next;
        }
        cout << "Added " << name << " to beginning " << endl;
    }

    void addAtEnd(string name) {
        CastleNode* temp = head;
       
        while (temp->next != nullptr) {
            temp = temp->next;
        
        }
        int tempNum = (temp->num + 1);
 
        CastleNode* newNode = new CastleNode(tempNum, name, nullptr);
        temp->next = newNode;
        cout << "Added " << temp->next->name << " at position " << temp->next->num << "! " << endl;
        temp = head;
    }

    void seeTheWall() {
        cout << endl;
        cout << "Seeing the wall: " << endl;
        CastleNode* temp = head;
         while (temp != nullptr) {
             cout << temp->name << " castle piece at position " << temp->num << " " << endl;
             temp = temp->next;
         } 
    }

};

//This program assumes the values entered are correct, and does not implement input error checking.
//The castle wall is a singly linked list with nodes.
int main() {
    cout << "Hello World & welcome to the castle wall linked list!\n";
    CastleList* myCastle = new CastleList();
    myCastle->addAtBeg("Firstwall");
    myCastle->addAtBeg("Ruined door");
    myCastle->addAtBeg("Ivy wall");
    myCastle->addAtBeg("Secret window");
    myCastle->seeTheWall();
    myCastle->addAtEnd("blue bricks");
    myCastle->addAtEnd("tapestry");
    myCastle->addAtEnd("wooden gate");
    myCastle->addAtEnd("mossy wall");
    myCastle->addAtBeg("ruined doorway");
    myCastle->seeTheWall();
    myCastle->addAtPos(3, "grand gate");
    myCastle->seeTheWall();
   
    cout << "SUCCESS!!!" << endl;

}