#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

// Helper function to generate double numbers of n digits
long long makeDoubleNumber(long long seq, int n) {
    long long multiplier = pow(10, n);
    return seq * multiplier + seq;
}

int main() {
    string input = "749639-858415,65630137-65704528,10662-29791,1-17,9897536-10087630,1239-2285,1380136-1595466,8238934-8372812,211440-256482,623-1205,102561-122442,91871983-91968838,62364163-62554867,3737324037-3737408513,9494926669-9494965937,9939271919-9939349036,83764103-83929201,24784655-24849904,166-605,991665-1015125,262373-399735,557161-618450,937905586-937994967,71647091-71771804,8882706-9059390,2546-10476,4955694516-4955781763,47437-99032,645402-707561,27-86,97-157,894084-989884,421072-462151";

    vector<pair<long long, long long>> ranges;
    stringstream ss(input);
    string token;

    // Parse input into ranges
    while (getline(ss, token, ',')) {
        size_t dash = token.find('-');
        long long start = stoll(token.substr(0, dash));
        long long end = stoll(token.substr(dash + 1));
        ranges.push_back({start, end});
    }

    long long totalSum = 0;

    // Iterate through each range
    for (auto &r : ranges) {
        long long start = r.first;
        long long end = r.second;

        int len_start = to_string(start).length();
        int len_end = to_string(end).length();

        // Only even-length numbers can be double numbers
        for (int L = len_start; L <= len_end; ++L) {
            if (L % 2 != 0) continue;
            int n = L / 2;

            long long lower = pow(10, n - 1);
            long long upper = pow(10, n) - 1;

            for (long long seq = lower; seq <= upper; ++seq) {
                long long num = makeDoubleNumber(seq, n);
                if (num >= start && num <= end) {
                    totalSum += num;
                }
            }
        }
    }

    cout << "Sum of invalid IDs: " << totalSum << endl;

    return 0;
}
