#include <iostream>
#include <array>
#include <string>
#include <algorithm>
#include <typeinfo>

using namespace std;

template<typename T, size_t size>
string array_to_string(const array<T, size>& arr)
{
    string res = "[";

    for (auto i : arr) {
        res.append(to_string(i)).append(", ");
    }

    res.erase(res.end() - 2, res.end());

    res += "]";

    return res;
}

template<typename T, size_t size>
T sum(const array<T, size>& arr)
{
    T res = 0;

    for (auto i : arr)
    {
        res += i;
    }

    return res;
}

template<typename T, size_t size>
T average(const array<T, size>& arr)
{
    return T(sum(arr) / arr.size());
}

int main(int argc, char* argv[])
{
    array<int, size_t(7)> arr = { 3, 222, 31, -4, 0, 7, 92 };

    cout << "Original: " << array_to_string(arr) << endl;

    sort(arr.begin(), arr.end());

    cout << "Sorted: " << array_to_string(arr) << endl;

    cout << "Sum of elements of array: " << sum(arr) << endl;

    cout << "Access element with \"operator []\": " << arr[0] << endl;

    cout << "Average of elements of array: " << average(arr) << endl;

    cout << "Find element \"3\" position in array: " << distance(arr.begin(), find(arr.begin(), arr.end(), 3)) << endl;

    replace(arr.begin(), arr.end(), 0, 92);

    cout << "Replace element \"0\" by \"92\" in array: " << array_to_string(arr) << endl;
}