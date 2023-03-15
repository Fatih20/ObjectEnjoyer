#ifndef _PLAYER_HPP
#define _PLAYER_HPP

#include <cstring>
#include <string>
#include <exception>
#include <vector>
#include "../DeckPlayer/DeckPlayer.hpp"
#include "../InventoryHolder/InventoryHolder.hpp"

using namespace std;

template <typename T>
class Player : InventoryHolder<T>
{
private:
    int gameID;
    string username;
    double score;
    DeckPlayer<T> handCards;

    /**
     * @brief Ask for username from the user
     *
     */
    string askForUsername();

protected:
    /**
     * @brief Set the gameID of the player
     *
     * @param gameID
     */
    void setGameID(int gameID);

public:
    /**
     * @brief Construct a new Player object
     *
     */
    Player();

    /**
     * @brief Construct a new Player object. Menanyakan username pemain melalui CLI.
     *
     */
    Player(int gameID);

    /**
     * @brief Destroy the Player object
     *
     */
    ~Player();

    /**
     * @brief Construct a new player object from another player
     *
     */
    Player(const Player &);

    /**
     * @brief Assign a player to another player with the assignment operator
     *
     */
    Player &operator=(const Player &);

    /**
     * @brief Get the username of the player
     *
     * @return string
     */
    string getUsername() const;

    /**
     * @brief Get the handCards attribute
     * 
     * @return DeckPlayer<T> 
     */
    DeckPlayer<T> getHandCards() const;

    /**
     * @brief Return the gameID of the object
     *
     * @return int
     */
    int getGameID();

    /**
     * @brief Get the player's score
     *
     * @return int
     */
    double getScore();

    /**
     * @brief Add score to the player
     *
     * @param addedScore
     */
    void operator+=(double addedScore);

    /**
     * @brief Subtract the player's score
     *
     * @param subtractedScore
     */
    void operator-=(double subtractedScore);

    /**
     * @brief Add card to the player
     *
     * @param addedCard
     */
    void operator+=(const T &addedCard);

    /**
     * @brief Compare the player's score
     *
     * @return true Left player's score is lower than the right
     * @return false Left player's score is not lower than the right player
     */
    bool operator<(const Player<T> &);

    /**
     * @brief Compare the player's score
     *
     * @return true Left player's score is higher than the right
     * @return false Left player's score is not higher than the right player
     */
    bool operator>(const Player<T> &);

    /**
     * @brief Compare the player's score
     *
     * @return true Left player's score is higher or equal to the right player
     * @return false Left player's score is not higher and not equal than the right player
     */
    bool operator>=(const Player<T> &);

    /**
     * @brief Compare the player's score
     *
     * @return true Left player's score is lower or equal to the right player
     * @return false Left player's score is not lower and not equal than the right player
     */
    bool operator<=(const Player<T> &);

    /**
     * @brief Compare the player's score
     *
     * @return true Left player's score is equal to the right player
     * @return false Left player's score is not equal to the right player
     */
    bool operator==(const Player<T> &);

    /**
     * @brief Compare the player's score
     *
     * @return true Left player's score is not equal to the right player
     * @return false Left player's score is equal to the right player
     */
    bool operator!=(const Player<T> &);

    /**
     * @brief Subtract the player's score
     *
     * @param subtractedScore
     */
    void subtractScore(double subtractedScore);

    /**
     * @brief Add score to the player
     *
     * @param addedScore
     */
    void addScore(double addedScore);

    /**
     * @brief Reset the player's score to 0
     *
     */
    void resetScore();

    /**
     * @brief Swap the deck of this player and the given player
     *
     * @param givenPlayer
     */
    void swapDeck(Player<T> &givenPlayer);

    /**
     * @brief Ask username from the user and validate its result until it's correct
     *
     */
    void setValidUsername();

    /**
     * @brief Print out the score
     *
     */
    void printScore();

    /**
     * @brief Print out the player's card
     *
     */
    void printColorCard();

    /**
     * @brief Add card to player's hand
     *
     * @param card
     */
    void addCard(const T &card);

    /**
     * @brief Draw numberOfCard amount of card for the player from the given deck game.
     *
     * @param deckGame
     * @param numberOfCards
     */
    void drawCard(DeckGame<T> &deckGame, int numberOfCards);

    /**
     * @brief Return all of the cards in this player's hands to the deckGame and retake a numberOfCards of new card from it
     *
     * @param deckGame
     * @param numberOfCards
     */
    void redrawCard(DeckGame<T> &deckGame, int newNumberOfCards);

    /**
     * @brief Return all of the cards in this player's hands to the deckGame and retake a the same amount of cards the player has before
     *
     * @param deckGame
     */
    void redrawCard(DeckGame<T> &deckGame);
    /**
     * @brief Return 1 if this player is higher, 0 if same, -1 if this player is lower
     *
     * @param otherPlayer
     * @param deckGame
     * @return int
     */
    int compareCombinationWeight(const Player<T> &otherPlayer, const DeckGame<T> &deckGame);

    /**
     * @brief Return true if we have equal combination weight
     *
     * @param otherPlayer
     * @param deckGame
     * @return int
     */
    bool equalCombinationWeight(const Player<T> &otherPlayer, const DeckGame<T> &deckGame);

    /**
     * @brief Return true if this player have lower combination weight
     *
     * @param otherPlayer
     * @param deckGame
     * @return true
     * @return false
     */
    bool lowerCombinationWeight(const Player<T> &otherPlayer, const DeckGame<T> &deckGame);

    /**
     * @brief Return true if this player have bigger combination weight
     *
     * @param otherPlayer
     * @param deckGame
     * @return true
     * @return false
     */
    bool higherCombinationWeight(const Player<T> &otherPlayer, const DeckGame<T> &deckGame);

    // Overloading untuk ngurusin deck nggak diimplementasikan dulu karena urusannya sama deck
    /*
    void operator+(Card<CardValueType> addedCard);
    */

    template <typename Y>
    friend std::ostream &operator<<(std::ostream &os, const Player<Y> &player);
};

#endif