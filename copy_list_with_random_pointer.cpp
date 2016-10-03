#include<iostream>
#include <unordered_map>
using namespace std;

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		unordered_map<RandomListNode*, RandomListNode*> umap;
		RandomListNode *head0 = new RandomListNode(0);
		RandomListNode *p = head0; 

		while (head != NULL) {
			if (umap.find(head) == umap.end()) {
				umap[head] = new RandomListNode(head->label);
			}
			p->next = umap[head];
			p = p->next;
			if (head->random) {
				if (umap.find(head->random)==umap.end()) {
					umap[head->random] = new RandomListNode(head->random->label);
				}
				p->random = umap[head->random];
			}
			head = head->next;
		}
		return head0->next;
	}
};

/*
class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		unordered_map<RandomListNode*, RandomListNode*> umap;
		RandomListNode *new_head = new RandomListNode(0);
		RandomListNode *oldn = head;
		RandomListNode *newn = new_head;
		
		while (oldn != NULL) {
			newn->next = new RandomListNode(oldn->label);	
			umap[oldn] = newn->next;
			newn = newn->next;
			oldn = oldn->next;
		}	
		oldn = head; newn = new_head->next;
		while (oldn != NULL) {
			if (oldn->random) {
				newn->random = umap[oldn->random];	
			}
			newn = newn->next;
			oldn = oldn->next;
		}
		return new_head->next;
	}
};
*/
void print(RandomListNode *head) 
{
	while (head != NULL) {
		cout << "label:" << head->label << " ";
		if (head->random) cout << "random:" << head->random->label << endl;
		else cout << "NULL\n";
		head = head->next;
	}
}

int main()
{
	RandomListNode *head = new RandomListNode(1);
	RandomListNode *n2 =  new RandomListNode(2);
	RandomListNode *n3 = new RandomListNode(3);
	head->next = n2;
	n2->next = n3;
	head->random = n3;
	
	print(head);
	Solution s;
	head = s.copyRandomList(head);
	print(head);
}
