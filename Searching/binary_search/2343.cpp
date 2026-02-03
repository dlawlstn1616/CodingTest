#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> lectures;

static int countBlurays(int size) {
    int count = 1;
    int sum = 0;

    for (int i = 0; i < N; i++) {
        if (sum + lectures[i] <= size) {
            sum += lectures[i];
        }
        else {
            count++;
            sum = lectures[i];
        }
    }
    return count;
}

static int binarySearch(int max_lecture, int sum_lecture) {
    int low = max_lecture;
    int high = sum_lecture;
    int result = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (countBlurays(mid) <= M) {
            result = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    lectures.resize(N);

    int max_lecture = 0;
    int sum_lecture = 0;

    for (int i = 0; i < N; i++) {
        cin >> lectures[i];
        max_lecture = max(max_lecture, lectures[i]);
        sum_lecture += lectures[i];
    }

    cout << binarySearch(max_lecture, sum_lecture) << "\n";

    return 0;
}