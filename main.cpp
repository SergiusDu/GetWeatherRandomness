#include <iostream>
#include <vector>

using namespace std;

int GetWeatherRandomness(const vector <int> &temperatures) {
    // Здесь реализация вашего решения
    const size_t last_date = temperatures.size();
    if (last_date == 1) {
        return 1;
    }
    int counter = 0;
    for(int i = 1; i <= last_date - 2; i++) {
        int temperature_of_day_before = temperatures[i - 1];
        int temperature_of_next_day = temperatures[i + 1];
        int current_temperature = temperatures[i];
        if( current_temperature > temperature_of_day_before && current_temperature > temperature_of_next_day) {
            counter++;
        }
    }

    if (temperatures[0] > temperatures[1]) {
        counter++;
    }
    if (temperatures[last_date - 1] > temperatures[last_date - 2]) {
        counter++;
    }
    return counter;
}

void print(int result) {
    cout << result << endl;
}

int main() {
    int n;
    cin >> n;
    vector <int> temperatures(n);
    for (int i = 0; i < n; ++i)
        cin >> temperatures[i];
    print(GetWeatherRandomness(temperatures));
}