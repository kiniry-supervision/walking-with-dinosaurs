#pragma once
#include "pipe.h"

//server
static std::vector<std::string> fullPipeNames;
static std::vector<HANDLE> pipes;
static std::vector<std::string> creatureFilePaths;

int pipeServerMain(int cores, int populationSize, int nrOfGenerations, std::vector<int> ancestor);

int setupServer(int pop, int cores);
void startPrograms();
int waitForClients();
int sendCreatures(std::vector<creature> creatures);
int sendOrders(int i);
void receiveAcknowledges();
std::vector<creature> getResults();