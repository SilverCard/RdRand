using namespace System;

#pragma once
namespace SilverCard {
	public ref class RandomGeneratorException : Exception
	{
	public:
		RandomGeneratorException() : Exception("rdrand did not generate a number.") {}
		RandomGeneratorException(String ^ message) : Exception(message) {}
		RandomGeneratorException(Exception ^ ex) : Exception("rdrand did not generate a number. See inner exception for details.", ex) {}
	};
}

