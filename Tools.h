#include <iostream>

using namespace std;

class Tools
{
public:
    // Splits string and stores all its parts in a vector
    static void SplitString(vector<string>& vectorToStore, string targetString, char splitBy);

    // Copies a file from specified directory 
    // to the directory the app is running at
    static bool CopyFileToWorkingDirectory(string path, string& newPath);

    // Gets all lines from a text file
    // and stores them in a vector 
    static void GetLinesFromFile(vector<string>& lines, string filePath);

    // Writes lines to a text file
    // (WANING!! ios::trunc will be used to ERASE all contents of the file!!!!)
    static void WriteLinesToFile(vector<string>& lines, string filePath);

    // Replace one string with another in a text file
    static void ReplaceLineInFile(int replaceAt, string replaceWith, string filePath);

    // Remove line in a text file by index
    static void RemoveLineInFile(int removeAt, string filePath);

    // Remove line in a text file by concurrence
    static void RemoveLineInFile(string lineToRemove, string filePath, bool removeAllOccurrences = false);

    // Clear terminal in any system you're running at
    static void ClearTerminal();

    // Converts bool to string
    static void BoolToString(bool targetBool, string& targetString);

    // Converts string to bool
    static void StringToBool(string targetString, bool& targetBool);

    // Replaces a part of string with another string
    static void ReplaceSubstring(string& targetString, string toReplace, string replaceWith);
};