#ifndef CONCLASS
#define CONCLASS
#include <iostream>

namespace necro {
	template <class TYP>
	class Iterator {
	private:
		TYP* this_el;
	public:
		// êîíñòðóêòîðû
		Iterator() : this_el(nullptr) {}
		Iterator(TYP* val) : this_el(val) {}
		~Iterator() {}
		// îïåðàòîðû ñðàâíåíèÿ
		bool operator !=(const Iterator<TYP>& other) const {
			if (this_el == nullptr || other.this_el == nullptr) {
				return false;
			}
			return (this->this_el != other.this_el);
		}
		bool operator ==(const Iterator<TYP>& other) const {
			if (this_el == nullptr || other.this_el == nullptr) {
				return false;
			}
			return (this->this_el == other.this_el);
		}
		bool operator >(const Iterator<TYP>& other) const {
			if (this_el == nullptr || other.this_el == nullptr) {
				throw std::logic_error("nullptr");
			}
			else {
				return (this->this_el > other.this_el);
			}
		}
		bool operator <(const Iterator<TYP>& other) const {
			if (this_el == nullptr || other.this_el == nullptr) {
				throw std::logic_error("nullptr");
			}
			else {
				return (this->this_el < other.this_el);
			}
		}
		bool operator >=(const Iterator<TYP>& other) const {
			if (this_el == nullptr || other.this_el == nullptr) {
				throw std::logic_error("nullptr");
			}
			else {
				return (this->this_el >= other.this_el);
			}
		}
		bool operator <=(const Iterator<TYP>& other) const {
			if (this_el == nullptr || other.this_el == nullptr) {
				throw std::logic_error("nullptr");
			}
			else {
				return (this->this_el <= other.this_el);
			}
		}
		// äîñòóï ê ýëåìåíòàì ìàññèâà ïî óêàçàòåëþ
		TYP& operator *() {
			return *this->this_el;
		}
		TYP* operator ->() {
			return this->this_el;
		}
		// ïåðåìåùåíèå èòåðàòîðà íà ñëåäóþùóþ ïîçèöèþ â ìàññèâå
		Iterator<TYP>& operator ++() {
			++this->this_el;
			return *this;
		}
		Iterator<TYP>& operator --() {
			--this->this_el;
			return *this;
		}
		Iterator<TYP>(const Iterator<TYP>& other) {
			this->this_el = other.this_el;
		}
		Iterator<TYP>& operator = (const Iterator<TYP> other) {
			this->this_el = other.this_el;
			return *this;
		}

	};


	template <class T>
	class vector {
	private:
		T* mas;
		int len;
	public:
		friend class Iterator<T>;
		vector() {
			this->len = 0;
			this->mas = nullptr;
		}

		vector(const vector& other) {
			this->len = other.len;
			this->mas = nullptr;
			if (this->len > 0) {
				this->mas = new T[this->len];
				for (int i = 0; i < this->len; i++) {
					this->mas[i] = other.mas[i];
				}
			}
		}

		vector& operator = (const vector other) {
			this->len = other.len;
			if (this->len > 0) {
				this->mas = new T[this->len];
				for (int i = 0; i < this->len; i++) {
					this->mas[i] = other.mas[i];
				}
			}
			return *this;
		}

		vector(int l) {
			if (l >= 0) {
				if (l > 0) {
					mas = new T[l];
					len = l;
				}
				else {
					len = 0;
					mas = nullptr;
				}
			}
			else { return nullptr; }
		}


		~vector() {
			delete[] mas;
		}

		void erase() {
			delete[] mas;
			mas = nullptr;
			len = 0;
		}


		T& operator[](int index) {
			if (index >= 0 && index < len)
				return mas[index];
			else { throw std::logic_error("Error"); }
		}


		int getlen()const { return len; }


		void resize(int new_len) {
			if (new_len == len) { return; }
			if (new_len <= 0) {
				erase();
				return;
			}
			T* nmas = new T[new_len];
			for (int i = 0; i < len; i++) {
				nmas[i] = mas[i];
			}
			delete[] mas;
			mas = nmas;
			len = new_len;
		}


		void reinit(int new_len) {
			erase();
			if (new_len <= 0) { return; }
			mas = new T[new_len];
			len = new_len;
		}
		void remove(int index) {
			if (index < 0 || index >= len) { return; }
			if (len == 1) {
				erase();
				return;
			}
			T* nmas = new T[len - 1];
			for (int i = 0; i < index; i++) {
				nmas[i] = mas[i];
			}
			for (int i = index + 1; i < len; i++) {
				nmas[i - 1] = mas[i];
			}
			delete[] mas;
			mas = nmas;
			this->len = this->len - 1;
			return;
		}

		void push_back(T new_el) {
			resize(this->len + 1);
			this->mas[this->len - 1] = new_el;
		}

		typedef Iterator<T> Iterator;
		Iterator begin() const {
			return Iterator(this->mas);
		}
		Iterator end() const {
			return Iterator(this->mas + (this->len));
		}
		Iterator find(int num) const {
			if (num < 0 || num > this->len) {
				num = this->len;
			}
			return Iterator(this->mas + num - 1);
		}
	};



}

#endif