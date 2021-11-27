
//  Looping_Functions.cpp

#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;

//MQ1
bool play_game(int n) {
    cout << "Welcome to my number guessing game\n\n";
    int entered;
    for (int i = 1; i < 7; i++) {
        cout << "Enter your guess: \n";
        string inputS;
        getline(cin, inputS);
        istringstream ss(inputS);
        ss >> entered;
        cout << "You entered: " << entered << "\n";
        if (entered == n) {
            cout << "You found it in " << i << " guess(es).\n";
            return true;
        }
    }
    cout << "I'm sorry. You didn't find my number.\n";
    cout << "It was " << n << "\n";
    return false;
}

//MQ2
double etox (double x, size_t n) {
    double num[n];
    num[0] = 1;
    double den[n];
    den[0] = 1;
    double total = 0;
    for (int i = 1; i < (int)n; i++) {
        num[i] = num[i-1] * x;
        den[i] = den[i-1] * i;
    }
    for (int i = 0; i < (int)n; i++) {
        total += (num[i]/den[i]);
    }
    return total;
}

//MQ3
size_t count_chars (string s, char c) {
    size_t count = 0;
    for (int i = 0 ; i < s.length(); i++){
        if (s[i] == c) {
            count = count + 1;
        }
    }
    return count;
}

//MQ4
size_t gcd (size_t a, size_t b) {
    return __gcd((int)a,(int)b);
    size_t smaller = min(a,b);
    size_t answer = 1;
    for (int i = (int)smaller ; i > 0 ; i--) {
        if (a%i == 0){
            if (b%i == 0) {
                answer = i;
                break;
            }
        }
    }
    return answer;
}

//MQ5
string get_ap_terms (int a, int d, size_t n) {
    int total[n];
    string ats;
    ats = "";
    for (int i = 0 ; i < (int)n ; i++) {
        total[i] = a + (d*i);
        ats = ats + to_string(total[i]);
        if (i != n-1) {
            ats = ats + ",";
        }
    }
    return ats;
}

//MQ6
string get_gp_terms(double a, double r, size_t n) {
    string ats;
    if (n>0) {
        ostringstream crt;
        crt << a;
        ats = crt.str();
        if (n>1) {
            ats = ats + ",";
        }
    }
    for (int i = 1; i < (int)n; i++) {
        a = a*r;
        ostringstream cvrt;
        cvrt << a;
        ats = ats + cvrt.str();
        if (i != n-1) {
            ats = ats + ",";
        }
    }
    return ats;
}

//MQ 7
double get_nth_fibonacci_number (size_t n) {
    double termNo[n];
    termNo[0] = 1;
    termNo[1] = 1;
    for (int i = 0 ; i < (int)n-2 ; i++) {
        termNo[i+2] = termNo[i] + termNo[i+1];
    }
    return termNo[n-1];
}
