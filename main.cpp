#include "Game.h"
#include <iostream>

int main()
{
	Game game;
	char again;

	game.Instructions();

	do
	{
		game.Play();
		std::cout<<"\nPlay again? (y/n): ";
		std::cin>>again;
	}while(again == 'y');

	std::cout<<"Exiting Program, Thanks for playing!"<<std::endl;
	return 0;
}