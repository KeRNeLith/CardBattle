//
// Created by Kernelith on 24/11/2016.
//

#include "Card.h"

Card::Card(const std::string& cardStr)
{
    // Compute card suit and value
    for (const auto& character : cardStr)
    {
        switch (character)
        {
            // Cases for suit
            case 'C':
                m_color = Suit::Club;
                break;
            case 'D':
                m_color = Suit::Diamond;
                break;
            case 'H':
                m_color = Suit::Heart;
                break;
            case 'S':
                m_color = Suit::Spade;
                break;

                // Cases for value
            case 'J':
                m_value = Value::Jack;
                break;
            case 'Q':
                m_value = Value::Queen;
                break;
            case 'K':
                m_value = Value::King;
                break;
            case 'A':
                m_value = Value::Ace;
                break;
            case '0':   // Special case for ten
                m_value = Value::Ten;
                break;

                // Case of simple values
            default:
                m_value = Card::Value(character - '0');
                break;
        }
    }
}