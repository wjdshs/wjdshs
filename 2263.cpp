#include <iostream>
int postorder[100001];
int inorder[100001];
int find_root[100001];
int n;

void func(int s, int e, int s2, int e2){
    if(s > e) return; 
    int root = postorder[e2];
    printf("%d", root);
    int pos = find_root[root];
    func(s, pos - 1, s2, s2 + (pos - 1 - s));
    func(pos + 1, e, s2 + pos - s, e2 - 1); 
    return; 
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) { 
		scanf("%d", &inorder[i]);
        find_root[inorder[i]] = i;  
	}
	for (int i = 0; i < n; ++i) scanf("%d", &postorder[i]);
	func(0, n - 1, 0, n - 1); 
}