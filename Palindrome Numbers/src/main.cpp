#include <iostream>
#include <string.h>
using namespace std;

char* process(const char* numbers);

int main() {
    const char* input    = NULL;
    const char* expected = 0;

    for (int i = 0; i <= 12; i++) {
        switch (i) {
        case 0:
            input    = "";
            expected = "";
            break;
        case 1:
            input    = "4 130031 9";
            expected = "1 8 1 260062 2 99";
            break;
        case 2:
            input    = "195 265 750";
            expected = "4 9339 5 45254 3 6666";
            break;
        case 3:
            input    = "2 99 4000000000 20 100 1";
            expected = "1 4 6 79497 1 4000000004 1 22 1 101 1 2";
            break;
        case 4:
            input    = "79 88 97 99";
            expected = "6 44044 6 44044 6 44044 6 79497";
            break;
        case 5:
            input    = "157 158 166 167 175 188 193 197";
            expected = "3 8888 3 11011 5 45254 11 88555588 4 9559 7 233332 8 233332 7 881188";
            break;
        case 6:
            input    = "266 273 274 292 365";
            expected = "11 88555588 4 5115 4 9559 8 233332 11 88555588";
            break;
        case 7:
            input    = "1089 1091 1099";
            expected = "4 79497 1 2992 2 11011";
            break;
        case 8:
            input    = "19991 2914560 12345678";
            expected = "8 16699661 5 47977974 1 99999999";
            break;
        case 9:
            input    = "777";
            expected = "4 23232";
            break;
        case 10:
            input    = "177 554";
            expected = "15 8836886388 3 11011";
            break;
        case 11:
            input    = "604 605 703 704 802 803 901 902";
            expected = "2 1111 1 1111 2 1111 1 1111 2 1111 1 1111 2 1111 1 1111";
            break;
        case 12:
            input    = "880";
            expected = "23 8813200023188";
            break;
        default:
            cout << "we should never get here" << endl;
            return -1;
        }
        char* actual = process( input );
	bool  equal  = false;
	if (actual != NULL) {
	    equal  = strcmp( expected, actual ) == 0;
	}
        cout << "test " << i << ": " << (equal ? "ok" : "failed");
        if (!equal) {
            cout << " expected [" << expected
                 << "] but was [" << (actual == NULL ? "NULL" : actual) << "]";
        }
        cout << endl;

        delete actual;
    }
    return EXIT_SUCCESS;
}
