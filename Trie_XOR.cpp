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

// Maximum possible XOR value of a pair present in an array

class trieNode
{
    public:
        trieNode* left ;
        trieNode* right ;
} ;

void Insert( int n , trieNode* head )
{
    trieNode* curr = head ;
    for( int i = 31 ; i >= 0 ; i-- )
    {
        int b = ( n >> i ) & 1 ;
        if(b == 0)
        {
            if( ! curr -> left )
            {
                curr -> left = new trieNode () ;
            }
            curr = curr->left ;
        }
        else
        {
            if( ! curr -> right)
            {
                curr -> right = new trieNode () ;
            }
            curr = curr -> right ;
        }
    }
}
int findMaxXorPair( trieNode* head , int* arr , int n )
{
    int max_xor = INT_MIN ;
    for( int i = 0; i < n ; i++ )
    {
        trieNode* curr = head ;
        int value = arr [i] ;
        int curr_xor = 0 ;
        for( int j = 31 ; j >= 0 ; j-- )
        {
            int b = ( value >> j ) & 1 ;
            if( b == 0 )
            {
                if( curr -> right )
                {
                    curr_xor += pow ( 2 , j ) ;
                    curr = curr -> right ;
                }
                else
                {
                    curr = curr -> left ;
                }
            }
            else
            {
                if( curr -> left )
                {
                    curr_xor += pow ( 2 , j ) ;
                    curr = curr -> left ;
                }
                else
                {
                    curr = curr -> right ;
                }
            }
        }
        max_xor = max( max_xor , curr_xor ) ;
    }
    return max_xor ;
}
int main()
{
    int arr [ 6 ] = { 8 , 1 , 2 , 15 , 10 , 5 } ;
    trieNode* head = new trieNode () ;
    for( int i = 0 ; i < 6 ; i++ )
    {
        Insert( arr[i] , head ) ;
    }
    cout << findMaxXorPair( head , arr , 6 ) << endl ;
    return 0 ;
}


