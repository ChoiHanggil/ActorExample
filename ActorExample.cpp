#include "ActorExample.h"

HRESULT ActorExample::Init(HINSTANCE hInstance, LPCWSTR title, UINT width, UINT height)
{
	HRESULT hr = D2DFramework::Init(hInstance, title, width, height);
	ThrowIfFailed(hr);

	mspBackground = std::make_unique<Actor>(this, L"Images/back1.png");
	mspBug = std::make_unique<Actor>(this, L"Images/bug1_1.png");


	return S_OK;
}

void ActorExample::Release()
{
	mspBug.reset();
	mspBackground.reset();

	D2DFramework::Release();
}

void ActorExample::Render()
{
	mspRenderTarget->BeginDraw();

	mspRenderTarget->Clear(D2D1::ColorF(0.0f, 0.2f, 0.4f, 1.0f));

	mspBackground->Draw();
	mspBug->Draw();

	mspRenderTarget->EndDraw();
	HRESULT hr = mspRenderTarget->EndDraw();
	if (hr == D2DERR_RECREATE_TARGET)
	{
		CreateDeviceResources();
	}
}
