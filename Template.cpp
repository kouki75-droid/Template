// Template.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>

//int main_int (int a, int b)
//{
//    return a > b ? a : b;
//}
//
//long main_long (long a, long b)
//{
//    return a > b ? a : b;
//}
//
//float main_float (float a, float b)
//{
//    return a > b ? a : b;
//}

//template<class T>
//T max(T a, T b)
//{
//    return a > b ? a : b;
//}
//
//int a = max(3, 5);
//double b = max(3.0, 5.0);

    
template<typename T,std::size_t N>
class StaticArray {
	T data[N];
public:
	constexpr T& operator[](std::size_t i){ return data[i]; }
	constexpr const T& operator[](std::size_t i) const { return data[i]; }
	constexpr std::size_t size() const { return N; }
};


int main()
{

   /* int a = 10;
    int b = 20;

    float c = 10.1;
    float d = 10.2;

    std::cout << "max:" << max(a, b) << std::endl;

    std::cout << "max:" << max(c, d) << std::endl;*/


    StaticArray<int, 3 > data;

    for (auto i = 0; i < data.size(); ++i) {

        data[i] =  i;
	}

	std::cout << data[11] << std::endl;
}

