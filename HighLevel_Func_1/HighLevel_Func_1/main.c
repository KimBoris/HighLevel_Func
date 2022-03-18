#include <stdio.h>

//int main(void)
//{
	//<함수에 대한 고급 이론>
	//함수의 이름 > 배열의 이름처럼 '주소 상수'에 부여한 식별자
	//포인터 변수(함수 포인터)에 담을 수 있는 정보

	//배열 - > 자료
	//ㄴ> 식별시 주소로 한다. *주소 상수
	//자료형
	//1. 정수형
	//2. 실수형
	//3. 유도형 : 배열 

	//이것말고 '함수형'이라는 것이 있다.
	// ㅇ        ㅇ        ㅇ()
	//반환형식  호출규칙	 이름(주소)
	//이 함수라는 것은 '기계어'로 번역이 된다.
	//어떠한 메모리에 저장되어 있다
	// 이런 메모리의 특징 = R-X가능 W불가능
	// >>연산하는 코드에 대한 해석이 변화가 일어나기 때문

	//<성능 향상>
	//함수 호출시에는 비용이 든다 ( CPU + 메모리 사용)
	//함수 호출 자체가 이미 연산인데다 스택을 사용해야 한다.

	//따라서, 매크로가 나왔는데
	//1.이 매크로의 치명적인 단점 : 함수 호출 자체가 이미 연산인데다 스택을 사용해야 하는 점
	//2. 매개변수의 자료형이 없다
	//그래서 __inline함수가 나왔다.

	/*
	<WHY매크로를 사용?>
	- 함수가 함수를호출하게 되면


	 B()|매개변수n
	 ---|------
	 A()|매개변수 
	 ---|------
		|			<<이 그림처럼 매개변수가 있다면 계속해서 써줘야한다.

		- Call Overhead = 함수를 호출하는데 드는 비용
		- 비용의 증가 > 스택(제어, 흐름과 관련된)의 증가
		- 매개변수의 복사양이 많아진다면 복사할 때 로드도 많이 증가
		- 함수 설계시 덩치큰 구조체를 매개변수로 주는것은 그리 좋은것은 아니다. 

		- 코드조각은 함수이다.
	    - 함수는함 수 - 1. 유지보수		만드는데 > 코드 조각의 내용이 너무 작고 자주 호출될 때 > 매크로를 사용한다. 
		             - 2. 구조를 위해서

	- 매크로가 아닌 대안 = __inline함수를 사용한다. , 대게 __inline함수로 불가능한 것들만 매크로를 사용한다.
	- ex) #연산, ##연산 등


	- ex)예시

	#define ADD(a,b) (a+b)

	int main(void)
	{
		printf("%d\n", ADD(3,4));	 - 이게 함수라면 함수를 넘겨 받아 결과를 찍어넣는다. 
									 - 함수처럼 생겼지만 실제로는 함수가 전혀 아니다. (a+b)일 뿐이다.
									 - 함수쪽에 OverHead가 전혀 없는 코드가 된다.
		//vs

		printf("%d\n", (a+b));		 - 함수가 아니라면 바로 결과를 출력함
	
		return 0;
	}



	//////////////////////////
	< (a+b)를 묶어놓은 이유   >
	/////////////////////////

	만약  a + b 라면?
	printf("%d", Add(3,4)*2);  = 11  > 3+4*2 = 11
	printf("%d", (3+4)*2); = 14;


	*/


/*
<매크로 특수화 연산자>
1. #  -> 인수가 무엇이든 '문자열'로 만들어주는 연산자
2. ## -> 두 매개변수를 한 덩어리로 묶어 코드를 만들어 주는 매크로
	*****오로지 매크로 내부에서만 사용가능하다.***** 



	(ex)
	#define STRING(a) #a

	#define PASTER(a,b) a##b

	int main(void)
	{
		int nData = 10;

		//PASTER(nDa, ta) = PASTER(nData) 와 같다.
		1. printf("%d", PASTER(nDa,ta));
		2. printf("%d", nData); 
		- 1,2 는 완벽히 같은 식이다.

		결과값 = 10, 10


		//"nData"로 처리된다.
		printf(%s, STRING(nData)); = "nData";



		* 이와 같은 매크로를 잘 알아두면 '코드생성기'혹은 '코드 자동화'를 구현하는데 도움이 된다.
		* 매크로의 가장 큰 쓰임새중 하나는 바로 '코드생성기'를 이용한 자동화
		* 함수의 오버헤드를 줄이는 역활도 하지만, 특정 소스코드를 생성하도록 할 수 있다.
		* 여기에 조건부 컴파일 전 처리기까지 더해지면 매우 정교한 처리가 가능하다.

*/



	//return 0;
//}

int Add(int a, int b)
{
	int nResult = 0;
	nResult = a + b;
	return nResult;
}

int main(void)
{
	int nResult = 0, x, y; 

	scanf("%d%d", &x, &y);
//	nResult = Add(3, 4);
	printf("%d\n", nResult);
	return 0;
}