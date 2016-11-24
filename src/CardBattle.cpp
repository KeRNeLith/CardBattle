//
// Created by Kernelith on 24/11/2016.
//

#include "CardBattle.h"

CardBattle::CardBattle()
        : m_pat(false)
        , m_nbRounds(0)
        , m_player1()
        , m_tmpPlayer1()
        , m_player2()
        , m_tmpPlayer2()
{
}

// Private function
Card& CardBattle::getCard(CardBattle::Player player)
{
    Deck& deck = player == Player::Player1 ? m_player1 : m_player2;
    Deck& tmpDeck = player == Player::Player1 ? m_tmpPlayer1 : m_tmpPlayer2;

    Card& card = deck.front();
    tmpDeck.push(card);
    deck.pop();

    return card;
}

void CardBattle::assignCardsTo(CardBattle::Player player)
{
    Deck& targetDeck = player == Player::Player1 ? m_player1 : m_player2;

    // Cards from player 1
    while (!m_tmpPlayer1.empty())
    {
        targetDeck.push( m_tmpPlayer1.front() );
        m_tmpPlayer1.pop();
    }

    // Cards from player 2
    while (!m_tmpPlayer2.empty())
    {
        targetDeck.push( m_tmpPlayer2.front() );
        m_tmpPlayer2.pop();
    }
}

void CardBattle::duel()
{
    Card& cardP1 = getCard(Player::Player1);
    Card& cardP2 = getCard(Player::Player2);

    // Player 2 win round
    if (cardP1.getValue() < cardP2.getValue())
    {
        assignCardsTo(Player::Player2);
    }
        // Player 1 win round
    else if (cardP1.getValue() > cardP2.getValue())
    {
        assignCardsTo(Player::Player1);
    }
        // Same card value => Battle
    else
    {
        battle();
    }
}

void CardBattle::battle()
{
    // At least one player hasn't enough cards to continue (discard + duel)
    if (m_player1.size() < 4 || m_player2.size() < 4)
    {
        m_pat = true;
    }
    else
    {
        for (unsigned int i = 0 ; i < 3 ; ++i)
        {
            getCard(Player::Player1);
            getCard(Player::Player2);
        }

        duel();
    }
}

// Public Interface
void CardBattle::addCard(CardBattle::Player player, const std::string& cardStr)
{
    Deck& playerDeck = player == Player::Player1 ? m_player1 : m_player2;
    playerDeck.push( Card(cardStr) );
}

void CardBattle::playRound()
{
    ++m_nbRounds;

    duel();
}

bool CardBattle::isFinished() const
{
    return m_pat || m_player1.empty() || m_player2.empty();
}

std::string CardBattle::getResult() const
{
    std::stringstream ss;

    if (m_pat)
    {
        ss << "PAT";
    }
    else
    {
        ss << (m_player1.empty() ? 2 : 1) << " " << m_nbRounds;
    }

    return ss.str();
}