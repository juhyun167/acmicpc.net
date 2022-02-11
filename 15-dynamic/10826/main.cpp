#include <bitset>

int main() {
	bitset<10> bs;

	// 전체를 0으로 설정
	bs.reset();
	
	// 전체를 1로 설정
	bs.set();

	// 최소 하나, 또는 전체가 1이면 true 반환
	bs.any();
	bs.all();

	// n번째 비트 반전
	bs.flip(n);

	// n번째 비트 1로, n + 1번째 비트 0으로 설정
	bs.set(n, true);
	bs.set(n + 1, false);

	// n번째 비트가 1이면 true 반환
	bs.test(n);
