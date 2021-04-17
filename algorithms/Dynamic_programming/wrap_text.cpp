
#include <iostream>
#include <vector>
#include <math.h>
#include <sstream>
using namespace std;
vector<vector<int>> get_cost_matrix(vector<int> size, int line)
{
    vector<vector<int>> cost;
    cost.resize(size.size());
    for (int i = 0; i < size.size(); i++)
        cost[i].resize(size.size());

    for (int i = 0; i < size.size(); i++)
    {
        int totalsum = 0;
        for (int j = i; j < size.size(); j++)
        {
            totalsum = totalsum + size[j];
            if (line - totalsum >= 0)
                cost[i][j] = pow(line - totalsum, 2);
            else
                cost[i][j] = 123456789;
            totalsum++;
        }
    }

    //  for(int i=0;i<size.size();i++)
    // {
    //  for(int j=0;j<size.size();j++){
    //     cout<<cost[i][j]<<" ";
    //  }
    //  cout<<endl;
    // }
    return cost;
}
vector<int> get_pointer(vector<vector<int>> cost, vector<int> size, vector<int> &minC)
{
    minC.resize(size.size());
    vector<int> pointer;
    pointer.resize(size.size());
    minC[size.size() - 1] = cost[size.size() - 1][size.size() - 1];
    pointer[size.size() - 1] = size.size();

    int s = cost.size() - 1;
    int j = cost.size() - 2;
    int i = cost.size() - 2;

    while (i >= 0)
    {
        int in = i;
        int minco = 979612; //big number
        int index = 0;
        while (in <= s)
        {
            if (cost[i][in] == 123456789) //to stop when hiiting infinity
                break;
            if (minco > (minC[in + 1] + cost[i][in]))
            {
                minco = minC[in + 1] + cost[i][in];
                minC[i] = minco;
                index = in + 1;
            }
            in++;
        }
        pointer[i] = index;

        i--;
    }

    // for(int i=0;i<min_cos.size();i++)
    // cout<<pointer[i]<<endl;

    return pointer;
}

void display(vector<string> name, vector<int> pointer)
{

    int counter = 0;
    for (int i = 0; i < pointer.size(); i = pointer[i])
    {
        cout << "line " << counter + 1 << ": ";
        for (int j = i; j < pointer[i]; j++)
            cout << name[j] << " ";
        cout << endl;
        counter++;
    }
}
vector<string> split(string str)
{
    vector<string> name;
    istringstream ss(str);
    string word;
    while (ss >> word)
    {

        name.push_back(word);
    }
    return name;
}
// void getsize(vector<string>name)
// {

//     vector<int>size;
//   for(int i=0;i<name.size();i++)
//         cout<<name[i].size();

//     return size;
// }
void wrap_text(vector<string> name, int L)
{
    vector<int> size;
    for (int i = 0; i < name.size(); i++)
        size.push_back(name[i].size());

    vector<int> minC;
    get_cost_matrix(size, L);
    get_pointer(get_cost_matrix(size, L), size, minC);
    cout << "Minimum cost: " << minC[0] << endl;
    display(name, get_pointer(get_cost_matrix(size, L), size, minC));
}

int main()
{
    cout << "---------------Test case 1-----------------" << endl;
    wrap_text(split("jackie Tom loves to cook"), 10);
    cout << endl;
    cout << "---------------Test case 2-----------------" << endl;
    wrap_text(split("blah blah blah blah reallylongword"), 16);

    //for any other testcase the user can enter
    cout << "do you like to test anything more" << endl;
    cout << "1:Yes\n";
    cout << "2:No, thanks\n";
    int userChoice;
    cin >> userChoice;

    if (userChoice != 2 && userChoice != 1)
    {
        cout << "Invalid answer, program will terminate, thanks\n";
        return 0;
    }

    else if (userChoice == 2)
    {
        cout << "Thanks for using my program\n";
        return 0;
    }
    else
    {
        string userinput;
        stringstream ss;
        cin.ignore();
        getline(cin, userinput);
        ss << userinput;
        cout << userinput;

        cout << endl;
        int width;
        cin >> width;
        cout << "---------------Test case 3-----------------" << endl;
        wrap_text(split(userinput), width);
    }

    return 0;
}
