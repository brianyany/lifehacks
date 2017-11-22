/*main*/
#include <vector>
#include <string>
#include <iostream>
#include <fstream>


using namespace std;
bool consistOf(string a, string b);

int main(){
    while(true){
        vector<string> wordsV;
        string line;
        ifstream words("words.txt");
        while(getline(words, line)){
            wordsV.push_back(line);
        }
        
        string target;
        cout << "input letters-------------------------------------" << endl;
        cin >> target;
        
        cout << "random combinations-------------------------------" << endl;
        for (auto i: wordsV){
            if(consistOf(i, target)){
                cout << i << endl;
            }
        }
        
        cout << "contain exact substring---------------------------" << endl;
        for (auto i: wordsV){
            if(i.find(target)!=string::npos){
                cout << i << endl;
            }
        }
    }
    return 0;
}

bool consistOf(string a, string b){
    bool ret=true;
    const char *cstr = b.c_str();
    if(a.length()>=10){
        return false;
    }
    for(int i=0; i<b.length(); i++){
        if(a.find(cstr[i])==string::npos){
            return false;
        }
    }
    return ret;
}
