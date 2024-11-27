#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

const int MaxNameLenght = 20;
const int MaxDiscriptionLenght = 100;
const int MaxCheckInNumber = 100;

int TodayDay = 17;
int TodayMounth = 5;
int TodayYear = 2023;

struct TCheckIn 
{
    char Name[MaxNameLenght] = "-";
    short priorety = 1;
    char Discription[MaxDiscriptionLenght] = "-";
    int Day = 0;
    int Mounth = 0;
    int Year = 0;
    int DeadLineDay = 0;
    int DeadLineMounth = 0;
    int DeadLineYear = 0;
};

TCheckIn CheckIns[MaxCheckInNumber];

void PrintTask(int ID) 
{
    cout <<"Name: " << CheckIns[ID].Name << "\n";
    cout <<"Discription: " << CheckIns[ID].Discription << "\n";
    cout <<"Date of the creation: "<< CheckIns[ID].Day << "." << CheckIns[ID].Mounth << "." << CheckIns[ID].Year << "\n";
    cout << "Dead line date: " << CheckIns[ID].DeadLineDay << "." << CheckIns[ID].DeadLineMounth << "." << CheckIns[ID].DeadLineYear << "\n";
}

void DeleteCheckIn(int ID) 
{
    char dash[2] = "-";
    strcmp(CheckIns[ID].Name, dash);
    CheckIns[ID].priorety = 9;
}

void EditCheckIn(const char* choise, int ID)
{
    char New[100] = "";
    int New2;
    if (strcmp("Priority", choise) == 0)
    {
        cin >> New2;
        if (New2>9)
        {
            New2 = 9;
        }
        CheckIns[ID].priorety = New2;
    }
    if (strcmp("Day", choise) == 0) 
    {
        cin >> New2;
        CheckIns[ID].DeadLineDay = New2;
    }
    if (strcmp("Year", choise) == 0)
    {
        cin >> New2;
        CheckIns[ID].DeadLineYear = New2;
    
    }
    if (strcmp("Mounth", choise) == 0)
    {
        cin >> New2;
        CheckIns[ID].DeadLineMounth = New2;
    }
    if (strcmp("Name", choise) == 0)
    {
        cin >> New;
        strcpy(CheckIns[ID].Name, New);
    }
    if (strcmp("Discription", choise) == 0) 
    {
        cin >> New;
        strcpy(CheckIns[ID].Discription, New);
    }

}
void FindTaskByName(const char* Name)
{
    for (int i = 0; i < MaxCheckInNumber; i++)
    {
        if (strcmp(CheckIns[i].Name, Name) == 0) 
        {
            PrintTask(i);
        }
    }
}
void FindTaskByDiscriotion(const char* Discription)
{
    for (int i = 0; i < MaxCheckInNumber; i++)
    {
        if (strcmp(CheckIns[i].Discription, Discription) == 0)
        {
            PrintTask(i);
        }
    }
}
void FindTaskByPriority(int Priority)
{
    for (int i = 0; i < MaxCheckInNumber; i++)
    {
        if (CheckIns[i].priorety == Priority)
        {
            PrintTask(i);
        }
    }
}
void FindTaskByDate(int Day, int Mounth, int Year, int DeadLineDay, int DeadLineMounth, int DeadLineYear)
{
    for (int i = 0; i < MaxCheckInNumber; i++)
    {
        if (CheckIns[i].Day == Day && CheckIns[i].Mounth == Mounth && CheckIns[i].Year == Year && CheckIns[i].DeadLineDay == DeadLineDay && CheckIns[i].DeadLineMounth == DeadLineMounth && CheckIns[i].DeadLineYear == DeadLineYear)
        {
            PrintTask(i);
        }
    }
}
void PrintTodayTask()
{
    int tmp1 = 0;
    int tmp2 = 0;
    for (int i = 0; i < MaxCheckInNumber; i++)
    {
        if (CheckIns[i].DeadLineYear == TodayYear) {
            tmp1 = CheckIns[i].DeadLineDay + (CheckIns[i].Mounth * 29);
            tmp2 = TodayDay + (TodayMounth * 29);
            if (tmp1 == tmp2 + 1) 
            {
                PrintTask(i);
            }
        }
    }
}
void PrintWeekTask()
{
    int tmp1 = 0;
    int tmp2 = 0;
    for (int i = 0; i < MaxCheckInNumber; i++)
    {
        if (CheckIns[i].DeadLineYear == TodayYear) {
            tmp1 = CheckIns[i].DeadLineDay + (CheckIns[i].Mounth * 29);
            tmp2 = TodayDay + (TodayMounth * 29);
            if (tmp1 == tmp2 + 7)
            {
                PrintTask(i);
            }
        }
    }
}
void PrintMounthTask()
{
    int tmp1 = 0;
    int tmp2 = 0;
    for (int i = 0; i < MaxCheckInNumber; i++)
    {
        if (CheckIns[i].DeadLineYear == TodayYear) {
            tmp1 = CheckIns[i].DeadLineDay + (CheckIns[i].Mounth * 29);
            tmp2 = TodayDay + (TodayMounth * 29);
            if (tmp1 == tmp2 + 29)
            {
                PrintTask(i);
            }
        }
    }
}
void PrintWeekTask()
{
    for (int i = 0; i < MaxCheckInNumber; i++)
    {
        
    }
}
void MakeCheckIn()
{
    char dash[2] = "-";
    char tmp[MaxNameLenght] = "";

    for (int i = 0; i < MaxCheckInNumber; i++) 
    {
        if (strcmp(CheckIns[i].Name, dash) == 0) 
        {
            cout << i << " is a ID of your task, please, enter a name of the task\n";
            char NewName[MaxNameLenght] = "";
            cin >> NewName;
            strcpy(CheckIns[i].Name, NewName);
            cout << "Good job, give a discription\n";
            char NewDiscription[MaxDiscriptionLenght] = "";
            cin >> NewDiscription;
            strcpy(CheckIns[i].Discription, NewDiscription);
            CheckIns[i].Day = TodayDay;
            CheckIns[i].Mounth = TodayMounth;
            CheckIns[i].Year = TodayYear;
            cout << "Please, enter a priority of the task (0 = highest, 9 = dead)\n";
            int NewPriority;
            cin >> NewPriority;
            CheckIns[i].priorety = NewPriority;
            cout << "Please, enter dead line day, mounth and year\n";
            cin >> CheckIns[i].DeadLineDay; cin >> CheckIns[i].DeadLineMounth; cin >> CheckIns[i].DeadLineYear;
            break;
        }
    }
}

int main()
{
    cout << "For correct work of programm, please, enter a date\n";
    MakeCheckIn();
}



