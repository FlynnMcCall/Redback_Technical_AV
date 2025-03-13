#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    ifstream log("candump.log");
    ofstream outfile("output.txt");
    ofstream debug_outfile("outfile.csv");

    string u_time;
    string can_version;
    string message;
    while (log >> u_time >> can_version >> message) {
        size_t pos = message.find('#');
        string header = message.substr(0, pos);
        string payload = message.substr(pos + 1);

        if (header != "705") {
            continue;
        }
        
        // Each char is in hex => 4 bits
        // WheelRR starts at index 32, length 16 => substr( 32/4 , 16 / 4)

        string RR_sub_str = payload.substr(8, 4);
        unsigned long WheelSpeedRR_Raw = stoul( RR_sub_str, 0, 16);
        
        double WheelSpeedRR = ((double)WheelSpeedRR_Raw) * 0.1;

        outfile << u_time << ": " << WheelSpeedRR << endl;
        //debug_outfile << i << ", " << WheelSpeedRR << "\n";
    }


    return 0;
}
// Question 3: This is an extension task that requires you to decode sensor data from a CAN log file.
// CAN (Controller Area Network) is a communication standard used in automotive applications (including Redback cars)
// to allow communication between sensors and controllers.
//
// Your Task: Using the definition in the Sensors.dbc file, extract the "WheelSpeedRR" values
// from the candump.log file. Parse these values correctly and store them in an output.txt file with the following format:
// (<UNIX_TIME>): <DECODED_VALUE>
// eg:
// (1705638753.913408): 1234.5
// (1705638754.915609): 6789.0
// ...
// The above values are not real numbers; they are only there to show the expected data output format.
// You do not need to use any external libraries. Use the resources below to understand how to extract sensor data.
// Hint: Think about manual bit masking and shifting, data types required,
// what formats are used to represent values, etc.
// Resources:
// https://www.csselectronics.com/pages/can-bus-simple-intro-tutorial
// https://www.csselectronics.com/pages/can-dbc-file-database-intro
