#include<bits/stdc++.h>

using namespace std;

const int K=26;

struct Node
{
    int next_node[K];
    int go_be[K];
    bool leaf = false;
    int link = -1;

    int parent;
    char c;

    Node(int _parent, char _c) : parent(_parent), c(_c)
    {
        fill(begin(next_node), end(next_node), -1);
        fill(begin(go_be), end(go_be), -1);
    }
};

vector<Node> trie;
void init()
{
    trie.clear();
    trie.resize(1);
}

int add(const string & s)
{
    int i = 0;
    for(char c : s)
    {
        int pos = c -'a';

        if(trie[i].next_node[pos] == -1)
        {
            trie[i].next_node[pos] = trie.size();
            trie.push_back(Node(i, c));
        }
        i = trie[i].next_node[pos];
    }

    trie[i].leaf = true;
}

int go(int i, int c);

int get_link(int i)
{
    if(trie[i].link == -1)
    {
        if(i == 0 || trie[i].parent == 0)
            trie[i].link = 0;
        else
            trie[i].link = go(get_link(trie[i].parent), trie[i].c);
    }

    return trie[i].link;
}

int go(int i, char c)
{
    int pos = c - 'a';

    if(trie[i].go_be[pos] == -1)
    {
        if(trie[i].next_node[pos] != -1)
            trie[i].go_be[pos] = trie[i].next_node[pos];
        else
            trie[i].go_be[pos] = i == 0 ? 0 : go(get_link(i), c);
    }

    return trie[i].next_node[c];
}

bool match(const string & s)
{
}

int main()
{



    return 0;
}