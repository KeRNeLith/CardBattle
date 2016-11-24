//
// Created by Kernelith on 24/11/2016.
//

#ifndef CARDBATTLE_CARD_H
#define CARDBATTLE_CARD_H

#include <string>

class Card
{
public:
    // Card colors
    enum Suit
    {
        Club,       // Trèfle
        Diamond,    // Carreau
        Heart,      // Coeur
        Spade       // Pique
    };

    // Card values
    enum Value
    {
        Two = 2,
        Three,
        Four,
        Five,
        Six,
        Seven,
        Eight,
        Nine,
        Ten,
        Jack,
        Queen,
        King,
        Ace
    };

private:
    Suit m_color;   ///< Card suit.
    Value m_value;  ///< Card color.

public:
    /**
     * Constructor.
     * @param cardStr Representation of the card as string "ValueSuit"
     */
    Card(const std::string& cardStr);

    /**
     * Destructor.
     */
    ~Card() = default;

    // Accessors
    /**
     * Get card suit.
     * @return Card suit.
     */
    Card::Suit getSuit() const { return m_color; }

    /**
     * Get card value.
     * @return Card value.
     */
    Card::Value getValue() const { return m_value; }
};


#endif //CARDBATTLE_CARD_H
