#include<bits/stdc++.h>
#define MAX ((int)2e9 + 5)
#define MAXL ((ll)1e16 + 5)
#define pi acos(-1)
#define MOD ((int)1e9 + 7)
#define N ((int)1e5 + 5)
#define eps (1e-8)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long
//#define int ll


using namespace std;



/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/

/// to declare vector: vector < data type > name;
/// to insert an element: name.push_back(element);
/// to erase an element: name.erase( name.begin() + index ); /// O ( size )
/// to erase a subsegment: name.erase( name.begin() + starting index , name.begin() + ending index + 1 ); /// O ( size )

int main()
{
    int n;
    cin>>n;
    vector < int > arr;

    /// or vector < int > arr ( n ) , this will create a vector of size n filling with zeros

    for(int i = 0 ; i<n ; i++){
        arr.push_back(i + 10);
    }
    cout<<arr.size()<<endl;
    for(int i = 0 ; i<n ; i++) cout<<arr[i]<<" ";
    cout<<endl;
    arr.erase(arr.begin() + 2 , arr.end() ); /// O ( size )
    cout<<arr.size()<<endl;
    for(int i = 0 ; i<arr.size() ; i++) cout<<arr[i]<<" ";
    cout<<endl;
    for(auto a : arr){
        cout<<a<<" ";
    }
    cout<<endl;


    return 0;
}
