#include "data.h"

Data::Data()
{

}

Data::~Data()
{

}

void Data::addFile(const string &fileName)
{
    fileNames.push_back(fileName);
    notify();
}

void Data::removeFile(const int &fileNumber)
{
    fileNames.erase(fileNames.cbegin() + fileNumber);
    notify();
}

const vector<string> & Data::getFileNames()
{
    return fileNames;
}
