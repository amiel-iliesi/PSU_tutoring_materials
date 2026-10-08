#include <iostream>
#include <cctype>
#include <print>

const size_t BREAKFAST = 0;
const size_t LUNCH = 1;
const size_t DINNER = 2;

const size_t FOOD = 0;
const size_t BEVERAGE = 1;

const size_t CARBOHYDRATES = 0;
const size_t PROTEIN = 1;
const size_t FIBER = 2;
const size_t SUGAR = 3;
const size_t FAT = 4;

int main()
{
	char choice;

	std::cout << "Welcome to the Daily Calorie Counter!\n";

	// calories[mealtime][type][macro]
	unsigned calories_table[3][2][5] = {};
	size_t mealtime;
	size_t type;
	size_t macro;
	int calories;

	do {
		std::cout << "Enter (1)Breakfast, (2)Lunch, (3)Dinner, or (Q)uit:\n>>> ";
		std::cin >> choice;
		choice = tolower(choice);

		if (choice == '1')
		{
			mealtime = BREAKFAST;
			bool valid_choice1;
			do {
				valid_choice1 = true;

				char choice1;
				std::cout << "Enter (1)Food, (2)Beverage:\n>>> ";
				std::cin >> choice1;
				choice1 = tolower(choice1);

				if (choice1 == '1')
				{
					type = FOOD;
					bool valid_choice11;
					do {
						valid_choice11 = true;

						char choice11;
						std::cout << "Enter--if mainly--(1)Carbohydrates, (2)Protein, (3)Fiber, (4)Sugar, (5)Fat\n>>> ";
						std::cin >> choice11;
						choice11 = tolower(choice11);

						if (choice11 == '1')
						{
							macro = CARBOHYDRATES;

							
							while (true) {
								std::cout << "How many calories?\n>>> ";
								std::cin >> calories;
								if (calories <= 0) {
									std::cout << "***ERROR: invalid choice\n";
								}
								else {
									break;
								}
							}
						}
						else if (choice11 == '2')
						{
							macro = PROTEIN;

							
							while (true) {
								std::cout << "How many calories?\n>>> ";
								std::cin >> calories;
								if (calories <= 0) {
									std::cout << "***ERROR: invalid choice\n";
								}
								else {
									break;
								}
							}
						}
						else if (choice11 == '3')
						{
							macro = FIBER;

							
							while (true) {
								std::cout << "How many calories?\n>>> ";
								std::cin >> calories;
								if (calories <= 0) {
									std::cout << "***ERROR: invalid choice\n";
								}
								else {
									break;
								}
							}
						}
						else if (choice11 == '4')
						{
							macro = SUGAR;

							
							while (true) {
								std::cout << "How many calories?\n>>> ";
								std::cin >> calories;
								if (calories <= 0) {
									std::cout << "***ERROR: invalid choice\n";
								}
								else {
									break;
								}
							}
						}
						else if (choice11 == '5')
						{
							macro = FAT;

							
							while (true) {
								std::cout << "How many calories?\n>>> ";
								std::cin >> calories;
								if (calories <= 0) {
									std::cout << "***ERROR: invalid choice\n";
								}
								else {
									break;
								}
							}
						}
						else
						{
							valid_choice11 = false;
							std::cout << "***ERROR: invalid choice\n";
						}
					} while (not valid_choice11);
				}
				else if (choice1 == '2')
				{
					type = BEVERAGE;
					bool valid_choice12;
					do {
						valid_choice12 = true;

						char choice11;
						std::cout << "Enter--if mainly--(1)Carbohydrates, (2)Protein, (3)Fiber, (4)Sugar, (5)Fat\n>>> ";
						std::cin >> choice11;
						choice11 = tolower(choice11);

						if (choice11 == '1')
						{
							macro = CARBOHYDRATES;

							
							while (true) {
								std::cout << "How many calories?\n>>> ";
								std::cin >> calories;
								if (calories <= 0) {
									std::cout << "***ERROR: invalid choice\n";
								}
								else {
									break;
								}
							}
						}
						else if (choice11 == '2')
						{
							macro = PROTEIN;

							
							while (true) {
								std::cout << "How many calories?\n>>> ";
								std::cin >> calories;
								if (calories <= 0) {
									std::cout << "***ERROR: invalid choice\n";
								}
								else {
									break;
								}
							}
						}
						else if (choice11 == '3')
						{
							macro = FIBER;

							
							while (true) {
								std::cout << "How many calories?\n>>> ";
								std::cin >> calories;
								if (calories <= 0) {
									std::cout << "***ERROR: invalid choice\n";
								}
								else {
									break;
								}
							}
						}
						else if (choice11 == '4')
						{
							macro = SUGAR;

							
							while (true) {
								std::cout << "How many calories?\n>>> ";
								std::cin >> calories;
								if (calories <= 0) {
									std::cout << "***ERROR: invalid choice\n";
								}
								else {
									break;
								}
							}
						}
						else if (choice11 == '5')
						{
							macro = FAT;

							
							while (true) {
								std::cout << "How many calories?\n>>> ";
								std::cin >> calories;
								if (calories <= 0) {
									std::cout << "***ERROR: invalid choice\n";
								}
								else {
									break;
								}
							}
						}
						else
						{
							valid_choice12 = false;
							std::cout << "***ERROR: invalid choice\n";
						}
					} while (not valid_choice12);
				}
				else 
				{
					valid_choice1 = false;
					std::cout << "***ERROR: invalid choice\n";
				}
			} while (not valid_choice1);
		}
		else if (choice == '2')
		{
			mealtime = LUNCH;
			bool valid_choice2;
			do {
				valid_choice2 = true;

				char choice1;
				std::cout << "Enter (1)Food, (2)Beverage:\n>>> ";
				std::cin >> choice1;
				choice1 = tolower(choice1);

				if (choice1 == '1')
				{
					type = FOOD;
					bool valid_choice21;
					do {
						valid_choice21 = true;

						char choice11;
						std::cout << "Enter--if mainly--(1)Carbohydrates, (2)Protein, (3)Fiber, (4)Sugar, (5)Fat\n>>> ";
						std::cin >> choice11;
						choice11 = tolower(choice11);

						if (choice11 == '1')
						{
							macro = CARBOHYDRATES;

							
							while (true) {
								std::cout << "How many calories?\n>>> ";
								std::cin >> calories;
								if (calories <= 0) {
									std::cout << "***ERROR: invalid choice\n";
								}
								else {
									break;
								}
							}
						}
						else if (choice11 == '2')
						{
							macro = PROTEIN;

							
							while (true) {
								std::cout << "How many calories?\n>>> ";
								std::cin >> calories;
								if (calories <= 0) {
									std::cout << "***ERROR: invalid choice\n";
								}
								else {
									break;
								}
							}
						}
						else if (choice11 == '3')
						{
							macro = FIBER;

							
							while (true) {
								std::cout << "How many calories?\n>>> ";
								std::cin >> calories;
								if (calories <= 0) {
									std::cout << "***ERROR: invalid choice\n";
								}
								else {
									break;
								}
							}
						}
						else if (choice11 == '4')
						{
							macro = SUGAR;

							
							while (true) {
								std::cout << "How many calories?\n>>> ";
								std::cin >> calories;
								if (calories <= 0) {
									std::cout << "***ERROR: invalid choice\n";
								}
								else {
									break;
								}
							}
						}
						else if (choice11 == '5')
						{
							macro = FAT;

							
							while (true) {
								std::cout << "How many calories?\n>>> ";
								std::cin >> calories;
								if (calories <= 0) {
									std::cout << "***ERROR: invalid choice\n";
								}
								else {
									break;
								}
							}
						}
						else
						{
							valid_choice21 = false;
							std::cout << "***ERROR: invalid choice\n";
						}
					} while (not valid_choice21);
				}
				else if (choice1 == '2')
				{
					type = BEVERAGE;
					bool valid_choice22;
					do {
						valid_choice22 = true;

						char choice11;
						std::cout << "Enter--if mainly--(1)Carbohydrates, (2)Protein, (3)Fiber, (4)Sugar, (5)Fat\n>>> ";
						std::cin >> choice11;
						choice11 = tolower(choice11);

						if (choice11 == '1')
						{
							macro = CARBOHYDRATES;

							
							while (true) {
								std::cout << "How many calories?\n>>> ";
								std::cin >> calories;
								if (calories <= 0) {
									std::cout << "***ERROR: invalid choice\n";
								}
								else {
									break;
								}
							}
						}
						else if (choice11 == '2')
						{
							macro = PROTEIN;

							
							while (true) {
								std::cout << "How many calories?\n>>> ";
								std::cin >> calories;
								if (calories <= 0) {
									std::cout << "***ERROR: invalid choice\n";
								}
								else {
									break;
								}
							}
						}
						else if (choice11 == '3')
						{
							macro = FIBER;

							
							while (true) {
								std::cout << "How many calories?\n>>> ";
								std::cin >> calories;
								if (calories <= 0) {
									std::cout << "***ERROR: invalid choice\n";
								}
								else {
									break;
								}
							}
						}
						else if (choice11 == '4')
						{
							macro = SUGAR;

							
							while (true) {
								std::cout << "How many calories?\n>>> ";
								std::cin >> calories;
								if (calories <= 0) {
									std::cout << "***ERROR: invalid choice\n";
								}
								else {
									break;
								}
							}
						}
						else if (choice11 == '5')
						{
							macro = FAT;

							
							while (true) {
								std::cout << "How many calories?\n>>> ";
								std::cin >> calories;
								if (calories <= 0) {
									std::cout << "***ERROR: invalid choice\n";
								}
								else {
									break;
								}
							}
						}
						else
						{
							valid_choice22 = false;
							std::cout << "***ERROR: invalid choice\n";
						}
					} while (not valid_choice22);
				}
				else 
				{
					valid_choice2 = false;
					std::cout << "***ERROR: invalid choice\n";
				}
			} while (not valid_choice2);
		}
		else if (choice == '3')
		{
			mealtime = DINNER;
			bool valid_choice3;
			do {
				valid_choice3 = true;

				char choice1;
				std::cout << "Enter (1)Food, (2)Beverage:\n>>> ";
				std::cin >> choice1;
				choice1 = tolower(choice1);

				if (choice1 == '1')
				{
					type = FOOD;
					bool valid_choice31;
					do {
						valid_choice31 = true;

						char choice11;
						std::cout << "Enter--if mainly--(1)Carbohydrates, (2)Protein, (3)Fiber, (4)Sugar, (5)Fat\n>>> ";
						std::cin >> choice11;
						choice11 = tolower(choice11);

						if (choice11 == '1')
						{
							macro = CARBOHYDRATES;

							
							while (true) {
								std::cout << "How many calories?\n>>> ";
								std::cin >> calories;
								if (calories <= 0) {
									std::cout << "***ERROR: invalid choice\n";
								}
								else {
									break;
								}
							}
						}
						else if (choice11 == '2')
						{
							macro = PROTEIN;

							
							while (true) {
								std::cout << "How many calories?\n>>> ";
								std::cin >> calories;
								if (calories <= 0) {
									std::cout << "***ERROR: invalid choice\n";
								}
								else {
									break;
								}
							}
						}
						else if (choice11 == '3')
						{
							macro = FIBER;

							
							while (true) {
								std::cout << "How many calories?\n>>> ";
								std::cin >> calories;
								if (calories <= 0) {
									std::cout << "***ERROR: invalid choice\n";
								}
								else {
									break;
								}
							}
						}
						else if (choice11 == '4')
						{
							macro = SUGAR;

							
							while (true) {
								std::cout << "How many calories?\n>>> ";
								std::cin >> calories;
								if (calories <= 0) {
									std::cout << "***ERROR: invalid choice\n";
								}
								else {
									break;
								}
							}
						}
						else if (choice11 == '5')
						{
							macro = FAT;

							
							while (true) {
								std::cout << "How many calories?\n>>> ";
								std::cin >> calories;
								if (calories <= 0) {
									std::cout << "***ERROR: invalid choice\n";
								}
								else {
									break;
								}
							}
						}
						else
						{
							valid_choice31 = false;
							std::cout << "***ERROR: invalid choice\n";
						}
					} while (not valid_choice31);
				}
				else if (choice1 == '2')
				{
					type = BEVERAGE;
					bool valid_choice32;
					do {
						valid_choice32 = true;

						char choice11;
						std::cout << "Enter--if mainly--(1)Carbohydrates, (2)Protein, (3)Fiber, (4)Sugar, (5)Fat\n>>> ";
						std::cin >> choice11;
						choice11 = tolower(choice11);

						if (choice11 == '1')
						{
							macro = CARBOHYDRATES;

							
							while (true) {
								std::cout << "How many calories?\n>>> ";
								std::cin >> calories;
								if (calories <= 0) {
									std::cout << "***ERROR: invalid choice\n";
								}
								else {
									break;
								}
							}
						}
						else if (choice11 == '2')
						{
							macro = PROTEIN;

							
							while (true) {
								std::cout << "How many calories?\n>>> ";
								std::cin >> calories;
								if (calories <= 0) {
									std::cout << "***ERROR: invalid choice\n";
								}
								else {
									break;
								}
							}
						}
						else if (choice11 == '3')
						{
							macro = FIBER;

							
							while (true) {
								std::cout << "How many calories?\n>>> ";
								std::cin >> calories;
								if (calories <= 0) {
									std::cout << "***ERROR: invalid choice\n";
								}
								else {
									break;
								}
							}
						}
						else if (choice11 == '4')
						{
							macro = SUGAR;

							
							while (true) {
								std::cout << "How many calories?\n>>> ";
								std::cin >> calories;
								if (calories <= 0) {
									std::cout << "***ERROR: invalid choice\n";
								}
								else {
									break;
								}
							}
						}
						else if (choice11 == '5')
						{
							macro = FAT;

							
							while (true) {
								std::cout << "How many calories?\n>>> ";
								std::cin >> calories;
								if (calories <= 0) {
									std::cout << "***ERROR: invalid choice\n";
								}
								else {
									break;
								}
							}
						}
						else
						{
							valid_choice32 = false;
							std::cout << "***ERROR: invalid choice\n";
						}
					} while (not valid_choice32);
				}
				else 
				{
					valid_choice3 = false;
					std::cout << "***ERROR: invalid choice\n";
				}
			} while (not valid_choice3);
		}
		else if (choice != 'q')
		{
			std::cout << "***ERROR: invalid choice\n";
		}

		calories_table[mealtime][type][macro] += calories;
	} while (choice != 'q');

	std::cout << "Calorie Breakdown:\n------------------\n";

	std::cout << "Breakfast:\n----------\n";
	std::println("        |{}|{}|{}|{}|{:5}|", "carbohydrates", "protein", "fiber", "sugar", "fat");
	std::println("{:8}|{:13}|{:7}|{:5}|{:5}|{:5}|",
			"food",
			calories_table[BREAKFAST][FOOD][CARBOHYDRATES],
			calories_table[BREAKFAST][FOOD][PROTEIN],
			calories_table[BREAKFAST][FOOD][FIBER],
			calories_table[BREAKFAST][FOOD][SUGAR],
			calories_table[BREAKFAST][FOOD][FAT]);
	std::println("{:8}|{:13}|{:7}|{:5}|{:5}|{:5}|",
			"beverage",
			calories_table[BREAKFAST][BEVERAGE][CARBOHYDRATES],
			calories_table[BREAKFAST][BEVERAGE][PROTEIN],
			calories_table[BREAKFAST][BEVERAGE][FIBER],
			calories_table[BREAKFAST][BEVERAGE][SUGAR],
			calories_table[BREAKFAST][BEVERAGE][FAT]);

	std::cout << "Lunch:\n-----\n";
	std::println("        |{}|{}|{}|{}|{:5}|", "carbohydrates", "protein", "fiber", "sugar", "fat");
	std::println("{:8}|{:13}|{:7}|{:5}|{:5}|{:5}|",
			"food",
			calories_table[LUNCH][FOOD][CARBOHYDRATES],
			calories_table[LUNCH][FOOD][PROTEIN],
			calories_table[LUNCH][FOOD][FIBER],
			calories_table[LUNCH][FOOD][SUGAR],
			calories_table[LUNCH][FOOD][FAT]);
	std::println("{:8}|{:13}|{:7}|{:5}|{:5}|{:5}|",
			"beverage",
			calories_table[LUNCH][BEVERAGE][CARBOHYDRATES],
			calories_table[LUNCH][BEVERAGE][PROTEIN],
			calories_table[LUNCH][BEVERAGE][FIBER],
			calories_table[LUNCH][BEVERAGE][SUGAR],
			calories_table[LUNCH][BEVERAGE][FAT]);

	std::cout << "DINNER:\n------\n";
	std::println("        |{}|{}|{}|{}|{:5}|", "carbohydrates", "protein", "fiber", "sugar", "fat");
	std::println("{:8}|{:13}|{:7}|{:5}|{:5}|{:5}|",
			"food",
			calories_table[DINNER][FOOD][CARBOHYDRATES],
			calories_table[DINNER][FOOD][PROTEIN],
			calories_table[DINNER][FOOD][FIBER],
			calories_table[DINNER][FOOD][SUGAR],
			calories_table[DINNER][FOOD][FAT]);
	std::println("{:8}|{:13}|{:7}|{:5}|{:5}|{:5}|",
			"beverage",
			calories_table[DINNER][BEVERAGE][CARBOHYDRATES],
			calories_table[DINNER][BEVERAGE][PROTEIN],
			calories_table[DINNER][BEVERAGE][FIBER],
			calories_table[DINNER][BEVERAGE][SUGAR],
			calories_table[DINNER][BEVERAGE][FAT]);

	return 0;
}
