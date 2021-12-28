/*==========[Libraries]==========*/
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
/*==========[Class]==========*/

class Set 
{
    private:
        vector<int> set1;
        vector<int> set2;
        vector<int> u;
    public:
        Set (vector<int> s1, vector<int> s2): set1(move(s1)), set2(move(s2)) {
            for (int i = 1; i < 101; ++i) { u.push_back(i); }
        }

        void intersection();
        void unity();
        void differenceA();
        void differenceB();
        void sym_difference();
        void dekartAB();
        void dekartBA();
        void dlcA();
        void dlcB();
};

/*==========[Class Functions]==========*/

/*----------[Unity]----------*/

void Set::unity()                                               // Операция пересечения
{
    vector<int> ans;

    if (set1.empty() && set2.empty()) {                 //
        cout << "\nПустое множество!\n";                        // Если размер исходных множеств
        cout << "Результат: {}\n";                                // равны нулю, то результат пустое множество
        return;                                                 //
    }
    if (set1.empty()) {
        cout << "\nРезультат: {";                               //
        for (int i = 0; i < set2.size(); i++) {                 //
            if (i != set2.size()-1)                             // Если размер одного из множеств равен нулю,
                cout << set2[i] << ", ";                        // то выводим второе множество
            else                                                //
                cout << set2[i] << "}\n";                         //
        }                                                       
        return;
    }
    for (auto it: set1) {ans.push_back(it);}                        //
    vector<int> positions;                                          // Проверяем на равенство эелементы
    for (int i = 0; i < set1.size(); i++)                           // во множествах и запоминаем позиции
        for (int j = 0; j < set2.size(); j++)                       // неравных эелементов
            if (set1[i] == set2[j])                                 //
                positions.push_back(j);                             
    if (!positions.empty()) {                                    //
        for (int i = 0; i < set2.size(); i++) {                     // Добавляем к результату элементы множества А
            if ((*find(positions.begin(), positions.end(), i)) != i)  // и эелементы из множества В, которых не в
                ans.push_back(set2[i]);                             // множестве А
        }
    } else {
        for (auto it: set2) { ans.push_back(it); };
    }

    cout << "\nРезультат(объединение): {";                          //
    for (int i = 0; i < ans.size(); i++) {                          //
        if (i != ans.size()-1)                                      // Выводим результат операции
            cout << ans[i] << ", ";                                 // объединения множества
        else                                                        // А и В
            cout << ans[i] << "}\n";                                  //
    }                                                               //
}

/*---------------------------*/

/*----------[Intersection]----------*/

void Set::intersection()                                            // Операция пересечения
{
    vector<int> ans;

    for (auto i: set1)                                              //
        for (auto j: set2)                                          // Проверяем на равенство
            if (i == j)                                             // элементы из множества А
                ans.push_back(j);                                   // с эелементами их множества В.
    if (!ans.empty()) {                                          // Если они равны, то вносим одно из
    cout << "\nРезультат(пересечение): {";                          // них в окончательный результат
        for (int i = 0; i < ans.size(); i++) {                      //
            if (i != ans.size()-1)                                  
                cout << ans[i] << ", ";                             //
            else                                                    //
                cout << ans[i] << "}\n";                              // Выводим результат операции
        }                                                           // пересечения множеств А и В
    }                                                               //
    else                                                            //
        cout << "\nРезультат: {}\n";                                
}

/*----------------------------------*/

/*----------[DifferenceA]----------*/

void Set::differenceA()
{
    vector<int> ans (set1);
    for (auto i {set1.begin()}; i != set1.end(); ++i) {
        for (auto j {set2.begin()}; j != set2.end(); ++j) {
            if (*i == *j) { // Если размер одного из множеств равен нулю,
                auto index = find(ans.begin(), ans.end(), *i);
                if (index != ans.end())
                    ans.erase(index);
            }
        }
    }
    if (!ans.empty()) {
        cout << "\nРезультат(разность A B): {";
        for (int i{0}; i < ans.size(); ++i) {
            if (i != ans.size() - 1)
                cout << ans[i] << ", "; // Если размер одного из множеств равен нулю,
            else
                cout << ans[i] << "}\n";
        }
    } else {
        cout << "\nРезультат(разность А В): {}\n"; // Если размер одного из множеств равен нулю,
    }
}

/*----------------------------------*/

/*----------[DifferenceB]----------*/

