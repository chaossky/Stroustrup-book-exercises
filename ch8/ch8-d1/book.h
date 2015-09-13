#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <cstdlib>

using namespace std;

inline void keep_window_open() { char ch; cin >> ch; }
void error(string s) { throw runtime_error(s); }
