# Tubes 1 IF2210: Candy Castle Card Game

## Table of Contents

- [Description](#description)
- [Program Requirements and Installation](#program-requirements-and-installation)
- [Get Started](#get-started)
- [Author](#author)

## Description
This is a CLI Based Card Game. The game based on a specific made up game called "Candy Game". 
Candu Game is a poker-like game with 6 rounds. At the end of each round one piece of table card taken from main deck. The game has 7 players, each starting with 0 points. Each player has a pair of hand card and one ability card given at round 2. The initial gift points are set to 64 and can dynamically increase/decrease based on each player's commands. Points are awarded at the end of round 6. The program offers a menu with two options for generating the order of cards in the deck: random or read from a file. During the game, players can choose from a list of commands: Double, Next, Half, and Ability. Winner determined at the end of 6 round as a player who has the highest combination of hand card and table card. The winner then receives the prize points while the other players receive nothing. The game ends when a player has accumulated 2^32 points or more. If no one reaches 2^32 points, the game restarts from the beginning round.

## Program Requirements and Installation
- C++ 11
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
3. Enter "help" for list of available commands and its description

## Author
- 13521060 / Fatih Nararya Rashadyfa I.
- 13521088 / Puti Nabilla Aidira
- 13521091 / Fakih Anugerah Pratama
- 13521130 / Althaaf Khasyi Atisomya
- 13521144 / Bintang Dwi Marthen

