#pragma once
#include <vector>

#define maxDNAVal 10000 //TODO:? get from shared/global var instead

class MTreeNode{
protected:	
	int startIndex;
	int endIndex;
	std::vector<MTreeNode*> children;
public:
	MTreeNode(int start){
		startIndex=start;
	}
	MTreeNode(int start,int end){
		startIndex=start;
		endIndex=end;
	}
	void setEnd(int end){
		endIndex=end;
	}
	void addChild(MTreeNode* child){
		children.push_back(child);
	}
	virtual std::vector<int> mutate();
};