/*************************************************************/
/*                                                           */
/*    Asignment 1		                                     */
/*                                                           */
/*************************************************************/
#include <iostream>
#include <string>
#include <utility>
using namespace std;

template <class TYPE>
class Table {
public:
	Table() {}
	virtual bool update(const string& key, const TYPE& value) = 0;
	virtual bool remove(const string& key) = 0;
	virtual bool find(const string& key, TYPE& value) = 0;
	virtual int numRecords() const = 0;
	virtual bool isEmpty() const = 0;
	virtual ~Table() {}
};

template <class TYPE>
class SimpleTable :public Table<TYPE> {

	struct Record {
		TYPE data_;
		string key_;
		Record(const string& key, const TYPE& data) {
			key_ = key;
			data_ = data;
		}

	};

	Record** records_;   //the table
	int max_;           //capacity of the array
	int size_;          //current number of records held
	int search(const string& key);

public:
	SimpleTable(int capacity);
	virtual bool update(const string& key, const TYPE& value);
	virtual bool remove(const string& key);
	virtual bool find(const string& key, TYPE& value);
	virtual ~SimpleTable();
	virtual bool isEmpty() const { return size_ == 0; }
	virtual int numRecords() const { return size_; }
};


//returns index of where key is found.
template <class TYPE>
int SimpleTable<TYPE>::search(const string& key) {
	int rc = -1;
	for (int i = 0; i < size_; i++) {
		if (records_[i]->key_ == key) {
			rc = i;
		}
	}
	return rc;
}


template <class TYPE>
SimpleTable<TYPE>::SimpleTable(int capacity) : Table<TYPE>() {
	records_ = new Record * [capacity];
	max_ = capacity;
	size_ = 0;
}


template <class TYPE>
bool SimpleTable<TYPE>::update(const string& key, const TYPE& value) {
	int idx = search(key);
	if (idx == -1) {
		if (size_ < max_) {
			records_[size_++] = new Record(key, value);
			for (int i = 0; i < size_ - 1; i++) {
				for (int j = 0; j < size_ - 1 - i; j++) {
					if (records_[j] > records_[j + 1]) {
						TYPE tmp = records_[j];
						records_[j] = records_[j + 1];
						records_[j + 1] = tmp;
					}
				}
			}
		}
	}
	else {
		records_[idx]->data_ = value;
	}
	return true;
}

template <class TYPE>
bool SimpleTable<TYPE>::remove(const string& key) {
	int idx = search(key);
	if (idx != -1) {
		delete records_[idx];
		for (int i = idx; i < size_ - 1; i++) {
			records_[i] = records_[i + 1];
		}
		size_--;
		return true;
	}
	else {
		return false;
	}
}

template <class TYPE>
bool SimpleTable<TYPE>::find(const string& key, TYPE& value) {
	bool found = false;
	int idx = search(key);
	if (idx != -1) {
		if (records_[idx]->data_ == value) {
			found = true;
		}

	}

	return found;
}

template <class TYPE>
SimpleTable<TYPE>::~SimpleTable() {

}


template <class TYPE>
class LPTable :public Table<TYPE> {

	struct Record {
		TYPE data_;
		string key_;
		Record(const string& key, const TYPE& data) {
			key_ = key;
			data_ = data;
		}

	};

	Record** records_;   //the table
	int max_;           //capacity of the array
	int size_;          //current number of records held
	int capacity_;
	int search(const string& key);
	int hashCode(const string& key);


public:
	LPTable(int capacity, double maxLoadFactor);
	void printTable();
	virtual bool update(const string& key, const TYPE& value);
	virtual bool remove(const string& key);
	virtual bool find(const string& key, TYPE& value);
	virtual ~LPTable();
	virtual bool isEmpty() const {
		if (size_ == 0) {
			return true;
		}
		else {
			return false;
		} 
	}
	virtual int numRecords() const { 
		return size_;
	}

};

// key is dictionary , value is 1 for all. 
// if SAME key exist in the hashCode aka red, red, increment the value by 1 INSTEAD of next index

template <class TYPE>
LPTable<TYPE>::LPTable(int capacity, double maxLoadFactor) : Table<TYPE>() {

	// define the function here
	capacity_ = capacity;
	max_ = capacity_ * maxLoadFactor;
	size_ = 0;

	records_ = new Record*[capacity_];
	
	for (int i = 0; i < capacity_; i++)
		records_[i] = nullptr; 

}

template <class TYPE>
int LPTable<TYPE>::search(const string & key) {
	int rc = -1;
	int counter = 0;
	int idx = hashCode(key);

	while (counter < max_) {
		if (records_[idx] != nullptr) {
			if (records_[idx]->key_ == key) {
				rc = idx;

				return rc;
			}
		}
		idx++;
		if (idx == capacity_) {
			idx = 0;
		};
		
		counter++;
		
	
	}

	return rc;
}


template <class TYPE>
int LPTable<TYPE>::hashCode(const string& key) {

	int hashCode_ = 0;

	for (int i = 0; i < key.length(); i++) {
		hashCode_ = hashCode_ + key[i];
	}

	int idx = hashCode_ % capacity_;

	return idx;
}



template <class TYPE>
bool LPTable<TYPE>::update(const string & key, const TYPE & value) {

	bool updated = false;
	int idx = search(key);
	int hash = hashCode(key);

	if (idx == -1) {
		if (size_ < max_) {
			while (records_[hash] != nullptr) {
				
				if (records_[hash]->key_ == "\0") {
					records_[hash]->key_ = key;
					records_[hash]->data_ = value;
					size_++;
					updated = true;
					return updated;
				}
				if (hash == capacity_) {
					hash = 0;
				}
				else {
					hash++;
				}
			}

			records_[hash] = new Record(key, value);
			size_++;
			updated = true;
		} 

		return updated;
		
	}
	else {
		records_[idx]->data_ += value;
		updated = true;
	}

	return updated;

}

template <class TYPE>
bool LPTable<TYPE>::remove(const string & key) {

	bool removed = false;
	int idx = search(key);

	if (idx != -1) {
		records_[idx]->key_= "\0";
		records_[idx]->data_ = 0;
		removed = true;
		size_--;
	}

	return removed;
}

template <class TYPE>
bool LPTable<TYPE>::find(const string & key, TYPE & value) {

	bool found = false;
	int counter = 0;
	int idx = hashCode(key);

	while (counter < max_) {
		if (records_[idx] != nullptr) {
			if (records_[idx]->key_ == key && records_[idx]->data_ == value) {
				found = true;
				return found;
			}
		}
		idx++;
		if (idx == capacity_) {
			idx = 0;
		}
		counter++;
	}
	return found;
}


template <class TYPE>
void LPTable<TYPE>::printTable() {

	for (int i = 0; i < capacity_; i++)
		if (records_[i] == nullptr) {
			cout << "record " << i << ":\t" << "EMPTY" << endl;
		}
		else {
			if (records_[i]->key_ == "\0" && records_[i]->data_ == 0) {
				cout << "record " << i << ":\t" << "DELETED" << endl;
			}
			else {
				cout << "record " << i << ":\t(" << records_[i]->key_ << " , " << records_[i]->data_ << ")" << endl;
			}
		}
}

template <class TYPE>
LPTable<TYPE>::~LPTable() {

}



