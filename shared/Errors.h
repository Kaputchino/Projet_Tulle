#ifndef PROJET_TULLE_ERRORS_H
#define PROJET_TULLE_ERRORS_H

#include <string>
#include <vector>

using namespace std;

class Errors {
    private:
        inline static vector<string> errors;
    public:
        static void appendError(string message);
        static string readErrors();
        static bool hasErrors();
};


#endif //PROJET_TULLE_ERRORS_H
