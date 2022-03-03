# 2player-dice
A simple dice roller for 2 players.

The game lasts five rounds, each "player" takes a turn rolling two six-sided dice. If two of the same value are rolled, a third dice is rolled, and the 
total is added to the players score.
If the total is even, an additional ten points are added, if the total is off, five points are subtracted.
The players total score should not fall below zero.

Dice rolling is done automatically by calling the function "rollDice()" and providing it with the players' current total score e.g. value = rollDice(p1Total);
This function uses rand() to roll the dice, rand() % 5 + 1 will provide a number between 1 and 6, like a dice.
