# Rock-Paper-Scissor-Game
This game has one master and two players.

The rules are given below:

If first player chooses rock and second player chooses scissor then master will give one point to the first player.
If first player chooses rock and second player chooses paper then master will give one point to the second player.
If first player chooses scissor and second player chooses paper then master will give one point to the first player.
If both the players chooses the same either rock, paper and scissor, then master will give the half point each to both players.

Player reaching more than 10 points first will win the game.

Write a C program to implement the following rock paper scissor game as simulating master as parent and players as two child process.
The parent program P first creates two pipes and spawns two child processes C and D. One of the two pipes is meant for communications between P and C, and the other for communications between P and D. Now, a loop runs as follows.

The program uses three types of codes: 
1 -- paper
2 -- scissor
3 -- rock

Step 1: In each iteration (also called round), P sends ready signal to the children C and D using signal handler not pipe.
Step 2: After receiving the ready signal, each of the two child processes C and D generates a random positive integer from 1 to 3(i.e. code 1 for paper) and sends that to P via its pipe.
Step 3: P reads the two integers and depending upon the above signal, it will increase the points of one or both the childs according to above 4 game rules.
Step 4: The child process who first obtains more than ten points wins the game, if there is a tie then parent will generate two random number, if the first generated number is bigger than second. then child one wins the game and vice versa.
Step 5: When the game ends, P sends a user-defined signal to both C and D, and the child processes exit after handling the signal (in order to know who was the winner). After C and D exit, the parent process P exits.

Important : During each iteration of the game, P should print appropriate messages (like P's printing the score after each round and childs are printing their random numbers.
