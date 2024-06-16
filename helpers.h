#ifndef EXPEDIA_COM_HELPERS_H
#define EXPEDIA_COM_HELPERS_H

#include <bits/stdc++.h>
using namespace std;

int readInt(int low, int high, bool cancel = false){
    cout << "\nEnter number in range " << low << " - " << high << ": ";
    int choice; cin >> choice;
    if(cancel && choice == -1)
        return choice;
    if (low <= choice && choice <= high)
        return choice;
    cout << "ERROR: invalid number...Try again\n";
    return readInt(low, high);
}

int readmenu(const vector<string> &choices, string header = "Menu") {
    cout << "\n"<<header<<":\n";
    for (int ch = 0; ch < (int) choices.size(); ++ch) {
        cout << "\t" << ch + 1 << ": " << choices[ch] << "\n";
    }
    return readInt(1, choices.size());
}

string return_current_time_and_date(){
    auto now = chrono::system_clock::now();
    auto in_time_t = chrono::system_clock::to_time_t(now);

    stringstream ss;
    ss << put_time(localtime(&in_time_t), "%Y-%m-%d %X");
    return ss.str();
}

#endif //EXPEDIA_COM_HELPERS_H
