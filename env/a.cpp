#include <iostream>
#include <string>
#include <set>
using namespace std;

void WordSplit() {
  
    string strArr[]= {"", ""};
     int arrLength;
    cin >> strArr[0];
    cin >> strArr[1];

  string & alphabeth = strArr[1];
  string & word = strArr[0];

  set<string> dict;

  int last = 0;
  for(int i =0 ; i < alphabeth.size(); i++)
  {
    if(alphabeth[i] == ',')
    {
      dict.insert(alphabeth.substr(last, i- last));
      last=i+1;
    }
  }

  string front_str="";

  while(word.size())
  {
    if(dict.count(front_str) && dict.count(word))
    {
      word = front_str + "," + word;
      break;
    }
    front_str += word[0];
    word.erase(0, 1);
  }


  // code goes here  
cout << strArr[0] << endl;

}

int main(void) { 
    WordSplit();

    return 0;

}