#include "Trie.h"
#include "Node.h"

Trie::Trie(std::string fileName) {
    this->rootNode = new Node(); // Create a root node for the alphabet to branch from
    readFile(fileName); // Read in all original Wordle words and insert it into the trie starting at root
}

void Trie::playWordle() {
    std::string currGuess;
    std::string emptyString = "";
    std::string emptyStringSearch = "";
    std::string didWin;
    bool isValid;
    int numOfGuesses = 5; // The first guess happens outside main loop
    int numGrey;
    int numYellow;
    int numGreen;
    double percentChange;


    std::cout << "Lets play Wordle!" << std::endl;
    std::cout << "Number of words you have to work with: ";
    std::cout << this->trieSize << std::endl;
    this->prevSize = this->trieSize;
    this->trieSize = 0; // Reset the trie size so next turn it has updated size

    std::cout << "What is your first guess?: ";
    std::cin >> currGuess;

    for (int i = 0; i < currGuess.size() ; ++i) {
        currGuess[i] = std::tolower(currGuess[i]);  // Turn the current guess to lowercase to avoid case sensitivity
    }

    std::cout << "Lets make sure that word is a valid word" << std::endl;
    isValid = search(this->rootNode,currGuess,emptyStringSearch);

    while (!isValid){
        std::cout << "That is not a possible answer. Please enter a valid word: ";
        std::cin >> currGuess;
        isValid = search(this->rootNode,currGuess,emptyStringSearch);
    }

    std::cout << "That word is valid." << std::endl;

    std::cout << "Did you win?: ";
    std::cin >> didWin;
    std::cout << std::endl; // Formatting

    for (int i = 0; i < didWin.size() ; ++i) {
        didWin[i] = std::tolower(didWin[i]); // Covert to lowercase to avoid case sensitivity
    }


    if (didWin != "yes" && didWin != "y") {

        std::cout << "Enter number of green letters: "; // Do green first because this eliminates most possible words
        std::cin >> numGreen;
        if (numGreen != 0){
            removeGreen(numGreen);
        }

        std::cout << std::endl; // Formatting

        std::cout << "Enter number of grey letters: "; // Do green second because this will remove more possible words
        std::cin >> numGrey;
        if (numGrey != 0){
            removeGrey(numGrey);
        }

        std::cout << std::endl; // Formatting

        std::cout << "Enter number of yellow letters: "; // Do yellow last because you have to traverse through
        std::cin >> numYellow;                          // an entire word before determining if it doesn't have yellow
        if (numYellow != 0){                           // Doing grey and green first will reduce the amount of words
            removeYellow(numYellow);                  // to traverse through, thus a better time complexity
        }


        std::cout << std::endl; // Formatting

        std::cout << "Here are your current valid words: " << std::endl;
        printWords(this->rootNode, emptyString);
    }

    else {
        std::cout << "Congratulations! Please give us the auto A" << std::endl;
    }

    int i = 0;
    while (i < numOfGuesses && (didWin != "y" && didWin != "yes")) {
        std::cout << std::endl; // Formatting

        percentChange = (prevSize - trieSize); // Show the percentage change of the previous list
        percentChange /= prevSize;
        percentChange *= 100;

        if (this->trieSize != 1) {
            std::cout << "You have cut down the amount of possible words by " << percentChange << '%' << std::endl;
            std::cout << "Number of words you have to work with: ";
            std::cout << this->trieSize << std::endl;
            std::cout << std::endl;
        }

        if (this->trieSize == 1){  // If the size of the trie is 1, then we must be at out answer
            std::cout << "Your answer is: ";
            printWords(this->rootNode, emptyString);

            std::cout << std::endl;

            std::cout << "Did it work?:  "; // Ensure the Wordle solver worked
            std::cin >> didWin;

            for (int i = 0; i < didWin.size() ; ++i) {
                didWin[i] = std::tolower(didWin[i]); // Covert to lowercase to avoid case sensitivity
            }

            if (didWin != "y" && didWin != "yes"){
                std::cout << "We messed up somewhere..." << std::endl; // Since there is only 1 word left and
                break;                                                // we did not find it, we can exit program
            } else{
                std::cout << "Congratulations! Please give us the auto A" << std::endl; // pls give auto a
                break;
            }

        }


        std::cout << "Next guess: ";
        std::cin >> currGuess;

        for (int i = 0; i < currGuess.size() ; ++i) {
            currGuess[i] = std::tolower(currGuess[i]);  // Turn the current guess to lowercase to avoid case sensitivity
        }

        std::cout << "Lets make sure that word is a valid word" << std::endl; // Search to see if the word is possible
        isValid = search(this->rootNode,currGuess,emptyStringSearch);

        while (!isValid) { // If it is not a valid word, keep asking for a word until we guess one
            std::cout << "That is an invalid word. Please enter a valid word: ";
            std::cin >> currGuess;
            isValid = search(this->rootNode, currGuess, emptyStringSearch);
        }

        std::cout << "That word is valid." << std::endl;

        std::cout << "Did you win?: ";
        std::cin >> didWin;
        std::cout << std::endl; // Formatting

        for (int i = 0; i < didWin.size() ; ++i) {
            didWin[i] = std::tolower(didWin[i]); // Covert to lowercase to avoid case sensitivity
        }

        if (didWin != "y" && didWin != "yes") {
            std::cout << "Enter number of green letters: ";
            std::cin >> numGreen;
            if (numGreen != 0){
                removeGreen(numGreen);
            }

            std::cout << std::endl; // Formatting


            std::cout << "Enter number of grey letters: ";
            std::cin >> numGrey;
            if (numGrey != 0){
                removeGrey(numGrey);
            }

            std::cout << std::endl; // Formatting

            std::cout << "Enter number of yellow letters: ";
            std::cin >> numYellow;
            if (numYellow != 0){
                removeYellow(numYellow);
            }

            std::cout << std::endl; // Formatting

            // Print out current words
            std::cout << "Here are your current valid words: " << std::endl;
            this->prevSize = this->trieSize; // Store curr size before changing in print
            this->trieSize = 0; // Reset the trie size so next turn it has updated size
            printWords(this->rootNode, emptyString);


        } else {
            std::cout << "Congratulations! Please give us the auto A" << std::endl;
        }
        i++;
    }
}


