#include<iostream>
#include<string>
using namespace std;

struct animalNode {
	string QorA;  
	animalNode* yesAnswer;  
	animalNode* noAnswer;
	animalNode(string str, animalNode* ptr1, animalNode* ptr2)
	{
		QorA = str;
		yesAnswer = ptr1;
		noAnswer = ptr2;
	}
};


class AnimalGuesser
{
	animalNode* root;
	int size;

public:
	AnimalGuesser()//at the time of execution, I have initialized with 10 random animals
	{
		root = new animalNode("does it live in sea?", 0, 0);
		root->noAnswer = new animalNode("is it a pet animal?",0,0);
		root->noAnswer->noAnswer = new animalNode("does it eat other animals?", 0, 0);
		root->noAnswer->noAnswer->yesAnswer = new animalNode("tiger", 0, 0);
		root->noAnswer->noAnswer->noAnswer = new animalNode("does it has zip?", 0, 0);
		root->noAnswer->noAnswer->noAnswer->yesAnswer = new animalNode("kangaroo", 0, 0);
		root->noAnswer->noAnswer->noAnswer->noAnswer = new animalNode("deer", 0, 0);
		root->noAnswer->yesAnswer = new animalNode("Is it also used for security?", 0, 0);
		root->noAnswer->yesAnswer->noAnswer = new animalNode("cat", 0, 0);
		root->noAnswer->yesAnswer->yesAnswer = new animalNode("dog", 0, 0);
		root->yesAnswer = new animalNode("does it also come on land?", 0, 0);
		root->yesAnswer->yesAnswer = new animalNode("is it fat?",0,0);
		root->yesAnswer->yesAnswer->yesAnswer = new animalNode("Hippopatomus", 0, 0);
		root->yesAnswer->yesAnswer->noAnswer = new animalNode("is it reptile?", 0, 0);
		root->yesAnswer->yesAnswer->noAnswer->yesAnswer = new animalNode("crocodile", 0, 0);
		root->yesAnswer->yesAnswer->noAnswer->noAnswer = new animalNode("seal", 0, 0);
		root->yesAnswer->noAnswer = new animalNode("is it very friendly?", 0, 0);
		root->yesAnswer->noAnswer->yesAnswer= new animalNode("dolphin", 0, 0);
		root->yesAnswer->noAnswer->noAnswer= new animalNode("shark", 0, 0);
		size = 10;//total animals entered are 10
	}

	void displayMessage()//this is used to display the opening sentence of game
	{
		cout << "Let's play the ''Guess the Animal'' game. Think of an animal and hit return when you're ready" << endl;
		cout << "for yes or no press yes or no" << endl;
	}

	void guess()
	{
		string o="yes";//first game is opened so it is always a yes at start
		while (o=="yes")//if user presses yes then game continues otherwise game over
		{
			animalNode* curr = root,*parentOfCurr=root;
			string opt;
			while ((curr->yesAnswer) && (curr->noAnswer))//to traverse thrrough questions
			{
				cout << curr->QorA << endl;//to print questions
				getline(cin, opt);//to get whether question answer is yes or no
				if (opt == "yes")// if entered input is yes
				{
					parentOfCurr = curr;
					curr = curr->yesAnswer;
				}
				else if (opt == "no")// if entered input is no
				{
					parentOfCurr = curr;
					curr = curr->noAnswer;
				}
				else
				{
					cout << "Please enter yes or no" << endl;//if it neither yes or no then take input again
				}
			}
			cout << "is it  a(n) " << curr->QorA << " : ";//now we come to guess
			string op;
			getline(cin, op);//is the guessed animal true?
			if (op == "yes")
			{
				cout << "I have guessed your animal" << endl;//guess is right
			}
			else if (op == "no")//if guess is wrong,then add the animal
			{
				cout << "Bummer! What animal were you thinking of? " << endl;
				string animal;
				getline(cin, animal);//take the input of new animal
				cout << "What is a yes/no question that I can use to tell a "<<curr->QorA<<" from a " << animal << " ?" << endl;
				string quest;
				getline(cin, quest);//take differentiating question
				cout << "For a " << animal << ", is the answer yes or no?" << endl;
				string option;
				getline(cin, option);//the answer for the question for new animal is yes/no
				animalNode* temp = curr;
				curr = new animalNode(quest, 0, 0);
				if (option == "yes")//join new animalNode to yesAnswer
				{
					curr->yesAnswer = new animalNode(animal, 0, 0);
					curr->noAnswer = temp;
				}
				else//join new animalNode to noAnswer
				{
					curr->noAnswer = new animalNode(animal, 0, 0);
					curr->yesAnswer = temp;
				}
				if (size == 1)
				{
					root = curr;
				}
				else
				{
					if (parentOfCurr->noAnswer == temp)//to join pointers to new animalNode
					{
						parentOfCurr->noAnswer = curr;
					}
					else
					{
						parentOfCurr->yesAnswer = curr;
					}
				}
				size++;//as new animal is added so size is increased
			}
			cout << "try again(yes/no)?";
			getline(cin, o);//if you want to continue game or not
		}
	}
};


int main()
{
	AnimalGuesser guesser;
	guesser.displayMessage();
	guesser.guess();
}
