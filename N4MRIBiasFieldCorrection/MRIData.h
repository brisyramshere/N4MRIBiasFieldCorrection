#pragma once
#include <memory>

template<class  T>
class MRIData
{
private:
	T* data;
	int iLen;
	int Xdim;
	int Ydim;
	int Zdim;
	float Xspace;
	float Yspace;
	float Zspace;
public:
	MRIData(T* data, int iLen)
	{
		data = new T[iLen];
		memcpy(this->data, data, iLen * sizeof(T));
	}
	MRIData(T value, int iLen) 
	{
		data = new T[iLen];
		memset(data, value, iLen * sizeof(T));
	}
	~MRIData();
	void SetDim(int* iDim);
	void SetSpace(float* fSpace);
	T& operator()(int x, int y, int z) { return *(data + z*Ydim*Xdim + y*Xdim + x); }
	T& operator()(int n) { return *(data + n); }
	void operator=(T value) { memset(data, value, sizeof(T)*iLen); }
};