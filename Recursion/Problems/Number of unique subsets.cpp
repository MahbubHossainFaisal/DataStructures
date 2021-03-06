#include<bits/stdc++.h>
using namespace std;

set <string> s;

void printSubsets(string input,string output)
{
    if(input.size() == 0){
        s.insert(output);
        return;
    }
    string output1 = output;
    string output2 = output;

    output2.push_back(input[0]);
    input.erase(input.begin() + 0);

    printSubsets(input,output1);
    printSubsets(input,output2);

}


int main()
{
    string input,output="";
    cin>>input;
    printSubsets(input,output);
    for(auto items: s){
        cout<<items<<" ";
    }
    return 0;
}
