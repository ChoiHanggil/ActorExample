#pragma once

#include "D2DFramework.h"

class Actor
{
public:
	Actor() = delete;
	//Framework->mspWICFactory->Codec, Converter
	Actor(D2DFramework* pFramework, LPCWSTR filename);
	Actor(D2DFramework* pFramework, LPCWSTR filename, float x, float y, float opacity = 1.0f);
	virtual ~Actor();
	//IBitmap
	//x,y
	//opacity

	virtual void Draw();

protected:
	D2DFramework* mpFramework; //일반포인터 소유권X, 참조만 사용 use a
	Microsoft::WRL::ComPtr<ID2D1Bitmap> mspBitmap; // have a 
	
	float mX;
	float mY;
	float mOpacity;

private:
	HRESULT LoadWICImage(LPCWSTR filename);
	void Draw(float x, float y, float opacity = 1.0f);
};

