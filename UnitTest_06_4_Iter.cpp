#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_06_4_Iter/Lab_06_4.cpp" // Перевірте шлях до файлу проекту

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest_Lab06_4_Iter)
    {
    public:
        TEST_METHOD(TestMethod_MaxAbs)
        {
            double a[] = { -3.5, 2.1, -8.4, 4.0, 0.0 };
            Assert::AreEqual(8.4, MaxAbs(a, 5), 0.001);
        }

        TEST_METHOD(TestMethod_SumBetweenPositives)
        {
            // Перше додатне: 2.0 (індекс 1), друге додатне: 3.0 (індекс 3)
            // Елемент між ними: -7.0 (індекс 2) -> сума = -7.0
            double a[] = { -1.0, 2.0, -7.0, 3.0, 5.0, 0.0 };
            Assert::AreEqual(-7.0, SumBetweenPositives(a, 6), 0.001);
        }

        TEST_METHOD(TestMethod_MoveZerosToEnd)
        {
            double a[] = { 0.0, 2.5, 0.0, -1.2, 4.0 };
            double expected[] = { 2.5, -1.2, 4.0, 0.0, 0.0 };

            MoveZerosToEnd(a, 5);

            for (int i = 0; i < 5; i++) {
                Assert::AreEqual(expected[i], a[i], 0.001);
            }
        }
    };
}