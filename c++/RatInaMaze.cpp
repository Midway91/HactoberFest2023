#include<iostream>
using namespace std;

bool IsSafe(int **arr,int x,int y,int n){
  if(x<n && y<n && arr[x][y]==1){
    return true;
  }
  return false;
}

bool RatInaMaze(int **arr,int x,int y,int n,int **solarr){
  if(x==n-1 && y==n-1 && IsSafe(arr,x,y,n)){
    solarr[x][y]=1;
    return true;
  }

  if(IsSafe(arr,x,y,n)){
    solarr[x][y]=1;
    if(RatInaMaze(arr,x+1,y,n,solarr)){
      return true;
    }
    if(RatInaMaze(arr,x,y+1,n,solarr)){
      return true;
    }
    solarr[x][y]=0; //Backtracking and changing value back
    return false;
  }
  return false;

}
int main()
{
  int n;
  cin>>n;
  int **arr = new int *[n];
  for(int i=0;i<n;i++){
     arr[i] = new int[n];
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>arr[i][j];
    }
  }

  int **Solarr = new int *[n];
  for(int i=0;i<n;i++){
    Solarr[i] = new int[n];
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      Solarr[i][j]=0;
    }
  }

  if(RatInaMaze(arr,0,0,n,Solarr)){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        cout<<Solarr[i][j]<<" ";
      }
      cout<<endl;
    }
  }
}