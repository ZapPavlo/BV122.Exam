#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <cstdio>
using namespace std;
//to do list

struct deal {
    string name;
    string priority;
    string description ;
    string deadline;
}; 


void fillArray(deal * Array, int SIZE) {           //заповнення масиву

    for (int i = SIZE-1; i < SIZE; i++)
    {
        cout << " ADDING DEAL " << endl;
        if (i >= 1)
        {
            cout << "Names already added:";
            for (int j = 0; j < SIZE; j++)
            {
                cout <<"   " << Array[j].name ;

            }
        }
        cout << endl;
        cin.ignore();
        cout << "Enter name:" << endl;
        getline(cin, Array[i].name);
        cout << " Enter priority:" << endl;        
        getline(cin, Array[i].priority);
        cout << " Enter description:" << endl;
        getline(cin, Array[i].description);
        cout << " Enter deadline:" << endl;
        getline(cin, Array[i].deadline);
        
    }
    
 }

void showArray(deal * Array, int SIZE) {       //показ масиву

    for (int i = 0; i < SIZE; i++)
    {
        cout << " DEAL: " <<" ";
        cout << Array[i].name << endl;
        /*cout << Array[i].priority << endl;   //закоментовано для кращого вигляду на екрані. просто по імені
        cout << Array[i].description << endl;
        cout << Array[i].deadline << endl;*/
        cout << endl;
    }
    
    
}
void ElementPlus(deal *& Array, int &SIZE, deal New) {    //додавання справи

    deal * newArray = new deal[SIZE + 1];
    for (int i = 0; i < SIZE; i++)
    {
        newArray[i] = Array[i];

    }
    newArray[SIZE] = New;
    SIZE++;
    delete[]Array;
    Array = newArray;
}   

void ElementMinus(deal*& Array, int& SIZE) {         //видалення справи
    string variableToDelete;
    string exit = "exit";
    int count = 1;                                //перевірка правильності вводу
    
    while (count == 1 ) {
        cout << "Enter deal name you want to delete" << endl;

        cin >> variableToDelete;


        for (int i = 0; i < SIZE; i++)
        {

            if (variableToDelete == Array[i].name) {
                swap(Array[i], Array[SIZE - 1]);
                --count;

            }
             
               
        }
        
    };
    SIZE--;
    deal* newArray = new deal[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        newArray[i] = Array[i];

    }
    
    
    delete[]Array;
    Array = newArray;
}

void SortDeal(deal*& Array, int& SIZE) {             //сортування справ
    int Sortconfirm;
    cout << "Sort ?" << endl << "1.Yes" << "2.No" << endl;
    cin >> Sortconfirm;
    system("CLS");
    if (Sortconfirm == 1)
    {
        for (int i = 0; i < SIZE; i++)
        {

            int SortChoose;
            do
            {
                cout << endl << "Sort by: " << endl;
                cout << "1.name: " << endl;
                cout << "2.priority: " << endl;
                cout << "3.description: " << endl;
                cout << "4.deadline: " << endl;
                cout << "5.Done and exit." << endl;
                cout << endl;

                cin >> SortChoose;
                system("CLS");
                switch (SortChoose)
                {

                case 1:
                    for (int i = 0; i < SIZE; i++)
                    {
                        for (int j = i + 1; j < SIZE; j++)
                        {
                            if (Array[i].name > Array[j].name) {
                                swap(Array[i], Array[j]);
                            }
                        }
                    }

                    break;
                case 2:
                    for (int i = 0; i < SIZE; i++)
                    {
                        for (int j = i + 1; j < SIZE; j++)
                        {
                            if (Array[i].priority > Array[j].priority) {
                                swap(Array[i], Array[j]);
                            }
                        }
                    }
                    break;

                case 3:
                    for (int i = 0; i < SIZE; i++)
                    {
                        for (int j = i + 1; j < SIZE; j++)
                        {
                            if (Array[i].description > Array[j].description) {
                                swap(Array[i], Array[j]);
                            }
                        }
                    }

                case 4:
                    for (int i = 0; i < SIZE; i++)
                    {
                        for (int j = i + 1; j < SIZE; j++)
                        {
                            if (Array[i].deadline > Array[j].deadline) {
                                swap(Array[i], Array[j]);
                            }
                        }
                    }
                    break;

                default:
                    cout << " Enter 1-5 pls" << endl;
                    break;
                }
            } while (SortChoose != 5);
            break;
        }

    }


}
void DealEdit(deal*& Array, int& SIZE) {          //редагування справи

    cout << " Choose deal name: ";
    string DealChoice;
    cin >> DealChoice;

    for (int i = 0; i < SIZE; i++)
    {
        if (DealChoice == Array[i].name) {
            int ChangeOption;
            do
            {

          
            cout << endl << "Enter option(1-4) you want to change: "<<endl;
            cout << "1.name: "        << Array[i].name << endl;
            cout << "2.priority: "    << Array[i].priority << endl;
            cout << "3.description: " << Array[i].description << endl;
            cout << "4.deadline: "    << Array[i].deadline << endl;
            cout << "5.Done and exit." << endl;
            cout << endl;
           
            cin >> ChangeOption;
            system("CLS");
            switch (ChangeOption)
            {
               
            case 1:
                cin.ignore();
                cout << " current:" << Array[i].name << " ";
                cout << " Edit: ";
                getline(cin, Array[i].name);
                
                break;
            case 2:
                cin.ignore();
                cout << " current:" << Array[i].priority << " ";
                cout << " Edit: ";
                getline(cin, Array[i].priority);
                break;
                
            case 3:
                cin.ignore();
                cout << " current:" << Array[i].description << " ";
                cout << " Edit: ";
                getline(cin, Array[i].description);
                break;
                
            case 4:
                cin.ignore();
                cout << " current:" << Array[i].deadline << " ";
                cout << " Edit: ";
                getline(cin, Array[i].deadline);
                break;
                
            default:
                cout << " Enter 1-5 pls" << endl;
                break;
            }
            } while (ChangeOption!=5);
            break;
        }
        
    }
};


