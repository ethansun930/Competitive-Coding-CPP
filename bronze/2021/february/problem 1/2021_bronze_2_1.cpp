#include<iostream> 
#include<string>
#include<unordered_map>
using namespace std;
const int DEFAULT_YEAR = 12000;
int main(){
    string animals[12] = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
    int N;
    cin >> N;
    unordered_map<string, int> birth_year;
    birth_year["Bessie"] = DEFAULT_YEAR;
    string name1, born, in, relation, animal, year, from, name2;
    for (int i = 0; i < N; i++) {
        cin >> name1 >> born >> in >> relation >> animal >> year >> from >> name2;
        birth_year[name1] = birth_year[name2];
        if (relation == "previous") {
            birth_year[name1]--;
            while(animals[birth_year[name1]%12] != animal) {
                birth_year[name1]--;
            }
        } 
        if (relation == "next") {
            birth_year[name1]++;
            while(animals[birth_year[name1]%12] != animal) {
                birth_year[name1]++;
            }
        }
    }
    int diff = birth_year["Elsie"] - DEFAULT_YEAR;
    if (diff < 0)
        diff = -diff;
    cout << diff << "\n";
    // for (const auto& [key, value] : birth_year) {
    //     cout << "Key: [" << key << "] Value: [" << value << "]" << "\n";
    // }

    return 0;
}