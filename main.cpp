#include "variables.h"
#include <iostream>
#include "enums.h"

#include <random>
#include <time.h>

enum Winner CheckWinner(enum Shape EnemyHand, enum Shape MyHand)
{
	if (EnemyHand == MyHand)
	{
		return Draw;
	}
	if (MyHand - EnemyHand == Rock - Paper || MyHand - EnemyHand == Paper - Sissors) // Rock - Paper => 1 - 0 = 1 Paper - Sissors => 0 - 2 = -2
	{
		return Enemy;
	}

	return Player;
	
}

void PrintShape(enum Shape s)
{
	if (s == Paper)
		std::cout << " Paper ";
	if (s == Rock)
		std::cout << " Rock ";
	if (s == Sissors)
		std::cout << " Sissors ";
}

void PrintResult(enum Shape MyHand, enum Shape EnemyHand, int score)
{
	std::cout << "You choose";
	PrintShape(MyHand);
	std::cout << " vs the ";
	PrintShape(EnemyHand);
	std::cout << "that the enemy choose" << std::endl;
}

void UpdateScore(enum Winner wins, int* score)
{

	if (wins == Player)
	{
		(*score)++;
	}
	else if (wins == Enemy)
	{
		(*score)--;
	}
}

void GetInput(enum Shape* EnemyPointer, enum Shape* PlayerPointer)
{
	*(EnemyPointer) = enum Shape(std::rand() % 3);

	std::cout << "Input a number 0 - 2" << std::endl;
	std::cin >> integer;

	integer = integer % 3;
	UpdateScore(CheckWinner(*EnemyPointer, *PlayerPointer));
	PlayerPointer = enum Shape(integer % 3);
}
int main()
{
	//hello();
	//variable();
	//forloop();
	//whileloop();
	//test();
	//solve_x(1, 4, 3);

	int integer = 0;
	int score = 0;

	std::srand(time(0));

	for (int i = 0; i < 100; i++)
	{
		enum Shape EnemyHand;
		enum Shape MyHand;
		GetInput(&EnemyHand, &MyHand);

		enum Winner current = CheckWinner(EnemyHand, MyHand);

		UpdateScore(current, &score);

		PrintResult(MyHand, EnemyHand, score);

		std::cout << "You won " << score << " matches out of " << i + 1 << std::endl;
	}
	return 0;
}