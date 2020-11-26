#pragma once

namespace Constants
{
	// 앞에 extern 붙이고 선언만 해주기
	// 선언과 body를 구분하지 않으면 헤더파일을 include할때마다 사본이 생김(다른 주소를 사용)
	extern const double pi;
	extern const double gravity;
	// . . .
}