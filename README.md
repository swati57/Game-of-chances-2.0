# **Game of Chances**  
## Overview:
 
Game of Chances is a fun quiz game developed in C as a class project. 
It runs in CLI and gives you and your friends little competetive platform to test General Knowledge. 

**Concepts learnt:** 
 - Fundamentals of Programming 
 - Function callings 
 - Header files and their uses 
 - Linkage of multiple files
 - Basic sorting technique (Bubble sort) 
 - Arrays 
 - Structs 
 - File Handling

**Challenges we overcame:** 

 - Continuous Development and Integration 
 - UI fixes 
 - .txt file usage from secondary storage 
 
 
## Guide to install and run the project
**GitHub Setup :**
- Fork the repository 
- Check the forked repository in your profile 
- Clone the project

**Local Setup :**

 - Create a folder and open it
 - For windows: Open git bash / For Linux: Open terminal and cd to that folder 
 - Clone the repository from link below 
```git clone https://github.com/SrijitaSarkar99/Game-of-chances-2.0.git```
- Compile the files and turn them into an executable file called run 
```gcc -o run main.c inputDet.c game.c fetchQues.c evaluate.c eliminateOne.c LeaderBoard.c```
- Now, run the  executable file called run 
```./run```

### Guide to contribute :
- Set original repo as your upstream remote
```git remote add upstream https://github.com/SrijitaSarkar99/Game-of-chances-2.0.git```
- Pull updates from upstream 
```git pull upstream```
- Make changes locally and push it your forked copy of the project 
- Create a pull request in GitHub

### Guide to use the project

 - Upon running you'll be shown a Menu and asked to enter the choice between "Start Game", "Leaderboard" and "Exit" 
 - On "Start Game", you'll be asked to enter details of players and game begins.
 - Each player is asked to enter a solution to the given problem and elemination is done accordingly. 
 - After each round score tally is shown. 
 - The game ends when every player is eleminated and Leaderboard is shown.
 - On choosing "Leaderboard", data of past games is displayed. 
 - "Exit" option ends the game.
