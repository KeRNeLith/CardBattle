//
// Created by Kernelith on 24/11/2016.
//

#ifndef CARDBATTLE_CARDBATTLE_H
#define CARDBATTLE_CARDBATTLE_H

#include <algorithm>
#include <queue>
#include <sstream>
#include <string>

#include "Card.h"

/**
 * Game class handle the run of the game.
 */
class CardBattle
{
public:
    enum Player
    {
        Player1,
        Player2
    };

    using Deck = std::queue<Card>;

private:
    bool m_pat;                 ///< No winner flag.
    unsigned int m_nbRounds;    ///< Number of rounds played.

    Deck m_player1;     ///< Cards of player 1.
    Deck m_tmpPlayer1;  ///< Temporary set of card for player 1.

    Deck m_player2;     ///< Cards of player 2.
    Deck m_tmpPlayer2;  ///< Temporary set of card for player 2.

    /**
     * Get the top card of the specified player's deck.
     * @param player Player to get card.
     * @return Card.
     */
    Card& getCard(CardBattle::Player player);

    /**
     * Assign all discard and played cards to the given player.
     * @param player Player that will receive cards.
     */
    void assignCardsTo(CardBattle::Player player);

    /**
     * Simulate a round.
     */
    void duel();

    /**
     * Simulate the case when players have the same card value.
     */
    void battle();

public:
    /**
     * Default constructor.
     */
    CardBattle();

    /**
     * Destructor.
     */
    ~CardBattle() = default;

    /**
     * Add a card to the deck of the specified player.
     * @param player Player that will receive the card.
     * @param cardStr Card represented as string.
     */
    void addCard(CardBattle::Player player, const std::string& cardStr);

    /**
     * Play a round of game.
     */
    void playRound();

    /**
     * Check if the game is finished.
     * @return true if at least one player has no cards.
     */
    bool isFinished() const;

    /**
     * Get game result.
     * @return WinnerPlayer NbRound, otherwise PAT.
     */
    std::string getResult() const;
};


#endif // CARDBATTLE_CARDBATTLE_H
