#include <iostream>
#include <vector>
using namespace std;

vector<bool> visited;
int my_counter = 0;

void print_ksubsets(int &j, int &k){
    if(j != 0){
        visited.push_back(false);
        j -= 1;
        print_ksubsets(j, k);
        j += 1;
        visited.pop_back();
    }
    if(k != 0){
        visited.push_back(true);
        k -= 1;
        print_ksubsets(j, k);
        k += 1;
        visited.pop_back();
    }
    if(j == 0 && k == 0){
        my_counter++;
        cout << "{";
        for(int i = 0; i < visited.size(); i++){
            if(visited[i])
                cout << i << ", ";
        }
        cout << "}" << endl;
    }

}

int main(){
    int n, k;
    cout << "Plug n,k for listing k-subsets of [n]:";
    cin >> n >> k;
    int j = n - k;
    print_ksubsets(j, k);
    cout << "counter: " << my_counter << endl;
}
