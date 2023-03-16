# Tubes 1 IF2210: Candy Castle Card Game

## Table of Contents

- [Description](#description)
- [Program Requirements and Installation](#program-requirements-and-installation)
- [Get Started](#get-started)
- [Author](#author)

## Description
This is a CLI Based Card Game. The game based on a specific made up game called "Candy Game". 
Candy Game is a poker-like game with 6 rounds. At the end of each round one piece of table card taken from main deck. The game has 7 players, each starting with 0 points. Each player has a pair of hand card and one ability card given at round 2. The initial gift points are set to 64 and can dynamically increase/decrease based on each player's commands. Points are awarded at the end of round 6. The program offers a menu with two options for generating the order of cards in the deck: random or read from a file. During the game, players can choose from a list of commands: Double, Next, Half, and Ability. Winner determined at the end of 6 round as a player who has the highest combination of hand card and table card. The winner then receives the prize points while the other players receive nothing. The game ends when a player has accumulated 2^32 points or more. If no one reaches 2^32 points, the game restarts from the beginning round.

Bonus: 
This program also includes "cangkul" card game.
With the following rules:
This game is played by two people (one-on-one), and it is done so that the game can be quickly finished because this game is considered a "side game" compared to the main card game. Players can only release/play a card that has the same color as the card that is currently being played. If a player does not have a card that can be released/played, then they must do "cangkul" (take card from discard pile) until they get a playable card. If the draw pile is empty, even if a player does not have a card that can be played, they must take the top card from the discard pile. Players can only "cangkul" and take from the discard pile if they do not have a card that can be played. As long as they have a playable card, they must play it. The winner is the player who first finishes all the cards in their hand.

## Program Requirements and Installation
C++ 17
```markdown
// installation 
sudo apt-get install gcc g++ clang -y
```

## Get Started
1. Run makefile
  ```markdown
  % make run
  ```
2. Enter commands/options as instructed
3. Enter "help" for list of available commands and its description (only available in Game Candy)
4. If you wish to input deck from file follow this file format:
  ```markdown
  <color><space><value>
  <color><space><value>
  ...
  -
  <ability-type>
  ```
  color format: G = green, B = blue, R = red, Y = yellow
  value format: 1 - 13
  ability-type format: REROLL, QUADRUPLE, QUARTER, REVERSE, SWAP, SWITCH, ABILITYLESS.
  color card input must be between 21 - 52 cards
  ability card input must be exactly 7

## Author
- 13521060 / Fatih Nararya Rashadyfa I.
- 13521088 / Puti Nabilla Aidira
- 13521091 / Fakih Anugerah Pratama
- 13521130 / Althaaf Khasyi Atisomya
- 13521144 / Bintang Dwi Marthen

