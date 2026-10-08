#include <iostream>
#include <cctype>
#include <cstring>
#include <print>
#include <string>

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

const char ERR_INVALID_CHOICE[] = "***ERROR: invalid choice\n";

void mealtime_menu(unsigned calories_table[3][2][5]);
void type_menu(unsigned calories_table[3][2][5], const size_t mealtime);
void macro_menu(unsigned calories_table[3][2][5], const size_t mealtime, const size_t type);
unsigned get_calories();
void print_mealtime_table(unsigned calories_table[3][2][5], unsigned mealtime);
unsigned calculate_daily_calories(const unsigned calories_table[3][2][5]);

int main()
{
	std::cout << "Welcome to the Daily Calorie Counter!\n";

	// calories[mealtime][type][macro]
	unsigned calories_table[3][2][5] = {};

	mealtime_menu(calories_table);

	std::cout << "Calorie Breakdown:\n------------------\n";

	print_mealtime_table(calories_table, BREAKFAST);
	std::println("");

	print_mealtime_table(calories_table, LUNCH);
	std::println("");

	print_mealtime_table(calories_table, DINNER);

	std::println("");
	std::println("Your total calories for the day is {}.",
			calculate_daily_calories(calories_table));
	
	return 0;
}

void mealtime_menu(unsigned calories_table[3][2][5])
{
	char choice;

	do {
		std::cout << "Enter (1)Breakfast, (2)Lunch, (3)Dinner, or (Q)uit:\n>>> ";
		std::cin >> choice;
		choice = tolower(choice);

		switch (choice) {
			case '1':
				type_menu(calories_table, BREAKFAST);
				break;
			case '2':
				type_menu(calories_table, LUNCH);
				break;
			case '3':
				type_menu(calories_table, DINNER);
				break;
			case 'q':
				break;
			default:
				std::cout << ERR_INVALID_CHOICE;
		}
	} while (choice != 'q');
}

void type_menu(unsigned calories_table[3][2][5], const size_t mealtime)
{
	bool valid_choice;

	do {
		valid_choice = true;

		char choice;
		std::cout << "Enter (1)Food, (2)Beverage:\n>>> ";
		std::cin >> choice;
		choice = tolower(choice);

		switch (choice) {
			case '1':
				macro_menu(calories_table, mealtime, FOOD);
				break;
			case '2':
				macro_menu(calories_table, mealtime, BEVERAGE);
				break;
			default:
				valid_choice = false;
				std::cout << ERR_INVALID_CHOICE;
		}
	} while (not valid_choice);
}

void macro_menu(unsigned calories_table[3][2][5], const size_t mealtime, const size_t type)
{
	size_t macro;
	bool valid_choice;
	
	do {
		valid_choice = true;

		char choice;
		std::cout << "Enter--if mainly--(1)Carbohydrates, (2)Protein, (3)Fiber, (4)Sugar, (5)Fat\n>>> ";
		std::cin >> choice;
		choice = tolower(choice);

		switch (choice) {
			case '1':
				macro = CARBOHYDRATES;
				break;
			case '2':
				macro = PROTEIN;
				break;
			case '3':
				macro = FIBER;
				break;
			case '4':
				macro = SUGAR;
				break;
			case '5':
				macro = FAT;
				break;
			default:
				valid_choice = false;
				std::cout << ERR_INVALID_CHOICE;
		}
	} while (not valid_choice);

	unsigned calories = get_calories();

	calories_table[mealtime][type][macro] += calories;
}

unsigned get_calories()
{
	unsigned calories;

	while (true) {
		std::cout << "How many calories?\n>>> ";
		std::cin >> calories;
		if (calories <= 0) {
			std::cout << ERR_INVALID_CHOICE;
		}
		else {
			break;
		}
	}

	return calories;
}

void print_mealtime_table(unsigned calories_table[3][2][5], unsigned mealtime)
{
	static const char BREAKFAST_TITLE[] = "Breakfast";
	static const char LUNCH_TITLE[] = "Lunch";
	static const char DINNER_TITLE[] = "Dinner";

	const char* mealtime_title = nullptr;

	switch (mealtime) {
		case BREAKFAST:
			mealtime_title = BREAKFAST_TITLE;
			break;
		case LUNCH:
			mealtime_title = LUNCH_TITLE;
			break;
		case DINNER:
			mealtime_title = DINNER_TITLE;
			break;
		default :
			std::cout << ERR_INVALID_CHOICE;
			return;
	}

	std::print("{}:\n{}\n", mealtime_title, std::string(strlen(mealtime_title)+1, '-'));
	std::println("        |{}|{}|{}|{}|{:>5}|", "carbohydrates", "protein", "fiber", "sugar", "fat");
	std::println("{:>8}|{:13}|{:7}|{:5}|{:5}|{:5}|",
			"food",
			calories_table[mealtime][FOOD][CARBOHYDRATES],
			calories_table[mealtime][FOOD][PROTEIN],
			calories_table[mealtime][FOOD][FIBER],
			calories_table[mealtime][FOOD][SUGAR],
			calories_table[mealtime][FOOD][FAT]);
	std::println("{:>8}|{:13}|{:7}|{:5}|{:5}|{:5}|",
			"beverage",
			calories_table[mealtime][BEVERAGE][CARBOHYDRATES],
			calories_table[mealtime][BEVERAGE][PROTEIN],
			calories_table[mealtime][BEVERAGE][FIBER],
			calories_table[mealtime][BEVERAGE][SUGAR],
			calories_table[mealtime][BEVERAGE][FAT]);
}

unsigned calculate_daily_calories(const unsigned calories_table[3][2][5])
{
	unsigned sum = 0;

	for (size_t mealtime = 0; mealtime < 3; ++mealtime) {
		for (size_t type = 0; type < 2; ++type) {
			for (size_t macro = 0; macro < 5; ++macro) {
				sum += calories_table[mealtime][type][macro];
			}
		}
	}

	return sum;
}
