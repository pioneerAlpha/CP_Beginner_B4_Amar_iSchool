#include<bits/stdc++.h>
#define MAX ((int)2e9 + 5)
#define MAXL ((ll)1e16 + 5)
#define pi acos(-1)
#define MOD ((int)1e8 + 7)
#define N ((int)2e5 + 5)
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

/// to declare: deque < data type > name;
///// to insert: deque < data type > name;

int main()
{
    fastio;
    set < int > stt;
//    cout<<stt.size()<<endl;
    stt.insert(5);
//    stt.insert(5);
//    cout<<stt.size()<<endl;
    stt.insert(-5);
    stt.insert(-6);
    stt.insert(6);
    stt.insert(0); /// log

    for( set < int > :: iterator itt = stt.begin() ; itt != stt.end() ; itt++){ /// n*logn
        cout<<*itt<<" ";
    }

    cout<<endl;

    set < int > :: iterator itt = stt.end();
    while(1){
        itt--;
        cout<<*itt<<" ";
        if(itt == stt.begin()) break;
    }

    cout<<endl;

    itt = stt.find(0);
    cout<<*itt<<endl;

    stt.erase(0); /// or stt.erase(itt);
    for( set < int > :: iterator itt = stt.begin() ; itt != stt.end() ; itt++){ /// n*logn
        cout<<*itt<<" ";
    }
    cout<<endl;
    stt.clear();
    cout<<stt.size()<<endl;


    return 0;
}
