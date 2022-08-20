#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    Node *root[26];
    bool flag;
    Node()
    {
        for (int i = 0; i < 26; i++)
            root[i] = NULL;
        flag = false;
    }
    bool is_contain(char c)
    {
        if (root[c - 'a'] != NULL)
            return true;
        return false;
    }
    Node *getNextnode(char c)
    {
        return root[c - 'a'];
    }
    Node *putNode(char c)
    {
        root[c - 'a'] = new Node;
        return root[c - 'a'];
    }

    void endOfword()
    {
        flag = true;
    }
};
class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node;
    }
    void insert(string s)
    {
        Node *node = root;
        for (int i = 0; i < s.length(); i++)
        {
            if (node->is_contain(s[i]))
            {
                node = node->getNextnode(s[i]);
            }
            else
            {
                node = node->putNode(s[i]);
            }
        }
        node->endOfword();
    }
    bool searchWord(string s)
    {
        Node *node = root;
        for (int i = 0; i < s.length(); i++)
        {
            if (!node->is_contain(s[i]))
            {

                return false;
            }
            node = node->getNextnode(s[i]);
        }

        if (node->flag == true)
            return true;
        return false;
    }
    bool checkPrefix(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (node->is_contain(prefix[i]))
            {
                node = node->getNextnode(prefix[i]);
            }
            else
                return false;
        }
        return true;
    }
};
int main()
{

    Trie object;
    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            string s;
            cin >> s;

            object.insert(s);
        }
        if (type == 2)
        {
            string s;
            cin >> s;
            if (object.checkPrefix(s))
            {
                cout << "YES"
                     << "\n";
            }
            else
                cout << "NO"
                     << "\n";
        }
        if (type == 3)
        {
            string s;
            cin >> s;
            if (object.searchWord(s))
            {
                cout << "YES"
                     << "\n";
            }
            else
                cout << "NO"
                     << "\n";
        }
    }
    return 0;
}
