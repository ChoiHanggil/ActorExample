#pragma once
#include "D2DFramework.h"
#include "Actor.h"
#include<memory>

class ActorExample : public D2DFramework
{
	std::unique_ptr<Actor> mspBackground;
	std::unique_ptr<Actor> mspBug;

public:
	HRESULT Init(HINSTANCE hInstance, LPCWSTR title = L"ActorExample", 
		UINT width =1024, UINT height = 768) override;
	void Release() override;
	void Render() override;


};

// �̱���(singleton) ����
//	���α׷� ���� �߿� �ν��Ͻ��� �ϳ��� �����ǵ��� ��
// 
// class Singleton
// {
//	public:
//		static Singleton& Instance()
//		{
//			static Singleton Instance;
//			return instance;
//		}
// }
//