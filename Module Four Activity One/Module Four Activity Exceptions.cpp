// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

bool do_even_more_custom_application_logic()
{
    // TODO: Throw any standard exception
    throw std::length_error("Some length error");
    std::cout << "Running Even More Custom Application Logic." << std::endl;

    return true;
}

// My class for my custom exception
class custom_Exception {
public:
    std::string what(void) {
        return "a custom return!";
    }
};
void do_custom_application_logic()
{
    // TODO: Wrap the call to do_even_more_custom_application_logic()
    //  with an exception handler that catches std::exception, displays
    //  a message and the exception.what(), then continues processing
    std::cout << "Running Custom Application Logic." << std::endl;

    try {
        if (do_even_more_custom_application_logic())
        {
            std::cout << "Even More Custom Application Logic Succeeded." << std::endl;
        }
    }
    catch (std::exception& e) {
        std::cout << "Standard exception caught: " << e.what() << std::endl;
    }
    

    // TODO: Throw a custom exception derived from std::exception
    //  and catch it explictly in main
    throw custom_Exception();
    std::cout << "Leaving Custom Application Logic." << std::endl;

}

float divide(float num, float den)
{
    // TODO: Throw an exception to deal with divide by zero errors using
    //  a standard C++ defined exception
    if (den == 0) {
        throw std::invalid_argument("Denominator cannot be zero!");
    }

    return (num / den);
}

void do_division() noexcept
{
    //  TODO: create an exception handler to capture ONLY the exception thrown
    //  by divide.

    float numerator = 10.0f;
    float denominator = 0;

    try {
        auto result = divide(numerator, denominator);
        std::cout << "divide(" << numerator << ", " << denominator << ") = " << result << std::endl;
    }
    catch (std::invalid_argument& e) {
        std::cout << "Division Error: " << e.what() << std::endl;
    }
}

int main()
{
    try {
        std::cout << "Exceptions Tests!" << std::endl;

        // TODO: Create exception handlers that catch (in this order):
        //  your custom exception
        //  std::exception
        //  uncaught exception 
        //  that wraps the whole main function, and displays a message to the console.
        do_division();
        do_custom_application_logic();
    }
    catch (custom_Exception e) {
        std::cout << "caught my custom exception: " << e.what() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Standard exception caught: " << e.what() << std::endl;
    }
    catch (...) {
        std::cout << "Woah an uncaught exception!" << std::endl;
    }
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu