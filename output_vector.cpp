template<typename T>
void output_vector(vector<T> a, string s = " ", bool can = false) {
	size_t n = a.size();
	if(can) {
		cout << n << '\n';
	}
	for(size_t i = 0; i < n - 1; ++i) {
		cout << a[i] << s;
	}
	cout << a[n - 1] << '\n';
}


template<typename T>
T maxi(vector<T>& v) {
	T x;
	for(const T& val : v) {
		x = max(x, val);
	}
	return x;
}


template<typename T>
T mini(vector<T>& v) {
	const int INF = ?;
	T x;
	for(const T& val : v) {
		x = min(x, val);
	}
	return x;
}

template<typename T>
void max_self(T& a, T b) {
	if(a < b) {
		a = b;
	}
}


template<typename T>
void min_self(T& a, T b) {
	if(a > b) {
		a = b;
	}
}