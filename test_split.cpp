/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream> 

Node* listNew (int arr[], int size){
  Node* head = nullptr;
  for(int i = size -1; i>= 0; i--){
    head = new Node(arr[i], head);
  }
  return head; 
}

void listPrinting(Node* head){
  while(head){
    std::cout<< head->value << " "; 
    head = head->next; 
  }
  std::cout<< std::endl; 
}

void deleteList(Node* head){
  while(head){
    Node* temp = head;
    head = head->next;
    delete temp; 
  }
}

int main(int argc, char* argv[])
{
  int arr[] = {1, 2, 3, 4, 5, 6};
  Node* in = listNew(arr, 6); 
  Node* odds = nullptr;
  Node* evens = nullptr; 

  split(in, odds, evens); 

  std::cout<< "Odds: ";
  listPrinting(odds);
  std::cout<< "Evens: ";
  listPrinting(evens);

  deleteList(odds);
  deleteList(evens); 

  return 0; 

}
