#pragma once
template<typename T>
class Arr
{
	T* _arr;
	int _size;
	int _cap; //  capacity
	int _grow; // grow   // изменить на +10 
public:
	Arr();
	Arr(int c);
	Arr(const Arr& obj);

	void setSize(int s, int grow = 10);  //

	int getSize()const;
	int getCap()const;
	int getGrow()const;
	int getUpperBound()const;		// отримання останнього допустимого індексу в масиві
	T* getData()const;			//  отримання адреси масиву з даними;

	void add(T val);		//  додавання елемента в масив
	void freeExtra();		// видалити «зайву» пам’ять (вище останнього допустимого індексу);
	void removeAll();		// видалити всі;
	void setAt(T val, int index);		// встановлення нового значення для певного елемента
	void append(Arr& obj);		// «складання» двох масивів;
	void insertAt(T val, int index);    // вставлення елемента(-ів) в задану позицію;
	void removeAt(int index);	// видалення елемента (-ів) із заданої позиції.
	void show()const;

	T getAt(int index);   // — отримання певного елемента (за індексом);

	T& operator[](int index);		// для реалізації двох попередніх функцій;
	Arr& operator=(const Arr& obj);

	bool isEmpty();		// масив порожній ?;
	bool isFull();
	~Arr();
};

template<typename T>
inline Arr<T>::Arr():_cap{ 10 },_arr{new T[10]}, _size{0}, _grow{10}
{
}

template<typename T>
inline Arr<T>::Arr(int c)
{
	_arr = new T[c];   
	_cap = c;
	_size = 0;
	_grow = 10;
}

template<typename T>
inline Arr<T>::Arr(const Arr& obj)
{
	if (obj._arr != nullptr)
	{
		_size = obj._size;
		_cap = obj._cap;
		_grow = obj._grow;
		_arr = new T[obj._cap];  //
		for (int i = 0; i < obj._size; i++)
		{
			_arr[i] = obj._arr[i];
		}
	}
}

template<typename T>
inline void Arr<T>::setSize(int s, int grow)
{
	_grow = grow;
	if (s > _cap)
	{
		T* newArr = new T[s+_grow];   // 
		_cap = s+_grow;					//
		for (int i = 0; i < _size; i++)
		{
			newArr[i] = _arr[i];
		}
		delete[]_arr;
		_arr = newArr;
	}
	else if (s < _size)
	{
		_size = s;
	}
}



template<typename T>
inline int Arr<T>::getSize() const
{
	return _size;
}

template<typename T>
inline int Arr<T>::getCap() const
{
	return _cap;
}

template<typename T>
inline int Arr<T>::getGrow() const
{
	return _grow;
}

template<typename T>
inline int Arr<T>::getUpperBound() const
{
	return _size-1;
}

template<typename T>
inline T* Arr<T>::getData() const
{
	return _arr;
}

template<typename T>
inline void Arr<T>::add(T val)
{
	if (isFull())
	{
		_cap += _grow;
		T* newArr = new T[_cap];
		for (int i = 0; i < _size; i++)
		{
			newArr[i] = _arr[i];
		}
		delete[]_arr;
		_arr = newArr;
	}
	_arr[_size] = val;
	_size++;
}

template<typename T>
inline void Arr<T>::freeExtra()
{
	if (_arr != nullptr && _size !=_cap)
	{
		_cap = _size;
		T* newArr = new T[_cap];
		for (int i = 0; i < _size; i++)
		{
			newArr[i] = _arr[i];
		}
		delete[]_arr;
		_arr = newArr;
	}
}

template<typename T>
inline void Arr<T>::removeAll()
{
	delete[]_arr;
	_cap = 10;
	_size = 0;
	_grow = 10;
	_arr = new T[_cap];
}

template<typename T>
inline T Arr<T>::getAt(int index)
{
	if (index >= 0 && index < _size)
	{
		return _arr[index];
	}
	return T (INT32_MAX);   //  return INT MAX  // TEST
}

template<typename T>
inline void Arr<T>::setAt(T val, int index)
{
	if (index >= 0 && index < _size)
	{
		_arr[index] = val;
	}
}

template<typename T>
inline T& Arr<T>::operator[](int index)
{
	if (index >= 0 && index < _size)
	{
		return _arr[index];
	}
	T exc = -1;				//  <---
	/*return _arr[0];		*/	//   nado exception
	return exc;				// fix later ?
}

template<typename T>
inline Arr<T>& Arr<T>::operator=(const Arr& obj)
{
	if (this != &obj && obj._arr != nullptr)
	{
		delete[]_arr;
		_arr = new T[obj._cap];
		_size = obj._size;
		_cap = obj._cap;
		_grow = obj._grow;
		for (int i = 0; i < obj._size; i++)
		{
			_arr[i] = obj._arr[i];
		}
	}
	return *this;
}

template<typename T>
inline void Arr<T>::append(Arr& obj)
{
	if (_arr != nullptr && obj._arr != nullptr)
	{
		setSize(_size + obj._size);
		for (int i = _size,j=0; j < obj._size; i++,j++)
		{
			_arr[i] = obj._arr[j];
		}
		_size += obj._size;
	}
}

template<typename T>
inline void Arr<T>::insertAt(T val, int index)
{
	if (index >= 0 && index < _size)
	{
		if (_size == _cap)
		{
			setSize(_size + 1);
		}
		for (int i = _size; i > index; i--)
		{
			_arr[i] = _arr[i - 1];
		}
		_arr[index] = val;
		_size++;
	}
}

template<typename T>
inline void Arr<T>::removeAt(int index)
{
	if (index >= 0 && index < _size)
	{
		for (int i = index; i < _size-1; i++)
		{
			_arr[i] = _arr[i + 1];
		}
		_size--;
	}
}

template<typename T>
inline bool Arr<T>::isEmpty()
{
	return _size == 0;
}

template<typename T>
inline bool Arr<T>::isFull()
{
	return _size == _cap;
}

template<typename T>
inline void Arr<T>::show() const
{
	for (int i = 0; i < _size; i++)
	{
		cout << _arr[i] << " ";
	}
	cout << endl;
}

template<typename T>
inline Arr<T>::~Arr()
{
	if (_arr != nullptr)
	{
		delete[]_arr;
	}
}
 
template<typename T>
inline ostream& operator<<(ostream& out, Arr<T>& obj)
{
	for (int i = 0; i < obj.getSize(); i++)
	{
		out << obj[i] << " ";
	}
	cout << endl;
	return out;
}
