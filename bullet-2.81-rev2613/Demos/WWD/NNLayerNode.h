#pragma once
#include "NNNode.h"

class NNLayerNode : public MTreeNode{
public:
	NNLayerNode(int start) : MTreeNode(start){
		//startIndex = start;							//set in MTreeNode Contructor
		//children = new std::vector<MTreeNode*>();		//set in MTreeNode Contructor
	}
	NNLayerNode(const NNLayerNode& other) : MTreeNode(other){
		children = new std::vector<MTreeNode*>();
		for(int i=0;i<other.children->size();i++){
			children->push_back(new NNNode((const NNNode&) *other.children->at(i)));
		}
	}
	/*
	std::vector<int> mutate(){
	std::vector<int> result = std::vector<int>();
	int random;
	do{
	random = rand()%maxDNAVal;
	result.push_back(random);	//lastNode/thereIsAnotherNode/thereisAnotherLayer - variable

	int random2= rand()%maxDNAVal;
	result.push_back(random2);	//nr of inputs - variable
	switch(random2%4){
	case 0:
	result.push_back(rand()%maxDNAVal); // constant input
	break;
	case 1:
	result.push_back(rand()%maxDNAVal); //function type
	result.push_back(rand()%maxDNAVal); //input1
	result.push_back(rand()%maxDNAVal); //input1 weight
	break;
	case 2:
	result.push_back(rand()%maxDNAVal); //function type
	result.push_back(rand()%maxDNAVal); //input1
	result.push_back(rand()%maxDNAVal); //input1 weight
	result.push_back(rand()%maxDNAVal); //input2
	result.push_back(rand()%maxDNAVal); //input2 weight
	break;
	case 3:
	result.push_back(rand()%maxDNAVal); //function type
	result.push_back(rand()%maxDNAVal); //input1
	result.push_back(rand()%maxDNAVal); //input1 weight
	result.push_back(rand()%maxDNAVal); //input2
	result.push_back(rand()%maxDNAVal); //input2 weight
	result.push_back(rand()%maxDNAVal); //input3
	result.push_back(rand()%maxDNAVal); //input3 weight
	break;
	}
	}
	while(random%3 != 0);

	return std::vector<int>();
	}
	*/
};