void Trie::insert(std::string currWord) {
    Node *curr = this->rootNode; // Set the current node to root because we start traversing from here
    int letterLocation;

    for (int i = 0; i < 5; ++i) {  // Go up to 5 because every possible wordle word is only 5 chars
        letterLocation = currWord[i] - 'a'; // 'z' - 'a' ==  Index 25, 'c' - 'a' == 2 Index 2 etc.
        if (curr->children[letterLocation] == nullptr) {  // If there is no branch off at this node, make one
            curr->children[letterLocation] = new Node();
        }
        curr = curr->children[letterLocation]; // Set curr to the next letter of the word
    }
    curr->leafNode = true;  // Indicates the latest node is the last node / letter
}                          // in the word, indicating it is a full word



void Trie::printWords(Node *currNode, std::string currString){
    if (!currNode){ // If its null, no point in wasting time and checking its children
        return;
    }

    if (currNode->leafNode == true){             // If we got to the last node, that means we have reached the end
        std::cout << currString << std::endl;   // of a word, so it is safe to print out the contents of currString
        this->trieSize++; // Update the size of the trie,so we can equate the difference of words everytime
        return;
    }

    for (int i = 0; i < 26; ++i) {
        if (currNode->children[i] != nullptr){ // Check here because if the ith node is null,
                                              // there is no way for there to be a word from this current character


            currString += i + 'a'; // The character of the current node is equal to the
                                  // position of the node plus 'a' :eg 2 +'a' = c


            printWords(currNode->children[i], currString); // Go to the next node and find its non-null children
            currString.pop_back();
        }  // Remove the current string one by one
    }
}


void Trie::removeGreen(int numGreen) {
    char greenChar;
    char currGreenChar;
    int greenIdx;
    int currGreenIdx;
    std::string emptyString = "";
    std::vector<std::pair<char,int>> greenChars;  // .first will be the green char and .second will be its position

    std::cout << "Input your green letters followed by their position " << std::endl;

    for (int i = 0; i < numGreen; ++i) {
        std::cout << "Enter green letter: ";
        std::cin >> greenChar;
        greenChar = std::tolower(greenChar); // Avoid case sensitivity
        this->greenGreyChars.push_back(greenChar); // Add curr green char to list of chars,so we don't accidentally del

        std::cout << "Enter its position: ";
        std::cin >> greenIdx;

        greenChars.push_back({greenChar,greenIdx});
    }

    // For each green letter and index, check the current valid words and delete non-corresponding words
    for (int i = 0; i < greenChars.size(); ++i) {
        currGreenChar = greenChars[i].first;
        currGreenIdx = greenChars[i].second;
        removeNonGreenChar(this->rootNode, nullptr, NULL ,0,currGreenIdx,currGreenChar);
                                 // Set it to null not 0 so we dont del root           // We can start branch at
    }                                                                                 // 0 because the root is 0
}                                                                                    // So if the user puts 1
                                                                                    // It will still equate correct

