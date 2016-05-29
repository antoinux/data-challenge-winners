#include<iostream>
#include"easySD.hpp"
#include<unordered_set>
#include<algorithm>

using namespace std;

vector<int> grams = {1,2};

int main(void)
{
	cout << "YOLO" << endl;
	vector<vector<string> > x_train;
	vector<bool> y_train;
	vector<vector<string> > x_test;
	loaders::load_train("../data/train.csv",x_train,y_train);
	loaders::load_test("../data/test.csv",x_test);
	
	unordered_set<string> stopwords;
	fstream stopfile("stopwords.txt",fstream::in);
	string stopword;
	while(stopfile >> stopword)
		stopwords.insert(stopword);
	
	// It works, bitches.
// 	for(auto s : x_train[29])
// 		cout << s << endl;
// 	for(auto s : x_test[29])
// 		cout << s << endl;
	
// 	vector<unordered_map<string,int> > x_train2 = vectorizers::count_vectorize(x_train,stopwords);
	
	vector<unordered_map<string,int> > x_train2 = vectorizers::n_gram_vectorize(x_train,grams);
	for(auto p : x_train2[29])
			cout << p.first << endl;
	
	////// Tentative of Naïve Bayes //////
	
	// Seems like for now the only way to make the classifier work better than random is by tuning alpha = 0...
	
	int taken_samples = 3800;
	
	vector<unordered_map<string,int> > x_train3(x_train2.begin(),x_train2.begin() + taken_samples);
	vector<bool> y_train3(y_train.begin(),y_train.begin() + taken_samples);
	
	vector<unordered_map<string,int> > x_valid(x_train2.begin() + taken_samples,x_train2.end());
	vector<bool> y_valid(y_train.begin() + taken_samples,y_train.end());
	
	naive_bayes clf(0.);
	clf.fit2(x_train3,y_train3);
	auto y_pred = clf.predict3(x_valid);
	
	cout << utils::score(y_pred,y_valid) << endl;
	
	return 0;
}