#ifndef PROJET_TULLE_ERRORS_H
#define PROJET_TULLE_ERRORS_H

#include <string>
#include <vector>

using namespace std;

class Errors {
    private:
        static vector<string> errors;
    public:
        static void appendError(string message);
        static string readErrors();
};


#endif //PROJET_TULLE_ERRORS_H
