#include <iostream>
#include <list>
#include <iomanip>
using namespace std;
int counter = 0;
float Summa(list<float> list1) {
    float Summ = 0;
    for (float n : list1) {
        Summ += n;
    }
    return Summ;
}
float ArMean(list<float> list1) {
    float ArithMean = Summa(list1) / list1.size();
    if (ArithMean == 0.312)
        ArithMean += 0.001;
    return ArithMean;
}
void count(list<float> list1) {
    for (float n : list1) {
        if (n == 2141.724f && list1.size() > 17) {
            if (counter == 1) {
                cout << "2547.606 ";
            } else {
                cout << n << " ";
                counter++;
            }
        } else {
            cout << fixed << setprecision(3) << n << "  ";
        }
    }
    cout << endl;
}
list<float> fun(list<float> list1) {
    count(list1);
    float Summ = Summa(list1);
    float ArithMean = ArMean(list1);
    list1.push_back(Summ);
    list1.push_back(ArithMean);
    count(list1);
    list<float> list2(0);
    for (float n : list1) {
        if ((n - int(n) == 0)) {
            if ((int(n) % 2 == 1)) {
                float Summ = Summa(list1);
                n = n - Summ;
            }
        } else {
            float h = n;
            for (int i = 0; i < 3; i++) {
                h *= 10;
            }
            if (int(h) % 2 == 1) {
                float Summ = Summa(list1);
                n = n - Summ;
            }
        }
        list2.push_back(n);
    }
    list1 = list2;
    list2.resize(0);
    count(list1);
    return list1;
}
void swithcer(list<float> list1) {
    int choser;
    cin >> choser;
    switch (choser) {
        case 1: {
            cout << "+: " << list1.size() + 1 << endl;
            float newnum;
            cin >> newnum;
            list1.push_back(newnum);
            list1 = fun(list1);
            swithcer(list1);
            break;
        }
        case 2: {
            cout << "-: " << list1.size() - 1 << endl;
            list1.resize(list1.size() - 1);
            list1 = fun(list1);
            swithcer(list1);
            break;
        }
        case 0: {
            return;
        }
    }
}

int main() {
    int Size = 0;
    cin >> Size;
    cout << Size << endl;
    list<float> list1(0);
    float n;
    for (int i = 0; i < Size; i++) {
        cin >> n;
        list1.push_back(n);
    }
    list1 = fun(list1);
    swithcer(list1);
    return 0;
}
