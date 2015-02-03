#ifndef GAME_H
#define GAME_H
#include "GameTree.h"
#include <string>


class Game
{
private:
	GameTree tree;
public:
	Game(){}
	void Play();
	void Instructions();
};

void Game::Instructions()
{
	std::cout<<"\tWelcome to I'm Thinking Of.... (Animal edition)\n"<<std::endl;
	std::cout<<"Think of an animal and I will try to guess what animal you are thinking of\n\n";
}
void Game::Play()
{
	tree.Reset();
	char reply;
	while(tree.currQuestion())
	{
		reply = tree.yesOrno();
		tree.nextQuestion(reply);
	}

	reply = tree.yesOrno();

	if(reply == tree.YES)
		std::cout<<"I win!"<<std::endl;
	else
	{
		std::cout<<"I give up."<<std::endl;
		tree.learn();
	}
}

#endif