// s 15:32
// e 16:06
#include<bits/stdc++.h>
using namespace std;

int truckCnt, bridgeLen, maxLoad;//트럭수,다리길이,최대하중
int weights[1001];
queue<int> bridge;
int ans;
int weightOnBridge;

int main(void)
{
	cin >> truckCnt >> bridgeLen >> maxLoad;
	for (int i = 0; i < truckCnt; ++i) {
		cin >> weights[i];
	}

	int enteringIdx = 0;

	while (true) {
		++ans;

		if (bridge.size() == bridgeLen) {// 트럭 다리에서 탈출
			int leavingIdx = bridge.front();

			if (leavingIdx == truckCnt - 1) { // 마지막 트럭 탈출 == 종료
				break;
			}

			bridge.pop();

			if (leavingIdx != -1) {
				weightOnBridge -= weights[leavingIdx];
			}
		}

		if (weightOnBridge + weights[enteringIdx] <= maxLoad) { // 트럭 다리에 진입
			bridge.push(enteringIdx);
			weightOnBridge += weights[enteringIdx++];
		}
		else { // 하중 초과 == 대기 
			bridge.push(-1);
		}
	}

	cout << ans;

	return 0;
}