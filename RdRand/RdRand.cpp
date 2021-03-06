#include "RdRand.h"
#include <immintrin.h>
#include <intrin.h>  

#pragma managed(push, off)

// Intel® Digital Random Number Generator (DRNG) Software Implementation Guide
// 4.2.1     Retry Recommendations
// It is recommended that applications attempt 10 retries in a tight loop in the unlikely event that the RDRAND instruction does not return a random number. 
const int rdrandRetry = 10;

const unsigned int flag_RDRAND = (1 << 30);

// Unmanaged rdrand16 implementation.
bool URdRand16(unsigned short* v) {
	for (int i = 0; i < rdrandRetry; ++i)
	{
		if (_rdrand16_step(v)) return true;
	}
	return false;
}

// Unmanaged rdrand32 implementation.
bool URdRand32(unsigned int* v) {
	for (int i = 0; i < rdrandRetry; ++i)
	{
		if (_rdrand32_step(v)) return true;
	}
	return false;
}

#ifdef _M_X64
// Unmanaged rdrand64 implementation.
bool URdRand64(unsigned __int64* v) {
	for (int i = 0; i < rdrandRetry; ++i)
	{
		if (_rdrand64_step(v)) return true;
	}
	return false;
}
#endif 

bool UIsRdRandSupported()
{
	int cpuid[4];
	__cpuidex(cpuid, 1, 0);
	return ((cpuid[2] & flag_RDRAND) == flag_RDRAND);
}

#pragma managed(pop)

UInt16 SilverCard::RdRand::Rand16()
{
	unsigned short v;
	if (!URdRand16(&v)) throw gcnew RandomGeneratorException();
	return v;
}

UInt32 SilverCard::RdRand::Rand32()
{
	unsigned int v;
	if (!URdRand32(&v)) throw gcnew RandomGeneratorException();	
	return v;
}

UInt64 SilverCard::RdRand::Rand64()
{
#ifdef _M_X64
	unsigned __int64 v;
	if (!URdRand64(&v)) throw gcnew RandomGeneratorException();
	return v;
#else
	throw gcnew RandomGeneratorException("Rand64 can only be called on x64 dll.");
#endif
}

Boolean SilverCard::RdRand::IsRdRandSupported()
{
	return UIsRdRandSupported();
}
