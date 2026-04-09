#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main(void)
{
  // 없으면 시간초과 난다..
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	int n;
	stack<pair<int, int>> tower; // 타워높이, 타워번호

	cin >> n;
	tower.push({ 100000001, 0 }); // 최고 높이 지정

	for (int i = 1; i <= n; i++) // 타워 번호 1로 시작
	{
		int height;
		cin >> height;

		// 높은 타워가 나올때까지 pop
		while (tower.top().first < height) {
			tower.pop();
		}
		cout << tower.top().second << " "; // 번호 출력

		// 이미 오른쪽에 타워를 넘어섰다면
		// 그 타워보다 낮은 높이의 왼쪽 타워는 계산할 필요가 없다
		// 고로 pair로 탑에 번호를 지정해 주면서
		// 필요한 높이의 타워만 저장한다.
		
		tower.push({ height, i });
	}
	// 송신 실패 - 0
	// 송신 성공 - 수신탑 번호 
}
