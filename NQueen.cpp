#include <bits/stdc++.h>
using namespace std;
#define Charpoka ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cin.exceptions(ios::badbit | ios::failbit)
#define endl '\n'
#define pb push_back
#define ll long long int
#define mx 100001
#define infinity 1 << 30

bool isSafe(int board[][10],int i,int j,int n)
{
   //Check column
   for(int row=0;row<i;row++)
   {
      if(board[row][j]==1)
         return false;
   }
   //Check Left diagonal
   int x=i;
   int y=j;
   while(x>=0 && y>=0)
   {
      if(board[x][y]==1)
         return false;
      x--;
      y--;
   }

   //Check Right Diagonal;
   x=i;
   y=j;
   while(x>=0 && y<n)
   {
      if(board[x][y]==1)
      {
         return false;
      }
      x--;
      y++;
   }
   //Checked in columns and diagonal
   return true;
}

bool solveNQueen(int board[][10],int i,int n)
{
   // base case
   if(i==n)
   {
      //Successfully placed queens in n rows
      //Print the board
      for(int i=0;i<n;i++)
      {
         for(int j=0;j<n;j++)
         {
            if(board[i][j]==1)
            {
               cout<<"*";
            }
            else
            {
               cout<<".";
            }
         }
         cout<<endl;
      }
      cout<<endl<<endl;
      return false;
      /*return true; //Will search for only one solution*/

   }

   //Recursive Case
   //Try to place the queen in the current row and call on the remaining part which will be solved by recursion
   for(int j=0;j<n;j++)
   {
      //iterating over all the columns
      //I've to check i,j th position in safe to place the queen or not
      if(isSafe(board,i,j,n))
      {
         //Place the Queen - Assuming i,j is the right position
         board[i][j]=1;
         bool CanWePlacenextQueen=solveNQueen(board,i+1,n);
         if(CanWePlacenextQueen)
            return true;
          //Means i,j position is not the right position
         board[i][j]=0;//Backtrack
      }
     
   }
   //Tried for all positions in the current row but couldn't plase the queen
   return false;
}

int main()
{
   Charpoka;
   int n;
   cin>>n;

   int board[10][10]={0};
   solveNQueen(board,0,n);
}