// Description:
// Write a program that outputs the string representation of numbers from 1 to n.
// But for multiples of three it should output "Fizz" instead of the number and for the multiples of five output "Buzz". 
// For numbers which are multiples of both three and five output "FizzBuzz".

// Example:
// n = 15,
// Return:
// [
//     "1",
//     "2",
//     "Fizz",
//     "4",
//     "Buzz",
//     "Fizz",
//     "7",
//     "8",
//     "Fizz",
//     "Buzz",
//     "11",
//     "Fizz",
//     "13",
//     "14",
//     "FizzBuzz"
// ]

#include <string>
#include <vector>
#include <map>
using std::string;
using std::vector;
using std::map;
using std::to_string;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        // using hashmap to avoid multiple if statements
        map<int, string> hash = {{3, "Fizz"}, {5, "Buzz"}};
        for (int i = 1; i <= n; ++i) {
            string num = "";
            for (auto p: hash) {
                if (i % p.first == 0) {
                    num += p.second;
                }
            }
            if (num == "") {
                num += to_string(i);
            }
            res.push_back(num);
        }
        return res;
    }
};