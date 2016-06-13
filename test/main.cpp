#include<iostream>
#include<iomanip>
#include"easySD.hpp"
#include<unordered_set>
#include<algorithm>
#include<armadillo>
#include<cmath>
#include<cstdio>
#include<cmath>

using namespace std;
using namespace arma;

vector<int> grams = {1};

int main(void)
{
	vector<vector<string> > x_train;
	vector<bool> y_train;
	vector<vector<string> > x_test;
	loaders::load_data("../data/train.csv","../data/test.csv",x_train,y_train,x_test);
	
	sp_mat A = vectorizers::bin_vectorize(x_train);
	
	int n_samples = A.n_rows,n = (n_samples*9)/10,n_valid = n_samples - n;
	sp_mat X_train = A.head_rows(n), X_valid = A.tail_rows(n_valid);
	vec Y_train(vector<double>(y_train.begin(),y_train.begin() + n)),Y_valid(vector<double>(y_train.begin() + n,y_train.end()));
	
	double C = 1.,tol = 1e-5,alpha = 0.002;
	logreg clf = logreg(C,tol,alpha);
	clf.fit(X_train,Y_train);
	cout << clf.score(X_valid,Y_valid) << endl;
	
	
	
	return 0;
}