void Trie::removeNonGreenChar(Node *currNode, Node *parentNode, int currI, int branch, int greenIdx, char greenChar) {
    if (branch == greenIdx) { // Once we get to the same depth of the index, we can check if that char is the same
        char charToDel= (currI + 'a'); // Calculate what the curr char. We pass i because that's the iteration of loop
        if (charToDel != greenChar){
                                // If the char does not equal it, it cant be a valid word, because the index must be
            delete parentNode->children[currI];
            parentNode->children[currI] = nullptr; // the given green char
            return; // We can return because there's no need to check further into this branch. Move to last branch
        }
    }

    for (int i = 0; i < 26; ++i) {
        if (currNode->children[i] != nullptr){
            int parentI = i;
            char currChar = i + 'a';
            removeNonGreenChar(currNode->children[i],currNode, i, branch + 1, greenIdx,greenChar); // Go to next branch
            if (checkIfNoChildren(currNode) && (!currNode->leafNode)){
                delete parentNode->children[i];
                parentNode->children[i] = nullptr;
                                 // Once we deleted the non green, the one above it can still be hanging there
            }                   // If it's not a leaf node, then it is not the end of a word, but also we check if
        }                      // it doesn't have children, because if it does, it is a prefix to another word, and
    }                         // we would lose connection to it if we deleted it
}


void Trie::removeGrey(int numGrey) {
    char greyLetter;
    std::cout << "Input your grey letters " << std::endl;

    for (int i = 0; i < numGrey; ++i) {
        std::cout << "Enter grey letter: ";
        std::cin >> greyLetter;
        greyLetter = std::tolower(greyLetter); // Avoids case sensitivity.
        if (checkIfGuessed(greyLetter)){
            std::cout << "Letter is already grey or green" << std::endl;
            continue; // If this letter has already been guessed (green or grey), no need to try and delete it
                     // If we do, we will seg fault by trying to delete a non-existent node, or we will null out a
                    // green letter. B/c if it is labeled as green in one spot, but grey in another, and we delete
                   // the letter bc it was grey, it will get rid of a possible word with the green char
        }
        this->greenGreyChars.push_back(greyLetter);
        removeGreyChars(this->rootNode, nullptr, NULL,' ', greyLetter);
                                                                  // Pass in an empty char so we don't accidentally
    }                                                            // delete anything on the first iteration
}

void Trie::removeGreyChars(Node *currNode, Node *parentNode, int currI, char currChar, char greyChar) {
    if (currChar == greyChar){ // If the current char were on is grey, we can delete it because it is not needed
                              // in the possible list of words
        delete parentNode->children[currI];
        parentNode->children[currI] = nullptr;
        return; // Return here, so we don't iterate past what we deleted
    }

    for (int i = 0; i < 26; ++i) {
        if (currNode->children[i] != nullptr){
            char currChar = i + 'a'; // Calculate the current char were on, which will associate with the curr Nodes
            removeGreyChars(currNode->children[i], currNode, i , currChar, greyChar); // child because that is where i is iterating
            if (checkIfNoChildren(currNode) && (!currNode->leafNode)){
                delete parentNode->children[i];
                parentNode->children[i] = nullptr;
                                 // Once we deleted the grey, the one above it can still be hanging there
            }                   // If it's not a leaf node, then it is not the end of a word, but also we check if
        }                      // it doesn't have children, because if it does, it is a prefix to another word, and
    }                         // we would lose connection to it if we deleted it
}


void Trie::removeYellow(int numYellow) {
    char yellowChar;
    char currYellowChar;
    int yellowIdx;
    int currYellowIdx;
    std::string emptyString = "";
    std::vector<std::pair<char,int>> yellowChars;

    std::cout << "Input your yellow letters followed by their position " << std::endl;

    for (int i = 0; i < numYellow; ++i) {
        std::cout << "Enter yellow letter: ";
        std::cin >> yellowChar;
        yellowChar = std::tolower(yellowChar); // Avoids case sensitivity

        if (checkIfGuessed(yellowChar)){  // If the letter is already green or grey, it is impossible to be yellow
            std::cout << "Letter is already grey or green" << std::endl;
            continue;
        }

        std::cout << "Enter its position: ";
        std::cin >> yellowIdx;

        yellowChars.push_back({yellowChar,yellowIdx});
    }

    // For each yellow letter check the current trie and delete non-corresponding words
    for (int i = 0; i < yellowChars.size(); ++i) {
        currYellowChar = yellowChars[i].first;
        currYellowIdx = yellowChars[i]. second;
        removeNonYellowWord(this->rootNode, nullptr,NULL, NULL, currYellowChar);
        removeWordsAtYellowIdx(this->rootNode, nullptr, NULL,0, currYellowIdx, currYellowChar);
    }
}

