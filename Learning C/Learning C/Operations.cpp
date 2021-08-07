void operations() {
	// assigned - =
	int a = 4;
	int b = 10;
	a = 5;

	// Math
	a = a + b;
	a = a - b;
	a = a / b;
	a = a * b;
	a = a % 2;

	a = ++a; //  At first a += 1
	a = --a; //	 At first a -= 1
	a = a++; //  At frist a = a, ignore a += 1
	a = a--; //  At first a = a, ignore a -= 1

	// Logical
	// && = And
	// || = Or
	// ! = not equal to
	a = 10;
	b = 20;
	bool c = (a == 30) && (b == 20); // c = false, && - together is true
	c = (a == 30) || (b == 20); // c = true, || - any
	bool d = !c; // d = false

	// Comparison
	// == 
	// != 
	// >
	// <
	// >=
	// <=

	// Operator abbreviations
	// +=
	// -=
	// *=
	// /=
	// %=
}