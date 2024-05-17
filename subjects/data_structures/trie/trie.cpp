#include<bits/stdc++.h>

using namespace std;

const int alphabet_size = 26;

struct trieNode
{
    trieNode * children[alphabet_size];

    trieNode()
    {
        for(int i = 0; i < alphabet_size; i++)
            this->children[i] = NULL;
    }

    bool end = false;
};

void freeTrieNode(trieNode * node)
{
    if(node == NULL)
        return;

    for(int i =0 ; i < alphabet_size; i++)
        freeTrieNode(node->children[i]);

    delete node;
}

class Trie
{


    private:
        trieNode * root = new trieNode();
    public:
        ~Trie()
        {
            freeTrieNode(root);
        }

        void insert(const string & s)
        {
            auto crawl = root;

            for(char c : s)
            {
                int index = c - 'a';

                if(crawl->children[index] == NULL)
                    crawl->children[index] = new trieNode();

                crawl = crawl->children[index];
                
            }

            crawl->end = true;
        }

        bool find_prefix(const string & s)
        {
            auto crawl = root;


            for(char c : s)
            {
                int index = c - 'a';

                if(crawl->children[index] == NULL)
                    return false;

                crawl = crawl->children[index];
            }

            return true;

        }


        bool find(const string & s)
        {
            auto crawl = root;


            for(char c : s)
            {
                int index = c - 'a';

                if(crawl->children[index] == NULL)
                    return false;

                crawl = crawl->children[index];
            }

            return crawl->end;
        }


    
};

int main()
{



    return 0;
}