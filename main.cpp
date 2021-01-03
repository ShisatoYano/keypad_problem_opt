#include <cstdio>

// count of all possible numbers of length n
// in a given numeric keypad
int get_count(char keypad[][3], int n)
{
    int total_count = 0;

    if (keypad == NULL || n <= 0) return 0;
    if (n == 1) return 10;

    // count of numbers starting with digit i for any length j
    int odd[10], even[10];
    int i = 0, j = 0, use_odd = 0;

    for (i = 0; i <= 9; ++i) {
        odd[i] = 1; // for j = 1
    }

    for (j = 2; j <= n; ++j) { // bottom up calculate from j = 2 to n
        use_odd = 1 - use_odd;

        if (use_odd == 1)
        {
            even[0] = odd[0] + odd[8];
            even[1] = odd[1] + odd[2] + odd[4];
            even[2] = odd[2] + odd[1] + odd[3] + odd[5];
            even[3] = odd[3] + odd[2] + odd[6];
            even[4] = odd[4] + odd[1] + odd[5] + odd[7];
            even[5] = odd[5] + odd[2] + odd[4] + odd[6] + odd[8];
            even[6] = odd[6] + odd[3] + odd[5] + odd[9];
            even[7] = odd[7] + odd[4] + odd[8];
            even[8] = odd[8] + odd[0] + odd[5] + odd[7] + odd[9];
            even[9] = odd[9] + odd[6] + odd[8];
        } else {
            odd[0] = even[0] + even[8];
            odd[1] = even[1] + even[2] + even[4];
            odd[2] = even[2] + even[1] + even[3] + even[5];
            odd[3] = even[3] + even[2] + even[6];
            odd[4] = even[4] + even[1] + even[5] + even[7];
            odd[5] = even[5] + even[2] + even[4] + even[6] + even[8];
            odd[6] = even[6] + even[3] + even[5] + even[9];
            odd[7] = even[7] + even[4] + even[8];
            odd[8] = even[8] + even[0] + even[5] + even[7] + even[9];
            odd[9] = even[9] + even[6] + even[8];
        }
    }

    // get count of all possible numbers of length n
    // starting with digit 0, 1, 2, ..., 9
    if (use_odd == 1)
    {
        for (i = 0; i <= 9; ++i) {
            total_count += even[i];
        }
    } else {
        for (i = 0; i <= 9; ++i) {
            total_count += odd[i];
        }
    }

    return total_count;
}

int main() {
    char keypad[4][3] = {{'1', '2', '3'},
                         {'4', '5', '6'},
                         {'7', '8', '9'},
                         {'*', '0', '#'}};

    printf("Count for numbers of length %d: %d", 4, get_count(keypad, 4));

    return 0;
}
