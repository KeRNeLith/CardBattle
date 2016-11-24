#include <cstdlib>

#include <fstream>
#include <iostream>

#include "src/CardBattle.h"

/**
 * Read an input file to initialize the game.
 * @param fileName File name.
 * @param game Game to initialize.
 */
void initGame(const std::string& fileName, CardBattle& game);

/**
 * MAIN FUNCTION.
 * @param argc Number of arguments.
 * @param argv Arguments : argument 1 is input file name.
 * @return EXIT_SUCCESS.
 */
int main(int argc, char** argv)
{
    std::string inputFileName = "inputs/test1.in.txt";
    if (argc >= 2)  // First program parameter as input file
    {
        inputFileName = argv[1];
    }

    // Game object
    CardBattle game;

    // Read input file to init game
    initGame(inputFileName, game);

    // Play the game
    while (!game.isFinished())
    {
        game.playRound();
    }

    // Result
    std::cout << game.getResult() << std::endl;

    return EXIT_SUCCESS;
}

void initGame(const std::string& fileName, CardBattle& game)
{
    std::ifstream inputFile(fileName);
    unsigned int nbCards = 0;
    std::string card;

    // Cards for player 1
    inputFile >> nbCards;
    for (unsigned int i = 0 ; i < nbCards ; ++i)
    {
        inputFile >> card;
        game.addCard(CardBattle::Player::Player1, card);
    }

    // Cards for player 2
    inputFile >> nbCards;
    for (unsigned int i = 0 ; i < nbCards ; ++i)
    {
        inputFile >> card;
        game.addCard(CardBattle::Player::Player2, card);
    }

    inputFile.close();
}