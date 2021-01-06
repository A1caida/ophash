#include <iostream>
#include <vector>
using namespace std;
// todo3:Ргтлыл тсхсп жов фздв ф цнгкгхзовпл ток
// todo3:Ълфхс хзшрлъзфнл ахс хсйз тугелоярс, рс рзх!!!

typedef struct Node_ 
{
    int data;
    Node_* next; 
} Node;


Node* insert(int data, Node** hashTable) {
    Node* p, * p0;
    if ((p = new Node) == 0) {
        cout << "Нет памяти." << endl;
        exit(-1);
    }
    p0 = hashTable[data % 7];
    hashTable[data % 7] = p;
    p->next = p0;
    p->data = data;
    return p;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    int** hash = new int*[8];
    cout << "Сколько значений?\n";
    int count;
    cin >> count;
    Node** hashTable = new Node * [count];
    for (size_t i = 0; i < 8; i++)
    {
        hash[i] = new int[count];
    }
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < count; j++)
        {
            hash[i][j] = 0;
        }
    }
    for (size_t i = 0; i < 8; i++)
    {
        hash[i][0] = 1;
    }
    for (size_t i = 0; i < count; i++)
    {
        int temp;
        cout << "Вводите значения\n";
        cin >> temp;
        hash[temp % 7][hash[temp % 7][0]] = temp;
        hash[temp % 7][0]++;
        insert(temp, hashTable);
    }
    cout <<"________________"<<endl;
    for (size_t i = 0; i < 8; i++)
    {
        cout << i << "-";
        for (size_t j = 1; j < count; j++)
        {
            if (hash[i][j]!=0)
            {
                cout <<hash[i][j] << "\t";
            }        
        }
        cout << endl;
    }
    
}

