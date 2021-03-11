/*******************************************************************************
 * Name        : stairclimber.cpp
 * Author      : 
 * Date        : 
 * Description : Lists the number of ways to climb n stairs.
 * Pledge      :
 ******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>
using namespace std;
int num_digits(int num) {
    int count = 0;
    while (num > 0)
    {
        num = num/10;
        count++;
    }
    return count;
}

vector<vector<int>> get_ways(int num_stairs) {
    // TODO: Return a vector of vectors of ints representing
    // the different combinations of ways to climb num_stairs
    // stairs, moving up either 1, 2, or 3 stairs at a time.
    vector<vector<int>> ways;
    vector<vector<int>> result;

    if(num_stairs <= 0){
        return {{}};
    }

    for (int i = 1; i < 4; i++)
    {
        if (num_stairs >= i){
            result = get_ways(num_stairs - i);

            for (size_t j = 0; j < result.size(); j++){
                result[j].insert(result[j].begin(),{i});
            }
            ways.insert(ways.end(), result.begin(), result.end());
        }
    }
    
    return ways;
}

void display_ways(const vector< vector<int> > &ways) {
    // TODO: Display the ways to climb stairs by iterating over
    // the vector of vectors and printing each combination.

    if (ways.size() > 1)
    {
        cout << ways.size() << " ways to climb " << ways[0].size() << " stairs." << endl;
    }
    else
    {
        cout << ways.size() << " way to climb " << ways[0].size() << " stair." << endl;
    }
    
    
    

    int max_digit = num_digits(ways.size());

    for (size_t i = 0; i < ways.size(); i++)
    {
        cout << setw(max_digit) << i+1 << ". " << "[";
        for (size_t j = 0; j < ways[i].size(); j++)
        {
            if (j < ways[i].size() - 1)
            {
                cout << ways[i][j] << ", ";
            }
            else
            {
                cout << ways[i][j];
            }
        }
        cout << "]" << endl;
    }
}


int main(int argc, char * const argv[]) {
    if (argc != 2)
    {
        cout << "Usage: ./stairclimber <number of stairs>";
        return 1;
    }
    istringstream iss;
    iss.str(argv[1]);
    int x;
    if (!(iss >> x) || !(x > 0))
    {
        cout << "Error: Number of stairs must be a positive integer.";
        return 1;
    }
   
    
    
    
    display_ways(get_ways(x));
    
    return 0;
}
