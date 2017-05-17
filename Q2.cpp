#include <iostream>

using namespace std;

struct node {
  int data;
  node* next;
};

void findElements(int k, node* head) {
	node* ref = head;
	node* main = head;
	if(head == NULL) {
      cout << "List doesn't exist" << endl;
      return;
	}
	for(int i = 0; i < k && ref->next != NULL; i++){
      ref = ref->next;
	}
	while(ref->next != NULL) {
		ref = ref->next;
		main = main->next;
	}
	while(main->next != NULL) {
		if(main != NULL)
		  cout << main->data << endl;
		main = main->next;
	}
	return;
}

