#include <bits/stdc++.h>
#define ll long long  //long long yerine (ll) yazıyorum.

using namespace std;

//GLOBAL değişkenler
vector<bool> visited;
vector<int> storage; //senin list1'in gibi yani
int my_count = 0;

void print_perm(int n, int m)
{
    if((int)storage.size() == m)
    {
        for(int i = 0; i < m; i++)
            cout << storage[i] << " "; //printf
        cout << '\n';
        my_count++;
    }
    else
    {
        for(int i = 1; i <= n; i++)
        {
            if(!visited[i-1])
            {
                storage.push_back(i);
                visited[i-1] = true;
                
                print_perm(n, m);

                //yaptığım değişikleri geri almam lazım
                storage.pop_back();
                visited[i-1] = false;
            }
        }
    }
}

int main()
{
    int n, m;
    cout << "Plug n, m for calculating P(n, m): "; //BU c++'taki printf fonksiyonu işte.
    cin >> n >> m; //scanf
    if(m > n || m < 0)
        return 1;
    for(int i = 0; i < n; i++)
        visited.push_back(false);
    print_perm(n, m);
    cout << '\n' << my_count << '\n'; //printf
    return 0;
}
