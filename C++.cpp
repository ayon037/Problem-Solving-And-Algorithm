#include <bits/stdc++.h>
using namespace std;
#define Charpoka ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'
#define SetBits(x) __builtin_popcount(x)
#define CntBits(x) (int)log2(x)+1
#define pb push_back
#define ll long long int
#define infinity 1 << 30
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define YES cout<<"YES\n"
#define Yes cout<<"Yes\n"
#define yes cout<<"yes\n"
#define NO cout<<"NO\n"
#define No cout<<"No\n"
#define no cout<<"no\n"
#define TC int t; cin>>t; while(t--)
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//*s.find_by_order(2) -> element at index 2
//s.order_of_key(3) -> lower bound of 3*/
typedef long double Tf;
const Tf EPS = 1e-9;
const ll MX = 1e8;
vector<bool>Prime(MX+1,false);
int dx[]= {0,1,-1,0,0};
int dy[]= {0,0,0,1,-1};

struct trieNode
{
    int value;
    trieNode* child[2];
    trieNode()
    {
        this->value=0;
        this->child[0]=this->child[1]=NULL;
    }
};

class Solution
{
    public:
        void Insert(trieNode* root,int pre_xor)
        {
            trieNode* temp=root;
            for(int i=31;i>=0;i--)
            {
                bool curr=pre_xor&(1<<i);
                if(temp->child[curr]==NULL)
                {
                    temp->child[curr]=new trieNode();
                }
                temp=temp->child[curr];
            }
            temp->value=pre_xor;
        }

        int query(trieNode* root,int pre_xor)
        {
            trieNode* temp=root;
            for(int i=31;i>=0;i--)
            {
                bool curr=pre_xor&(1<<i);
                if(temp->child[1-curr]!=NULL)
                {
                    temp=temp->child[1-curr];
                }
                else if(temp->child[curr]!=NULL)
                {
                    temp=temp->child[curr];
                }
            }
            return pre_xor^(temp->value);
        }

        int maxSubarrayXOR(int N,int *arr)
        {
            trieNode* root=new trieNode();
            Insert(root,0);
            int result=INT_MIN,pre_xor=0;
            for(int i=0;i<N;i++)
            {
                pre_xor=pre_xor^arr[i];
                Insert(root,pre_xor);
                result=max(result,query(root,pre_xor));
            }
            return result;
        }


};

int main()
{
    Charpoka;
    int N,X;
    cin>>N;
    int arr[N];
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
    }
    Solution ob;
    cout<<ob.maxSubarrayXOR(N,arr)<<endl;
    return 0;
}

/*
3
7
6 7 3 4 4 6 5
6 3 4 4 7 6 5
3
1 2 1
1 1 2
3
2 2 1
2 1 2
*/
