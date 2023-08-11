#include <iostream>
#include <sstream>
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <regex>

#include "Tools.h"

using namespace std;

void Tools::SplitString(vector<string>& vectorToStore, string targetString, char splitBy)
{
    stringstream targetStringStream(targetString);
    string segment;
        
    while (getline(targetStringStream, segment, splitBy))
        vectorToStore.push_back(segment);
}

bool Tools::CopyFileToWorkingDirectory(string path, string& newPath)
{
    filesystem::path sourceFile = path;
    filesystem::path targetDirectory = filesystem::current_path();

    filesystem::path finalTarget = targetDirectory / sourceFile.filename();
    newPath = finalTarget.string();
    
    try
    {
        filesystem::create_directories(targetDirectory);
        bool result = filesystem::copy_file(sourceFile, finalTarget, filesystem::copy_options::overwrite_existing);

        return result;
    }
    catch (exception& exception)
    {
        cout << exception.what() << endl;
        return false;
    } 
}

void Tools::GetLinesFromFile(vector<string>& lines, string filePath)
{
    filesystem::path targetPath = filePath;
    fstream fileStream(targetPath, ios::in);
    string line;

    if (fileStream.is_open())
    {
        while (getline(fileStream, line))
            lines.push_back(line);
    }

    fileStream.close();
}

void Tools::WriteLinesToFile(vector<string>& lines, string filePath)
{
    filesystem::path targetPath = filePath;
    fstream fileStream(targetPath, ios::out | ios::trunc);

    if (fileStream.is_open())
    {
        for (const auto& line : lines)
            fileStream << line << endl;    
    }

    fileStream.close();
}

void Tools::ReplaceLineInFile(int replaceAt, string replaceWith, string filePath)
{
    vector<string> lines;

    Tools::GetLinesFromFile(lines, filePath);

    lines.erase(lines.begin() + replaceAt);
    lines.insert(lines.begin() + replaceAt, replaceWith);

    Tools::WriteLinesToFile(lines, filePath);
}

void Tools::RemoveLineInFile(int removeAt, string filePath)
{
    vector<string> lines;

    Tools::GetLinesFromFile(lines, filePath);

    lines.erase(lines.begin() + removeAt);

    Tools::WriteLinesToFile(lines, filePath);
}

void Tools::RemoveLineInFile(string lineToRemove, string filePath, bool removeAllOccurrences = false)
{
    vector<string> lines;
    
    Tools::GetLinesFromFile(lines, filePath);

    for (int i = 0; i < lines.size(); i++)
    {
        if (lines.at(i).contains(lineToRemove))
        {
            lines.erase(lines.begin() + i);

            if (!removeAllOccurrences)
                break;
        }
    }

    Tools::WriteLinesToFile(lines, filePath);
}

void Tools::ClearTerminal()
{
    #if defined _WIN32
		system("cls");
	#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
		system("clear");
	#elif defined (__APPLE__)
		system("clear");
	#endif	
}

void Tools::BoolToString(bool targetBool, string& targetString)
{
    targetString = targetBool ? "true" : "false";
}

void Tools::StringToBool(string targetString, bool& targetBool)
{
    targetBool = targetString == "true";
}

void Tools::ReplaceSubstring(string& targetString, string toReplace, string replaceWith)
{
    string intermediateString = regex_replace(targetString, regex(toReplace), replaceWith);
    targetString = intermediateString;
}