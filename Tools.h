#include <iostream>

using namespace std;

class Tools
{
public:
    static vector<string> SplitString(string targetString, char splitBy);

    static bool CopyFileToWorkingDirectory(string path, string& newPath);

    static void GetLinesFromFile(vector<string>& lines, string filePath);

    static void WriteLinesToFile(vector<string>& lines, string filePath);

    static void ReplaceLineInFile(int replaceAt, string replaceWith, string filePath);

    static void RemoveLineInFile(int removeAt, string filePath);
    
    static void RemoveLineInFile(string lineToRemove, string filePath, bool removeAllOccurrences = false);

    static void ClearTerminal();

    static void BoolToString(bool targetBool, string& targetString);

    static void StringToBool(string targetString, bool& targetBool);
};