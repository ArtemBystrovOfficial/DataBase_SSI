// CPP DataBase SII
// v 1.0
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <locale>
#include <Windows.h>
#include <string>
#include <fstream>
#include <cstdio>
typedef long long ll;

using namespace std;

// Создание базз данных через консоль для удобной работы с тестами
// 
// Быстрый команндный интерфейс
// 
// Дальнейшая оптимизация и разработка v 1.1 скоро
//
// Artem Bystrov 2021

// Создание/Удаление баз
void CreateBase()
{
    string command;
    cout << "CreateBase: Для удаления базы $Delete, Для создания базы $Add" << endl;
        cin >> command;
       
    int col = -1;
    string check;
    vector < string > Base_List;
    ifstream in_base("Base_List.txt");
    while (1)
    {
        
        getline(in_base, check);
            if (check == "$")break;
        Base_List.push_back(check);
    }

    if (command == "$Add") {


        ofstream out_base("Base_List.txt");
     

        string data_name;
        string data_base;
        cout << "CreateBase: " << "Название новой базы" << endl;
        cin >> data_name;
        for (int i = 0; i != Base_List.size(); i++)
        {
            out_base << Base_List[i] << endl;
        }
        out_base << data_name<<endl;
        out_base << "$";

        ofstream  out("Bases/data" + data_name + ".txt");
        cout << "CreateBase: " << "Вводите данные через пробел, по окончанию вызовите функцию $End" << endl;
        while (1)
        {
            col++;
            cin.sync();

            getline(cin, data_base);
            if (data_base == "$End") break;
            if (col != 0)
                out << "$" << col << " " << data_base << endl;

        }
        out << "$" << endl;
            out.close();
        out_base.close();
    }
    else {
        if (command == "$Delete") {
            ofstream out_base("Base_List.txt");

            string s, way;

            bool key = false;
            cout << "CreateBase: " << "Название базы для удаления" << endl;
            cin >> s;
            for (int i = 0; i != Base_List.size(); i++)
            {

                if (Base_List[i] == s) {
                    key = true;

                    way = "Bases/data" + s + ".txt";
                    const char* c = way.c_str();
                    remove(c);

                    cout << "CreateBase: " << "База успешно удалена" << endl;


                }
                else {
                    out_base << Base_List[i] << endl;
                }
            }
            out_base << "$" << endl;
            if (key == false)cout << "CreateBase: " << "База не найдена" << endl;


            out_base.close();
        }
        else {
            cout << "Unknown Command" << endl;
        }
    }

}

// Список баз
void ListBase()
{
    

        string check;
        ifstream in_base("Base_List.txt");
        while (1)
        {

            getline(in_base, check);
            if (check == "$")break;
            cout << check << endl;
        }
    
}

// Просмотр содержимомго баз
void Base_Show(string data_name)
{
    string check;
    vector < string > Base_List;
    ifstream in_base("Base_List.txt");
    while (1)
    {

        getline(in_base, check);
        if (check == "$")break;
        Base_List.push_back(check);
    }
 
   
        ofstream out_base("Base_List.txt");

        string s, way;

        bool key = false;
        s = data_name;
        for (int i = 0; i != Base_List.size(); i++)
        {

            if (Base_List[i] == s) {
                key = true;
            }
            out_base << Base_List[i] << endl;
        }
        out_base << "$" << endl;
        out_base.close();
        int step = 0;
        if (key == false)cout << "База не найдена" << endl;
        else {
  

            ifstream  in("Bases/data" + data_name + ".txt");
            string data_base;
            while (1)
            {
                step++;
                cin.sync();

                getline(in, data_base);
                if (data_base == "$") break;
                cout << data_base << endl;


            }
            if(step==1) cout << "Base: База пуста" << endl;
        }
    
}

// Добавление\удаление элементов баз
void SettingBase(string data_name)
{
    string check;
    vector < string > Base_List;
    ifstream in_base("Base_List.txt");
    while (1)
    {

        getline(in_base, check);
        if (check == "$")break;
        Base_List.push_back(check);
    }

    ofstream out_base("Base_List.txt");

    string s, way;

    bool key = false;
    s = data_name;
    for (int i = 0; i != Base_List.size(); i++)
    {

        if (Base_List[i] == s) {
            key = true;
        }
        out_base << Base_List[i] << endl;
    }
    out_base << "$" << endl;
    out_base.close();
    vector < string > base;
    if (key == false)cout << "База не найдена" << endl;

    else {


        ifstream  in("Bases/data" + data_name + ".txt");
        string data_base;
        while (1)
        {

            cin.sync();

            getline(in, data_base);
            if (data_base == "$") break;
            base.push_back(data_base);


        }

        cout << "SettingBase: Введите $Add для добавления элемента $Delete для удаления" << endl;
        string s1;
        cin >> s1;
        if (s1 == "$Add") {
            ofstream  out("Bases/data" + data_name + ".txt");
            for (int i = 0; i != base.size(); i++)
            {
                out << base[i] << endl;
            }
            cout << "Вводите новые элементы, чтобы звершить введите $End" << endl;
            getline(cin, s1);
            int k = 0;
            while (1)
            {
                k++;
                cin.sync();

                getline(cin, s1);
                if (s1 == "$End")break;
                out << "$" << base.size() + k << " " << s1 << endl;
            }
            out << "$";
            out.close();

        }
        if (s1 == "$Delete") {
            cout << "Введите номер элемента" << endl;
            int n;
            cin >> n;
            ofstream  out("Bases/data" + data_name + ".txt");
            for (int i = 0; i != base.size(); i++)
            {
                int k = 0;
                if (i + 1 >= n) {
                    if (i + 1 != n)
                    {
                        for (int j = 0; j != base[i].size(); j++)
                        {
                            if (base[i][j] == ' ') {
                                k = j; break;
                            }
                        }
                        out << "$" << i << base[i].substr(k, base[i].size() - k)<<endl;
                    }
                }
                else {
                    out << base[i] << endl;
                }
            }
            out << "$";
            out.close();

        }
    }


}

