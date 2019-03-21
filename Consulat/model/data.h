#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <string>

#include "subjectdata.h"

using namespace std;

class Data: public SubjectData
{
public:
    Data();
    ~Data();

    void addFile(const string &);
    void removeFile(const int &);
    const vector<string>& getFileNames();

private:
    vector<string> fileNames;
};

#endif // MODEL_H
