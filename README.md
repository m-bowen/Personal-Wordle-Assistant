# Wordle Personal Assistant
Final Project for CSC 212 Data Structures and Abstractions. Created by Mark Bowen, John Ruscito, Jenna Sasson, and Ellie Oswald. 

# What is the Project?
This project applies the Trie Data Structure to create a Wordle helper. At the beginning of runtime, a Trie is created that will store the ~2,300 possible solutions provided by the Wordle website. As the game is played, a user can use the Personal Assistant to find possible solutions much quicker than thinking on their own. During runtime, the user is prompted to enter the output from the game (i.e. green letters and their respective positions, yellow letters, and grey letters). The Personal Assistant also reports the percentage of words cut down by the latest guess. 

### Visual of How a Trie Works
![Trie Example](https://github.com/m-bowen/Personal-Wordle-Assistant/blob/main/trie_example.jpg?raw=true)


# How to Compile & Run
- Download the files from github.
- Run the following command to compile the files:
```g++ -std=c++14 -Wall main.cpp Node.cpp Trie.cpp -o WordlePersonalAssistant```
- Run the following command after:
```./WordlePersonalAssistant```

### How To Compile Visualizer
- Download SFML Visualizer Folder
- Run the Following Command:
```g++ -c SFML_Visualizer.cpp -I/SFML-2.1/include```
- Run the following command after:
```g++ SFML_Visualizer.o SFML_Visualizer -lsfml-graphics -lsfml-system -lsfml-window```
- Then run the following command to view it:
```./SFML_Visualizer```
