/*
 Jonard Bolante
 Professor Ryan
 CS280-005
 October 1st, 2017
 PROGRAM 1
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include <iterator>
#include <string>

using namespace std;

int main(int argc, char*argv[] ) {
    if (argc <= 1) {
        cerr << "NO FILES" << endl;
        return -1;
    }
    ifstream myFileToRead;
    std::string nameOfFile("");
    bool cUsed = false;
//    bool mUsed = false;
//    bool bUsed = false

    for (int i = 1; i < argc; i++) {
        nameOfFile = argv[i];
        if(nameOfFile.find("-") == 0) {
            if (nameOfFile == string("-c"))
                cUsed = true;
/*        else if (nameOfFile == string("-m"))
            mUsed = true;
        else if (nameOfFile == string("-b"))
            bUsed = true;
*/          else
            {
                cerr << nameOfFile + " UNRECOGNIZED FLAG" << endl;
                return -1;
            }
        }
        else
            continue;
    }




    if (cUsed) {
        for (int i = 1; i<argc; i++) {                            // LETS LOOP THROUGH ALL ARGUMENTS
            std::string fileContents("");
            int longestLine = 0;
            int lineLength = 0;
            vector<string> longestWordList;
            vector<string> wordList;
            vector<string> lineList;
            nameOfFile = argv[i];                               // Temporary string contains the name of the file. Now I can do whatever I want with it.
            if (nameOfFile == string("-c"))
                continue;
            myFileToRead.open(argv[i]);                         // OPENS FILE
            if (myFileToRead.is_open() == false)                 // CHECK IF OPEN WAS SUCCESSFUL
                printf("%s FILE NOT FOUND\n", argv[i]);
            else {                                                   // IF SUCCESSFULLY OPEN, DO THIS:
                // STORE ALL CONTENTS FROM THE FILE INTO MY ARRAY(or Vector)
                while (!myFileToRead.eof()) {                     // while theres something in my file,
                    getline(myFileToRead, fileContents);        // get line-by-line and store in string
                    lineList.push_back(fileContents);           // store that LINE in to my array
                }
                // FIND LONGEST LINE
                for (int i = 0; i < (signed) lineList.size(); i++)     // loop through the entire array(which is line by line)
                    if (lineList[i].size() > (unsigned) lineLength) {
                        lineLength = lineList[i].size();
                        longestLine = i;                               // longestLine represents the index of the list
                    }
                // COUNT HOW MANY TIMES THE LINE APPEARS IN FILE
                int countLongestLines = 0;
                for (int i = 0; i < (signed) lineList.size(); i++)
                    if (lineList[i].size() == lineList[longestLine].size())
                        countLongestLines += 1;
                // FIND THE LONGEST WORD IN THE ENTIRE FILE. INCLUDE REPEATING WORDS
                std::string longestWord("");
                map<string, int> myMap;
                for (unsigned i = 0; i < lineList.size(); i++) {          // Creating a vector(array) that holds a word for every index
                    std::string line(lineList[i]);
                    std::string bufferStr("");                       // SPLITTING THE ENTIRE STRING AND
                    stringstream ss(line);                            // PLACING IT INTO MY VECTOR
                    while (ss >> bufferStr) {
                        wordList.push_back(bufferStr);
                    }
                }
                for (int i = 0; i < (signed) wordList.size(); i++)        // loop through the all the words in file
                    if (wordList[i].length() > longestWord.length())
                        longestWord = wordList[i];                      // Take only the longest WORD. Not wordS and store it
//          longestWord now contains the longest WORD - not wordS
                int countLongWords = 0;
                string temp = "";
                for (int i = 0; i < (signed) wordList.size(); i++) {
                    countLongWords = 0;
                    if (wordList[i].length() == longestWord.length()) {    // If there are other words with the same length(longest words), add to my map
                        temp = wordList[i];
                        for (int i = 0; i < (signed) wordList.size(); i++)
                            if (temp == wordList[i])
                                countLongWords++;
                        myMap[wordList[i]] = countLongWords;
                    }
                }
                cout << argv[i] << ":" << endl;
                for (std::map<string, int>::iterator it = myMap.begin(); it != myMap.end(); ++it) {
                    if ((it != myMap.end()) && (next(it) == myMap.end())) {     // <-- checks whether if its the last element of map
                        cout << it->first;
                        cout << "(" << it->second << ")"<<endl;
                    } else
                        std::cout << it->first << "(" << it->second << ")" << ", ";
                }
                string longestLineeee = lineList[longestLine];
                cout << longestLineeee.length() << "(" << countLongestLines << ")" << endl;
                myFileToRead.close();
            }
        }
    }
    else{
        for (int i = 1; i < argc; i++) {
            std::string fileContents("");
            int longestLine = 0;
            int lineLength = 0;
            vector<string> longestWordList;
            vector<string> wordList;
            vector<string> lineList;
            myFileToRead.open(argv[i]);                             // OPENS FILE
            if (myFileToRead.is_open() == false)                    // CHECK IF OPEN WAS SUCCESSFUL
                printf("%s FILE NOT FOUND\n", argv[i]);
            else {                                                   // IF SUCCESSFULLY OPEN, DO THIS:
/*
 _______________________________________________________________________________________
 _______________________________________________________________________________________
 _______________________________________________________________________________________
 _______________________________________________________________________________________
 _______________________________________________________________________________________
 _______________________________________________________________________________________
*/
                // STORE ALL CONTENTS FROM THE FILE INTO MY ARRAY(or Vector)
                while (!myFileToRead.eof()) {                     // while theres something in my file,
                    getline(myFileToRead, fileContents);        // get line-by-line and store in string
                    lineList.push_back(fileContents);           // store that LINE in to my array
                }
                // FIND LONGEST LINE
                for (int i = 0;
                     i < (signed) lineList.size(); i++)     // loop through the entire array(which is line by line)
                    if (lineList[i].size() > (unsigned) lineLength) {
                        lineLength = lineList[i].size();
                        longestLine = i;                               // longestLine represents the index of the list
                    }
                // COUNT HOW MANY TIMES THE LINE APPEARS IN FILE
                int countLongestLines = 0;
                for (int i = 0; i < (signed) lineList.size(); i++)
                    if (lineList[i].size() == lineList[longestLine].size())
                        countLongestLines += 1;
                // FIND THE LONGEST WORD IN THE ENTIRE FILE. INCLUDE REPEATING WORDS
                std::string longestWord("");
                map<string, int> myMap;
                for (unsigned i = 0;
                     i < lineList.size(); i++) {          // Creating a vector(array) that holds a word for every index
                    std::string line(lineList[i]);
                    std::string bufferStr("");                       // SPLITTING THE ENTIRE STRING AND
                    stringstream ss(line);                            // PLACING IT INTO MY VECTOR
                    while (ss >> bufferStr) {
                        wordList.push_back(bufferStr);
                    }
                }
                for (int i = 0; i < (signed) wordList.size(); i++)        // loop through the all the words in file
                    if (wordList[i].length() > longestWord.length())
                        longestWord = wordList[i];                      // Take only the longest WORD. Not wordS and store it
//   longestWord now contains the longest WORD - not wordS
                int countLongWords = 0;
                string temp = "";
                for (int i = 0; i < (signed) wordList.size(); i++) {
                    countLongWords = 0;
                    if (wordList[i].length() ==
                        longestWord.length()) {    // If there are other words with the same length(longest words), add to my map
                        temp = wordList[i];
                        for (int i = 0; i < (signed) wordList.size(); i++)
                            if (temp == wordList[i])
                                countLongWords++;
                        myMap[wordList[i]] = countLongWords;
                    }
                }
                cout << argv[i] << ":" << endl;
                for (std::map<string, int>::iterator it = myMap.begin(); it != myMap.end(); ++it) {
                    if ((it != myMap.end()) &&
                        (next(it) == myMap.end()))      // <-- checks whether if its the last element of map
                        cout << it->first;
                    else
                        std::cout << it->first << ", ";
                }
                string longestLineeee = lineList[longestLine];
                cout << "\n" << longestLineeee.length() << endl;

            }
            myFileToRead.close();
        }
    }
    return 0;
}
