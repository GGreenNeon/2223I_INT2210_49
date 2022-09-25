#include <iostream>
using namespace std;

class point {
    public: double x,y;
    void print() {
        cout << x << ' ' << y;
    }
};

class line {
    public: double a, b, c;
    void get (point M, point N) {
        a = N.y - M.y;
	    b = M.x - N.x;
	    c = a * (M.x) + b * (M.y);
    }
};

void isIntersect (line m, line n) {
    //giai he 2 phuong trinh tuyen tinh = dinh ly Cramer.
    point ans;
    double det = m.a * n.b - m.b * n.a;
    if (det != 0) {
        double det1 = m.c * n.b - m.b * n.c;
        double det2 = m.a * n.c - m.c * n.a;
        ans.x = det1 / det;
        ans.y = det2 / det;
        ans.print ();
    }
    else {
        if (m.a * n.c == m.c * n.a) {
            cout << "MANY";
        }
        else {
            cout << "NO";
        }
    }
}

int main() {
    point A,B,C,D;
    cin>> A.x >> A.y;
    cin>> B.x >> B.y;
    cin>> C.x >> C.y;
    cin>> D.x >> D.y;
    
    line AB, CD;
    AB.get (A,B);
    CD.get (C,D);

    isIntersect(AB, CD);
    
	return 0;
}