#include <iostream>
using namespace std;



/*
this function is to check if the dictionary contains a specfic word or not
*/
int dictionaryContains(string &word)
{
    string dictionary[] = {"mobile","samsung","sam","sung",
                            "man","mango", "icecream","and",
                            "go","i","love","ice","cream"};
    int n = sizeof(dictionary)/sizeof(dictionary[0]);
    for (int i = 0; i < n; i++)
        if (dictionary[i].compare(word) == 0)
            return true;
    return false;
}
 

void wordBreakUtil(string str, int size, string result);
 
//a function that called the the Util function
void wordBreak(string str)
{

    wordBreakUtil(str, str.size(), "");
}
 
//This is the main functin that do all the work
void wordBreakUtil(string str, int n, string result)
{
   //parsing the input string 
    for (int i=1; i<=n; i++)
    {
        //extract substring from 0 to i in prefix
        string prefix = str.substr(0, i);
 
        //it checks if it is in the dictionary 
        //if no it wont go for the next nodes for this call
        // if be is prefix so it wont contine in this sub recursive tree
        // it will backtrack
        if (dictionaryContains(prefix))
        {
         //if it reaches to the end of the string 
         //return and print the result 
            if (i == n)
            {
                // add this element to previous prefix
                result += prefix;
                cout << result << endl; //print result
                return;
            }
            //if not returned, then it will continue in the recursive tree
            wordBreakUtil(str.substr(i, n-i), n-i,
                                result + prefix + " ");
        }
    }      //end for
}//end function
 

 //Drive function where we can test the above functions

int main()
{
    cout << "First Test:\n";
    wordBreak("iloveicecreamandmango");
 
    cout << "\nSecond Test:\n";
    wordBreak("ilovesamsungmobile");
    return 0;
}