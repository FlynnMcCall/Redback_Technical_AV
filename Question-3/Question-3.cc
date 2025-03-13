#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    ifstream log("candump.log");
    ofstream outfile("output.txt");
    //ofstream debug_outfile("outfile.csv");

    int i = 0;
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
        
        // SG_ WheelSpeedRR : 32|16@0+ (0.1,0) [0|0] "km/h" Vector__XXX
        // Each char is in hex => 4 bits
        // WheelRR starts at index 32, length 16 => substr( 32/4 , 16 / 4)

        string RR_sub_str = payload.substr(8, 4);
        
        // reverse byte order
        swap(RR_sub_str[0], RR_sub_str[2]);
        swap(RR_sub_str[1], RR_sub_str[3]);


        unsigned long WheelSpeedRR_Raw = stoul( RR_sub_str, 0, 16);
        double WheelSpeedRR = ((double)WheelSpeedRR_Raw) * 0.1;

        outfile << u_time << ": " << WheelSpeedRR << endl;
        //debug_outfile << i++ << ", " << WheelSpeedRR << "\n";
    }

    return 0;
}
