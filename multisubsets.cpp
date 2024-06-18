#include <iostream>
#include <vector>
using namespace std;
vector<int> storage;
vector<int> vec;
int n;
int my_counter = 0;

void print_multisubsets(int r=0)
{

    if(n==r)
    {
        my_counter++;
        cout << "{";
        for(int j = 0; j < n; j++)
            for(int k = 0; k < storage[j]; k++)
                cout << j+1 << ", ";
        cout << "}" << endl;
    }
    else
        for(int i = 0; i <= vec[r]; i++)
        {
            storage.push_back(i);
            print_multisubsets(r+1);
            storage.pop_back();
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

    print_multisubsets();
    cout << "counter: " << my_counter;
    return 0;
}
