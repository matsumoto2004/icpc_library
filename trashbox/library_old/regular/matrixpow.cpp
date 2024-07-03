//行列の乗算
vector<vector<mint>> matrix_multiply(vector<vector<mint>> X, vector<vector<mint>> Y) {
	vector<vector<mint>> Z(X.size(), vector<mint>(Y[0].size()));
	rep(i, X.size()) {
		rep(k, Y.size()) {
			rep(j, Y[0].size()) {
				Z[i][j] = Z[i][j] + X[i][k] * Y[k][j];
			}
		}
	}
	return Z;
}

//A^nの計算
vector<vector<mint>> matrix_pow(vector<vector<mint>> A, ll n) {
	vector<vector<mint>> B(A.size(), vector<mint>(A[0].size()));
	//単位行列でBを初期化
	rep(i, B.size()) {
		B[i][i] = 1;
	}

	while (n>0) {
		if (n & 1) { B = matrix_multiply(B, A); }
		A = matrix_multiply(A, A);
		n = n >> 1;
	}
	return B;
}


/*
//行列の乗算
VVl matrix_multiply(VVl X, VVl Y) {
	VVl Z(X.size(), Vl(Y[0].size()));
	rep(i, X.size()) {
		rep(k, Y.size()) {
			rep(j, Y[0].size()) {
				Z[i][j] = (Z[i][j] + X[i][k] * Y[k][j]);
			}
		}
	}
	return Z;
}

//A^nの計算
VVl matrix_pow(VVl A, ll n) {
	VVl B(A.size(), Vl(A[0].size()));
	//単位行列でBを初期化
	rep(i, B.size()) {
		B[i][i] = 1;
	}

	while (n>0) {
		if (n & 1) { B = matrix_multiply(B, A); }
		A = matrix_multiply(A, A);
		n = n >> 1;
	}
	return B;
}
*/
