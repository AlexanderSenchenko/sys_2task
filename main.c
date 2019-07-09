#include <stdio.h>

#define N2 3
#define N3 3
#define N4 5
#define N5 7

void task2()
{
	int arr[N2][N2];

	for (int i = 0; i < N2; ++i) {
		for (int j = 0; j < N2; ++j) {
			arr[i][j] = i * N2 + j;
		}
	}

	for (int i = 0; i < N2; ++i) {
		for (int j = 0; j < N2; ++j) {
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
}

void task3()
{
	int arr[N3][N3];

	for (int i = 0; i < N3; ++i) {
		for (int j = 0; j < i; ++j)
			arr[i][j] = 0;

		for (int k = i; k < N3; ++k)
			arr[i][k] = 1;
	}

	for (int i = 0; i < N3; ++i) {
		for (int j = 0; j < N3; ++j) {
			printf("%d ", arr[i][j]);
		}
		
		printf("\n");
	}
}

void task4()
{
	int arr[N4][N4];
	int n = N4;
	int value = 1;
	int count_iter = ((N4 % 2) == 0) ? N4 / 2 : N4 / 2 + 1;

	for (int i = 0; i < count_iter; ++i, --n) {
		for (int j = i; j < n; ++j)
			arr[i][j] = value++;

		for (int j = i + 1; j < n; ++j)
			arr[j][n - 1] = value++;

		for (int j = n - 2; j >= i; --j)
			arr[n - 1][j] = value++;

		for (int j = n - 2; j > i; --j)
			arr[j][i] = value++;
	}

	for (int i = 0; i < N4; ++i) {
		for (int j = 0; j < N4; ++j)
			printf("%d\t", arr[i][j]);	
		printf("\n");
	}
}

int incr_i(int i)
{
	return ((i + 1) > N5 - 1) ? 0 : i + 1;
}

int decr_i(int i)
{
	return ((i - 1) < 0) ? N5 - 1 : i - 1;
}

int incr_j(int j)
{
	return ((j + 1) > N5 - 1) ? 0 : j + 1;
}

int decr_j(int j)
{
	return ((j - 1) < 0) ? N5 - 1 : j - 1;
}

void task5()
{
	int arr[N5][N5];
	int value;

	scanf("%d", &value);

	int curr_value = value;

	int i = 0;
	int j = 0;

	for (int i = 0; i < N5; ++i) {
		for (int j = 0; j < N5; ++j)
			arr[i][j] = value;
	}

	arr[N5 - 1][j + 1] = arr[0][0] + 1;

	do {
		if ((i == N5 - 1) && (j == 0)) {
			i = N5 - 2;
		} else {
			i = decr_i(i);
			j = incr_j(j);
		}
		// printf("%d %d %d\n", i, j, curr_value - 1);

		if (arr[i][j] != value) {
			i += 2;
			--j;
		}

		// printf("%d %d %d\n", i, j, curr_value - 1);

		arr[i][j] = --curr_value;

		// for (int i = 0; i < N5; ++i) {
		// 	for (int j = 0; j < N5; ++j)
		// 		printf("%d\t", arr[i][j]);	
		// 	printf("\n");
		// }
		// printf("\n");

		
	} while ((i != 0) || (j != N5 / 2));
	

	for (int i = 0; i < N5; ++i) {
		for (int j = 0; j < N5; ++j)
			printf("%d\t", arr[i][j]);	
		printf("\n");
	}
}

void task6()
{
	int arr[N5][N5];
	int value;

	scanf("%d", &value);

	int curr_value = value + 1;

	int i = 0;
	int j = 0;

	for (int i = 0; i < N5; ++i) {
		for (int j = 0; j < N5; ++j)
			arr[i][j] = value;
	}

	arr[N5 - 1][j + 1] = arr[0][0] + 1;
	arr[i + 1][N5 - 1] = arr[0][0] - 1;

	curr_value = value + 1;

	i = N5 - 1;
	j = 1;

	do {
		// if ((i == N5 - 1) && (j == 0)) {
		// 	i = N5 - 2;
		// } else {
			i = decr_i(i);
			j = incr_j(j);
		// }
		// printf("%d %d %d\n", i, j, curr_value - 1);

		if (arr[i][j] != value) {
			i += 2;
			--j;
		}

		// printf("%d %d %d\n", i, j, curr_value - 1);

		arr[i][j] = ++curr_value;

		// for (int i = 0; i < N5; ++i) {
		// 	for (int j = 0; j < N5; ++j)
		// 		printf("%d\t", arr[i][j]);	
		// 	printf("\n");
		// }
		// printf("\n");
	} while ((i != N5 - 1) || (j != N5 / 2));

	curr_value = value - 1;

	i = 1;
	j = N5 - 1;

	do {
		if ((i == N5 - 1) && (j == 0)) {
			i = N5 - 2;
		} else {
			i = incr_i(i);
			j = decr_j(j);
		}
		// printf("%d %d %d\n", i, j, curr_value - 1);

		if (arr[i][j] != value) {
			i -= 2;
			++j;
		}

		// printf("%d %d %d\n", i, j, curr_value - 1);

		arr[i][j] = --curr_value;

		// for (int i = 0; i < N5; ++i) {
		// 	for (int j = 0; j < N5; ++j)
		// 		printf("%d\t", arr[i][j]);	
		// 	printf("\n");
		// }
		// printf("\n");
	} while ((i != 0) || (j != N5 / 2));
	
	for (int i = 0; i < N5; ++i) {
		for (int j = 0; j < N5; ++j)
			printf("%d\t", arr[i][j]);	
		printf("\n");
	}

	// test
	int glob_sum;
	int curr_sum;
	int count_str = 0;
	
	for (int i = 0; i < N5; ++i) {
		curr_sum = 0;
		
		for (int j = 0; j < N5; ++j)
			curr_sum += arr[i][j];

		if (i == 0) {
			glob_sum = curr_sum;
		} else if (glob_sum != curr_sum) {
			printf("Error sum");
		} else {
			printf("row %d) %d\n", i, curr_sum);
		}

		curr_sum = 0;

		for (int j = 0; j < N5; ++j)
			curr_sum += arr[j][i];

		if (glob_sum != curr_sum) {
			printf("Error sum");
		} else {
			printf("coll %d) %d\n", i, curr_sum);
		}
	}

	curr_sum = 0;

	for (int i = 0; i < N5; ++i) {
		curr_sum += arr[i][i];
	}

	if (glob_sum != curr_sum) {
		printf("Error sum");
	} else {
		printf("%d) %d\n", count_str++, curr_sum);
	}

	curr_sum = 0;

	for (int i = N5 - 1, j = 0; i >= 0; --i, ++j) {
		curr_sum += arr[i][j];
	}

	if (glob_sum != curr_sum) {
		printf("Error sum");
	} else {
		printf("%d) %d\n", count_str++, curr_sum);
	}
}

int main()
{
	// task2();
	// task3();
	// task4();
	// task5();
	task6();

	return 0;
}