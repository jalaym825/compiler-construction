#include <iostream>
#include <regex>
#include <vector>

using namespace std;

// Function to analyze JavaScript function syntax
string analyzeFunctionSyntax(const string &code) {
    // Improved regular expressions
    regex functionDeclaration(R"(^\s*function\s+([a-zA-Z_$][a-zA-Z0-9_$]*)\s*\(([^)]*)\)\s*\{([\s\S]*)\}\s*$)");
    regex functionExpression(R"(^\s*const\s+([a-zA-Z_$][a-zA-Z0-9_$]*)\s*=\s*function\s*\(([^)]*)\)\s*\{([\s\S]*)\}\s*;?\s*$)");
    regex arrowFunctionBlock(R"(^\s*const\s+([a-zA-Z_$][a-zA-Z0-9_$]*)\s*=\s*\(([^)]*)\)\s*=>\s*\{([\s\S]*)\}\s*;?\s*$)");
    regex arrowFunctionImplicit(R"(^\s*const\s+([a-zA-Z_$][a-zA-Z0-9_$]*)\s*=\s*\(([^)]*)\)\s*=>\s*([^{}]+)\s*;?\s*$)");

    // Check for function type matches
    if (regex_match(code, functionDeclaration)) {
        return "Valid Function Declaration!";
    } else if (regex_match(code, functionExpression)) {
        return "Valid Function Expression!";
    } else if (regex_match(code, arrowFunctionBlock)) {
        return "Valid Arrow Function with Block!";
    } else if (regex_match(code, arrowFunctionImplicit)) {
        return "Valid Arrow Function with Implicit Return!";
    } else {
        return "Syntax Error: Invalid function definition!";
    }
}

// Main function to test different cases
int main() {
    vector<string> testCases = {
        "const sum = (a, b) => { return a + b; };",  // Valid block arrow function
        "const greet = (name) => { console.log('Hello, ' + name); };",  // Valid
        "const sum = (a, b) => a + b;",  // Valid implicit return arrow function
        "function add(a, b) { return a + b; }",  // Valid function declaration
        "const multiply = function (a, b) { return a * b; };",  // Valid function expression
        "const invalidFunc = () = { return 42; };",  // Syntax Error
        "const missingBracket = a, b) => { return a + b; };",  // Syntax Error
    };

    for (const auto &test : testCases) {
        cout << "Checking: " << test << endl;
        cout << "Result: " << analyzeFunctionSyntax(test) << endl << endl;
    }

    return 0;
}
