#include <iostream>
using namespace std;
#include <string>
#include <stdlib.h>
#include <chrono>
#include <ctime>
#include "SerialPort.h"

char output[MAX_DATA_LENGTH];
char *port = "\\\\.\\COM4";
char incoming[MAX_DATA_LENGTH];

int main()
{
    //
    SerialPort arduino(port);
    if (arduino.isConnected())
    {

        cout << "Connection is Established";
    }
    else
    {

        cout << "Error in port name";
    }
    while (arduino.isConnected())
    {

        string command;
        cin >> command;
        char *charArray = new char[command.size() + 1];
        copy(command.begin(), command.end(), charArray);
        charArray[command.size()] = '\n';

        arduino.writeSerialPort(charArray, MAX_DATA_LENGTH);
        arduino.readSerialPort(output, MAX_DATA_LENGTH);

        auto end = std::chrono::system_clock::now();

        std::time_t end_time = std::chrono::system_clock::to_time_t(end);

        cout << output << "Message received at: " << std::ctime(&end_time);

        delete[] charArray;
    }

    return 0;
}