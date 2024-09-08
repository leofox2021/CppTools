#include <iostream>
#include <sstream>
#include <filesystem>
#include <fstream>
#include <windows.h>

#include "Tools.h"

using namespace std;

vector<string> LeosTools::Tools::SplitString(string targetString, char splitBy)
{
    stringstream targetStringStream(targetString);
    vector<string> targetStringSplit;
    string segment;
        
    while (getline(targetStringStream, segment, splitBy))
        targetStringSplit.push_back(segment);
    
    return targetStringSplit;
}

bool LeosTools::Tools::CopyFileToWorkingDirectory(string path, string& newPath)
{
    filesystem::path sourceFile = path;
    filesystem::path targetDirectory = filesystem::current_path();

    filesystem::path finalTarget = targetDirectory / sourceFile.filename();
    newPath = finalTarget.string();
    
    try
    {
        create_directories(targetDirectory);
        bool result = copy_file(sourceFile, finalTarget, filesystem::copy_options::overwrite_existing);

        return result;
    }
    catch (exception& exception)
    {
        cout << exception.what() << endl;
        return false;
    } 
}

void LeosTools::Tools::GetLinesFromFile(vector<string>& lines, string filePath)
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

void LeosTools::Tools::WriteLinesToFile(vector<string>& lines, string filePath)
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

void LeosTools::Tools::ReplaceLineInFile(int replaceAt, string replaceWith, string filePath)
{
    vector<string> lines;

    GetLinesFromFile(lines, filePath);

    lines.erase(lines.begin() + replaceAt);
    lines.insert(lines.begin() + replaceAt, replaceWith);

    WriteLinesToFile(lines, filePath);
}

void LeosTools::Tools::RemoveLineInFile(int removeAt, string filePath)
{
    vector<string> lines;

    GetLinesFromFile(lines, filePath);

    lines.erase(lines.begin() + removeAt);

    WriteLinesToFile(lines, filePath);
}

void LeosTools::Tools::RemoveLineInFile(string lineToRemove, string filePath, bool removeAllOccurrences)
{
    vector<string> lines;

    GetLinesFromFile(lines, filePath);

    for (int i = 0; i < lines.size(); i++)
    {
        if (lines.at(i).find(lineToRemove) != string::npos)
        {
            lines.erase(lines.begin() + i);

            if (!removeAllOccurrences)
                break;
        }
    }

    WriteLinesToFile(lines, filePath);
}

void LeosTools::Tools::ClearTerminal()
{
    #if defined _WIN32
		system("cls");
	#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
		system("clear");
	#elif defined (__APPLE__)
		system("clear");
	#endif	
}

void LeosTools::Tools::BoolToString(bool targetBool, string& targetString)
{
    targetString = targetBool ? "true" : "false";
}

void LeosTools::Tools::StringToBool(string targetString, bool& targetBool)
{
    targetBool = targetString == "true";
}

void LeosTools::Tools::FixDigitFormat(const int zeroRequired, string& digitString)
{
    for (int i = 0; i < zeroRequired; i++)
        digitString.insert(0, "0");
}