// Поиск по всем базам
void Find(string data_name)
{
    string element;
    int k;
    vector <string> bases;
    string check;
    ifstream in_base("Base_List.txt");
    while (1)
    {

        getline(in_base, check);
        if (check == "$")break;
        bases.push_back(check);
    }
    bool key;
    for (int i = 0; i != bases.size(); i++)
    {
        key = false;
        ifstream  in("Bases/data" + bases[i] + ".txt");
        string data_base;
        vector <string > base;
        while (1)
        {

            cin.sync();

            getline(in, data_base);
            if (data_base == "$") break;
            base.push_back(data_base);


        }
        in.close();
        k = 0;

        cout << bases[i] << endl;
        ifstream  in_element("Bases/data" + bases[i] + ".txt");
        while(1)
        {
            in_element>> element;
            if (element == "$")break;
            if (element[0] == '$')k++;
            if (element == data_name)
            {
                cout <<"  "<< base[k-1] << endl;
                key = true;
            }
        }
        if (key == false) cout << "  None" << endl;
        in_element.close();
    }
}

// Поиск внутри одной базы
void FindBase(string data_name,string base_type)
{
    string element;
    int k;
    bool key_check = false;
 
    string check;
    ifstream in_base("Base_List.txt");
    while (1)
    {
      
        getline(in_base, check);
        if (check == "$")break;
        if (base_type == check) key_check = true;
    }
    if (key_check == false) cout << "FindBase: База не найдена" << endl;
    else {
        bool key;
        
            key = false;
            ifstream  in("Bases/data" + base_type + ".txt");
            string data_base;
            vector <string > base;
            while (1)
            {

                cin.sync();

                getline(in, data_base);
                if (data_base == "$") break;
                base.push_back(data_base);


            }
            in.close();
            k = 0;

            cout << base_type << endl;
            ifstream  in_element("Bases/data" + base_type + ".txt");
            while (1)
            {
                in_element >> element;
                if (element == "$")break;
                if (element[0] == '$')k++;
                if (element == data_name)
                {
                    cout << "  " << base[k - 1] << endl;
                    key = true;
                }
            }
            if (key == false) cout << "  None" << endl;
            in_element.close();
        
    }
}

// Удаление всех баз
void Reset()
{
    string check;
    vector < string > Base_List;
    ifstream in_base("Base_List.txt");
    while (1)
    {

        getline(in_base, check);
        if (check == "$")break;
        Base_List.push_back(check);
    }

    ofstream out_base("Base_List.txt");

    string s, way;

    bool key = false;

    for (int i = 0; i != Base_List.size(); i++)
    {

     
            key = true;

            way = "Bases/data" + Base_List[i] + ".txt";
            const char* c = way.c_str();
            remove(c);

            cout << "CreateBase: " << "База " << Base_List[i]<<" успешно удалена" << endl;


  
    }
    out_base << "$" << endl;

}

// Главная часть программы
int main()
{
    cout << "$<-SII - DATABASE v 1.0->" << endl;
    while (1) {
        setlocale(LC_ALL, "Russian");
        string s,data,data_set;
        cout << "Введите комманду ( Для справки $Info )"<<endl;
       cin>> s;
       if (s == "$Exit")
           return 0;

       else if (s == "$Info")

           cout << "---------------\n$Info - Информация\n$CreateBase - Создание/удаление базы\n$SettingBase <name> - Изменение существующей базы\n$ListBase - Список всех баз\n$Exit - Выход\n$Base <name> - Вывод базы\n$Find <name_elemnt> - Поиск элемента по всем базам\n$FindBase <name_element> <base> - Поиск элемента в определенной базе\n$ResetAllBases - Сбросить все базы\n--------------" << endl;

       else if (s == "$CreateBase")

           CreateBase();

       else if (s == "$ListBase")

           ListBase();

       else if (s == "$Base")
       {
           cin >> data;
           Base_Show(data);
       }

       else if (s == "$SettingBase")
       {
           cin >> data;
           SettingBase(data);
       }

       else if (s == "$Find")
       {
           cin >> data;
           Find(data);
       }
       
       else if (s == "$FindBase")
       {
           cin >> data;
           cin >> data_set;
           FindBase(data, data_set);

       }

       else if (s == "$ResetAllBases")
       {
           Reset();
       }
    }
}

