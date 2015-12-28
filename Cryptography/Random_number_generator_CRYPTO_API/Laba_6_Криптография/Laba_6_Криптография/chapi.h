#include <iostream>
#include <windows.h>
using namespace std;

class CAPI
{
public:
	HCRYPTPROV hProv; //хэндл криптопровайдера иницализированного вызовом функции CryptAcquireContext
	int dwLen; //длина генерируемой последовательности в байтах
	byte *pbBuffer; //буфер для хранения результирующих данных

	CAPI(HCRYPTPROV HProv, int length){
		hProv = HProv;
		dwLen = length;
		pbBuffer = new byte[dwLen];
	}
	~CAPI()
	{
		delete[] pbBuffer;
		CryptAcquireContext(&hProv, 0, 0, PROV_RSA_FULL, CRYPT_DELETEKEYSET);
	}

	void Generate()
	{
		CryptAcquireContext(&hProv, 0, 0, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT | CRYPT_NEWKEYSET);
		CryptGenRandom(hProv, dwLen, pbBuffer);
	}

	void Out()
	{
		for (DWORD i = 0; i < dwLen; ++i)
			cout << hex << DWORD(pbBuffer[i]);
	}
};