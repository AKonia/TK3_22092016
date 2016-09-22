#include <iostream>
#include <cstring>
class String
{	
	private:
		char * data;
		size_t len;
	public:
		String(){data = 0; len = 0;};
		String(const String & s)
		{
			len = s.len;
			data = new char[len];
			for(size_t i = 0; data[i] = s.data[i]; i++);
		}
		String(const char * s, size_t length)
		{
			len = length;
			data = new char[len];
			for(size_t i = 0; data[i] = s[i]; i++);
		}
		~String(){delete[] data;};
		char &operator[](size_t indx){return data[indx % len];};
		bool operator==(const String & s)
		{	
			if(!(len - s.len))
				return false;
			for(size_t i =0; data[i]; i++)
				if(data[i] != s.data[i])
					return false;
			return true;
		}
		String & operator=(const String & s)
		{	
			len = s.len;
			delete[] data;
			data = new char[len];
			for(size_t i = 0; data[i] = s.data[i]; i++);
			return *this;
		}
		String & operator=(const char * s)
		{	
			len = strlen(s);
			delete[] data;
			data = new char[len];
			for(size_t i = 0; data[i] = s[i]; i++);
			return *this;
		}
		void printStr(){std::cout << data;}		
		size_t getLen(){return len;}
};


class StringArray
{
	private:
		String * data;
		size_t len;
	public:
		StringArray(size_t length, String * arr)
		{
			len = length; 
			data = new String[len];
			for(int i = 0; i < len; i++)
				data[i] = arr[i];
		}
		String & operator[](size_t indx){return data[indx % len];}	
		StringArray & mergeUniqe(StringArray & sa)
		{
			size_t newLen = len;
			for(int i = 0; i < sa.len; i++)
			{
				newLen++;
				for(int j = 0; j < len; j++)
					if(sa[i] == data[j])
					{
						newLen--;
						break;
					}
			}
			String * newData = new String[newLen];
			for(int i = 0; i < len; i++)
				newData[i] = data[i];
		 	int indx = len+1;
			for(int i = 0; i < sa.len; i++)
			{
				bool ansCopy = true;
				for(int j = 0; j < len; j++)
					if(sa[i] == data[j])
					{
						ansCopy = false;
						break;
					}
				if(ansCopy)
					newData[indx++] = sa[i]; 
			}
			delete[] data;
			len = newLen;
			data = newData;
			return *this; 
		}
		StringArray & merge(StringArray * sa)
		{
			String * mergedData = new String[len + sa->len];						
			for(int i = 0; i < len; i++)
				mergedData[i] = data[i];
			delete[] data;
			for(int i = 0; i < sa->len; i++)
				mergedData[i+len] = data[i];
			len += sa->len; 
			return *this;
		}
		~StringArray(){delete[] data;}
};