bool Trie::removeNonYellowWord(Node *currNode, Node *parentNode,int currI, char currChar,char yellowChar) {
    if (currChar == yellowChar) { // If at anypoint the current character is equal to the yellow char, then curr word
        return true;             // is a valid word
    }

    if (currNode->leafNode) {
        delete parentNode->children[currI];
        parentNode->children[currI] = nullptr;
        return false; // Can return false here because if we did not hit the first return, and we are on the last
    }                // node, then that means the entire word did not have a yellow

    for (int i = 0; i < 26; ++i) {
        if (currNode->children[i] != nullptr) {
            char currChar = i + 'a'; // Create current char by the ith position in the alphabet if child is not null
            bool yellowInWord = removeNonYellowWord(currNode->children[i], currNode, i, currChar, yellowChar);
            if (checkIfNoChildren(currNode) && (!yellowInWord)) {     // Since recursion just finished, we go back to the
                delete parentNode->children[i];                  // previous node. If it doesn't have anymore children
                parentNode->children[i] = nullptr;              // that means it is not a prefix to any other word
            }                                                      // so it is safe to delete that node as well. Then repeat
        }
    }
}

//// This function is exactly the same as remove green EXCEPT that if the current character at the designated branch
//// is equal to yellow, we delete this word. This is because if you guess a letter at a specific location and
//// it is yellow, that word can NOT be an answer. Example: Calfs, L is yellow at position 3. All words
/// must include the letter L, but since L was not green, words with L at position 3 are invalid.
void Trie::removeWordsAtYellowIdx(Node *currNode, Node *parentNode, int currI, int branch, int yellowIdx,
                                  char yellowChar) {
    if (branch == yellowIdx) { //
        char charToDel= (currI + 'a');
        if (charToDel == yellowChar){;
            delete parentNode->children[currI];
            parentNode->children[currI] = nullptr;
            return;
        }
    }

    for (int i = 0; i < 26; ++i) {
        if (currNode->children[i] != nullptr){
            char currChar = i + 'a';
            removeWordsAtYellowIdx(currNode->children[i],currNode, i, branch + 1, yellowIdx,yellowChar);
            if (checkIfNoChildren(currNode) && (!currNode->leafNode)){
                delete parentNode->children[i];
                parentNode->children[i] = nullptr;
            }
        }
    }

}


bool Trie::checkIfNoChildren(Node *currNode) {
    bool hasNoChild = true;

    for (int i = 0; i < 26 ; ++i) {             // Go through the entire alphabet, if that node has a child
        if (currNode->children[i] != nullptr){  // that means that node is part of another word, so we can't delete it
            hasNoChild = false;                 // If we deleted it, we would lose connection to another word
            return hasNoChild; // Return right when we find out it has a child, so we don't waste time checking others
        }
    }
    return hasNoChild;
}

bool Trie::checkIfGuessed(char currChar) {
    for (int i = 0; i < this->greenGreyChars.size(); ++i) {
        if (currChar == this->greenGreyChars[i]){
            return true; // If char has been used before as a grey or green, we don't want to accidentally delete it
        }
    }
    return false;
}


bool Trie::search(Node *currNode, std::string desiredString, std::string currString) {
    if (desiredString.length() != 5){ // Can immediately return false here because every Wordle guess must be 5 chars
        return false;
    }

    if (currString == desiredString) { // If we have built the string we are searching for then we can return true
        return true;
    }

    for (int i = 0; i < 26; ++i) {
        if (currNode->children[i] != nullptr) {
            currString += i + 'a';
            if (search(currNode->children[i],desiredString, currString)){
                return true;
            }
            currString.pop_back();
        }
    }
    return false; // This is if we have built all possible strings and the word was never found
}


void Trie::readFile(std::string fileName) {
    std::ifstream file(fileName); // Open file
    std::string str;

    while (std::getline(file, str)) { // read in file line by line and append it to a vector
        insert(str); // Append to the trie word by word to save memory on using a vector of words
        this->trieSize++;
        this->originalSize = this->trieSize;
    }

    file.close();
}


int Trie::getTrieSize(){
    return this->trieSize;
}


int Trie::getOriginalSize() {
    return this->originalSize;
}
