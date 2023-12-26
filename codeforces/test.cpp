#include <iostream>
using namespace std;
 
int peaks[100001];
 
bool checkChallenging(int location, int n) {
    if(location == 0 || location == n - 1) {
        return false;
    }
 
    int currentPeak = peaks[location];
    int lastPeak = peaks[location - 1];
    int nextPeak = peaks[location + 1];
 
    if(currentPeak > lastPeak && currentPeak > nextPeak) {
        return true;
    }
 
    return false;
}
 
int main() {
    int n;
    cin >> n;
 
    for(int i = 0; i < n; i++) {
        cin >> peaks[i];
    }
 
    int highestDistance = 0;
    int numChallenging = 0;
    int count = 1;
 
    for(int i = 0; i < n; i++) {
        bool challenging = checkChallenging(i, n);
 
        if(challenging) {
            numChallenging++;
            if(count > highestDistance) {
                highestDistance = count;
            }
 
            count = 1;
        }
 
        count++;
    }
    
    if (highestDistance == 0)  {
        cout << 0;
    } else {
        while(n % highestDistance != 0 && highestDistance != n) {
            highestDistance++;
        }
 
        cout << n / highestDistance << endl;
    }
 
    return 0;
}