void FindDeal(deal*& Array, int& SIZE) {                  //Search function 

    for (int i = 0; i < SIZE; i++)
    {

        int SearchChoice;
        do
        {

            cout << endl << "Search deal by: " << endl;
            cout << "1.name: " << endl;
            cout << "2.priority: " << endl;
            cout << "3.description: " << endl;
            cout << "4.deadline: " << endl;
            cout << "5.Done and exit." << endl;
            cout << endl;

            cin >> SearchChoice;
            system("CLS");
            switch (SearchChoice)
            {
                
            case 1:
            {
                cout << " Enter deal name you want to find: ";

                string Dealname;
                cin.ignore();
                getline(cin, Dealname);
                for (int i = 0; i < SIZE; i++)
                {
                    if (Dealname == Array[i].name) 
                    {
                        cout << " DEAL: " << " ";
                        cout << Array[i].name << endl;
                        cout << Array[i].priority << endl;
                        cout << Array[i].description << endl;
                        cout << Array[i].deadline << endl;
                        cout << endl;
                    }
                }

                
            }
                break;
            case 2:
            {
                cout << " Enter deal priority you want to find: ";
                string Dealpriority;
                cin.ignore();
                getline(cin, Dealpriority);
                for (int i = 0; i < SIZE; i++)
                {
                    if (Dealpriority == Array[i].priority)
                    {
                        cout << " DEAL: " << " ";
                        cout << Array[i].name << endl;
                        cout << Array[i].priority << endl;
                        cout << Array[i].description << endl;
                        cout << Array[i].deadline << endl;
                        cout << endl;
                    }
                }
            }
                break;
            case 3:
            {
                cout << " Enter deal description you want to find: ";
                string Dealdescription;
                cin.ignore();
                getline(cin, Dealdescription);
                for (int i = 0; i < SIZE; i++)
                {
                    if (Dealdescription == Array[i].description)
                    {
                        cout << " DEAL: " << " ";
                        cout << Array[i].name << endl;
                        cout << Array[i].priority << endl;
                        cout << Array[i].description << endl;
                        cout << Array[i].deadline << endl;
                        cout << endl;
                    }
                }
            }
                 break;
            case 4:
            {
                cout << " Enter deal deadline you want to find: ";
                string Dealdeadline;
                cin.ignore();
                getline(cin, Dealdeadline);
                for (int i = 0; i < SIZE; i++)
                {
                    if (Dealdeadline == Array[i].deadline)
                    {
                        cout << " DEAL: " << " ";
                        cout << Array[i].name << endl;
                        cout << Array[i].priority << endl;
                        cout << Array[i].description << endl;
                        cout << Array[i].deadline << endl;
                        cout << endl;
                    }
                }
                
            }
                break;
            default:
                cout << " Enter 1-5 pls" << endl;
                break;
            }
        } while (SearchChoice != 5);
        break;
    }




}


int main()

{
    srand(time(0));
    setlocale(LC_ALL, "RUS");
    char userchoice;
    int N = 0;
    deal * Arr = new deal[N];
    
    
    do
    {
        deal number;                                                             //менюшка головна
        cout<< endl << "1. Add deal" << endl <<"2. Delete deal"<<endl 
            << "3. Show deals" << endl << "4. Edit deal" 
            << endl<< "5. Search deal" <<endl<< "6. Exit" << endl;
        cin >> userchoice;
        system("CLS");
        switch (userchoice)
        {
        case '1':
        {

            ElementPlus(Arr, N, number);
            fillArray(Arr, N);
            system("CLS");
            break;
        }
        case '2':
        {
            ElementMinus(Arr, N);
            showArray(Arr, N);
            break;
        }
        case '3': 
        {
            showArray(Arr, N);
            SortDeal(Arr, N);
           
            cout << endl;
            break;
        }
        case '4':
        {
            DealEdit(Arr,N);
            break;
        }
        case '5': 
        {
            FindDeal(Arr, N);
           
            break;
        }
        case '6':
        {
            cout << " Bye!";
            break;
        }
        default:
            cout << "wrong";
            break;
        }
    } while (userchoice != 6);

    return(0);

    system("pause");
}