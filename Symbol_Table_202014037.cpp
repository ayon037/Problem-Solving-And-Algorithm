#include <bits/stdc++.h>
using namespace std;

int Hash_Code(string s2)
{
    int sum = 0;
    for (int i = 0; i < s2.size(); i += 2)
    {
        if (i % 2 == 0)
        {
            int val = s2[i];
            sum = sum + (val << 7);
        }
    }
    return sum;
}
class SymbolInfo
{
public:
    string symbol;
    string category;
    string data_type;
    SymbolInfo(string sy, string ca, string da)
    {
        symbol = sy;
        category = ca;
        data_type = da;
    }
};

map<int, vector<SymbolInfo>> mp;
class SymbolTable
{
public:
    int mx = 0;
    int idx = 0;
    void Store(string s1, string s2, string s3)
    {
        int sum, pos;
        sum = Hash_Code(s2);
        idx = sum % 10;
        mx = max(mx, idx);
        mp[idx].push_back(SymbolInfo(s1, s2, s3));
        for (int j = 0; j < mp.size(); j++)
        {
            int flag = 0;
            for (int i = 0; i < mp[j].size(); i++)
            {
                if (mp[j][i].category == s2)
                {
                    pos = i;
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
                break;
        }
        cout << "Inserted at position " << idx << "," << pos << endl;
    }

    void Print()
    {
        for (int j = 0; j < mp.size(); j++)
        {
            cout << j << " -> ";
            for (int i = 0; i < mp[j].size(); i++)
            {
                if (mp[j][i].symbol == "null")
                {
                    cout << "< " << mp[j][i].category << " , " << mp[j][i].data_type << " > ";
                }
                else
                {
                    cout << "< " << mp[j][i].symbol << " , " << mp[j][i].category << " , " << mp[j][i].data_type << " > ";
                }
            }
            cout << endl;
        }
    }

    void Find(string s)
    {
        int flag = 0;
        for (int j = 0; j < mp.size(); j++)
        {
            int pos;
            for (int i = 0; i < mp[j].size(); i++)
            {
                string sp = mp[j][i].category;
                if (sp == s)
                {
                    pos = i;
                    flag = 1;
                    cout << "Found at " << j << ", " << pos << endl;
                    break;
                }
            }
            if (flag == 1)
                break;
        }
        if (flag == 0)
        {
            cout << "Not Found" << endl;
        }
    }

    void Delete(string s)
    {
        int flag;
        for (int j = 0; j < mp.size(); j++)
        {
            flag = 0;
            int pos;
            for (int i = 0; i < mp[j].size(); i++)
            {
                if (mp[j][i].category == s)
                {
                    pos = i;
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
            {
                mp[j].erase(mp[j].begin() + pos);
                cout << "Deleted from " << j << ", " << pos << endl;
                break;
            }
        }
        if (flag == 0)
        {
            cout << "Not Found" << endl;
        }
    }
};

int main()
{
    ifstream file("file.txt");
    string str;
    while (getline(file, str))
    {
        string s1 = "", s2 = "", s3 = "";
        // getline(cin,str);
        SymbolTable ob1;
        if (str[0] == 'I')
        {
            int cnt = 0;
            for (int i = 1; i < str.size(); i++)
            {
                if (str[i] == ' ')
                    cnt++;

                if (cnt == 1)
                {
                    if (str[i + 1] != ' ' && (i + 1) != str.size())
                    {
                        s1 += str[i + 1];
                    }
                }
                else if (cnt == 2)
                {
                    if (str[i + 1] != ' ' && (i + 1) != str.size())
                    {
                        s2 += str[i + 1];
                    }
                }
                else
                {
                    if (str[i + 1] != ' ' && (i + 1) != str.size())
                    {
                        s3 += str[i + 1];
                    }
                }
            }

            if (cnt == 2)
            {
                s3 = s2;
                s2 = s1;
                s1 = "null";
            }

            ob1.Store(s1, s2, s3);
        }
        else if (str[0] == 'P')
        {
            ob1.Print();
        }
        else if (str[0] == 'L')
        {
            for (int i = 2; i < str.size(); i++)
            {
                s2 += str[i];
            }
            ob1.Find(s2);
        }
        else if (str[0] == 'R')
        {
            for (int i = 2; i < str.size(); i++)
            {
                s2 += str[i];
            }
            ob1.Delete(s2);
        }
    }
    file.close();
    return 0;
}
