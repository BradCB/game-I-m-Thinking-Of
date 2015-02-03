#ifndef GAMETREE_H
#define GAMETREE_H
#include <string>
#include <memory>
#include <iostream>

class GameTree{

private:
	
	class GameNode{
	public:
		GameNode(const std::string& q,GameNode* y,GameNode* n)
		:question(q)
		,yesP(y)
		,noP(n)
	{}
		bool lastQuestion() const
		{
			return (yesP== NULL && noP== NULL);
		}
	
	std::string question;
	GameNode* yesP;	//yes pointer
	GameNode* noP;	//no pointer

	};//end class node						



	GameNode* rootP; //root pointer
	GameNode* currP; //current pointer
	GameNode* currParentp; //current parent pointer
	


public:
	
	GameTree(); //starting tree
	~GameTree(); //free memory
	void Reset(); //reset to root
	void Delete(GameNode* nodeP); //delete node
	bool currQuestion(); //display current question
	void nextQuestion(char a); //goes to next question
	void learn(); //adds a new animal
	char yesOrno(const std::string& q = ""); //utility function

	static const char YES = 'y';
	static const char NO = 'n';

};//end GameTree class

//-------------------constructior-----------------//
GameTree::GameTree()
{
	GameNode* Catp = new GameNode("Is it a Cat?",NULL,NULL);
	GameNode* Fishp = new GameNode("Is it a Fish?",NULL,NULL);
	GameNode* Questionp = new GameNode("Does it live in water?",Fishp,Catp);

	rootP = Questionp;  //set the root question
	currP = rootP;
	currParentp = NULL;
}
//-------------------Yes or No Utility-----------------//
char GameTree::yesOrno(const std::string& q)
{
	char reply;
	do
	{std::cout<<q;
		std::cout<<" ("<<YES<<"/"<<NO<<"): ";
		std::cin>>reply;
	}while(reply != YES && reply != NO);

	return reply;
}
//-------------------Destructor-----------------//
GameTree::~GameTree()
{
	Delete(rootP);
}
//-------------------Reset Root-----------------//
void GameTree::Reset()
{
	currP = rootP;
	currParentp = NULL;

}
//-------------------Delete node-----------------//
void GameTree::Delete(GameNode* node)
{
	if(node != NULL)
	{
		Delete(node->yesP);
		Delete(node->noP);
		delete node;
		node = NULL;
	}
}
//-------------------Current question-----------------//
bool GameTree::currQuestion()
{
	if(currP == NULL)
	{
		return false;
	}
	std::cout<<currP->question;
	return(!currP->lastQuestion());
}
//-------------------Next question-----------------//
void GameTree::nextQuestion(char answer){

	if(currP == NULL) 
	{
		return;
	}

	if(currP->lastQuestion()) 
	{
		return;
	}

	currParentp = currP; 

	if(answer == YES)
	{
		currP = currP->yesP;
	}
	else
	{
		currP = currP->noP;
	}
}
//-------------------Learn New Animal-----------------//
void GameTree::learn()
{
	std::cout<<"What animal were you thinking of ?:"<<std::endl;
	
	std::string animal;
	std::cin.ignore();
	getline(std::cin, animal);

	std::cout<<"What yes or no question would distinguish a these two animals? :"<<std::endl;
	std::string question;
	getline(std::cin, question);

	GameNode* animalp = new GameNode("Is it a "+ animal +"?",NULL,NULL);
	GameNode* questionp = new GameNode(question,NULL,NULL);

	char answer = yesOrno("What would be the answer for a "+ animal +" ?: ");

	if(answer == YES)
	{
		questionp->yesP = animalp;
		questionp->noP = currP;
	}
	else
	{
		questionp->noP = animalp;
		questionp->yesP = currP;
	}
	if(currParentp->yesP == currP)
		
		currParentp->yesP = questionp;
	else
	{
		currParentp->noP = questionp;
	}	
}


#endif