4.	#include <iostream>
5.	#include <cmath>
6.	using namespace std;
7.	
8.	class Poligon {
9.	protected:
10.	    int* x = 0;
11.	    int* y = 0;
12.	    int size;
13.	
14.	public:
15.	    Poligon() {
16.	        // Вводим количество вершин многоугольника
17.	        cin >> size;
18.	        x = new int[size];
19.	        y = new int[size];
20.	
21.	        // Вводим координаты x для каждой вершины
22.	        cout << "Enter x-coordinates: ";
23.	        for (int i = 0; i < size; i++) {
24.	            cin >> x[i];
25.	        }
26.	
27.	        // Вводим координаты y для каждой вершины
28.	        cout << "Enter y-coordinates: ";
29.	        for (int i = 0; i < size; i++) {
30.	            cin >> y[i];
31.	        }
32.	    }
33.	
34.	    double calculateS() {
35.	        // Вычисляем площадь многоугольника по координатам вершин
36.	        double polygon = 0;
37.	        for (int i = 0; i < size - 1; i++) {
38.	            polygon += ((x[i] - x[i + 1]) * (y[i] + y[i + 1])) / 2.0;
39.	        }
40.	        polygon += ((x[size - 1] - x[0]) * (y[size - 1] + y[0])) / 2.0;
41.	        polygon = abs(polygon);
42.	        return polygon;
43.	    }
44.	
45.	    float calculateP() {
46.	        // Вычисляем периметр многоугольника как сумму длин его сторон
47.	        double perimeter = 0;
48.	        for (int i = 0; i < size - 1; i++) {
49.	            perimeter += sqrt(pow((x[i + 1] - x[i]), 2) + pow((y[i + 1] - y[i]), 2));
50.	        }
51.	        perimeter += sqrt(pow((x[size - 1] - x[0]), 2) + pow((y[size - 1] - y[0]), 2));
52.	        return static_cast<float>(perimeter);
53.	    }
54.	
55.	    void print() {
56.	        // Выводим координаты вершин, периметр и площадь многоугольника
57.	        cout << "Abscissa: ";
58.	        for (int i = 0; i < size; i++) {
59.	            cout << x[i] << " ";
60.	        }
61.	
62.	        cout << "Ordinata: ";
63.	        for (int i = 0; i < size; i++) {
64.	            cout << y[i] << " ";
65.	        }
66.	
67.	        cout << "Perimeter = " << calculateP() << " Area = " << calculateS() << endl;
68.	    }
69.	
70.	    friend bool operator^(Poligon p1, Poligon p2) {
71.	        bool A = false, B = false, C = false, D = false;
72.	        bool intersection = false;
73.	
74.	        // Проверяем пересечение двух многоугольников
75.	        for (int i = 0; i < p1.size; i++) {
76.	            for (int j = 0; j < p2.size; j++) {
77.	                if (p1.x[i] < p2.x[j])
78.	                    A = true;
79.	                if (p1.x[i] > p2.x[j])
80.	                    B = true;
81.	                if (p1.y[i] > p2.y[j])
82.	                    C = true;
83.	                if (p1.y[i] < p2.y[j])
84.	                    D = true;
85.	            }
86.	            if (A && B && D && C)
87.	                intersection = true;
88.	            A = false;
89.	            B = false;
90.	            C = false;
91.	            D = false;
92.	        }
93.	        return intersection;
94.	    }
95.	};
96.	
97.	int main() {
98.	    Poligon p1;
99.	    Poligon p2;
100.	
101.	    cout << "Polygon 1: ";
102.	    p1.print();
103.	
104.	    cout << "Polygon 2: ";
105.	    p2.print();
106.	
107.	    bool fol = p1 ^ p2;
108.	    if (fol == true) {
109.	        cout << "Polygon 1 intersects Polygon 2" << endl;
110.	    }
111.	    else {
112.	        cout << "Polygon 1 does not intersect Polygon 2" << endl;
113.	    }
114.	
115.	    return 0;
116.	}
