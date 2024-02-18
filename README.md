# Prisoner's Dilemma
This project is a C++ implementation of the classic game theory problem known as the Prisoner's Dilemma. It simulates the interactions between two players who must decide whether to cooperate or betray each other, leading to different outcomes based on their decisions.
<br><br>
The game follows some simple rules:<br>
- There are 20 rounds in total, each comprising of 10 turns for each player.
- If both players cooperate, they both receive a moderate sentence.<br>
- If one player betrays while the other cooperates, the betrayer receives no sentence while the cooperator receives a severe sentence.<br>
- If both players betray each other, they both receive a moderate sentence.
<br><br>

This project was inspired by the video ["What Game Theory Reveals About Life, The Universe, and Everything"](https://www.youtube.com/watch?v=mScpHTIi-kM&t=1040s&pp=ygUKdmVyaXRhc2l1bQ%3D%3D) by Veritasium. 
<br>
["Tabulate"](https://github.com/p-ranav/tabulate) by p-ranav was used to tabulate the data. 
<br><br>

You may simply clone the repository to your machine and run the command
```bash
g++ main.cpp
./a.out
```
to run the game.
<br><br>
Furthermore, one can also add more strategies in ```strategies.h``` to implement unique decision-making approaches.
