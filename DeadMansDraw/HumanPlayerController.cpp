#include "HumanPlayerController.h"
#include <iostream>

HumanPlayerController::HumanPlayerController()
{
    // I'm going to put HumanPlayerController constructor logic here
}

HumanPlayerController::~HumanPlayerController()
{
    // I'm going to put HumanPlayerController destructor logic here
}

bool HumanPlayerController::wantsToDraw(const Player& player)
{
    std::cout << "Draw again? (y/n): ";
    char input;
    std::cin >> input;
    return (input == 'y' || input == 'Y');
}
