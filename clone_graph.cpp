#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>
using namespace std;

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode*> neighbors;
	UndirectedGraphNode(int x) : label(x) {}
};
/*
class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (node == NULL) return NULL;
		unordered_set<UndirectedGraphNode*> visited;
		unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> umap;
		queue<UndirectedGraphNode*> que;	
		que.push(node);
		UndirectedGraphNode *copy = new UndirectedGraphNode(node->label);
		umap[node] = copy;
		visited.insert(node);

		while ( !que.empty() ) {
			vector<UndirectedGraphNode*> vec = que.front()->neighbors;
			que.pop();
			for (int i=0; i<vec.size(); ++i) {
				if (visited.find(vec[i]) == visited.end()) {
					visited.insert(vec[i]);
					que.push(vec[i]);
					umap[vec[i]] = new UndirectedGraphNode(vec[i]->label);
				}
			}	
		}
		visited.clear();
		que.push(node);
		visited.insert(node);
		while ( !que.empty() ) {
			vector<UndirectedGraphNode*> vec = que.front()->neighbors;
			UndirectedGraphNode* newn = umap[que.front()];
			que.pop();
			for (int i=0; i<vec.size(); ++i) {
				if (visited.find(vec[i]) == visited.end()) {
					que.push(vec[i]);
					visited.insert(vec[i]);
				}
				(newn->neighbors).push_back(umap[vec[i]]);	
			}	
		}
		return copy;
	}
};
*/
/*
class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (node == NULL) return NULL;
		unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> umap;
		unordered_set<UndirectedGraphNode*> visited;
		queue<UndirectedGraphNode*> que;
		visited.insert(node);
		que.push(node);

		while ( !que.empty() ) {
			if (umap.find(que.front()) == umap.end()) {
				umap[que.front()] = new UndirectedGraphNode(que.front()->label);
			}
			vector<UndirectedGraphNode*> vec = que.front()->neighbors;
			UndirectedGraphNode* newn = umap[que.front()];
			que.pop();
			for (int i=0; i<vec.size(); ++i) {
				if (visited.find(vec[i]) == visited.end()) {
					visited.insert(vec[i]);
					que.push(vec[i]);
				}
				if (umap.find(vec[i]) == umap.end()) {
					umap[vec[i]] = new UndirectedGraphNode(vec[i]->label);
				}				
				(newn->neighbors).push_back(umap[vec[i]]);	
			}
		}
		return umap[node];
	}
};
*/

class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (node == NULL) return NULL;
		unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> umap;
		queue<UndirectedGraphNode*> que;
		que.push(node);
		umap[node] = new UndirectedGraphNode(node->label);

		while ( !que.empty() ) {
			UndirectedGraphNode* newn = umap[que.front()];
			vector<UndirectedGraphNode*> vec = que.front()->neighbors;
			que.pop();
			for (int i=0; i<vec.size(); ++i) {
				if (umap.find(vec[i]) == umap.end()) {
					que.push(vec[i]);
					umap[vec[i]] = new UndirectedGraphNode(vec[i]->label);
				}
				(newn->neighbors).push_back(umap[vec[i]]);
			}
		}
		return umap[node];
	}
};

int main()
{

}
