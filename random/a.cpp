#include<bits/stdc++.h>

using namespace std;

int solve(string texto, string padrao) {

  int index_incio = -1;

  for(int i = 0; i < texto.size(); i++)
  {
    bool tem_diferente = false;

    for(int j = 0; j < padrao.size(); j++)
    {
      if(i+j == texto.size()){
        tem_diferente=true;
        break;
      }

      if(padrao[j] != texto[i+j])
        tem_diferente=true;
    }



    /*----------------------------------------------------------------------------------------------------*/


    if(!tem_diferente)
    {
      index_incio = i;
      break;
    }
  }

  return index_incio;
}

int main()
{
    int t = 1; 
    // cin >> t;

    for(int i = 0; i < t; ++i) {
        cout << solve("aaab", "aa") << endl;
    }

    return 0;
}
