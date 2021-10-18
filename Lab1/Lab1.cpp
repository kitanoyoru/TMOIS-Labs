/*==========[Libraries]==========*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*==========[Class]==========*/

class Set {
    private:
        vector<int> set1;
        vector<int> set2;
    public:
        Set (vector<int> s1, vector<int> s2): set1(s1), set2(s2) {}

        void intersection();
        void unity();
};

/*==========[Class Functions]==========*/

/*----------[Unity]----------*/

void Set::unity() {
    vector<int> ans;
    if (set1.size() == 0 && set2.size() == 0) {
        cout << "\nПустое множество!\n";
        cout << "Результат: {}";
        return;
    }
    if (set1.size() == 0) {
        cout << "\nРезультат: {";
        for (int i = 0; i < set2.size(); i++) {
            if (i != set2.size()-1)
                cout << set2[i] << ", ";
            else
                cout << set2[i] << "}";
        }
        return;
    }
    if (set2.size() == 0) {
        cout << "\nРезультат: {";
        for (int i = 0; i < set1.size(); i++) {
            if (i != set1.size()-1)
                cout << set1[i] << ", ";
            else
                cout << set1[i] << "}";
        }
        return;      
    }
    for (auto it: set1) {ans.push_back(it);}
    vector<int> positions;
    for (int i = 0; i < set1.size(); i++)
        for (int j = 0; j < set2.size(); j++)
            if (set1[i] == set2[j])
                positions.push_back(j);
    if (positions.size() != 0)
        for (int i = 0; i < set2.size(); i++) {
            if (*find(positions.begin(), positions.end(), i) != i) 
                ans.push_back(set2[i]);
        }

    cout << "\nРезультат(объединение): {";
    for (int i = 0; i < ans.size(); i++) {
        if (i != ans.size()-1)
            cout << ans[i] << ", ";
        else
            cout << ans[i] << "}";
    }
}

/*---------------------------*/

/*----------[Intersection]----------*/

void Set::intersection() {
    vector<int> ans;
    for (auto i: set1)
        for (auto j: set2)
            if (i == j)
                ans.push_back(j);
    cout << "\nРезультат(пересечение): {";
    for (int i = 0; i < ans.size(); i++) {
        if (i != ans.size()-1)
            cout << ans[i] << ", ";
        else
            cout << ans[i] << "}";
    }
}

/*----------------------------------*/

/*==========[Main Function]==========*/

int main () 
{
    int number;

    int power_s1; 
    cout << "Введите мощность множества А: "; cin >> power_s1;
    
Problem_s1:    
    vector<int> s1 = {};
    cout << "Введите множество А: ";
    for (int i = 0; i < power_s1; i++) {cin >> number; s1.push_back(number);}
    for (int i = 0; i < power_s1; i++)
        for (int j = 0; j < power_s1; j++)
            if (i != j)
                if (s1[i] == s1[j]) {
                    cout << "Ошибка! Введите множество заново!\n";
                    goto Problem_s1;
                }
    
    cout << endl;

    int power_s2;
    cout << "Введите мощность множества B: "; cin >> power_s2;

Problem_s2:
    vector<int> s2;
    cout << "Введите множество B: ";
    for (int i = 0; i < power_s2; i++) {cin >> number; s2.push_back(number);}
    for (int i = 0; i < power_s2; i++)
        for (int j = 0; j < power_s2; j++)
            if (i != j)
                if (s2[i] == s2[j]) {
                    cout << "Ошибка! Введите множество заново!\n";
                    goto Problem_s2;
                }
    
    cout << endl;

    Set s(s1, s2);
    int operation;
    cout << "Операции над множествами:\n"
         << "  1 - Объединение;\n"
         << "  2 - Пересечение.\n";
    cout << "Введите операцию: "; cin >> operation;
    switch (operation) {
        case 1:
            s.unity();
            break;
        case 2:
            s.intersection();
            break;
    }

    return 0;

}

// 1. Если мошность введенного множества меньше power;
// 2. Сделат проверку на пустые множества в intersection

