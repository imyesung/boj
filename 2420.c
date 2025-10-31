#include <stdio.h>

static inline unsigned long long uabsdiff(long long N, long long M)
{
	return (N >= M)
		? (unsigned long long)N - (unsigned long long)M // true
		: (unsigned long long)M - (unsigned long long)N; // false
}

int main(void)
{
	long long N, M; // signed 64-bit integers

	if (scanf("%lld %lld", &N, &M) != 2) // Error handling for invalid input
		return 1;

	printf("%llu\n", uabsdiff(N, M)); // unsigned 64-bit output
	return 0;
}