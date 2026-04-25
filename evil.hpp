
#ifndef EVIL_HPP
#define EVIL_HPP

#include <iostream>
using namespace std;

class Evil{
private:
	int st, ed, val;
	int *data;

public:
	//构造函数
	Evil() : st(0), ed(0), val(0), data(nullptr) {
		if (ed >= st) {
			data = new int[ed - st + 1]();
		}
	}
	
	Evil(int s, int e, int v) : st(s), ed(e), val(v) {
		if (ed >= st) {
			data = new int[ed - st + 1]();
		} else {
			data = nullptr;
		}
	}

	//下标运算符重载
	int& operator[](int i) {
		if (i >= st && i <= ed) {
			return data[i - st];
		} else {
			return data[0]; // Return data[st] when i is out of range
		}
	}

	//赋值运算符重载
	Evil& operator=(const Evil& other) {
		if (this != &other) {
			// Clean up current resources
			delete[] data;
			
			// Copy values
			st = other.st;
			ed = other.ed;
			val = other.val;
			
			// Copy data array
			if (ed >= st) {
				data = new int[ed - st + 1];
				for (int i = 0; i < ed - st + 1; i++) {
					data[i] = other.data[i];
				}
			} else {
				data = nullptr;
			}
		}
		return *this;
	}

	//前缀++重载
	Evil& operator++() {
		val++;
		return *this;
	}

	//后缀++重载
	Evil operator++(int) {
		Evil temp = *this;
		val++;
		return temp;
	}

	//输出重载
	friend ostream& operator<<(ostream& os, const Evil& e) {
		os << e.val << " ";
		for (int i = 0; i < e.ed - e.st + 1; i++) {
			os << e.data[i] << " ";
		}
		os << endl;
		return os;
	}

	//析构函数
	~Evil() {
		delete[] data;
	}
	
    void Print(){
		cout << val << " ";
		for(int i = 0;i < ed-st+1;++i)
			cout << data[i] <<" ";
		cout << endl;
	}
};

#endif//EVIL_HPP
