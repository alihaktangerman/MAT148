#include <iostream>
#include <vector>
using namespace std;
vector<bool> visited;
int my_counter = 0;
int r = 0;

void print_subsets(int n){
    if(r == n){
        my_counter++;
        cout << "{";
        for(int i = 0; i < n; i++){
            if(visited[i])
                cout << i + 1 << ", ";
        }
        cout << "}" << endl;
    }
    else{
        visited[r] = true;
        r += 1;
        print_subsets(n);
        r -= 1;
        visited[r] = false;
        r += 1;
        print_subsets(n);
        r -= 1;
    }
};

int main(){
    int n;
    cout << "Plug n for listing 2^[n]: ";
    cin >> n;
    for(int i = 0; i < n; i++)
        visited.push_back(false);
    print_subsets(n);
    cout << "counter: " << my_counter << endl;
}
