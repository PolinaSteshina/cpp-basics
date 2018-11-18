#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Znak
{
    string full_name;
    string zodiac;
    int birth_date[3]; // [0] — day, [1] — month, [2] — year
};

void InputPeople(Znak* people, const int kNumPeople);
bool IsLeap(int year);
void SortArray(Znak* people, const int kNumPeople);
void PrintPerson(Znak person);
bool IsValidDate(int* date);
bool IsFirstPersonYounger(int* birth_date_1, int* birth_date_2);
void FindPeople(Znak* people, const int kNumPeople, string zodiac);

int main()
{
    const int kNumPeople = 8;
    Znak people[kNumPeople];
    
    InputPeople(people, kNumPeople);
    SortArray(people, kNumPeople);
    
    cout << string(33, '#');
    cout << "\n\nData entered: \n";
    for (int i = 0; i < kNumPeople; i++)
    {
        PrintPerson(people[i]);
        cout << endl;
    }
    
    string zodiac;
    cout << "Enter the zodiac sign of a person to search for: ";
    cin >> zodiac;
    FindPeople(people, kNumPeople, zodiac);
    
    return 0;
}

void InputPeople(Znak* people, const int kNumPeople)
{
    for (int i = 0; i < kNumPeople; i++)
    {
        cout << "Enter full name (e.g., Ivanov Ivan): ";
        getline(cin, people[i].full_name);
        cout << "Enter zodiac sign (e.g., Taurus): ";
        cin >> people[i].zodiac;
        
    date_check:
        cout << "Enter day of birth: ";
        cin >> people[i].birth_date[0];
        cout << "Enter month of birth: ";
        cin >> people[i].birth_date[1];
        cout << "Enter year of birth >= 1000: ";
        cin >> people[i].birth_date[2];
        cout << endl;
        cin.ignore();
        
        if (!IsValidDate(people[i].birth_date))
        {
            cout << "Invalid date:";
            for (int j = 0; j < 3; j++)
                cout << " " << people[i].birth_date[j];
            cout << ". Try again.\n";
            goto date_check;
        }
    }
}

bool IsFirstPersonYounger(int* birth_date_1, int* birth_date_2)
{
    // -1 — first person is older than second
    //  0 — equal
    //  1 — younger
    
    string first_date = to_string(birth_date_1[2] * 10000 +
                                  birth_date_1[1] * 100 + birth_date_1[0]);
    string second_date = to_string(birth_date_2[2] * 10000 +
                                   birth_date_2[1] * 100 + birth_date_2[0]);
    
    return first_date.compare(second_date) == 1;
}

void SortArray(Znak* people, const int kNumPeople)
{
    int i = 0;
    bool swapped = true;
    while (swapped)
    {
        swapped = false;
        for (int j = 0; j < kNumPeople - i - 1; j++)
        {
            if (IsFirstPersonYounger(people[j].birth_date, people[j + 1].birth_date))
            {
                swap(people[j], people[j + 1]);
                swapped = true;
            }
        }
        i++;
    }
}

void PrintPerson(Znak person)
{
    cout << "Name: " << person.full_name << endl;
    cout << "Zodiac: " << person.zodiac << endl;
    cout << "Birthday: " << person.birth_date[0] << ".";
    cout << person.birth_date[1] << "." << person.birth_date[2] << endl;
}

bool IsLeap(int year)
{
    if (((year % 4 == 0) && (year % 100 != 0)) || year % 400 == 0)
        return 1;
    else
        return 0;
}

bool IsValidDate(int* date)
{
    int day = date[0];
    int month = date[1];
    int year = date[2];
    
    // Month and year check
    if (month >= 1 && month <= 12 && year >= 1000)
    {
        // Days check
        if (day >= 1 && day <= 31)
        {
            // Check February
            if (month == 2)
                return ((day <= 28) || (day == 29 && IsLeap(year)));
            
            // Check April, June, September, November
            if (month == 4 || month == 6 || month == 9 || month == 11)
                return (day <= 30);
            
            // For other months
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

void FindPeople(Znak* people, const int kNumPeople, string zodiac)
{
    bool is_found = false;
    for (int i = 0; i < kNumPeople; i++)
    {
        if (zodiac == people[i].zodiac)
        {
            if (!is_found)
            {
                cout << "\nZodiac sign found:\n\n";
                is_found = true;
            }
            PrintPerson(people[i]);
            cout << endl;
        }
    }
    
    if (!is_found) cout << "\nNo people with this zodiac sign.\n";
}
