#include <vector>
using namespace std; 

int minJumps(vector<int>& arr) {
    if (arr.size() == 1) {
        return 0; 
    }
    int numJumps = 0;
    int jumpingRange = arr[0];
    int numSteps = arr[0];
  
    for (int i = 1; i < arr.size() - 1; ++i) {
        jumpingRange = max(jumpingRange, i + arr[i]);
        numSteps -= 1;
        if (numSteps == 0) {
            numJumps += 1;
            numSteps = jumpingRange - i;
        }
    }
    return numJumps + 1;
}
