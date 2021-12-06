/*==========[Libraries]==========*/
#include <boost/logic/tribool.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*==========[Class]==========*/

class Set 
{
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

void Set::unity()                                               // Операция пересечения
{
    vector<int> ans;

    if (set1.size() == 0 && set2.size() == 0) {                 //
        cout << "\nПустое множество!\n";                        // Если размер исходных множеств
        cout << "Результат: {}\n";                                // равны нулю, то результат пустое множество
        return;                                                 //
    }
    if (set1.size() == 0) {                                     
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
    if (positions.size() != 0)                                      //
        for (int i = 0; i < set2.size(); i++) {                     // Добавляем к результату элементы множества А
            if ((*find(positions.begin(), positions.end(), i)) != i)  // и эелементы из множества В, которых не в
                ans.push_back(set2[i]);                             // множестве А
        }                                                           //

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
    if (ans.size() != 0) {                                          // Если они равны, то вносим одно из
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

/*==========[Main Function]==========*/

int main () 
{
    int number;

    int power_s1;                                                   // Пользователь задает 
    cout << "\nВведите мощность множества А: "; cin >> power_s1;    // мощность множества А
    
Problem_s1:    
    vector<int> s1 = {};                                            //
    cout << "Введите множество А: ";                                //
    for (int i = 0; i < power_s1; i++)                              //
        {cin >> number; s1.push_back(number);}                      //  Пользователь задает
    for (int i = 0; i < power_s1; i++)                              //  множество А
        for (int j = 0; j < power_s1; j++)                          //
            if (i != j)                                             //
                if (s1[i] == s1[j]) {                               //
                    cout << "Ошибка! Введите множество заново!\n";  //
                    goto Problem_s1;                                //
                }
    
    cout << endl;

    int power_s2;                                                   // Пользователь задает
    cout << "Введите мощность множества B: "; cin >> power_s2;      // мощность множества В

Problem_s2:                                                         //
    vector<int> s2;                                                 //
    cout << "Введите множество B: ";                                //
    for (int i = 0; i < power_s2; i++)                              //
        {cin >> number; s2.push_back(number);}                      //
    for (int i = 0; i < power_s2; i++)                              // Пользователь задает
        for (int j = 0; j < power_s2; j++)                          // множество В
            if (i != j)                                             //
                if (s2[i] == s2[j]) {                               //
                    cout << "Ошибка! Введите множество заново!\n";  //
                    goto Problem_s2;                                //
                }                                                   //
    
    cout << endl;

    Set s(s1, s2);
    int operation;                                                  //
    cout << "\nОперации над множествами:\n"                         // Пользователь выбирает
         << "  1 - Объединение;\n"                                  // операцию из списка:
         << "  2 - Пересечение.\n";                                 // 1 - Объединения 
    cout << "Введите операцию: "; cin >> operation;                 // 2 - Пересечения
    switch (operation) {                                            //
        case 1:
            s.unity();
            break;
        case 2:
            s.intersection();
            break;
    }

    return 0;

}
