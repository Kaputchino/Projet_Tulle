#include "core/headers/Errors.h"

using namespace std;

void Errors::appendError(string message) {
    errors.push_back(message);
}

string Errors::readErrors() {

    string res = "";

    while (!errors.empty()) {
        res = res + errors.back() + "\n";
        errors.pop_back();
    }

    return res;
}

bool Errors::hasErrors() {
    return errors.empty();
}

void Errors::init() {
    while (!errors.empty()) {
        errors.pop_back();
    }
}