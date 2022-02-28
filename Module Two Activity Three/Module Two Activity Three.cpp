// BufferOverflow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip> // Will use this for std::setw
#include <iostream>

int main()
{
	std::cout << "Buffer Overflow Example" << std::endl;

	// TODO: The user can type more than 20 characters and overflow the buffer, resulting in account_number being replaced -
	//  even though it is a constant and the compiler buffer overflow checks are on.
	//  You need to modify this method to prevent buffer overflow without changing the account_order
	//  varaible, and its position in the declaration. It must always be directly before the variable used for input.

	const std::string account_number = "CharlieBrown42";
	std::string initial_input;
	char user_input[20];
	std::cout << "Enter a value: ";

	std::cin >> std::setw(21) >> initial_input; // Put their input into initial_input while setting a maximum width of 21 characters (since obviously anything after 20 is the overflow)
	if (initial_input.length() > 20) { // If the string exceeds 20 characters, it's an overflow
		std::cout << "You have exceeded the 20 character limit. Terminating the program.." << std::endl;

		return false;
	}

	strcpy_s(user_input, 20, initial_input.c_str()); // Copy the string onto the char array

	std::cout << "You entered: " << user_input << std::endl;
	std::cout << "Account Number = " << account_number << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
