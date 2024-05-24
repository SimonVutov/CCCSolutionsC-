#include <vector>
#include <iostream>
using namespace std;
/*
long long factorial(int n){
    if(n == 0) return 1;
    return n * factorial(n-1);
}*/

/*
int solve (int a, int b, int c) {
    if (a + b + c == 7) return (a % 2 == 1 && b % 2 == 1 && c % 2 == 1);
    return solve(a + 1, b, c) + solve(a, b + 1, c) + solve(a, b, c + 1);

}

int main(){
    cout << solve(0, 0, 0);
}*/

int main() {
    //0.02128625245
    //0.0212862362522
    int x = 10000;
    for (int i = 1; i < x; i++) {
        for (int j = 1; j < x; j++) {
            for (int k = 1; k < x; k++) {
                if (abs(1/0.0212862362522 - (double)(i+j*2.2360679775)/k) < 0.000001) {
                    cout << i << " " << j << " " << k << endl;
                }
            }
        }
    }
}
/*
int main() {
    int x = 10000;
    int ans = 1e9;
    for (int i = 1; i < x; i++) {
        for (int j = 1; j < x; j++) {
            for (int k = 1; k < x; k++) {
                
                int a = i, b = j, c = k;
                
                if (b-8-a==c-b+8 && b*b - a*a == c*c -b*b) {
                    cout << a + b + c << endl;
                    ans = min(ans, a+b+c);
                }
            }
        }
    }
    cout << ans;
}
*/

/*    int ans = 0;
    int total = 0;
    for (int i = 1; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= 9; k++) {
                double d1 = (double)(100*i + 10*j + k);
                double d2 = (double)(100*k + 10*j + i);
                total++;
                if (d1/d2 == (2 - (double)(k/i))) {
                    
                    cout << ans << " " << i << " " << j << " " << k << endl;
                    ans++;
                }
            }
        }
    }
    cout << ans << " total: " << total;
}*/
/*
int main() {
    int curNum = 1;
    for(int i = 1; i <= 888; i++) {
        curNum *= 5;
        curNum %= 2024;
    }
    int curNum2 = 1;
    for(int i = 1; i <= 888; i++) {
        curNum2 *= 8;
        curNum2 %= 2024;
    }

    cout << (curNum + curNum2 ) % 2024 << endl;

    cout << curNum << curNum2;
}*/

/*

int main() {
    long long topNum = 1, bottomNum = 1;
    long long curTop = 0, curBottom = 0;
    for (int i = 1; i <= 100; i++) {
        curTop = 4 * (2*i - 1);
        curBottom = (2*i*i + 2*i + 1);
        
        topNum *= (curBottom - curTop);
        bottomNum *= curBottom;
        cout << i << " " << topNum << " " << bottomNum << endl;

        for (int i = 1; i <= 100000000; i++) {
            if (topNum % i == 0 && bottomNum % i == 0) {
                topNum /= i;
                bottomNum /= i;
            }
        }
    }

    cout << topNum << " " << bottomNum << endl;
}*/

/*
int main() {
    //6 by 6

    int ans = 0;
    int total = 0;

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            for (int k = i; k < 6; k++) {
                for (int l = j; l < 6; l++) {

                    //bottom left is (i, j)
                    //top right is (k, l)

                    int counts = 0;

                    for (int a = i; a <= k; a++) {
                        for (int b = j; b <= l; b++) {
                            if ((a == 3 && b == 1) || (a == 1 && b == 4)) counts++;
                        }
                    }
                    total ++;

                    if (counts == 1) ans++;
                }
            }
        }
    }

    cout << ans << " total: " << total;
}
*/