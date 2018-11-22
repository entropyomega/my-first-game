#include <iostream>
#include <random>
#include <ctime>



int main()
{
	std::default_random_engine randomEngine(time(NULL));
	std::uniform_real_distribution<float> Attack(0.0f, 1.0f);


	//Mert Properties
	float MertAttack = 0.6f;
	float MertHealth = 1000.0f;
	float MertDamage = 15.0f;
	float currentMertHealth = MertHealth;

	//Poder Properties
	float PoderAttack = 0.49f;
	float PoderHealth = 400.0f;
	float PoderDamage = 50.0f;
	float currentPoderHealth = PoderHealth;

	float AttackResult;

	int numMert;
	int numPoder;

	char turn = 'M';

	std::cout << "~#^^****+++~~   <<<<<<<>>>>>>   ~~+++****^^#~" << std::endl;
	std::cout << "~~~~~~~~~~~~~                   ~~~~~~~~~~~~~" << std::endl;
	std::cout << "                PODER vs MERT                " << std::endl;
	std::cout << "~~~~~~~~~~~~~                   ~~~~~~~~~~~~~" << std::endl;
	std::cout << "~#..****+++~~   <<<<<<<>>>>>>   ~~+++****..#~" << std::endl;
	std::cout << " " << std::endl;
	std::cout << " " << std::endl;

	//input game dynamics
	std::cout << "Enter the number of weapons a Mert have: ";
	std::cin >> numMert;
	std::cout << " " << std::endl;
	std::cout << "*" << std::endl;
	std::cout << "*" << std::endl;
	std::cout << " " << std::endl;

	std::cout << "Enter the current level of Poder Derangement: ";
	std::cin >> numPoder;
	std::cout << " " << std::endl;
	std::cout << "*" << std::endl;
	std::cout << "*" << std::endl;
	std::cout << " " << std::endl;

	std::cout << "..-----------------------------------------.." << std::endl;
	std::cout << "          THE BATTLE IS BEGINNING!           " << std::endl;
	std::cout << "==-----------------------------------------==" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "*" << std::endl;
	std::cout << "*" << std::endl;
	std::cout << " " << std::endl;

	while ((numMert > 0) && (numPoder > 0))
	{

		//Mert turn
		if (turn == 'M')
		{

			//attack result
			AttackResult = Attack(randomEngine);

			//check if attack successful
			if (AttackResult <= MertAttack)
			{
				currentPoderHealth -= MertDamage;

				if (currentPoderHealth < 0)
				{
					numPoder--;
					currentPoderHealth = PoderHealth;
				}
			}

			turn = 'P';

		}

		else 
		{

			if (AttackResult <= PoderAttack)
			{
				currentMertHealth -= PoderDamage;

				if (currentMertHealth < 0)
				{
						numMert--;
						currentMertHealth = MertHealth;
				}

			}

				turn = 'M';
				
		}
					   			 		  		  		 	   		
		
	}

	std::cout << "........................................." << std::endl;
	std::cout << "          the battle has ended           " << std::endl;
	std::cout << "==.....................................==" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "*" << std::endl;
	std::cout << "*" << std::endl;
	std::cout << " " << std::endl;

	if (numMert > 0)
	{
		std::cout << "~#^^****+++~~   <<<<<<<>>>>>>   ~~+++****^^#~" << std::endl;
		std::cout << "~~~~~~~~~~~~~                   ~~~~~~~~~~~~~" << std::endl;
		std::cout << "                   MERT WIN                  " << std::endl;
		std::cout << "~~~~~~~~~~~~~                   ~~~~~~~~~~~~~" << std::endl;
		std::cout << "~#..****+++~~   <<<<<<<>>>>>>   ~~+++****..#~" << std::endl;
		std::cout << " " << std::endl;
		std::cout << "There are " << numMert << " Mert weapons left" << std::endl;
	}

	else
	{
		std::cout << "~#^^****+++~~   <<<<<<<>>>>>>   ~~+++****^^#~" << std::endl;
		std::cout << "~~~~~~~~~~~~~                   ~~~~~~~~~~~~~" << std::endl;
		std::cout << "                  PODER WIN                  " << std::endl;
		std::cout << "~~~~~~~~~~~~~                   ~~~~~~~~~~~~~" << std::endl;
		std::cout << "~#..****+++~~   <<<<<<<>>>>>>   ~~+++****..#~" << std::endl;
		std::cout << " " << std::endl;
		std::cout << "There are " << numPoder << " Poder Derangements left" << std::endl;
	}

	system("PAUSE");
	return 0;
}