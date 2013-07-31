template <typename type>
void swap(type &a, type &b){
	type c;
	c = a;
	a = b;
	b = c;
}