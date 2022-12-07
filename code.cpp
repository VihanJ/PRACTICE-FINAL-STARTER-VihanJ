// Vihan Jayaraman
// 7644545
// Do not include a main function in this file
// Only submit this file
// See code.h for the descriptions of each problem
#include "code.h"


/* Problem 1: 10 pts */
 
TeaPacket* bestPacket(TeaPacket* head){

   if (head == NULL) {
      return head;
   } else {
      if (head->next!=NULL) {
         TeaPacket* bestOfNextPackets = bestPacket(head->next);
         int largestValue = bestOfNextPackets->rarity*bestOfNextPackets->rating;
         if (largestValue > head->rarity*head->rating) {
            return bestOfNextPackets;
         } else {
            return head; 
         }
      } else {
         return head;
      }
   }

}



/* Problem 2: 10 points*/

Node* insert(Node* head, int value){
   Node* newNode = new Node();
   newNode->data = value;

   Node* currNode = head;

   //gets node before newNode
   while (true) {
      if (currNode->next->data < newNode->data) {
         currNode = currNode->next;
      } else {
         break;
      }
   }
   Node* nextNode = currNode->next;

   currNode->next = newNode;
   newNode->next = nextNode; 

   return head;

}

/* Problem 3: 10 points*/

bool isBalanced(std::string s){
   
   int counter = 0;
   for (int i = 0; i < s.length(); i++) {
      if (s[0] == 'A') {
         counter++;
      } else if (s[0] == 'B') {
         counter--;
      }
   }
   return (counter==0);
}


