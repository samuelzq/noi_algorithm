#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	int n;

	cin >> n;
	int i1, i2, i3, i4, i5, i6, i7, i8, i9, i0;
	for (i1 = 9; i1 < 12; i1++)
		for(i2 = 9; i2 < 12; i2++)
			for(i3 = 9; i3 < 12; i3++)
				for(i4 = 9; i4 < 12; i4++)
					for(i5 = 9; i5 < 12; i5++)
						for(i6 = 9; i6 < 12; i6++)
							for(i7 =9 ; i7 < 12; i7++)
								for(i8 = 9; i8 < 12; i8++)
									for(i9 = 9; i9 < 12; i9++)
										for(i0 = 9; i0 < 12; i0++) {
            int m = i1 + i2 * 3 + i3 * 9 + i4 * 27 + i5 * 81 + i6 * pow(3, 5)
					+ i7 * pow(3, 6) + i8 * pow(3, 7) + i9 * pow(3, 8)
					+ i0 * pow(3, 9);
			if (m == n)
				cout << i1 << '\n' << i2 << '\n' << i3 << '\n'
					<< i4 << '\n' << i5 << '\n' << i6 << '\n'
					<< i7 << '\n' << i8 << '\n' << i9 << '\n'
					<< i0;
		}
	return 0;
}
