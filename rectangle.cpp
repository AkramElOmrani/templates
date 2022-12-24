struct Rect {
	int x1, x2, y1, y2;
	Rect(int a, int b, int c, int d) {
		x1 = a;
		y1 = b;
		x2 = c;
		y2 = d;
	}
	Rect() {
		cin >> x1 >> y1 >> x2 >> y2;
	}
	ll area() {
		return ((ll)x2 - x1) * ((ll)y2 - y1);
	}
	void dbg_rect() {
		cerr << '(' << x1 << ", " << y1 << "), (" << x2 << ", " << y2 << ")\n";
	}
};

ll intersection(Rect a, Rect b) {
	int X_inter = max(0, min(a.x2, b.x2) - max(a.x1, b.x1));
	int Y_inter = max(0, min(a.y2, b.y2) - max(a.y1, b.y1));
	return (ll)X_inter * Y_inter;
}

Rect intersection2(Rect a, Rect b) {
	if(intersection(a, b) == 0) {
		return Rect{0,0,0,0};
	}
	return Rect{max(a.x1, b.x1), max(a.y1, b.y1), 
			min(a.x2, b.x2), min(a.y2, b.y2)};
}