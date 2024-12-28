#include <iostream>

int main(){
	struct Foo1 {
		int a;
		char b;
		float c;
		char d;
	};

	Foo1 foo1;
	printf("sizeof(foo1): %d\n", sizeof(foo1));
	printf("&foo1.a: %p, sizeof(foo1.a): %d\n", &foo1.a, sizeof(foo1.a));
	printf("&foo1.b: %p, sizeof(foo1.b): %d\n", &foo1.b, sizeof(foo1.b));
	printf("&foo1.c: %p, sizeof(foo1.c): %d\n", &foo1.c, sizeof(foo1.c));
	printf("&foo1.d: %p, sizeof(foo1.d): %d\n", &foo1.d, sizeof(foo1.d));
	printf("--------------------------------------\n");

	struct Foo2 {
		int a;
		float c;
		char b;
		char d;
	};

	Foo2 foo2;
	printf("sizeof(foo2): %d\n", sizeof(foo2));
	printf("&foo2.a: %p, sizeof(foo2.a): %d\n", &foo2.a, sizeof(foo2.a));
	printf("&foo2.c: %p, sizeof(foo2.c): %d\n", &foo2.c, sizeof(foo2.c));
	printf("&foo2.b: %p, sizeof(foo2.b): %d\n", &foo2.b, sizeof(foo2.b));
	printf("&foo2.d: %p, sizeof(foo2.d): %d\n", &foo2.d, sizeof(foo2.d));
	printf("--------------------------------------\n");

	Foo2 F[5];
	for (int i = 0; i < 5; i++) {
		printf("&F[%d]: %p\n", i, &F[i]);
	} //end-for	

    return 0;
}