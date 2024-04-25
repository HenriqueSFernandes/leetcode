#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int main() {
    ofstream file;
    stringstream ss;

    int id;
    string title;
    string url;
    string difficulty;
    cout << "What is the id?\n";
    cin >> id;
    cout << "What is the title?\n";
    cin.ignore();
    getline(cin, title);
    cout << "What is the url?\n";
    cin >> url;
    cout << "What is the difficulty?\n";
    cin >> difficulty;

    int lowerBound = (id / 50) * 50 + 1;
    int upperBound = lowerBound + 49;
    stringstream folderNameStream;
    folderNameStream << lowerBound << "-" << upperBound;
    string folderName = folderNameStream.str();

    file.open("README.md", ios::app);
    ss << "| " << id << "  | [" << title << "](" << url << ") | [C++](./"
       << folderName << "/";
    replace(title.begin(), title.end(), ' ', '-');
    ss << id << '-' << title << ".cpp)   | "s << difficulty << "  |\n";
    file << ss.str();
    file.close();

    stringstream location;
    location << "./" << folderName << "/" << id << '-' << title << ".cpp";
    ofstream code(location.str());
    return 0;
}