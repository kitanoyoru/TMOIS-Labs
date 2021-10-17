/*==========[Libraries]==========*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*==========[Class]==========*/

class Set {
    private:
        vector<int> set1;
        vector<int> set2;
    public:
        Set (vector<int> s1, vector<int> s2): set1(s1), set2(s2) {}

        void intersection();
        vector<int> unity();
};

/*==========[Class Functions]==========*/
// need to repair
vector<int> Set::unity() {
    vector<int> ans;
    for (auto it: set1) {ans.push_back(it);}
    for (auto i: set1)
        for (auto j: set2)
            if (i == j) {
                continue;
            }
            else {
                ans.push_back(j);
            }
    return ans;
}
// work
void Set::intersection() {
    vector<int> ans;
    for (auto i: set1)
        for (auto j: set2)
            if (i == j)
                ans.push_back(j);
    cout << "\nРезультат: {";
    for (int i = 0; i < ans.size(); i++) {
        if (i != ans.size()-1)
            cout << ans[i] << ", ";
        else
            cout << ans[i] << "}";
    }
}


/*==========[Main Function]==========*/

int main () 
{
    vector<int> s1;
    vector<int> s2;
    int number;
    int power_s1, power_s2;

    cout << "Введите мощность множества А: "; cin >> power_s1;
    cout << "Введите множество А: ";
    for (int i = 0; i < power_s1; i++) {cin >> number; s1.push_back(number);}
    cout << endl;
    cout << "Введите мощность множества B: "; cin >> power_s2;
    cout << "Введите множество B: ";
    for (int i = 0; i < power_s2; i++) {cin >> number; s2.push_back(number);}

    Set s(s1, s2);
    s.intersection();

    return 0;

}

/* 1.Починить unity
   2. Если мошность введенного множества меньше power;
   3. Сделать выбор функции в main */