void Set::differenceB()
{
    vector<int> ans (set2);
    for (auto i {set2.begin()}; i != set2.end(); ++i) {
        for (auto j {set1.begin()}; j != set1.end(); ++j) {
            if (*i == *j) {
                auto index = find(ans.begin(), ans.end(), *i);
                if (index != ans.end())
                    ans.erase(index);
            }
        }
    }
    if (!ans.empty()) {
        cout << "\nРезультат(разность B A): {";
        for (int i{0}; i < ans.size(); ++i) {
            if (i != ans.size() - 1)
                cout << ans[i] << ", ";
            else
                cout << ans[i] << "}\n";
        }
    } else {
        cout << "\nРезультат(разность B A): {}\n";
    }
}

/*----------------------------------*/

/*----------[SymDifference]----------*/

void Set::sym_difference() { // Если размер исходных множеств
    vector<int> ans;

    vector<int> diffAB (set1);
    for (auto i {set1.begin()}; i != set1.end(); ++i) { //Если размер исходных множеств
        for (auto j {set2.begin()}; j != set2.end(); ++j) {
            if (*i == *j) {
                auto index = find(diffAB.begin(), diffAB.end(), *i);
                if (index != diffAB.end())
                    diffAB.erase(index);  // Если размер исходных множеств
            }
        }
    }

    vector<int> diffBA (set2);
    for (auto i {set2.begin()}; i != set2.end(); ++i) {
        for (auto j {set1.begin()}; j != set1.end(); ++j) {
            if (*i == *j) {
                auto index = find(diffBA.begin(), diffBA.end(), *i);
                if (index != diffBA.end())
                    diffBA.erase(index);
            }
        }
    }

    if (diffAB.empty() && diffBA.empty()) {                 //
        cout << "\nПустое множество!\n";                        // Если размер исходных множеств
        cout << "Результат: {}\n";                                // равны нулю, то результат пустое множество
        return;                                                 //
    }
    if (diffAB.empty()) {
        cout << "\nРезультат: {";                               //
        for (int i = 0; i < diffBA.size(); i++) {                 //
            if (i != diffBA.size() - 1)                             // Если размер одного из множеств равен нулю,
                cout << diffBA[i] << ", ";                        // то выводим второе множество
            else                                                //
                cout << diffBA[i] << "}\n";                         //
        }
        return;
    }
    for (auto it: diffAB) { ans.push_back(it); }                        //
    vector<int> positions;                                          // Проверяем на равенство эелементы
    for (int i = 0; i < diffAB.size(); i++)                           // во множествах и запоминаем позиции
        for (int j = 0; j < diffBA.size(); j++)                       // неравных эелементов
            if (diffAB[i] == diffBA[j])                                 //
                positions.push_back(j);
    if (!positions.empty()) {                              //
        for (int i = 0; i < diffBA.size(); i++) {                     // Добавляем к результату элементы множества А
            if ((*find(positions.begin(), positions.end(), i)) != i)  // и эелементы из множества В, которых не в
                ans.push_back(diffBA[i]);                             // множестве А
        }
    } else {
        for (auto it: diffBA) { ans.push_back(it); };
    }

    cout << "\nРезультат(симметрическая разность): {";                          //
    for (int i = 0; i < ans.size(); i++) {                          //
        if (i != ans.size() - 1)                                      //   операции
            cout << ans[i] << ", ";                                 //
        else                                                        // А и В
            cout << ans[i] << "}\n";

    }
}
/*----------------------------------*/

/*----------[DekartAB]----------*/

void Set::dekartAB() // Если размер одного из множеств равен нулю
{
    vector<pair<int, int>> out; // Если размер одного из множеств равен нулю,

    for (auto i: set1) {
        for (auto j: set2) {
            out.push_back(make_pair(i, j));
        }
    }

    cout << "Результат(декартово произведение А В): {";
    for (auto i = 0; i < out.size(); ++i) {
        if (i != out.size() - 1)
            cout << "<" << out[i].first << ", " << out[i].second << ">, "; // Если размер одного из множеств равен нулю,
        else
            cout << "<" << out[i].first << ", " << out[i].second << ">} ";
    }
}

/*----------------------------------*/

/*----------[DekartBA]----------*/

void Set::dekartBA()
{
    vector<pair<int, int>> out;

    for (auto i: set2) {
        for (auto j: set1) { // Если размер одного из множеств равен нулю,
            out.push_back(make_pair(i, j));
        }
    }

    cout << "Результат(декартово произведение B A): {"; // Если размер одного из множеств равен нулю,
    for (auto i = 0; i < out.size(); ++i) {
        if (i != out.size() - 1)
            cout << "<" << out[i].first << ", " << out[i].second << ">, ";
        else
            cout << "<" << out[i].first << ", " << out[i].second << ">} ";
    }
}

