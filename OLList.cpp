// OLList.cpp

#include <iostream>
#include <stdlib.h>
using namespace std;
#include "OLList.h"

OLList::OLList()
: headM(0)
{
}

OLList::OLList(const OLList& source)
{
    copy(source);
}

OLList& OLList::operator =(const OLList& rhs)
{
    if (this != &rhs) {
        destroy();
        copy(rhs);
    }
    return *this;
}

OLList::~OLList()
{
    destroy();
}

void OLList::print() const
{
    cout << '[';
    if (headM != 0) {
        cout << ' ' << headM->item;
        for (const Node *p = headM->next; p != 0; p = p->next)
            cout << ", " << p->item;
    }
    cout << " ]\n";
}

void OLList::insert(const ListItem& itemA)
{
    Node *new_node = new Node;
    new_node->item = itemA;
    
    if (headM == 0 || itemA <= headM->item ) {
        new_node->next = headM;
        headM = new_node;
        // point one
    }
    else {
        Node *before = headM;      // will point to node in front of new node
        Node *after = headM->next; // will be 0 or point to node after new node
        while(after != 0 && itemA > after->item) {
            before = after;
            after = after->next;
        }
        new_node->next = after;
        before->next = new_node;
        // point two
    }
}

void OLList::remove(const ListItem& itemA)
{
	
	

    // if list is empty, do nothing
    if (headM == 0 || itemA < headM->item)
        return;
    
    Node *doomed_node = 0; 
	
    // if the eleemnt to be removed is the first element
    if (itemA == headM->item) {
        doomed_node = headM;
        headM = headM->next;
		delete doomed_node;
		return;

    }
    else {
				
        Node *before = headM;
        Node *maybe_doomed = headM->next;
        while(maybe_doomed != 0 && itemA != maybe_doomed->item) {
            before = maybe_doomed;
            maybe_doomed = maybe_doomed->next;
        }
		if (maybe_doomed->item == itemA) {
			// move before next to the next node pass the doomed node
			before->next = maybe_doomed->next;
			// now delete where maybe_doomed points 
			delete maybe_doomed;
			
		}
        // point three
    }
    // the remaining part of this function is missing. As part of exercise A
    // students are supposed to complete the rest of the definition of this function.
}

void OLList::destroy(){
	Node *to_be_delete = headM;
	Node *forward = new Node;
	
	while (headM != nullptr) {
		forward = to_be_delete->next;
		delete to_be_delete;
		headM = forward;
		to_be_delete = headM;
	}
	//default line
    headM =0;
}

void OLList::copy(const OLList& source){
Node *temp = source.headM;
Node *current = new Node;
headM = current;
  
  while (1) {
	  current->item = temp->item;
	  if (temp->next == nullptr) {
		  break;
	  }
	  current->next = new Node;
	  current = current->next;
	  temp = temp->next;
	 
  }
  current->next = nullptr;
	

}





