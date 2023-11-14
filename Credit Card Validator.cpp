
#include<bits/stdc++.h>

using namespace std;

bool isNumberString(const string& s) {
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }
    return true;
}

int main() {
    string CreditCardNumber;
    
    cout << "This program uses the Luhn Algorigthm to validate a Credit Card number." << endl;
    cout << "You can enter 'exit' anytime to quit." << endl;
    
    while (true) {
        
        cout << "Please enter a Credit number to validate: ";
        cin >> CreditCardNumber;
        
        if (CreditCardNumber == "exit")
            break;
        
        else if (!isNumberString(CreditCardNumber)) {
            cout << "Bad input, Please type again ";
            continue;
        }
            
        int len = CreditCardNumber.length();
        int doubleEvenSum = 0;
        
        
        for (int i = len - 2; i >= 0; i = i - 2) {
            int val = ((CreditCardNumber[i] - 48) * 2);
            if (val > 9) {
                val = (val / 10) + (val % 10);
            }
            doubleEvenSum += val;
        }
        
        
        
        for (int i = len - 1; i >= 0; i = i - 2) {
            doubleEvenSum += (CreditCardNumber[i] - 48);
        }
        
        // check if the 'doubleEvenSum' is a multiple of 10.
        // If yes, it is a valid CC number. Otherwise, not.
        
        cout << (doubleEvenSum % 10 == 0 ? "Valid!" : "Invalid!") << endl;
        
        continue;        
    }

    return 0;
}