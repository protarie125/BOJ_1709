#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using pll2 = pair<ll, ll>;
using vll2 = vector<pll2>;

bool isCircle(ll x, ll y, ll r2) {
	return (((x * x) + (y * y)) < r2) &&
		(r2 < (((x + 1) * (x + 1)) + ((y + 1) * (y + 1))));
}

vll2 mov{ {1, 0}, {0, -1}, {1, -1} };

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	ll n;
	cin >> n;

	const auto& r = n / 2;
	const auto& r2 = r * r;

	auto ct = ll{ 0 };
	auto x = ll{ 0 };
	auto y = ll{ r - 1 };

	while (x != y) {
		++ct;
		for (int i = 0; i < 3; ++i) {
			auto nx = x + mov[i].first;
			auto ny = y + mov[i].second;

			if (isCircle(nx, ny, r2)) {
				x = nx;
				y = ny;
				break;
			}
		}
	}

	cout << 4 + ct * 8;

	return 0;
}