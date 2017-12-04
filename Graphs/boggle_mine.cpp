#include<iostream>
#include<cstring>
using namespace std;
 
#define M 4
#define N 4
 
// Let the given dictionary be following
string dictionary[] = {"GEEKS", "FOR", "QUIZ", "GO","SET","FORT","LOL"};
int n = sizeof(dictionary)/sizeof(dictionary[0]);

bool checkWord(string &str)
{
	for (int i=0; i<n; i++)
        if (str.compare(dictionary[i]) == 0)
          return true;
    return false;
}
void goDeep(char boggle[M][N],bool visited[M][N],int i,int j,string str)
{
	visited[i][j]=true;
	str+=boggle[i][j];
	if(checkWord(str))
		cout<<"word found\t"<<str<<endl;

	for(int row=i-1;row<=i+1 && row<M;row++)
		for(int col=j-1;col<=j+1 && col<N;col++)
			if(row>=0 && col>=0 && visited[row][col]==false)
				goDeep(boggle,visited,row,col,str);
	 // Erase current character from string and mark visited
    // of current cell as false
    str.erase(str.length()-1);
    visited[i][j] = false;
}
void findWords(char boggle[M][N])
{
	int i,j;
	bool visited[M][N];
	for(i=0;i<M;i++)
		for(j=0;j<N;j++)
			visited[i][j]=false;
	string str = "";

	for(i=0;i<M;i++)
		for(j=0;j<N;j++)
			goDeep(boggle,visited,i,j,str);
}
int main(int argc, char const *argv[])
{
	 char boggle[M][N] = {{'O','G','I','Z'},
                          {'X','U','E','K'},
                          {'O','Q','S','E'},
                     	  {'F','R','T','S'}};
 
    findWords(boggle);
    return 0;
}
