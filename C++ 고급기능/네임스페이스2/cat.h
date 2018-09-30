#ifndef CAT_H
#define CAT_H

// 야옹이와 관련된 것들
namespace Cat
{
	// 야옹이 한 마리 정보
	class Info
	{
	public:
		void Meow();
	protected:
		char name[20];
	};

	// 여기에 extern 키워드를 붙여준 이유는
	// 일단 extern 키워드를 붙이는 것은 다른 파일에서 정의한 변수를 사용하겠다고 선언하는 의미르 가지고 있다
	// 다른 모든 헤더 파일이 그렇듯이 cat.h 파일의 용도는 example.cpp 와 같은 파일에 의해서 포함되기 위한 것이다
	// 즉 example.cpp(다른.cpp 파일) 에서 cat.cpp에 정의된 cats나 count 변수에 접근할 수 있게 만드는 역활을 한다
	extern Info cats[20];
	extern int count;

	void CreateAll();
}

#endif // !CAT_H

