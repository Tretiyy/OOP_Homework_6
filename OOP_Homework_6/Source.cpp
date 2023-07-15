#include <iostream>
#include <stack>
#include <string>
#include <ctime>

using namespace std;

#pragma region First
/*bool checkBrackets(const string& input)
{
    stack<char> bracketStack;
    for (size_t i = 0; i < input.size(); i++)
    {
        char currentChar = input[i];
        if (currentChar == '(' || currentChar == '[' || currentChar == '{')
            bracketStack.push(currentChar);
        else if (currentChar == ')' || currentChar == ']' || currentChar == '}') {
            if (bracketStack.empty())
                return false;
            char top = bracketStack.top();
            bracketStack.pop();
            if ((currentChar == ')' && top != '(') ||
                (currentChar == ']' && top != '[') ||
                (currentChar == '}' && top != '{'))
                return false;
        }
    }
    return bracketStack.empty();
}*/
#pragma endregion

#pragma region Second
class Client 
{
public:
    string name;
    int priority;
    Client(const string& name, int priority) : name(name), priority(priority) {}
};

class PrinterQueue
{
public:
    void push(const Client& client) 
    {
        printStack.push(client);
    }

    void print()
    {
        if (!printStack.empty())
        {
            Client client = printStack.top();
            printStack.pop();
            time_t currentTime;
            time(&currentTime);
            char timestamp[26];
            ctime_s(timestamp, sizeof(timestamp), &currentTime);
            printHistory.push(make_pair(client.name, currentTime));
            cout << "Document print: " << client.name << " (Priority: " << client.priority << ")" << endl;
            cout << "Print time: " << timestamp;
        }
        else
            cout << "Print queue is empty!" << endl;
    }

    void displayPrintHistory() 
    {
        cout << "Print history:" << endl;
        while (!printHistory.empty())
        {
            pair<string, time_t> entry = printHistory.top();
            printHistory.pop();
            char timestamp[26];
            time_t currentTime = entry.second;
            ctime_s(timestamp, sizeof(timestamp), &currentTime);
            cout << "Document: " << entry.first << endl;
            cout << "Print time: " << timestamp;
        }
    }
private:
    stack<Client> printStack;
    stack<pair<string, time_t>> printHistory;
};
#pragma endregion


int main() 
{
    // FIRST

    /*string input;
    cout << "Enter a string with brackets: ";
    getline(cin, input);
    if (checkBrackets(input))
        cout << "The string is correct!" << endl;
    else
        cout << "The string is not correct!" << endl;*/

    // SECOND

    PrinterQueue printer;
    printer.push(Client("Doc 1", 2));
    printer.push(Client("Doc 2", 1));
    printer.push(Client("Doc 3", 3));
    printer.print();
    printer.print();
    printer.print();

    printer.displayPrintHistory();

    system("pause");

    return 0;
}