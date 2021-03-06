#include "RandomGeneratorException.h"

using namespace System;

#pragma once
namespace SilverCard {
	public ref class RdRand
	{
	public:
		static UInt16 Rand16();
		static UInt32 Rand32();
		static UInt64 Rand64();
		static Boolean IsRdRandSupported();
	};
}
