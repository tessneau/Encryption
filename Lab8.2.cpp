#include <iostream>
#include <vector>
using namespace std;

void displayValues(vector<int> &scores) 
{
    for (unsigned int i = 0 ; i < scores.size(); i++) 
        cout << scores[i] << " ";
    cout << endl;
}

void inputValues(vector<int> &scores) 
{
    int next;
    cin >> next;
    while (next > 0)
    {
        scores.push_back(next);
        cin >> next;
    }
}
void swap_values(int& v1, int& v2)
{
    int temp;
    temp = v1;
    v1 = v2;
    v2 = temp;
}
 
 
int index_of_smallest(vector<int> &a, int start_index)
{
    int min = a[start_index];
    int index_of_min = start_index;
    
    for (int index = start_index + 1; index < a.size(); index++)
        if (a[index] < min)
        {
            min = a[index];
            index_of_min = index;
            //min is the smallest of a[start_index] through a[index]
        }
 
    return index_of_min;
}

void sort(vector<int> &a)
{
    int   index_of_next_smallest;
    for (int index = 0; index < a.size() - 1; index++)
    {//Place the correct value in a[index]:
        
        index_of_next_smallest = index_of_smallest(a, index);
        
        swap_values(a[index], a[index_of_next_smallest]);
        //a[0] <= a[1] <=...<= a[index] are the smallest of the original array 
        //elements. The rest of the elements are in the remaining positions.
    }
}

int main() {
    vector<int> theNums;
    
    cout << "Enter a list of positive values to sort, -1 to end: ";
    inputValues(theNums);
    displayValues(theNums);
    sort(theNums);
    displayValues(theNums);
    
    return 0;
}