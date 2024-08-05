#include<bits/stdc++.h>

using namespace std;

int main(){

    int arr[100];

    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 10};

    int a = 15;


    // Poe um valor no fim do vetor
    v.push_back(a);
    v.pop_back();

    // cout << v.size() << endl;

    // Redefine o tamanho do vetor para que
    // v.size() == 20
    v.resize(20, 1);

    // cout << v.size() << endl;

    // v.erase(v.begin() + 4);

    v[1];

    // sort(arr, arr+100);

    sort(v.begin(), v.end());

 /////////////////////////////////////

    queue < int > q;

    // Poe algo no fim da fila
    q.push(12321);
    q.push(1);
    q.push(2);
    q.push(3);

    q.size();

    // Tira quem esta na frente da fila
    q.pop();

    q.empty();

    // Retorna quem esta na frente da fila
    q.front();
    // Retorna quem esta no fim da fila
    q.back();


    // Modo de ler a fila na ordem
    while( ! q.empty())
    {
        int cara_da_frente = q.front();
        q.pop();
    }

  ////////////////////

    stack<int> s;

    // Poe um valor no topo da pilha
    s.push(10);
    s.push(11);
    s.push(15);
    s.push(120);
    s.push(10);

    // tira um valor do topo da pilha
    s.pop();

    // Retorna o valor que esta no topo
    s.top();

    s.size();
    s.empty();

  //////////////////////////////////////

    set<int> c;

    c.insert(3);
    c.insert(4);
    c.insert(5);

    c.erase(3);

    c.size();
    c.empty();

    // cout << c.size() << endl;

    c.insert(4);

    // cout << c.size() << endl;

    c.count(6);

    c.begin();
    c.end();

    // for each
    c.insert(6);
    c.insert(2);
    c.insert(3);
    for(int i : c)
    {
        // cout << i << endl;
    }

    // multiset<int>;

  ///////////////////////////////////

    map<string, int> m;

    m["joao"] = 7;
    m["paulo"] = 8;
    m["marcelo"] = 10;

    cout << m["joao"] << endl;

    m.size();

    m["gabriel"] = 5;

    m.size();
    m.empty();

    m.insert({"string", 2});

    // if(m.count("joao") == 1)
    //     cout << "tem joao" << endl;
        
    m.erase("joao");

    m.begin();
    m.end();

    for(auto p : m)
    {
        cout << p.first << ' ' << p.second << endl;
    }

	return 0;
}


// 10 1 3
// 10
// 10
// 0
// 6
// 7