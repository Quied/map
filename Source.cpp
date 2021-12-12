#include <iostream>
#include <vector>
#include <set>

template <typename K, typename V>
class map {
private:

	K Key;
	V Value;

	std::vector<std::pair<K, V>>Vec;

public:
	void insert(K const &key, V const &value) {
		std::pair<K, V>pr;
		pr.first = key;
		pr.second = value;

		Vec.push_back(pr);
	}

	void print(K const &key) {

		std::set<std::pair<K, V>>st;

		for (int i = 0; i < Vec.size(); i++) { st.emplace(Vec[i]); }
		Vec.clear();
	
		for (auto el : st) {Vec.push_back(el);}
		st.clear();

		for (int i = 0; i < Vec.size(); i++) {
			if (key == Vec[i].first) {
				std::cout << Vec[i].second;
			}
		}
		std::cout << std::endl;
	}

	void ShowALL() {
		for (int i = 0; i < Vec.size(); i++) { std::cout << " Key: " << Vec[i].first << " Value: " << Vec[i].second << std::endl;}
	}

};


int main() {

	map<std::string, int>mp;
	mp.insert("Hello", 7);
	mp.insert("Asio", 12);
	mp.insert("Boo", 18);
	mp.insert("Fill", 17);
	mp.insert("Cool", 17);
	mp.insert("Cpp", 23);

	mp.print("Cpp");


	mp.ShowALL();
	
	
}