template <class v>
struct HashItem
{
	int key;
	v value;

	HashItem()
	{
    }
    HashItem(int key, v value)
    {
        this->key = key;
        this->value = value;
    }
	void operator=(const HashItem& rhs)
	{
		this->key = rhs.key;
		this->value = rhs.value;
	}
	void insert(int key, v data)
	{
		this->key = key;
		value = data;
	}
    int getkey()
    {
        return key;
    }
    v& getValue()
    {
        return value;
    }
};