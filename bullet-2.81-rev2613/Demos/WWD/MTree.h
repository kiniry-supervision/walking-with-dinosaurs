#pragma once
#include <vector>
//#include "MTreeNode.h"
#include "partNode.h"
#include "NNNode.h"

#define IMPACTPERCENTAGEBREEDPART 80
#define IMPACTPERCENTAGESEEDPART 50
//#define NNONLY
//#define NNMAINONLY

class MTree{
private:
	partNode* bodyPart;
	std::vector<NNLayerNode*>* NNPart;
public:
	MTree(){
		NNPart = new std::vector<NNLayerNode*>();
	}
	MTree(const MTree& other){
		bodyPart = new partNode((const partNode&)(*other.bodyPart));
		NNPart = new std::vector<NNLayerNode*>();
		for(int i = 0;i<other.NNPart->size();i++){
			NNPart->push_back(new NNLayerNode((const NNLayerNode&)(*other.NNPart->at(i))));
		}
	}
	~MTree(void){
		for(int i=0;i<(int)NNPart->size();i++){
			delete NNPart->at(i);
		}
		delete bodyPart;
		delete NNPart;
	}
	std::vector<int> mutateDNA(std::vector<int> DNA);
	void setBody(partNode* body){bodyPart=body;}
	partNode* getBodyPart(){return bodyPart;}
	void addNeuralNetworkLayer(NNLayerNode* NN){NNPart->push_back(NN);}
	std::vector<int> crossBreed(std::vector<int> myDNA, std::vector<int> seedDNA, MTree* seed);
	std::vector<int> NNcrossBreed(std::vector<int> myDNA, std::vector<int> seedDNA, std::vector<NNLayerNode*>* myNode, std::vector<NNLayerNode*>* seedNode);
	inline MTreeNode* getRandomBodyNode(MTree* tree);
	MTreeNode* ReduceImpact(MTreeNode* node,int choosePercentage);
};

int NN(int index, std::vector<int> *DNA,partNode* body); //guest from Grammar.h