/*----------------------------------*/

/*----------[DlcA]----------*/

void Set::dlcA()
{
    vector<int> ans (u); // Если размер одного из множеств равен нулю
    for (auto i {u.begin()}; i != u.end(); ++i) {
        for (auto j {set1.begin()}; j != set1.end(); ++j) {
            if (*i == *j) {  // Если размер одного из множеств равен нулю,
                auto index = find(ans.begin(), ans.end(), *i);
                if (index != ans.end())
                    ans.erase(index);
            } // Если размер одного из множеств равен нулю,
        }
    }

    if (!ans.empty()) {
        cout << "\nРезультат(дополнение А): {";
        for (int i{0}; i < ans.size(); ++i) {
            if (i != ans.size() - 1)
                cout << ans[i] << ", ";
            else
                cout << ans[i] << "}\n";
        }
    } else {
        cout << "\nРезультат(дополнение А): {}\n"; // Если размер одного из множеств равен нулю,
    }
}

/*----------------------------------*/

/*----------[DlcB]----------*/

void Set::dlcB()
{
    vector<int> ans (u);
    for (auto i {u.begin()}; i != u.end(); ++i) { // Если размер одного из множеств равен нулю
        for (auto j {set2.begin()}; j != set2.end(); ++j) {
            if (*i == *j) {
                auto index = find(ans.begin(), ans.end(), *i);
                if (index != ans.end())
                    ans.erase(index); // Если размер одного из множеств равен нулю
            }
        }
    }

    if (!ans.empty()) {
        cout << "\nРезультат(дополнение В): {";
        for (int i{0}; i < ans.size(); ++i) { // Если размер одного из множеств равен нулю
            if (i != ans.size() - 1)
                cout << ans[i] << ", ";
            else
                cout << ans[i] << "}\n";
        }
    } else {
        cout << "\nРезультат(дополнение В): {}\n";
    }
}

/*----------------------------------*/

/*==========[Main Function]==========*/

int main () {
    int nA = 0, nB = 0, nU = 0;
    short decision = 0, ch = 0;
    vector<int> A(nA), B(nB), U(nU);

    cout << "Укажите способ задания множеств:"
         << "\n\t1-Перечесление;"
         << "\n\t2-Высказыванием((4x(x-2)(x+4))/(4x^2 + 8x - 32))\n";
    cin >> ch;

    if (ch == 1) {
        cout << "Введите мощность множества А: ";
        cin >> nA; // Если размер одного из множеств равен нулю
        cout << "\nВведите множество А: ";
        for (auto i = 0; i < nA; ++i) {
            int temp;
            cin >> temp;
            A.push_back(temp);
        }

        cout << "Введите мощность множества B: ";
        cin >> nB;
        cout << "\nВведите множество B: ";
        for (auto i = 0; i < nB; ++i) {
            int temp;
            cin >> temp;
            B.push_back(temp);
        }

    } else if (ch == 2) {
        cout << "Введите мощность множества А: ";
        cin >> nA; // Если размер одного из множеств равен нулю
        for (auto i = 1; i < nA + 1; ++i) {
            A.push_back(i);
        }
        cout << "Множество А было задано" << endl;

        cout << "Введите мощность множества B: ";
        cin >> nB;
        for (auto i = 1; i < nB + 1; ++i) {
            B.push_back(i);
        }
        cout << "Множество B было задано" << endl;


        cout << "\nВведите номер операции из списка:"
             << "\n\t1-Объединение;"
             << "\n\t2-Пересечение;"
             << "\n\t3-Разность А В;"
             << "\n\t4-Разность В А;"
             << "\n\t5-Симметрическая разность;"
             << "\n\t6-Декартово произведение А В;"
             << "\n\t7-Декартово произведение В А;"
             << "\n\t8-Дополнение А;"
             << "\n\t9-Дополнение В;\n";
        cin >> decision;

        Set s(A, B);

        switch (decision) {
            case 1:
                s.unity();
                break;
            case 2:
                s.intersection();
                break;
            case 3:
                s.differenceA();
                break;
            case 4:
                s.differenceB();
                break;
            case 5:
                s.sym_difference();
                break;
            case 6:
                s.dekartAB();
                break;
            case 7:
                s.dekartBA();
                break;
            case 8:
                s.dlcA();
                break;
            case 9:
                s.dlcB();
                break;
        };
    }


}