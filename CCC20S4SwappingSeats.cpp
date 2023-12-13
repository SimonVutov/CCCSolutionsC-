#include <vector>
#include <unordered_set>
#include <string>
#include <iostream>
using namespace std;

struct counts {
    int A, B, C;
};

int main() {
    string s;
    cin >> s;

    int n = s.size();
    int As = 0, Bs = 0, Cs = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') As++;
        else if (s[i] == 'B') Bs++;
        else Cs++;
    }

    int minSwaps = 1e9;

    counts A = { 0, 0, 0 }, B = { 0, 0, 0 }, C = { 0, 0, 0 };
    for (int i = 0; i < As; i++) {
        if (s[i] == 'A') A.A++;
        else if (s[i] == 'B') A.B++;
        else A.C++;
    }
    for (int i = As; i < As + Bs; i++) {
        if (s[i] == 'A') B.A++;
        else if (s[i] == 'B') B.B++;
        else B.C++;
    }
    for (int i = As + Bs; i < n; i++) {
        if (s[i] == 'A') C.A++;
        else if (s[i] == 'B') C.B++;
        else C.C++;
    }

    for (int i = 0; i <= n; i++) { //first As letters after i is for A, next is Bs, next is Cs
        int sum = 0;
        sum += min(A.B, B.A);
        sum += min(A.C, C.A);
        sum += min(B.C, C.B);
        sum += 2 * (A.B + B.A + A.C + C.A + B.C + C.B - 2 * sum) / 3;
        minSwaps = min(minSwaps, sum);

        //cout << A.A << " " << A.B << " " << A.C << " " << B.A << " " << B.B << " " << B.C << " " << C.A << " " << C.B << " " << C.C << endl;

        if (i == n) break;
        if (s[i] == 'A') {
            A.A--;
            C.A++;
        } else if (s[i] == 'B') {
            A.B--;
            C.B++;
        } else {
            A.C--;
            C.C++;
        }

        if (s[(i + As) % n] == 'A') {
            B.A--;
            A.A++;
        } else if (s[(i + As) % n] == 'B') {
            B.B--;
            A.B++;
        } else {
            B.C--;
            A.C++;
        }

        if (s[(i + As + Bs) % n] == 'A') { //mod n to wrap around (i + As + Bs
            C.A--;
            B.A++;
        } else if (s[(i + As + Bs) % n] == 'B') {
            C.B--;
            B.B++;
        } else {
            C.C--;
            B.C++;
        }
    }

    //now do the same thing but in the order of Cs, Bs, As

    A.A = A.B = A.C = B.A = B.B = B.C = C.A = C.B = C.C = 0;
    for (int i = 0; i < Cs; i++) {
        if (s[i] == 'A') C.A++;
        else if (s[i] == 'B') C.B++;
        else C.C++;
    }
    for (int i = Cs; i < Cs + Bs; i++) {
        if (s[i] == 'A') B.A++;
        else if (s[i] == 'B') B.B++;
        else B.C++;
    }
    for (int i = Cs + Bs; i < n; i++) {
        if (s[i] == 'A') A.A++;
        else if (s[i] == 'B') A.B++;
        else A.C++;
    }

    for (int i = 0; i <= n; i++) { //first Cs letters after i is for C, next is Bs, next is As
        int sum = 0;
        sum += min(A.B, B.A);
        sum += min(A.C, C.A);
        sum += min(B.C, C.B);
        sum += 2 * (A.B + B.A + A.C + C.A + B.C + C.B - 2 * sum) / 3;
        minSwaps = min(minSwaps, sum);

        //cout << A.A << " " << A.B << " " << A.C << " " << B.A << " " << B.B << " " << B.C << " " << C.A << " " << C.B << " " << C.C << endl;

        if (i == n) break;
        if (s[i] == 'A') {
            C.A--;
            A.A++;
        } else if (s[i] == 'B') {
            C.B--;
            A.B++;
        } else {
            C.C--;
            A.C++;
        }
        if (s[(i + Cs) % n] == 'A') {
            B.A--;
            C.A++;
        } else if (s[(i + Cs) % n] == 'B') {
            B.B--;
            C.B++;
        } else {
            B.C--;
            C.C++;
        }
        if (s[(i + Cs + Bs) % n] == 'A') {
            A.A--;
            B.A++;
        } else if (s[(i + Cs + Bs) % n] == 'B') {
            A.B--;
            B.B++;
        } else {
            A.C--;
            B.C++;
        }
    }

    cout << minSwaps << endl;
}