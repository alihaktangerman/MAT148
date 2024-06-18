#include <iostream>
#include <vector>
using namespace std;
vector<int> storage;
vector<int> vec;
int n;
int my_counter = 0;
bool b;

void print_multiperms()
{
    b = true;
    for(int i = 0; i < n; i++) b = b && (vec[i] == 0);
    if(b)
    {
        my_counter++;
        cout << "(";
        for(auto a: storage)
            cout << a << ", ";
        cout << ")" << endl;
    }
    else{
        for(int i = 0; i < n; i++)
        {
            if(vec[i] != 0)
            {
                vec[i]--;
                storage.push_back(i);
                print_multiperms();
                storage.pop_back();
                vec[i]++;
            }
        }
    }
}

int main(){
    cout << "Plug the number of different elements n: ";
    cin >> n;
    int j;
    for(int k=1; k<=n; k++)
    {
        cout << "Plug how may of type" << k << " elemets there are: ";
        cin >> j;
        vec.push_back(j);
    }

    print_multiperms();
    cout << "counter: " << my_counter;
    return 0;
}
