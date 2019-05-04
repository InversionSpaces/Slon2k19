#include <iostream>
#include <utility>
#include <vector>
#include <cassert>

using namespace std;

typedef pair<int, int> point;

point operator+(const point& a, const point& b) {
	return point(a.first + b.first, a.second + b.second);
}

istream& operator>>(istream& in, point& p){
	in>>p.first>>p.second;
	return in;
}

point size;
vector<vector<int> > heights;
vector<vector<char> > watered;
vector<point> wateredPoints;

point rain, mazai;

inline bool isValid(const point& p) {
	return 	(p.first >= 0) && 
			(p.second >= 0) &&
			(p.first < size.first) &&
			(p.second < size.second);
}

inline void setHeight(const point& p, const int& h) {
	heights[p.first][p.second] = h;
}

inline int getHeight(const point& p) {
	return heights[p.first][p.second];
}

inline bool getWatered(const point& p) {
	return watered[p.first][p.second];
}

inline void setWatered(const point& p) {
	wateredPoints.push_back(p);
	watered[p.first][p.second] = true;
}

const point moves[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void debug(){
	cout<<"------------\n";
	for(auto &c: heights){
		for(auto &i: c)
			cout<<i<<' ';
		cout<<'\n';
	}
	cout<<"------------\n";
	for(auto &c: watered){
		for(auto &i: c)
			cout<<int(i)<<' ';
		cout<<'\n';
	}
	cout<<"------------\n";
}

int main() {

	cin>>size;

	assert(size.first > 0 && size.second > 0);

	swap(size.first, size.second);

	heights.resize(size.first);
	for(auto &c: heights){
		c.resize(size.second);
		for(auto &i: c)
			cin>>i;
	}

	watered.resize(size.first);
	for(auto &c: watered)
		c.assign(size.second, false);

	cin>>rain>>mazai;
	rain = rain + point(-1, -1);
	mazai = mazai + point(-1, -1);

	swap(rain.first, rain.second);
	swap(mazai.first, mazai.second);

	int ans = 0;
	
	setWatered(rain);

	while(true){
		//debug();

		for(int i = 0; i < wateredPoints.size(); i++) { 
			// doesn't work with for(point& current: wateredPoints)
			// a hour wasted here!
			point current = wateredPoints[i];
			for(int i = 0; i < 4; i++){
				point near = current + moves[i];
				if(!isValid(near)) continue;
				/*
				cout<<"Current "<<current.first<<' '<<current.second;
				cout<<" + Move "<<moves[i].first<<' '<<moves[i].second;
				cout<<" = Near "<<near.first<<' '<<near.second;
				*/

				if(!getWatered(near) && (getHeight(near) <= getHeight(current)))
					//cout<<" - add";
					setWatered(near);
				//cout<<'\n';
			}
		}

		if(getWatered(mazai)){
			cout<<ans;
			return 0;
		}

		point bottom(-1, -1);
		bool found = false;

		for(point& current: wateredPoints){
			if(!found || (getHeight(current) < getHeight(bottom))) {
				found = true;
				bottom = current;
			}
		}

		vector<point> bottoms;

		for(point& current: wateredPoints){
			if(getHeight(current) == getHeight(bottom)) 
				bottoms.push_back(current);
		}

		/*
		cout<<"Bottoms \n";
		for(point& p: bottoms)
			cout<<p.first<<' '<<p.second<<'\n';
		*/

		point closest(-1, -1);
		found = false;

		for(point& current: bottoms){
			for(int i = 0; i < 4; i++) {
				point near = current + moves[i];
				if(!isValid(near)) continue;

				if((!found || (getHeight(near) < getHeight(closest))) 
					&& getHeight(near) > getHeight(bottom)){
					found = true;
					closest = near;
				}
			}
		}

		ans += (getHeight(closest) - getHeight(bottom)) * bottoms.size();

		for(point& current: bottoms)
			setHeight(current, getHeight(closest));
	}
}
