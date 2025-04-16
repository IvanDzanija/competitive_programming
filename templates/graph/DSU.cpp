int find(int x) {
	while (x != link[x])
		x = link[x];
	return x;
}
bool same(int a, int b) { return find(a) == find(b); }
void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (len[a] < len[b])
		swap(a, b);
	len[a] += len[b];
	link[b] = a;
}
