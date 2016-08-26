#include"Configer.h"

/*****************将字符串转换为能减少哈希冲突的整形的公式*********************/

static size_t BKDRHash(const char * str)
{
	unsigned int seed = 131; // 31 131 1313 13131 131313
	unsigned int hash = 0;
	while (*str)
	{
		hash = hash * seed + (*str++);
	}
	return (hash & 0x7FFFFFFF);
}

/*****************减少哈希冲突的素数表（_capacity）*********************/

const int _PrimeSize = 28;
static const unsigned long _PrimeList[_PrimeSize] =
{
	53ul, 97ul, 193ul, 389ul, 769ul,
	1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
	49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
	1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
	50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
	1610612741ul, 3221225473ul, 4294967291ul
};

template<class K,class V>
struct Node
{

	Node(K key = K(), V value=V())
		:_key(key), _value(value), _next(NULL)
	{}

	K _key;
	V _value;
	Node<K, V>* _next;
};

template<class T>
struct HashFun
{
	size_t operator()(T t)
	{
		return t;
	}
};

template<>
struct HashFun<string>
{
	size_t operator()(const string& str)
	{
		return BKDRHash(str.c_str());
	}
};

template<class K,class V,class H>
class HashBucket
{
public:
	HashBucket()
		:_size(0)
	{}

	HashBucket(const HashBucket& H)               //拷贝构造
	{
		_array.resize(H._array.size());
		_size = H._size;
		Node<K, V> *_old = NULL,*_new = NULL;
		for (int i = 0; i < _array.size(); ++i)
		{
			_old = H._array[i];
			if (_old)
			{
				_new = new Node<K, V>(_old->_key, _old->_value);
				_new->_next = _array[i];
				_array[i] = _new;
				_old = _old->_next;
			}
		}
	}

	HashBucket<K, V, H>& operator = (HashBucket<K, V, H> Hash)
	{
		if (this != NULL)
		_swap(Hash);
		return *this;
	}

	~HashBucket()
	{
		Node<K, V> *cur;
		for (int i = 0; i < _array.size(); ++i)
		{
			cur = _array[i];
			while (cur)
			{
				cur = cur->_next;
				delete _array[i];
				_array[i] = cur;
			}
		}
	}


	void Insert(K& key, V& value);
	Node<K, V>* Find(K& key, V& value);
	bool Delete(K& key,V& value);
	bool Alter(K& key, V& value, V& newValue);
	void Show();
protected:
	vector<Node<K, V>*> _array;
	size_t _size;

	size_t _getCapacity()
	{
		for (int i = 0; i < _PrimeSize; ++i)
		{
			if (_PrimeList[i] > _size)
				return _PrimeList[i];
		}
	}
	void _swap(HashBucket<K,V,H>& Hash)
	{
		_array.swap(Hash._array);
		_size = Hash._size;
	}
};

template<class K, class V, class H>
void HashBucket<K, V, H>::Insert(K& key, V& value)
{
	int index;
	if (_size == _array.size())       //扩容
	{
		HashBucket<K, V, H> tmp;
		int newCapacity = _getCapacity();
		Node<K, V> *_old = NULL;
		tmp._array.resize(newCapacity);
		for (int i = 0; i < _array.size(); ++i)
		{
			_old = _array[i];
			while (_old)
			{
				_old = _old->_next;
				index = H()(_array[i]->_key) % newCapacity;
				_array[i]->_next = tmp._array[index];
				tmp._array[index] = _array[i];
				_array[i] = _old;
			}
		}
		_swap(tmp);
	}
	Node<K, V>* cur = new Node<K,V>(key,value);
	index = H()(key) % _array.size();
	cur->_next = _array[index];
	_array[index] = cur;
	_size++;
}
template<class K, class V, class H>
Node<K, V>* HashBucket<K, V, H>::Find(K& key,V& value)
{
	int index = H()(key) % _array.size();
	Node<K, V>* node = _array[index];
	while (node)
	{
		if (node->_value == value)
			return node;
		node = node->_next;
	}
	return NULL;
}
template<class K, class V, class H>
bool HashBucket<K, V, H>::Delete(K& key,V& value)
{
	int index = H()(key) % _array.size();
	Node<K, V> *node = _array[index],*pre = NULL;
	while (node)
	{
		if (node->_value == value)
		{
			if (pre)
				pre->_next = node->_next;
			else
				_array[index] = node->_next;
			delete node;
			return true;
		}
		pre = node;
		node = node->_next;
	}
	return false;
}
template<class K, class V, class H>
bool HashBucket<K, V, H>::Alter(K& key,V& value, V& newValue)
{
	Node<K, V>* node = Find(key,value);
	if (node)
	{
		node->_value = newValue;
		return true;
	}
	return false;
}

template<class K, class V, class H>
void HashBucket<K, V, H>::Show()
{
	Node<K, V>* cur;
	for (int i = 0; i < _array.size(); ++i)
	{
		cur = _array[i];
		while (cur)
		{
			cout << '[' << cur->_key << ']' << " : " << cur->_value << endl;
			cur = cur->_next;
		}
	}
}


void main()
{
	HashBucket<string, string, HashFun<string>> H;
	string str1 = "物联网";
	string str2 = "计本";
	string str3 = "网络";
	string name1 = "石豪";
	string name2 = "林中豪";
	string name3 = "段家涛";
	string name4 = "王越";
	string name5 = "嘉宝";

	H.Insert(str1,name1);
	H.Insert(str1,name2);
	H.Insert(str2,name3);
	H.Insert(str2,name4);
	H.Insert(str3,name5);

	H.Alter(str2, name3, name1);
	H.Delete(str2, name1);
	H.Show();
}