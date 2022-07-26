#include <bits/stdc++.h>
using namespace std;

string Give_String(char c)
{
        if (c == 'a')
        {
            // str.replace(i, 1, "@");
            return "@";
        }
        if (c == 'b')
        {
            // str.replace(i, 1, "8");
            return "8";
        }
        if (c == 'c')
        {
            // str.replace(i, 1, "(");
            return "(";
        }
        if (c == 'd')
        {
            // str.replace(i, 1, "|)");
            return "|)";
        }
        if (c == 'e')
        {
            // str.replace(i, 1, "3");
            return "3";
        }
        if (c == 'f')
        {
            // str.replace(i, 1, "#");
            return "#";
        }
        if (c == 'g')
        {
            // str.replace(i, 1, "6");
            return "6";
        }
        if (c == 'h')
        {
            // str.replace(i, 1, "[-]");
            return "[-]";
        }
        if (c == 'i')
        {
            // str.replace(i, 1, "|");
            return "|";
        }
        if (c == 'j')
        {
            // str.replace(i, 1, "_|");
            return "_|";
        }
        if (c == 'k')
        {
            // str.replace(i, 1, "|<");
            return "|<";
        }
        if (c == 'l')
        {
            // str.replace(i, 1, "1");
            return "1";
        }
        if (c == 'm')
        {
            // str.replace(i, 1, "[]\\/[]");
            return "[]\\/[]";
        }

        if (c == 'n')
        {
            // str.replace(i, 1, "[]\\[]");
            return "[]\\[]";
        }
        if (c == 'o')
        {
            // str.replace(i, 1, "0");
            return "0";
        }
        if (c == 'p')
        {
            // str.replace(i, 1, "|D");
            return "|D";
        }

        if (c == 'q')
        {
            // str.replace(i, 1, "(,)");
            return "(,)";
        }

        if (c == 'r')
        {
            // str.replace(i, 1, "|Z");
            return "|Z";
        }

        if (c == 's')
        {
            // str.replace(i, 1, "$");
            return "$";
        }

        if (c == 't')
        {
            // str.replace(i, 1, "']['");
            return "']['";
        }

        if (c == 'u')
        {
            // str.replace(i, 1, "|_|");
            return "|_|";
        }
        if (c == 'v')
        {
            // str.replace(i, 1, "\\/");
            return "\\/";
        }
        if (c == 'w')
        {
            // str.replace(i, 1, "\\/\\/");
            return "\\/\\/";
        }
        if (c == 'x')
        {
            // str.replace(i, 1, "{}");
            return "}{";
        }
        if (c == 'y')
        {
            // str.replace(i, 1, "`/");
            return "`/";
        }

        if (c == 'z')
        {
            // str.replace(i,1,"2");
            return "2";
        }
        
}



int main()
{
    string str;
    getline(cin, str);
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = tolower(str[i]);
        }

        
    }

    for(int i = 0; i < str.size(); i++)
    {
        if(str[i]>='a' && str[i]<='z')
        {
            cout<<Give_String(str[i]);
        }
        else
        {
            cout<<str[i];
        }
    }

    // cout<<s;
    // cout<<str;
    return 0;
}