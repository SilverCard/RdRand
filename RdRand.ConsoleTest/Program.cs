using System;
using SilverCard;

namespace SilverCard.RdRandConsoleTest
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Title = "RdRand.ConsoleTest";                        

            if (RdRand.IsRdRandSupported())
            {
                try
                {
                    Console.WriteLine($"Testing {nameof(RdRand.Rand16)}.");
                    for (int i = 0; i < 10; i++) Console.WriteLine(RdRand.Rand16());

                    Console.WriteLine($"Testing {nameof(RdRand.Rand32)}.");
                    for (int i = 0; i < 10; i++) Console.WriteLine(RdRand.Rand32());

                    Console.WriteLine($"Testing {nameof(RdRand.Rand64)}.");
                    for (int i = 0; i < 10; i++) Console.WriteLine(RdRand.Rand64());

                    Console.WriteLine("Test complete.");
                }
                catch (Exception ex)
                {
                    Console.WriteLine(ex);
                }
            }
            else
            {
                Console.WriteLine("RdRand is not supported in this machine.");
            }
     
            Console.ReadLine();
        }
    }
}
